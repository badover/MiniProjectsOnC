#include <stdio.h>

int main(){
    char source[] = "sup world";
    char dest[50];

    const char *src = source;
    char *dst = dest;
    int len = sizeof(dest);

    while(*src != '\0' && len --> 1){
        *dst++ = *src++;
    }
    *dst = '\0';

    puts(source);
    puts(dest);
}