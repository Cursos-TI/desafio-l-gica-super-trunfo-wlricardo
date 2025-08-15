#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.


#define MAX 100     // Tamanho máximo para strings

/**
 * 
 * FUNÇÕES AUXILIARES
 * 
 */

// Temporizador de 2.000 milissegundos (2 segundos)
#ifdef _WIN32
    #include <windows.h>  // Para usar a função Sleep() no Windows
    void esperar_dois_milissegundos()
    {
        Sleep(2000);
    }
#else
    #include <unistd.h>   // Para usar a função sleep() no Linux/MacOS
    void esperar_dois_milissegundos()
    {
        sleep(2);
    }
#endif

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
        #include <windows.h>        // Para usar a função Sleep() no Windows
        system("cls");
    #else
        #include <unistd.h>         // Para usar a função sleep() no Linux/MacOS
        system("clear");
    #endif
}

/**
 * 
 * FUNÇÕES PARA FORMATAÇÃO DE EXIBIÇÕES NA TELA
 * 
 */

// Função fim()
/* Exibe uma mensagem de fim de programa */
void fim() 
{
    printf("\n\n.......FIM DO PROGRAMA.......\n\n");
}

/**
 * 
 * PROGRAMA PRINCIPAL
 * 
 */

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
    printf("\nEstado......................: ");    
    fgets(estado1, MAX, stdin);
    estado1[strcspn(estado1, "\n")] = '\0';       // Remove o \n do final

    /* Código */
    printf("Código......................: ");
    fgets(codigo_carta1, MAX, stdin);
    codigo_carta1[strcspn(codigo_carta1, "\n")] = '\0';

    /* Cidade */
    printf("Cidade......................: ");    
    fgets(cidade1, MAX, stdin);
    cidade1[strcspn(cidade1, "\n")] = '\0';

    /* População */
    printf("População...................: ");
    scanf("%d", &populacao1);

    /* Área (em km²)*/
    printf("Área (em km²)...............: ");
    scanf("%f", &area1);

    /* PIB (em bilhões)*/    
    printf("PIB (em bilhões)............: ");
    scanf("%f", &pib1);

    printf("Qtd de pontos turísticos....: ");
    scanf("%d", &qtd_pontos_turisticos1);

    printf("\n\t ++ Dados cadastrados com sucesso ++\n");
    esperar_dois_milissegundos();
    limpar_tela();

    limpar_buffer();                              // Limpa o buffer para evitar problemas com fgets após scanf

    // Cadastro das variáveis da Carta 2
    printf("+++ CARTA 2 +++\n");

    /* Estado */
    printf("\nEstado......................: ");    
    fgets(estado2, MAX, stdin);
    estado2[strcspn(estado2, "\n")] = '\0';       // Remove o \n do final

    /* Código */
    printf("Código......................: ");
    fgets(codigo_carta2, MAX, stdin);
    codigo_carta2[strcspn(codigo_carta2, "\n")] = '\0';

    /* Cidade */
    printf("Cidade......................: ");    
    fgets(cidade2, MAX, stdin);
    cidade2[strcspn(cidade2, "\n")] = '\0';

    /* População */
    printf("População...................: ");
    scanf("%d", &populacao2);

    /* Área (em km²)*/
    printf("Área (em km²)...............: ");
    scanf("%f", &area2);

    /* PIB (em bilhões)*/    
    printf("PIB (em bilhões)............: ");
    scanf("%f", &pib2);

    printf("Qtd de pontos turísticos....: ");
    scanf("%d", &qtd_pontos_turisticos2);

    printf("\n\t ++ Dados cadastrados com sucesso ++\n");
    esperar_dois_milissegundos();
    limpar_tela();

    // Exibindo os dados lidos (opcional, para verificar)
    printf(" -- Dados da Carta 1 --\n");
    printf("-Estado...............: %s\n", estado1);
    printf("-Código da carta......: %s\n", codigo_carta1);
    printf("-Cidade...............: %s\n", cidade1);
    printf("-População............: %d\n", populacao1);
    printf("-Área.................: %.2f km²\n", area1);    
    printf("-PIB..................: %.2f\n", pib1);
    printf("-Pontos turísticos....: %d\n", qtd_pontos_turisticos1);

    printf("\n -- Dados da Carta 2 --\n");
    printf("-Estado...............: %s\n", estado2);
    printf("-Código da carta......: %s\n", codigo_carta2);          
    printf("-Cidade...............: %s\n", cidade2);
    printf("-População............: %d\n", populacao2);
    printf("-Área.................: %.2f km²\n", area2);    
    printf("-PIB..................: %.2f\n", pib2);
    printf("-Pontos turísticos....: %d\n", qtd_pontos_turisticos2);

    fim();

    return 0;
}