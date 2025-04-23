#include <stdio.h>


struct Person {
    char name[100];
    char date[11]; 
    char cpf[15];
};

void populatePerson(struct Person* p) {
    printf("Name: ");
    scanf_s(" %[^\n]", p->name, 100); 

    printf("Date (DD-MM-AAAA): ");
    scanf_s(" %s", p->date, 11);

    printf("CPF: ");
    scanf_s(" %s", p->cpf, 15);
}

void printPerson(const struct Person* p) {
    printf("\n--- Printing... ---\n");
    printf("Name: %s\n", p->name);
    printf("Date: %s\n", p->date);
    printf("CPF: %s\n", p->cpf);
}

int main() {
    struct Person person;
    struct Person* ptrPerson = &person;

    populatePerson(ptrPerson);
    printPerson(ptrPerson);

    return 0;
}
