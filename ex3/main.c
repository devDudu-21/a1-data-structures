#include <stdio.h>

#define MONTHS 12
#define WEEKS 4

int main() {
    // Declaração de uma matriz para armazenar as vendas semanais de cada mês.
    float sales[MONTHS][WEEKS];
    // Vetores para armazenar o total de vendas por mês e por semana, respectivamente.
    float totalPerMonth[MONTHS] = {0};
    float totalPerWeek[WEEKS] = {0};
    // Variável para armazenar o total de vendas do ano.
    float totalYear = 0;

    // Solicita as vendas de cada semana para cada mês.
    printf("Digite as vendas semanais de cada mês:\n");
    for (int month = 0; month < MONTHS; month++) {
        // Informar o mês que está sendo processado.
        printf("Mês %d:\n", month + 1);
        for (int week = 0; week < WEEKS; week++) {
            // Solicita o valor de venda para a semana atual.
            printf("  Semana %d: ", week + 1);
            scanf("%f", &sales[month][week]);

            // Atualiza os totais por mês, por semana e o total anual.
            totalPerMonth[month] += sales[month][week];
            totalPerWeek[week] += sales[month][week];
            totalYear += sales[month][week];
        }
    }

    // Imprime o total de vendas por mês.
    printf("\nTotal de vendas por mês:\n");
    for (int month = 0; month < MONTHS; month++) {
        printf("Mês %2d: R$ %.2f\n", month + 1, totalPerMonth[month]);
    }

    // Imprime o total de vendas por semana ao longo do ano.
    printf("\nTotal de vendas por semana ao longo do ano:\n");
    for (int week = 0; week < WEEKS; week++) {
        printf("Semana %d: R$ %.2f\n", week + 1, totalPerWeek[week]);
    }

    // Exibe o total de vendas do ano.
    printf("\nTotal de vendas no ano: R$ %.2f\n", totalYear);

    return 0;
}
