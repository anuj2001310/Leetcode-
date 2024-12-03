typedef struct {
    int size;
    char* arr;
} string;

string* init(int cap) {
    string* ptr = (string*)malloc(sizeof(string) * cap);
    ptr->size = 0;
    ptr->arr = (char*)malloc(sizeof(char) * cap);
    return ptr;
}

void freeStr(string* ptr) {
    free(ptr->arr);
    free(ptr);
}

char* addSpaces(char* s, int* spaces, int spacesSize) {
    int n = strlen(s);
    string* str = init(n + spacesSize + 1);
    int i = 0, k = 0;
    while (i < n && k < spacesSize) {
        if (i == spaces[k]) {
            str->arr[str->size++] = ' ';
            k++;
        }
        
        str->arr[str->size++] = s[i];
        i++;
    }
    while (i < n)
        str->arr[str->size++] = s[i++];

    str->arr[str->size] = '\0';
    return str->arr;
    freeStr(str);
}