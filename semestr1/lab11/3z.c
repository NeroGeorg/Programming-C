#include <stdio.h>

#define SQR(x) (x) * (x) // ставим скобки тк макрос не учитывает порядок операций

int main() {
int y = 25;
int z = SQR(y + 1);
printf("z = %d\n", z);
return 0;
}