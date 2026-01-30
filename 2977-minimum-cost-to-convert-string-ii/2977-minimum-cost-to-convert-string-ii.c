#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long ull;

/* Polynomial rolling hash base */
const ull BASE = 131;

/* A large number to represent infinity */
const long long INF = 1000000000000000LL;

/* Compute hash of a string */
ull computeHash(char* s) {
    ull h = 0;
    for (int i = 0; s[i]; i++) {
        h = h * BASE + (s[i] - 'a' + 1);
    }
    return h;
}

/* Main function to find minimum cost */
long long minimumCost(char* source, char* target, char** original,
                      int originalSize, char** changed, int changedSize,
                      int* cost, int costSize) {

    int n = strlen(source);

    /* Step 1: Collect all unique strings from original and changed */
    ull uniqueHashes[300];
    int uniqueLens[300];
    int uniqueCount = 0;

    for (int i = 0; i < originalSize; i++) {
        ull hOrig = computeHash(original[i]);
        ull hChanged = computeHash(changed[i]);

        // Check and add original[i]
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (uniqueHashes[j] == hOrig) {
                found = 1;
                break;
            }
        }
        if (!found) {
            uniqueHashes[uniqueCount] = hOrig;
            uniqueLens[uniqueCount] = (int)strlen(original[i]);
            uniqueCount++;
        }

        // Check and add changed[i]
        found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (uniqueHashes[j] == hChanged) {
                found = 1;
                break;
            }
        }
        if (!found) {
            uniqueHashes[uniqueCount] = hChanged;
            uniqueLens[uniqueCount] = (int)strlen(changed[i]);
            uniqueCount++;
        }
    }

    /* Step 2: Initialize Floyd–Warshall distance matrix */
    long long dist[300][300];
    for (int i = 0; i < uniqueCount; i++) {
        for (int j = 0; j < uniqueCount; j++) {
            dist[i][j] = (i == j) ? 0 : INF;
        }
    }

    /* Step 3: Fill in direct conversion costs */
    for (int i = 0; i < costSize; i++) {
        ull hOrig = computeHash(original[i]);
        ull hChanged = computeHash(changed[i]);
        int u = -1, v = -1;

        for (int j = 0; j < uniqueCount; j++) {
            if (uniqueHashes[j] == hOrig)
                u = j;
            if (uniqueHashes[j] == hChanged)
                v = j;
        }

        if (u != -1 && v != -1 && cost[i] < dist[u][v]) {
            dist[u][v] = cost[i];
        }
    }

    /* Step 4: Floyd–Warshall to find minimal conversion cost between all pairs
     */
    for (int k = 0; k < uniqueCount; k++) {
        for (int i = 0; i < uniqueCount; i++) {
            if (dist[i][k] == INF)
                continue;
            for (int j = 0; j < uniqueCount; j++) {
                if (dist[k][j] == INF)
                    continue;
                long long newDist = dist[i][k] + dist[k][j];
                if (newDist < dist[i][j]) {
                    dist[i][j] = newDist;
                }
            }
        }
    }

    /* Step 5: Precompute rolling hashes for source and target strings */
    ull prefixHashSource[1005] = {0};
    ull prefixHashTarget[1005] = {0};
    ull power[1005] = {1};

    for (int i = 0; i < n; i++) {
        power[i + 1] = power[i] * BASE;
        prefixHashSource[i + 1] =
            prefixHashSource[i] * BASE + (source[i] - 'a' + 1);
        prefixHashTarget[i + 1] =
            prefixHashTarget[i] * BASE + (target[i] - 'a' + 1);
    }

    /* Step 6: Dynamic Programming array */
    long long dp[1005];
    for (int i = 0; i <= n; i++)
        dp[i] = INF;
    dp[n] = 0;

    /* Step 7: For each position, try all possible transformations */
    for (int i = n - 1; i >= 0; i--) {
        /* If characters already match, no cost for one character */
        if (source[i] == target[i]) {
            if (dp[i + 1] < dp[i])
                dp[i] = dp[i + 1];
        }

        /* Try all unique words as candidates for substring conversion */
        for (int w = 0; w < uniqueCount; w++) {
            int length = uniqueLens[w];
            if (i + length > n)
                continue;

            /* Compute hashes of substring source[i..i+length) and
             * target[i..i+length) */
            ull hashSubSource = prefixHashSource[i + length] -
                                prefixHashSource[i] * power[length];
            ull hashSubTarget = prefixHashTarget[i + length] -
                                prefixHashTarget[i] * power[length];

            if (hashSubSource == uniqueHashes[w]) {
                // Find index v of target substring in uniqueHashes
                int v = -1;
                for (int u = 0; u < uniqueCount; u++) {
                    if (uniqueHashes[u] == hashSubTarget) {
                        v = u;
                        break;
                    }
                }

                if (v == -1)
                    continue;
                if (dist[w][v] == INF)
                    continue;

                long long newCost = dist[w][v] + dp[i + length];
                if (newCost < dp[i])
                    dp[i] = newCost;
            }
        }
    }

    return (dp[0] == INF) ? -1 : dp[0];
}