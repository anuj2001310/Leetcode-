bool isSumEqual(char* f, char* s, char* t) {
    int val(char* str) {
        int v = 0;
        for (; *str; str++)
            v = v * 10 + (*str - 'a');
        return v;
    }
    return val(f) + val(s) == val(t);
}