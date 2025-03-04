#include <stdio.h>
#include <string.h>

void main(){

    char str[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua...\n";
    char str2[strlen(str)+1];

    int j = 0;
    for(int i = strlen(str)-1; i>=0; i--){
        if(str[i] != ' ') {
            str2[j++] = str[i];
        }
        else{
            str2[j++] = ' ';
        }
    }
    str2[j] = '\0';

    printf("Оригинальная: %s\n", str);
    printf("В обратном порядке:%s", str2);
}
