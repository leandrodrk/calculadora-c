#include <stdio.h>

#define OK 0
#define ERRO_DIVISAO_ZERO 1
#define ERRO_OPERACAO_INVALIDA 2

/* Cálculo puro: não lê nem imprime nada. */
double calcular(double a, double b, char operacao, int *erro)
{
    *erro = OK;
    switch (operacao) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                *erro = ERRO_DIVISAO_ZERO;
                return 0;
            }
            return a / b;
        default:
            *erro = ERRO_OPERACAO_INVALIDA;
            return 0;
    }
}

/* Entrada: devolve 1 se leu um número válido, 0 se não. */
int ler_numero(const char *mensagem, double *valor)
{
    printf("%s", mensagem);
    return scanf("%lf", valor) == 1;
}

int ler_operacao(const char *mensagem, char *operacao)
{
    printf("%s", mensagem);
    return scanf(" %c", operacao) == 1;
}

/* Saída */
void mostrar_resultado(double resultado, int erro)
{
    if (erro == ERRO_DIVISAO_ZERO)
        printf("Erro: divisao por zero.\n");
    else if (erro == ERRO_OPERACAO_INVALIDA)
        printf("Erro: operacao invalida.\n");
    else
        printf("Resultado: %.2f\n", resultado);
}

int main(void)
{
    double n1, n2;
    char operacao;
    int erro;

    if (!ler_numero("Primeiro numero: ", &n1) ||
        !ler_numero("Segundo numero: ", &n2) ||
        !ler_operacao("Operacao (+ - * /): ", &operacao)) {
        printf("Entrada invalida.\n");
        return 1;
    }

    double resultado = calcular(n1, n2, operacao, &erro);
    mostrar_resultado(resultado, erro);
    return 0;
}
