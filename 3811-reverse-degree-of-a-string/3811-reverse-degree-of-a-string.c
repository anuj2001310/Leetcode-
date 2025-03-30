int reverseDegree(char* s) {
    int sum = 0;
    
    for (int i = 0; *s; s++)
        sum += ((26 - *s + 'a') * (++i));
    
    /*
    for (int i = 0; s[i]; i++) 
        sum += ((26 - s[i] + 'a') * (i + 1));
    */
    return sum;
}