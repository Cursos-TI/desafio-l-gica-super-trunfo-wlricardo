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
    DENSIDADE_POPULACIONAL,
    QTD_ATRIBUTOS                               // Quantidade total de atributos úteis disponíveis + 1
} Atributo;

// Função menu()
/* Exibe um menu com as opções a serem seleciondas pelos usuários */
int menu(int contador, int opcoes_usadas[])  
{    
    int opcao;                                  // Opção escolhida pelo usuário 
    int opcao_valida;                           // Flag para verificar se a opção é válida  
    int opcoes_validas[QTD_ATRIBUTOS-1];       // Opções válidas do tamanho do enum Atributo
    char* nomes_atributos[] = {                 // Nomes dos atributos para exibição
        "População",
        "Área",
        "PIB",
        "Quantidade de pontos turísticos",
        "Densidade populacional"
    };

    for (size_t i = 0; i < QTD_ATRIBUTOS-1; i++)
    {   
        opcoes_validas[i] = i + 1;              // Preenche o array com as opções válidas segundo o tamanho do enum Atributo (1 a 5)
    }    

    do
    {
<<<<<<< HEAD
        printf("\nEscolha o %do atributo a ser comparado: \n", contador + 1);
=======
        printf("\nEscolha o %do atributo a ser comparado: ", contador + 1);
        printf("\n1. População");
        printf("\n2. Área");
        printf("\n3. PIB");
        printf("\n4. Quantidade de pontos turísticos");
        printf("\n5. Densidade populacional");
        printf("\n\n>  ");
        scanf("%d", &opcao); limpar_buffer();  
>>>>>>> cdc45d0 (Comparação entre duas cartas e exibição dos resultados)

        int opcoes_disponiveis = 0;             // Contador de opções disponíveis
        for (int i = 0; i < QTD_ATRIBUTOS-1; i++) {
            if (!opcoes_usadas[i]) {            // Se a opção ainda não foi usada
                printf("[%d] %s\n", opcoes_validas[i], nomes_atributos[i]);
                opcoes_disponiveis++;
            }
        }

        if (opcoes_disponiveis == 0) {
            printf("\nNenhuma opção disponível!\n");
            return -1;                          // Erro: não deveria acontecer com QTD_ATRIBUTOS <= 5
        }

        printf("\n>  ");
        if (scanf("%d", &opcao) != 1) {
            limpar_buffer();
            printf("\n\t ++ Entrada inválida! Tente novamente. ++\n");
            esperar_dois_milissegundos();
            limpar_tela();
            continue;
        }
        limpar_buffer();

        // Verifica se a opção é válida e se está disponível
        opcao_valida = 0;
        for (int i = 0; i < 5; i++) {
            if (opcao == opcoes_validas[i] && !opcoes_usadas[i]) {
                opcao_valida = 1;
                break;
            }
        }

        if (!opcao_valida) {
            printf("\n\t ++ Opção inválida ou já escolhida! Tente novamente. ++\n");
            esperar_dois_milissegundos();
            limpar_tela();
        }

        // Marca a opção como usada
        for (int i = 0; i < 5; i++) {
            if (opcao == opcoes_validas[i]) {
                opcoes_usadas[i] = 1;
                break;
            }
        }
        limpar_tela();
    } while (!opcao_valida);    
    return opcao;
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

// Função para exibir a saída formatada das cartas
void exibir_saida_formatada(Carta carta1, Carta carta2, Atributo atributo)
{
    printf("-----------------------------------------------------       -----------------------------------------------------\n");
    printf("Cidade 1 - %-44s     Cidade 2 - %-44s\n", carta1.cidade, carta2.cidade);

    switch (atributo)
    {
        case POPULACAO:
<<<<<<< HEAD
            printf("População - %-38lu    População - %-38lu\n", carta1.populacao, carta2.populacao);       
        break;
        case AREA:
            printf("Área - %-43.2f    Área - %-43.2f\n", carta1.area, carta2.area);   
        break;
        case PIB:
            printf("PIB - %-44.2f    PIB - %-44.2f\n", carta1.pib, carta2.pib);
        break;
        case PONTOS_TURISTICOS:
            printf("Quantidade de pontos turísticos - %-16d    Quantidade de pontos turísticos - %-16d\n", carta1.qtd_pontos_turisticos, carta2.qtd_pontos_turisticos);
        break;
        case DENSIDADE_POPULACIONAL:
        printf("Densidade populacional - %-25.2f    Densidade populacional - %-25.2f\n", carta1.densidade_populacional, carta2.densidade_populacional);               
    }   
=======
        printf("População - %-44lu    População - %-44lu\n", carta1.populacao, carta2.populacao);       
        break;
    case AREA:
        printf("Área - %-49.2f    Área - %-49.2f\n", carta1.area, carta2.area);   
        break;
    case PIB:
        printf("PIB - %-50.2f    PIB - %-50.2f\n", carta1.pib, carta2.pib);
        break;
    case PONTOS_TURISTICOS:
        printf("Quantidade de pontos turísticos - %-22d    Quantidade de pontos turísticos - %-22d\n", carta1.qtd_pontos_turisticos, carta2.qtd_pontos_turisticos);
        break;
    case DENSIDADE_POPULACIONAL:
        printf("Densidade populacional - %-31.2f    Densidade populacional - %-31.2f\n", carta1.densidade_populacional, carta2.densidade_populacional);               
    }
>>>>>>> cdc45d0 (Comparação entre duas cartas e exibição dos resultados)
}

