typedef struct string {
    char* str;
    int size;
} string;

string* init(int cap) {
    string* st = (string*)malloc(sizeof(string));
    st->str = (char*)malloc(sizeof(char) * cap);
    st->size = 0;
    return st;
}
bool isPrefix(char* s, char* target) {
    int n = strlen(target), m = strlen(target);
    if (n > m)
        return false;
    int j = 0;
    for (int i = 0; target[i] && s[j]; ++i) {
        if (target[i] != s[j])
            return false;
        else
            j++;
    }
    return true;
}
int isPrefixOfWord(char* sentence, char* searchWord) {
    char** words = (char**)malloc(sizeof(char*) * 100);
    int idx = 0;
    string* h = init(100);
    for (int i = 0; sentence[i]; ++i) {
        if (sentence[i] == ' ') {
            words[idx++] = h->str;
            free(h);
            h = init(100);
        } else
            h->str[h->size++] = sentence[i];
    }
    words[idx++] = h->str;
    for (int i = 0; i < idx; i++) {
        if (isPrefix(words[i], searchWord))
            return i + 1;
    }
    return -1;
}