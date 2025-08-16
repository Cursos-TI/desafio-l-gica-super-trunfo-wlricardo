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
 * FUNÇÕES PARA FORMATAÇÃO DE EXIBIÇÕES NA TELA
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
        system("cls");
    #else
        system("clear");
    #endif
}

// Função fim()
/* Exibe uma mensagem de fim de programa */
void fim() 
{
    printf("\n\n.......FIM DO PROGRAMA.......\n\n");
}

/**
 * 
 * FUNÇÕES AUXILIARES
 * 
 */

// Calcular densidade populacional
float calcular_densidade_populacional(float populacao, float area) 
{
    if (area == 0) 
    {
        return 0.0;           // Evita divisão por zero
    }
    return populacao / area;
}

// Calcular PIB per capita
float calcular_pib_per_capita(float pib, float populacao) 
{
    if (populacao == 0) 
    {
        return 0.0;           // Evita divisão por zero
    }
    return (pib * 1000000000.0f) / populacao;      // PIB em bilhões
}

// Struct para armazenar as propriedades de uma carta
typedef struct {
    char estado[MAX];
    char codigo[MAX];
    char cidade[MAX];
    unsigned long int populacao;
    float area;                     // Área em km²
    float pib;                      // PIB em bilhões
    float densidade_populacional;   // Densidade populacional (hab/km²)
    float pib_per_capita;           // PIB per capita (R$)
    int qtd_pontos_turisticos;
} Carta;

// Função para cadastrar uma carta
void cadastrar_carta(Carta *carta) 
{
    /* Estado */
    printf("\nEstado......................: ");    
    fgets(carta->estado, MAX, stdin);
    carta->estado[strcspn(carta->estado, "\n")] = '\0';       // Remove o \n do final

    /* Código */
    printf("Código......................: ");
    fgets(carta->codigo, MAX, stdin);
    carta->codigo[strcspn(carta->codigo, "\n")] = '\0';

    /* Cidade */
    printf("Cidade......................: ");    
    fgets(carta->cidade, MAX, stdin);
    carta->cidade[strcspn(carta->cidade, "\n")] = '\0';

    /* População */
    printf("População...................: ");
    scanf("%lu", &carta->populacao); limpar_buffer();

    /* Área (em km²)*/
    printf("Área (em km²)...............: ");
    scanf("%f", &carta->area); limpar_buffer();

    /* PIB (em bilhões)*/    
    printf("PIB (em bilhões)............: ");
    scanf("%f", &carta->pib); limpar_buffer();

    printf("Qtd de pontos turísticos....: ");
    scanf("%d", &carta->qtd_pontos_turisticos); limpar_buffer();

    carta->densidade_populacional = calcular_densidade_populacional(carta->populacao, carta->area);
    carta->pib_per_capita = calcular_pib_per_capita(carta->pib, carta->populacao);
    printf("Densidade populacional......: %.2f hab/km²\n", carta->densidade_populacional);
    printf("PIB per capita..............: %.2f\n", carta->pib_per_capita);
}

// Função para exibir os dados de uma carta
void exibir_carta(Carta carta)
{
    printf("- Estado..................: %s\n", carta.estado);
    printf("- Código da carta.........: %s\n", carta.codigo);
    printf("- Cidade..................: %s\n", carta.cidade);
    printf("- População...............: %lu\n", carta.populacao);
    printf("- Área....................: %.2f km²\n", carta.area);
    printf("- PIB.....................: R$ %.2f bilhões\n", carta.pib);
    printf("- Pontos turísticos.......: %d\n", carta.qtd_pontos_turisticos);
    printf("- Densidade populacional..: %.2f hab/km²\n", carta.densidade_populacional);
    printf("- PIB per capita..........: R$ %.2f\n", carta.pib_per_capita);
}

