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

typedef enum {
    POPULACAO = 1,
    AREA,
    PIB,
    PONTOS_TURISTICOS,
    DENSIDADE_POPULACIONAL
} Atributo;

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

// Função para determinar qual carta é a vencedora
// Retorna 1 se carta1 vencer, 2 se carta2 vencer, 0 em caso de empate
Carta* carta_vencedora(Carta* carta1, Carta* carta2, Atributo atributo)
{
    int comparacao;
    switch (atributo) {
        case POPULACAO:
            comparacao = carta1->populacao > carta2->populacao ? 1 : (carta1->populacao == carta2->populacao ? 0 : 2);
            break;
        case AREA:
            comparacao = carta1->area > carta2->area ? 1 : (carta1->area == carta2->area ? 0 : 2);
            break;
        case PIB:
            comparacao = carta1->pib > carta2->pib ? 1 : (carta1->pib == carta2->pib ? 0 : 2);
            break;
        case PONTOS_TURISTICOS:
            comparacao = carta1->qtd_pontos_turisticos > carta2->qtd_pontos_turisticos ? 1 : (carta1->qtd_pontos_turisticos == carta2->qtd_pontos_turisticos ? 0 : 2);
            break;
        case DENSIDADE_POPULACIONAL:
            comparacao = carta1->densidade_populacional < carta2->densidade_populacional ? 1 : (carta1->densidade_populacional == carta2->densidade_populacional ? 0 : 2);
            break;
        default:
            printf("Atributo inválido!\n");
            comparacao = 0;         // Indica empate
    }

    if(comparacao == 1) {
        return carta1;              // Carta 1 vence
    } else if(comparacao == 2) {
        return carta2;              // Carta 2 vence
    } else {
        return NULL;                // Empate
    }   
}

// Função que retorna o valor do atributo escolhido na comparação
double obter_valor_atributo(Carta carta, Atributo atributo)
{
    switch (atributo) {
        case POPULACAO:
            return carta.populacao;
            break;
        case AREA:
            return carta.area;
            break;
        case PIB:
            return carta.pib;
            break;
        case PONTOS_TURISTICOS:
            return carta.qtd_pontos_turisticos;
            break;
        case DENSIDADE_POPULACIONAL:
            return carta.densidade_populacional;
            break;
        default:
            printf("Atributo inválido!\n");
            return 0; // Indica empate
    }
}

// Função para comparar duas cartas por um de seus atributos
void comparar_cartas(Carta carta1, Carta carta2)
{
    char atributo[40];
    int opcao;
    double valor;
    double valor1, valor2;
    Carta* vencedor;
    
    printf("\nEscolha o atributo a ser comparado: ");
    printf("\n1. População");   
    printf("\n2. Área");
    printf("\n3. PIB");
    printf("\n4. Quantidade de pontos turísticos");
    printf("\n5. Densidade populacional");
    printf("\n\n>  ");
    scanf("%d", &opcao); limpar_buffer();

    vencedor = carta_vencedora(&carta1, &carta2, opcao);

    switch (opcao) {
        case 1: // Comparar população
            strcpy(atributo, "População");
            valor1 = carta1.populacao;
            valor2 = carta2.populacao;
            break;
        case 2: // Comparar área
            strcpy(atributo, "Área");
            valor1 = carta1.area;
            valor2 = carta2.area;
            break;
        case 3: // Comparar PIB
            strcpy(atributo, "PIB");
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            break;
        case 4: // Comparar quantidade de pontos turísticos
            strcpy(atributo, "Quantidade de pontos turísticos");
            valor1 = carta1.qtd_pontos_turisticos;
            valor2 = carta2.qtd_pontos_turisticos;
            break;                
        case 5: // Comparar densidade populacional
            strcpy(atributo, "Densidade populacional");
            valor1 = carta1.densidade_populacional;
            valor2 = carta2.densidade_populacional;
            break;
        default:
            printf("\n\t ++ Atributo inválido! ++\n");
    }    

    printf("\nResultado da comparação:\n");
    printf("\nAtributo escolhido: %-30s\n", atributo);
    printf("Cidade 1 : %-30s\t:::\t Cidade 2 : %-30s\n", carta1.cidade, carta2.cidade);
    printf("%s da Carta 1  : %-30.2f\t:::\t %s da Carta 2  : %-30.2f\n", atributo, valor1, atributo, valor2);
    printf("\nResultado : ");

    if (vencedor != NULL) {
        valor = obter_valor_atributo(*vencedor, opcao);
        if(vencedor == &carta1) {
            printf("A Carta 1 venceu com %s = %.2f\n", atributo, valor);
        } else {
            printf("A Carta 2 venceu com %s = %.2f\n", atributo, valor);
        }
    } else {    
        printf("Houve empate!\n");
    }
}

/**
 * 
 * PROGRAMA PRINCIPAL
 * 
 */

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades    
    Carta carta1, carta2;
    
    // Cadastro das variáveis da Carta 1
    printf("+++ CARTA 1 +++\n");
    cadastrar_carta(&carta1);
        
    printf("\n\t ++ Dados cadastrados com sucesso ++\n");
    esperar_dois_milissegundos();
    limpar_tela();

    // Cadastro das variáveis da Carta 2
    printf("+++ CARTA 2 +++\n");
    cadastrar_carta(&carta2);

    printf("\n\t ++ Dados cadastrados com sucesso ++\n");
    esperar_dois_milissegundos();
    limpar_tela();

    // Exibindo os dados lidos 
    printf(" --- Dados da Carta 1 ---\n");
    exibir_carta(carta1);

    printf("\n --- Dados da Carta 2 ---\n");
    exibir_carta(carta2);

    printf("\n\t ++ Iniciando o jogo ++\n");
    esperar_dois_milissegundos();
    limpar_tela();

    comparar_cartas(carta1, carta2);

    fim();

    return 0;
}