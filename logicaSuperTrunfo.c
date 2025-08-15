#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.


#define MAX 100  // Tamanho máximo para strings

/**
 * 
 * FUNÇÕES AUXILIARES
 * 
 */

// Limpeza do buffer de entrada (útil após scanf antes de fgets)
int limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return 0;
}

// Limpar tela
void limpar_tela()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    char estado1[MAX], estado2[MAX];
    char codigo_carta1[MAX], codigo_carta2[MAX];
    char cidade1[MAX], cidade2[MAX];
    int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int qtd_pontos_turisticos1, qtd_pontos_turisticos2;
    
    
    // Cadastro das variáveis da Carta 1
    printf("+++ CARTA 1 +++\n");

    /* Estado */
    printf("\nEstado : ");
    fgets(estado1, MAX, stdin);
    estado1[strcspn(estado1, "\n")] = '\0';       // Remove o \n do final

    /* Código */
    printf("Código : ");
    fgets(codigo_carta1, MAX, stdin);
    codigo_carta1[strcspn(codigo_carta1, "\n")] = '\0';

    /* Cidade */
    printf("Cidade : ");
    fgets(cidade1, MAX, stdin);
    cidade1[strcspn(cidade1, "\n")] = '\0';

    /* População */
    printf("População : ");
    scanf("%d", &populacao1);

    /* Área (em km²)*/
    printf("Área (em km²) : ");
    scanf("%f", &area1);

    /* PIB (em bilhões)*/
    printf("PIB (em bilhões) : ");
    scanf("%f", &pib1);

    printf("Qtd de pontos turísticos: ");
    scanf("%d", &qtd_pontos_turisticos1);

    // Exibindo os dados lidos (opcional, para verificar)
    printf("\n--- Dados da Carta 1 ---\n");
    printf("Estado: %s\n", estado1);
    printf("Código da carta: %s\n", codigo_carta1);
    printf("Cidade: %s\n", cidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f\n", pib1);
    printf("Pontos turísticos: %d\n", qtd_pontos_turisticos1);

    return 0;
}