// Função para comparar duas cartas por um de seus atributos
void comparar_cartas(Carta carta1, Carta carta2)
{
    char atributo[30];
    int opcao, carta_vencedora = 0;
    unsigned long int valor;
    
    printf("\nEscolha o atributo a ser comparado: ");
    printf("\n1. População");   
    printf("\n2. Área");
    printf("\n3. PIB");
    printf("\n4. Quantidade de pontos turísticos");
    printf("\n5. Densidade populacional");
    printf("\n\n>  ");
    scanf("%d", &opcao); limpar_buffer();

    /* O nome dos dois países.
       O atributo usado na comparação.
       Os valores do atributo para cada carta.
       Qual carta venceu.
       Em caso de empate, exibir a mensagem "Empate!".*/

    switch (opcao) {
        case 1: // Comparar população
            atributo[30] = "População";
            carta_vencedora = carta1.populacao > carta2.populacao ? 1 : (carta1.populacao == carta2.populacao ? 0 : 2);
            if (carta1.populacao > carta2.populacao) {
                carta_vencedora = 1;
                valor = carta1.populacao;
            } else if (carta1.populacao < carta2.populacao) {
                carta_vencedora = 2;
                valor = carta2.populacao;
            } else {
                valor = 0;  // Empate
            }
            break;
        case 2: // Comparar área
            atributo[30] = "Área";
            if (carta1.area > carta2.area) {
                carta_vencedora = 1;
                valor = carta1.area;
            } else if (carta1.area < carta2.area) {
                carta_vencedora = 2;
                valor = carta2.area;
            } else {
                valor = 0;  // Empate   
            } 
            break;
        case 3: // Comparar PIB
            atributo[30] = "PIB";
            if (carta1.pib > carta2.pib) {
                carta_vencedora = 1;
                valor = carta1.pib;                
            } else if (carta1.pib < carta2.pib) {
                carta_vencedora = 2;
                valor = carta2.pib;
            } else {
                valor = 0;  // Empate
            }
            break;
        case 4: // Comparar quantidade de pontos turísticos
            if (carta1.qtd_pontos_turisticos > carta2.qtd_pontos_turisticos) {
                carta_vencedora = 1;
                valor = carta1.qtd_pontos_turisticos;
            } else if (carta1.qtd_pontos_turisticos < carta2.qtd_pontos_turisticos) {
                carta_vencedora = 2;
                valor = carta2.qtd_pontos_turisticos;
            } else {
                valor = 0;  // Empate
            }
            break;                
        case 5: // Comparar densidade populacional
            if (carta1.densidade_populacional > carta2.densidade_populacional) {
                carta_vencedora = 1;
                valor = carta1.densidade_populacional;
            } else if (carta1.densidade_populacional < carta2.densidade_populacional) {
                carta_vencedora = 2;
                valor = carta2.densidade_populacional;
            } else {
                valor = 0;  // Empate
            }
            break;
        default:
            printf("\n\tAtributo inválido!\n");
    }    

    printf("\nResultado da comparação:\n");
    printf("Cidade 1 : %-30s ::: Cidade 2 : %-30s\n", carta1.cidade, carta2.cidade);
    printf("Atributo escolhido: %-30s\n", atributo);
    if (valor == 0) {
        printf("Empate!\n");
        return 0; // Indica empate
    } else {
        printf("Carta vendedora: %d\n", carta_vencedora);
    }
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
    unsigned long int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int qtd_pontos_turisticos1, qtd_pontos_turisticos2;
    float densidade1, densidade2;
    float calcular_pib_per_capita1, calcular_pib_per_capita2;
    
    
    // Cadastro das variáveis da Carta 1
    printf("+++ CARTA 1 +++\n");
    Carta carta1;
    cadastrar_carta(&carta1);
        
    printf("\n\t ++ Dados cadastrados com sucesso ++\n");
    esperar_dois_milissegundos();
    limpar_tela();

    // Cadastro das variáveis da Carta 2
    printf("+++ CARTA 2 +++\n");
    Carta carta2;   
    cadastrar_carta(&carta2);

    printf("\n\t ++ Dados cadastrados com sucesso ++\n");
    esperar_dois_milissegundos();
    limpar_tela();

    // Exibindo os dados lidos 
    printf(" --- Dados da Carta 1 ---\n");
    exibir_carta(carta1);

    printf("\n --- Dados da Carta 2 ---\n");
    exibir_carta(carta2);

    fim();

    return 0;
}