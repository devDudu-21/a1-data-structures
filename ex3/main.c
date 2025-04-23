#include <stdio.h>

#define MONTHS 12
#define WEEKS 4

int main() {
    float sales[MONTHS][WEEKS];
    float totalPerMonth[MONTHS] = {0};
    float totalPerWeek[WEEKS] = {0};
    float totalYear = 0;

    printf("Digite as vendas semanais de cada mês:\n");
    for (int month = 0; month < MONTHS; month++) {
        printf("Mês %d:\n", month + 1);
        for (int week = 0; week < WEEKS; week++) {
            printf("  Semana %d: ", week + 1);
            scanf("%f", &sales[month][week]);

            totalPerMonth[month] += sales[month][week];
            totalPerWeek[week] += sales[month][week];
            totalYear += sales[month][week];
        }
    }

    printf("\nTotal de vendas por mês:\n");
    for (int month = 0; month < MONTHS; month++) {
        printf("Mês %2d: R$ %.2f\n", month + 1, totalPerMonth[month]);
    }

    printf("\nTotal de vendas por semana ao longo do ano:\n");
    for (int week = 0; week < WEEKS; week++) {
        printf("Semana %d: R$ %.2f\n", week + 1, totalPerWeek[week]);
    }

    printf("\nTotal de vendas no ano: R$ %.2f\n", totalYear);

    return 0;
}
