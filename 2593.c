#include <stdio.h>
#include <string.h>

#define MAX_TEXTO_LEN 10001
#define MAX_PALAVRAS 128
#define MAX_PALAVRA_LEN 51

// Função para encontrar as posições das palavras de busca no texto
void encontrar_posicoes(char texto[], char palavras_busca[][MAX_PALAVRA_LEN], int qtd_palavras) {
    // Dividir o texto em palavras
    char *token = strtok(texto, " ");
    int posicao = 0;
    int encontrou_palavra = 0;

    while (token != NULL) {
        // Para cada palavra de busca
        for (int i = 0; i < qtd_palavras; i++) {
            // Verificar se a palavra está no texto
            if (strcmp(token, palavras_busca[i]) == 0) {
                if (encontrou_palavra) {
                    printf(" ");
                }
                printf("%d", posicao);
                encontrou_palavra = 1;
            }
        }
        // Procurar pela próxima palavra no texto
        token = strtok(NULL, " ");
        if (!encontrou_palavra) {
            printf("-1");
        }
        if (token != NULL) {
            posicao += strlen(token) + 1;
        }
        encontrou_palavra = 0;
    }
    printf("\n");
}

int main() {
    char texto[MAX_TEXTO_LEN];
    int qtd_palavras;
    char palavras_busca[MAX_PALAVRAS][MAX_PALAVRA_LEN];

    // Receber o texto
    fgets(texto, MAX_TEXTO_LEN, stdin);
    texto[strcspn(texto, "\n")] = '\0'; // Remover o caractere de nova linha

    // Receber a quantidade de palavras de busca
    scanf("%d", &qtd_palavras);

    // Receber as palavras de busca
    for (int i = 0; i < qtd_palavras; i++) {
        scanf("%s", palavras_busca[i]);
    }

    // Encontrar as posições das palavras de busca no texto e imprimir
    encontrar_posicoes(texto, palavras_busca, qtd_palavras);

    return 0;
}
