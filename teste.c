#include <stdio.h>
#include <string.h>

#define MAX_TEXT_SIZE 10001
#define MAX_WORD_SIZE 51
#define MAX_WORDS 128

void searchWords(char text[], char words[][MAX_WORD_SIZE], int wordCount) {
    int textLen = strlen(text);

    for (int i = 0; i < wordCount; i++) {
        char *ptr = text;
        int found = 0;
        int isFirst = 1;

        while ((ptr = strstr(ptr, words[i])) != NULL) {
            if (isFirst) {
                printf("%d", (int)(ptr - text));
                isFirst = 0;
                found = 1;
            } else {
                printf(" %d", (int)(ptr - text));
            }
            ptr += strlen(words[i]);
        }

        if (!found) {
            printf("-1");
        }
        printf("\n");
    }
}

int main() {
    char text[MAX_TEXT_SIZE];
    char words[MAX_WORDS][MAX_WORD_SIZE];
    int wordCount;

    // Leitura do texto
    fgets(text, MAX_TEXT_SIZE, stdin);
    text[strcspn(text, "\n")] = '\0'; // Remover o caractere de nova linha

    // Leitura da quantidade de palavras
    scanf("%d", &wordCount);

    // Leitura das palavras
    for (int i = 0; i < wordCount; i++) {
        scanf("%s", words[i]);
    }

    // Busca das palavras no texto e impressão das posições
    searchWords(text, words, wordCount);

    return 0;
}
