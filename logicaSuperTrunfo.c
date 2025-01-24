#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// criação de uma struct que representa a carta de trunfo.
// torna o código a frente mais legível.
struct carta
{
    char estado;
    char codigo[4];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int numPontosTuristicos;
    float pibPerCapta;
    float densidadePop;
};
typedef struct carta Carta; // torna possível se referir ao struct somente como "Carta"

// calcula pib per capta e densidade populacional de uma carta
// e salva os valores na própria carta
int calculaValoresCarta(Carta *carta)
{
    carta->pibPerCapta = carta->pib * 1000000000 / carta->populacao;
    carta->densidadePop = carta->populacao / carta->area;
}

// cadastra uma nova carta com input do usuário
Carta cadastrarCarta()
{
    Carta carta;

    printf("--- Cadastro de carta ---\n\n");

    printf("Digite o Estado: ");
    scanf(" %c", &carta.estado);

    printf("Digite o código da carta: ");
    scanf(" %s", carta.codigo); // arrays não precisam de um pointer. mesma coisa que dizer &codigoCarta[0]

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta.nome); // permite entrar nomes com espaços em branco

    printf("Digite a população: ");
    scanf(" %d", &carta.populacao);

    printf("Digite a área: ");
    scanf(" %f", &carta.area);

    printf("Digite o PIB: ");
    scanf(" %f", &carta.pib);

    printf("Digite o número de pontos turísticos: ");
    scanf(" %d", &carta.numPontosTuristicos);

    calculaValoresCarta(&carta);

    printf("\n--- Cadastro concluído ---\n");
    return carta;
}

// cria e retorna uma nova carta aleatória com auxilio do rand()
Carta gerarCartaAleatoria()
{
    Carta carta;
    carta.estado = (rand() % 8) + 65; // char entre A e H
    carta.codigo[0] = carta.estado;
    carta.codigo[1] = '0';
    carta.codigo[2] = (char) ((rand() % 4) + 49); // número de 1 até 4
    strcpy(carta.nome, "Cidade Aleatória");
    carta.populacao = rand() % 12000001;      // a cidade mais populosa do pais tem 11450000 pessoas
    carta.area = rand() % 154000;             // a maior cidade do pais tem 159533 km2.
    carta.pib = rand() % 829;                 // o maior pib de um municipio do pais é 828,9 bilhões de reais
    carta.numPontosTuristicos = rand() % 100; // esse eu inventei mesmo
    calculaValoresCarta(&carta);
    return carta;
}

// printa os valores de uma carta
// função não usada nesse desafio
void printCarta(Carta *carta)
{
    printf("Estado: %c\n", carta->estado);
    printf("Código da carta: %s\n", carta->codigo);
    printf("Nome da Cidade: %s\n", carta->nome);
    printf("População: %d\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("Densidade Populacional: %.2f pessoas/km²\n", carta->densidadePop);
    printf("PIB: %.2f bilhões de reais\n", carta->pib);
    printf("PIB per Capita: %d reais\n", (int)carta->pibPerCapta); // o desafio quer um numero sem casas decimais na resposta
    printf("Número de Pontos Turísticos: %d\n", carta->numPontosTuristicos);
}

int main(int argc, char const *argv[])
{
    srand(time(0)); // muda a seed do gerador de números aleatórios

    Carta carta1 = cadastrarCarta();
    Carta carta2 = gerarCartaAleatoria();

    int opcao;
    printf("Escolha uma característica para comparar:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de pontos turísticos\n");
    printf("5. Densidade populacional\n");
    printf("6. PIB per capta\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        if (carta1.populacao == carta2.populacao)
        {
            printf("Empate!\n");
        }
        else if (carta1.populacao > carta2.populacao)
        {
            printf("%s venceu!\n", carta1.nome);
        }
        else
        {
            printf("%s venceu!\n", carta2.nome);
        }
        printf("População %s: %d\n", carta1.nome, carta1.populacao);
        printf("População %s: %d\n", carta2.nome, carta2.populacao);
        break;
    case 2:
        if (carta1.area == carta2.area)
        {
            printf("Empate!\n");
        }
        else if (carta1.area > carta2.area)
        {
            printf("%s venceu!\n", carta1.nome);
        }
        else
        {
            printf("%s venceu!\n", carta2.nome);
        }
        printf("Área %s: %.2f\n", carta1.nome, carta1.area);
        printf("Área %s: %.2f\n", carta2.nome, carta2.area);
        break;
    case 3:
        if (carta1.pib == carta2.pib)
        {
            printf("Empate!\n");
        }
        else if (carta1.pib > carta2.pib)
        {
            printf("%s venceu!\n", carta1.nome);
        }
        else
        {
            printf("%s venceu!\n", carta2.nome);
        }
        printf("PIB %s: %.2f\n", carta1.nome, carta1.pib);
        printf("PIB %s: %.2f\n", carta2.nome, carta2.pib);
        break;
    case 4:
        if (carta1.numPontosTuristicos == carta2.numPontosTuristicos)
        {
            printf("Empate!\n");
        }
        else if (carta1.numPontosTuristicos > carta2.numPontosTuristicos)
        {
            printf("%s venceu!\n", carta1.nome);
        }
        else
        {
            printf("%s venceu!\n", carta2.nome);
        }
        printf("Número de pontos turísticos %s: %d\n", carta1.nome, carta1.numPontosTuristicos);
        printf("Número de pontos turísticos %s: %d\n", carta2.nome, carta2.numPontosTuristicos);
        break;
    case 5:
        if (carta1.densidadePop == carta2.densidadePop)
        {
            printf("Empate!\n");
        }
        else if (carta1.densidadePop < carta2.densidadePop) // MENOR densidade vence!
        {
            printf("%s venceu!\n", carta1.nome);
        }
        else
        {
            printf("%s venceu!\n", carta2.nome);
        }
        printf("Densidade populacional %s: %.2f\n", carta1.nome, carta1.densidadePop);
        printf("Densidade populacional %s: %.2f\n", carta2.nome, carta2.densidadePop);
        break;
    case 6:
        if (carta1.pibPerCapta == carta2.pibPerCapta)
        {
            printf("Empate!\n");
        }
        else if (carta1.pibPerCapta > carta2.pibPerCapta)
        {
            printf("%s venceu!\n", carta1.nome);
        }
        else
        {
            printf("%s venceu!\n", carta2.nome);
        }
        printf("PIB per capta %s: %d\n", carta1.nome, (int)carta1.pibPerCapta);
        printf("PIB per capta %s: %d\n", carta2.nome, (int)carta2.pibPerCapta);
        break;
        break;
    default:
        printf("Opção inválida\n");
    }

    /*
    printCarta(&carta1);
    printf("\n");
    printCarta(&carta2);
    */

    return 0;
}