// Função para exibir a saída formatada da carta vencedora
/*void exibir_atributo_carta_vencedora(Carta carta, Atributo atributo)
{
    char atributo_str[40];
    switch (atributo) {
        case POPULACAO:
            strcpy(atributo_str, "População");
            break;
        case AREA:
            strcpy(atributo_str, "Área");
            break;
        case PIB:
            strcpy(atributo_str, "PIB");
            break;
        case PONTOS_TURISTICOS:
            strcpy(atributo_str, "Quantidade de pontos turísticos");
            break;
        case DENSIDADE_POPULACIONAL:
            strcpy(atributo_str, "Densidade populacional");
            break;
        default:
            printf("Atributo inválido!\n");
            return;
    }
}*/

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
    int opcoes_usadas[QTD_ATRIBUTOS-1] = {0};      // Array para marcar as opções já escolhidas (0 = não usado, 1 = usado)
    char atributo[2][40] = { "", "" };              // Array para armazenar os atributos escolhidos
    int opcao[2] = {0,0}, contador = 0;
    int atributos_escolhidos[2] = {0, 0};           // Para armazenar as opções já escolhidas
    double valor[2] = {0.0, 0.0};                   // Valores dos atributos escolhidos para comparação : valor[0] para carta1 e valor[1] para carta2
    double soma[2] = {0.0, 0.0};                    // Soma dos valores dos atributos escolhidos : soma[0] para carta1 e soma[1] para carta2
    Carta* vencedor_atributo[2] = {NULL, NULL};     // Array para armazenar o vencedor de cada atributo
    Carta* vencedor_partida = NULL;                 // Vencedor da partida (melhor de 2)
    
    while (contador < 2) {        
<<<<<<< HEAD
        opcao[contador] = menu(contador, opcoes_usadas);  // Chama a função para exibir menu dinâmico
=======
        opcao[contador] = menu(contador); 
>>>>>>> cdc45d0 (Comparação entre duas cartas e exibição dos resultados)

        // Verifica se a opção já foi escolhida anteriormente
        /*int ja_escolhida = 0;
        for (int i = 0; i < contador; i++) {
            if (opcao[contador] == atributos_escolhidos[i]) {
                ja_escolhida = 1;
                break;
            }
        }
        if (ja_escolhida) {
            printf("\n\t ++ A opção %d já foi escolhida! ++", opcao[contador]);
            printf("\n\t ++ Tente novamente...     ++\n");
            esperar_dois_milissegundos();
            limpar_tela();
            continue;
        }*/
        atributos_escolhidos[contador] = opcao[contador];

        switch (opcao[contador]) {
            case 1: // Comparar população
                strcpy(atributo[contador], "População");
                valor[0] = (unsigned long int)carta1.populacao; soma[0] += valor[0];
                valor[1] = (unsigned long int)carta2.populacao; soma[1] += valor[1];
                break;
            case 2: // Comparar área
                strcpy(atributo[contador], "Área");
                valor[0] = carta1.area; soma[0] += valor[0];
                valor[1] = carta2.area; soma[1] += valor[1];
                break;
            case 3: // Comparar PIB
                strcpy(atributo[contador], "PIB");
                valor[0] = carta1.pib; soma[0] += valor[0];
                valor[1] = carta2.pib; soma[1] += valor[1];
                break;
            case 4: // Comparar quantidade de pontos turísticos
                strcpy(atributo[contador], "Quantidade de pontos turísticos");
                valor[0] = carta1.qtd_pontos_turisticos; soma[0] += valor[0];
                valor[1] = carta2.qtd_pontos_turisticos; soma[1] += valor[1];
                break;
            case 5: // Comparar densidade populacional
                strcpy(atributo[contador], "Densidade populacional");
                valor[0] = carta1.densidade_populacional; soma[0] += valor[0];
                valor[1] = carta2.densidade_populacional; soma[1] += valor[1];
                break;
            default:
                printf("\n\t ++ Atributo inválido! ++\n");
        }
        vencedor_atributo[contador] = carta_vencedora(&carta1, &carta2, (Atributo)opcao[contador]);
        contador++;  
    }
    
