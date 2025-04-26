#include <stdio.h>

struct Person {
    char name[100];
    char date[11]; 
    char cpf[15];
};

// Função populatePerson:
// Lê e preenche os dados de uma pessoa utilizando scanf_s
void populatePerson(struct Person* p) {
    // Solicita e lê o nome da pessoa
    printf("Name: ");
    scanf_s(" %[^\n]", p->name, 100); 

    // Solicita e lê a data de nascimento no formato DD-MM-AAAA
    printf("Date (DD-MM-AAAA): ");
    scanf_s(" %s", p->date, 11);

    // Solicita e lê o CPF da pessoa
    printf("CPF: ");
    scanf_s(" %s", p->cpf, 15);
}

// Função printPerson:
// Exibe os dados da pessoa no console
void printPerson(const struct Person* p) {
    printf("\n--- Printing... ---\n");
    printf("Name: %s\n", p->name);
    printf("Date: %s\n", p->date);
    printf("CPF: %s\n", p->cpf);
}

int main() {
    // Declaração de uma variável do tipo Person
    struct Person person;
    // Ponteiro para acessar a estrutura person
    struct Person* ptrPerson = &person;

    // Preenche a estrutura com os dados fornecidos pelo usuário
    populatePerson(ptrPerson);
    // Imprime os dados da pessoa
    printPerson(ptrPerson);

    return 0;
}
