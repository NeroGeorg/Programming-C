#include <stdio.h>

typedef struct
{
char str[5]; // расширили массив до 5 тк как число 4 значное
int num;
} NumberRepr;

void format(NumberRepr* number)
{
sprintf(number->str, "%d", number->num);
}

int main()
{
NumberRepr number = { .num = 1025 };
format(&number);
printf("str: %s\n", number.str);
printf("num: %d\n", number.num);
return 0;
}