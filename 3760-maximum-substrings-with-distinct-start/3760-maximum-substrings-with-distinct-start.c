int maxDistinct(char* s) {
    int cnt = 0;
    int arr[26] = {};
    for (; *s; s++) {
        int id = *s - 'a';
        if (arr[id] == 0)
            ++cnt;
        arr[id]++;

    }
    return cnt;
}