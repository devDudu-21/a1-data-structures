#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id;
    char name[50];
    int class;
    float normal_hours;
    float extra_hours;
    float hourly_rate;
    float salary_normal;
    float salary_extra;
    float inss;
    float salary_net;
} Employee;

// Função read_employees:
// Lê os dados dos funcionários e os armazena no vetor 'employees'
int read_employees(Employee *employees) {
    int count;
    printf("Digite o número de funcionários: ");
    scanf("%d", &count);
    getchar(); // Consome o '\n'

    for (int i = 0; i < count; i++) {
        printf("\nFuncionário %d\n", i + 1);
        printf("Número de inscrição: ");
        scanf("%d", &employees[i].id);
        getchar();

        printf("Nome: ");
        fgets(employees[i].name, sizeof(employees[i].name), stdin);
        employees[i].name[strcspn(employees[i].name, "\n")] = '\0';

        printf("Classe (1 ou 2): ");
        scanf("%d", &employees[i].class);
        printf("Horas normais: ");
        scanf("%f", &employees[i].normal_hours);
        printf("Horas extras: ");
        scanf("%f", &employees[i].extra_hours);
    }

    return count;
}

// Função calculate_salaries:
// Calcula os salários com base nas horas normais, extras, alíquota e desconto do INSS
void calculate_salaries(Employee *emp, float reference_salary) {
    // Define um multiplicador baseado na classe do funcionário
    float multiplier = (emp->class == 1) ? 1.3 : 1.9;
    emp->hourly_rate = reference_salary * multiplier;
    emp->salary_normal = emp->normal_hours * emp->hourly_rate;
    emp->salary_extra = emp->extra_hours * emp->hourly_rate * 1.3;

    // Calcula a dedução do INSS e o salário líquido
    emp->inss = (emp->salary_normal + emp->salary_extra) * 0.11;
    emp->salary_net = (emp->salary_normal + emp->salary_extra) - emp->inss;
}

// Função print_paycheck:
// Imprime o contracheque do funcionário com todos os detalhes dos cálculos
void print_paycheck(Employee *emp) {
    printf("\n-----------------------------------------\n");
    printf("NÚMERO DE INSCRIÇÃO: %d\tNOME: %s\n", emp->id, emp->name);
    printf("SALÁRIO HORAS NORMAIS: R$ %.2f\n", emp->salary_normal);
    printf("SALÁRIO HORAS EXTRAS: R$ %.2f\n", emp->salary_extra);
    printf("DEDUÇÃO INSS: R$ %.2f\n", emp->inss);
    printf("SALÁRIO LÍQUIDO: R$ %.2f\n", emp->salary_net);
    printf("-----------------------------------------\n");
}

int main() {
    Employee employees[MAX];
    float reference_salary;

    // Solicita o salário de referência a partir do qual os demais cálculos serão baseados.
    printf("Digite o salário de referência: ");
    scanf("%f", &reference_salary);

    // Lê os dados dos funcionários.
    int count = read_employees(employees);

    // Calcula os salários para cada funcionário.
    for (int i = 0; i < count; i++) {
        calculate_salaries(&employees[i], reference_salary);
    }

    // Imprime o contracheque de cada funcionário.
    for (int i = 0; i < count; i++) {
        print_paycheck(&employees[i]);
    }

    return 0;
}
