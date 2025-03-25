#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "ru_RU.UTF-8");

    if (argc != 2){
        fprintf(stderr, "Use: %d <file.txt>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file;
    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    wchar_t words[256];
    int n = 0;
    int line_number = 0;

    while (fgetws(words, sizeof(words)/sizeof(wchar_t), file)) {
        line_number++;
        wprintf(L"%d.  %ls", line_number, words);

        int len = wcslen(words);
        if (len > 0 && words[len - 1] == L'\n') {
            words[len - 1] = L'\0';
            len--;
        }

        if (len > 0 && (words[0] == L'Я' || words[0] == L'я') && (words[len - 1] == L'Я' || words[len - 1] == L'я')) {
            n++;
        }
    }
    wprintf(L"\nКол-во строк: %d\n", n);

    fclose(file);
    return 0;    
}
