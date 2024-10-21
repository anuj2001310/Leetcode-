typedef struct {
    char* key;
    UT_hash_handle hh;
} hash_t;

bool check(hash_t* wc, char* key) {
    hash_t* tmp;
    HASH_FIND_STR(wc, key, tmp);
    return tmp;
}

bool entry(hash_t** wc, char* key) {
    hash_t* tmp;
    HASH_FIND_STR(*wc, key, tmp);
    if (tmp == NULL) {
        tmp = malloc(sizeof(hash_t));
        tmp->key = strdup(key);
        HASH_ADD_STR(*wc, key, tmp);
        return true;
    }
    return false;
}

void erase(hash_t** wc, char* key) {
    hash_t* tmp;
    HASH_FIND_STR(*wc, key, tmp);
    HASH_DEL(*wc, tmp);
}

#define SUBSTRING_LEN 5

int helper(char* s, int size, int start, hash_t* map) {
    int count = HASH_COUNT(map);
    if (start == size)
        return count;

    char sub[20] = {0};
    int index = 0;

    for (int i = start + 1; i <= size && i - start <= SUBSTRING_LEN; i++) {
        int len = i - start;
        strncpy(sub, s + start, len);
        sub[len] = '\0';
        if (check(map, sub) == false) {
            entry(&map, sub);
            int temp = helper(s, size, i, map);
            count = count > temp ? count : temp;
            erase(&map, sub);
        }
    }
    return count;
}

int maxUniqueSplit(char* s) {
    hash_t *map = NULL, *p, *tmp;
    int size = strlen(s);
    return helper(s, size, 0, map);
}