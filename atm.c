#include <stdio.h>
#include <time.h>

int main()
{
    /*Notas foi criado um vetor para qtd de notas por valores*/
    int valores[4] = {100, 50, 20, 10};
    int notas[4] = {0, 0, 0, 0};
    int usadas[4] = {0, 0, 0, 0};
    int opcao;
    int valorsaque;
    int saque;
    int dinheirodepositado = 0;

    /*O comando do-while em C é uma estrutura de repetição que
    executa um bloco de código pelo menos uma vez antes de testar
    a condição*/
    do
    {
        /*Menu*/
        printf("\n ------SIMULADOR DE SAQUE------\n");
        printf("\n 1 - Mostra quantidade de notas disponiveis\n");
        printf("\n 2 - Abastecer ATM\n");
        printf("\n 3 - Sacar dinheiro\n");
        printf("\n 0 - Sair\n");

        /*Solicita um opção do menu*/
        printf("\nDigite a opção desejada: ");
        scanf("%d", &opcao);

        /*switch contro-la as opções selecionadas*/
        switch (opcao)
        {
        case 1:
            printf("\nQuantidade de notas disponiveis de R$%d: %d\n", valores[3], notas[3]);
            printf("\nQuantidade de notas disponiveis de R$%d: %d\n", valores[2], notas[2]);
            printf("\nQuantidade de notas disponiveis de R$%d: %d\n", valores[1], notas[1]);
            printf("\nQuantidade de notas disponiveis de R$%d: %d\n", valores[0], notas[0]);
            break;
        case 2:
            printf("\n--- ABASTECER ATM ---\n");
            printf("\nDigite a quantidade de notas de R$10: ");
            scanf("%d", &dinheirodepositado);
            if (dinheirodepositado < 0)
            {
                printf("\nQuantidade inválida. Não é possível depositar notas negativas.\n");
                break;
            }
            notas[3] = notas[3] + dinheirodepositado;

            /*Solicita a quantidade de notas de R$20*/
            printf("\nDigite a quantidade de notas de R$20: ");
            scanf("%d", &dinheirodepositado);
            if (dinheirodepositado < 0)
            {
                printf("\nQuantidade inválida. Não é possível depositar notas negativas.\n");
                break;
            }
            notas[2] = notas[2] + dinheirodepositado;

            /*Solicita a quantidade de notas de R$50*/
            printf("\nDigite a quantidade de notas de R$50: ");
            scanf("%d", &dinheirodepositado);
            if (dinheirodepositado < 0)
            {
                printf("\nQuantidade inválida. Não é possível depositar notas negativas.\n");
                break;
            }
            notas[1] = notas[1] + dinheirodepositado;

            /*Solicita a quantidade de notas de R$100*/
            printf("\nDigite a quantidade de notas de R$100: ");
            scanf("%d", &dinheirodepositado);
            if (dinheirodepositado < 0)
            {
                printf("\nQuantidade inválida. Não é possível depositar notas negativas.\n");
                break;
            }
            notas[0] = notas[0] + dinheirodepositado;

            break;
        case 3:
            printf("\nDigite o valor do saque: ");
            scanf("%d", &valorsaque);
            saque = valorsaque;

            for (int i = 0; i < 4; i++)
            {
                usadas[i] = 0;
            }

            /*Inicio do laço for com indici de 0 á 3*/
            for (int i = 0; i < 4; i++)
            {
                int total = saque / valores[i];

                if (total <= notas[i])
                {
                    usadas[i] += total;
                    saque -= total * valores[i];
                }
                else
                {
                    usadas[i] += notas[i];
                    saque -= notas[i] * valores[i];
                }
            }
            /* Verifica se conseguiu realizar o saque */
            if (saque == 0)
            {
                printf("\nSaque realizado com sucesso!\n");
                printf("\nValor total: R$%d\n", valorsaque);

                printf("\nNotas utilizadas:\n");

                for (int i = 0; i < 4; i++)
                {
                    if (usadas[i] > 0)
                    {
                        printf("\nNotas de R$%d: %d\n", valores[i], usadas[i]);
                    }
                }
                for (int i = 0; i < 4; i++)
                {
                    /* Atualiza o caixa */
                    notas[i] -= usadas[i];
                }
            }
            else
            {
                printf("\nNão foi possível realizar o saque. Notas insuficientes.\n");
                int saldo = notas[0] * valores[0] + notas[1] * valores[1] + notas[2] * valores[2] + notas[3] * valores[3];
                printf("\nvalor em conta: R$%d\n", saldo);
            }
            break;
        case 0:
            printf("\nSair ");
            break;
        default:
            printf("\nOpção inválida!\n");
            break;
        }
    } while (opcao != 0);
    printf("\nObrigado por utilizar o simulador de saque!\n");
    return 0;
}