<<<<<<< HEAD
    printf("\n========================================================================================================");
    printf("\n                                         RESULTADO DA RODADA                                            ");
    printf("\n========================================================================================================\n\n");
=======
    printf("\n=================================================================================================================");
    printf("\n                                               RESULTADO DA RODADA                                               ");
    printf("\n=================================================================================================================\n\n");
>>>>>>> cdc45d0 (Comparação entre duas cartas e exibição dos resultados)

    for (size_t i = 0; i < 2; i++)
    {
        printf("Atributo escolhido #%zu: %-30s\n\n", i+1, atributo[i]);
        printf("CARTA 1:                                                    CARTA 2:                                          \n");
        
<<<<<<< HEAD
        exibir_saida_formatada(carta1, carta2, (Atributo)opcao[i]);    
        printf("\n>> Resultado : ");
=======
        exibir_saida_formatada(carta1, carta2, opcao[i]);
    
        printf("Resultado : ");
>>>>>>> cdc45d0 (Comparação entre duas cartas e exibição dos resultados)
        if (vencedor_atributo[i] != NULL) {
            valor[i] = obter_valor_atributo(*vencedor_atributo[i], (Atributo)opcao[i]);
            if(vencedor_atributo[i] == &carta1) {
                printf("A Carta 1 venceu com %s = %.2f\n\n\n", atributo[i], valor[i]);
            } else {
                printf("A Carta 2 venceu com %s = %.2f\n\n\n", atributo[i], valor[i]);
            }
        } else {    
            printf("Houve empate!\n\n\n");
        }
<<<<<<< HEAD
        printf("\n");
=======
        printf("\n\n");
>>>>>>> cdc45d0 (Comparação entre duas cartas e exibição dos resultados)
    }
    
    if (soma[0] > soma[1]) {
        vencedor_partida = &carta1;
    } else if (soma[1] > soma[0]) {
        vencedor_partida = &carta2;
    } else {
        vencedor_partida = NULL; // Empate
    }
    
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("SOMA DOS ATRIBUTOS : %-29.2f    SOMA DOS ATRIBUTOS : %-29.2f\n", soma[0], soma[1]);
    printf("\n\n");
    if (vencedor_partida != NULL) {
        if (vencedor_partida == &carta1) {
            printf("\n                                         RESULTADO DA RODADA                                         \n");
            printf("                                      A Carta 1 venceu a partida !                                 \n\n\n");
        } 
        if (vencedor_partida == &carta2) {
            printf("                                      A Carta 2 venceu a partida !                                 \n\n\n");
        }
    } else {
        printf("                                             HOUVE EMPATE !                                            \n\n\n");
    }
    printf("========================================================================================================\n");
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
