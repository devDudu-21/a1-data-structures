#include <stdio.h>
#include <string.h>

#define MAX 100

// Definindo a estrutura
typedef struct {
    int id;
    char nome[50];
    char endereco[100];
    float precoMedio;
    char tipoComida[30];
} Restaurante;

// Função para ler os dados dos restaurantes
int lerRestaurantes(Restaurante *r) {
    int count;
    printf("Digite o número de restaurantes: ");
    scanf("%d", &count);
    getchar(); 

    for (int i = 0; i < count; i++) {
        printf("Restaurante %d:\n", i + 1);
        r[i].id = i + 1;

        printf("Nome: ");
        fgets(r[i].nome, sizeof(r[i].nome), stdin);
        r[i].nome[strcspn(r[i].nome, "\n")] = '\0';


        printf("Endereco: ");
        fgets(r[i].endereco, sizeof(r[i].endereco), stdin);
        r[i].endereco[strcspn(r[i].endereco, "\n")] = '\0';

        printf("Preco medio: ");
        scanf("%f", &r[i].precoMedio);
        getchar(); // Limpa o buffer do enter

        printf("Tipo de comida: ");
        fgets(r[i].tipoComida, sizeof(r[i].tipoComida), stdin);
        r[i].tipoComida[strcspn(r[i].tipoComida, "\n")] = '\0';

        printf("\n=========================================\n");
        printf("\n");
    }
    return count;
}


// Função para mostrar os dados dos restaurantes
void mostrarRestaurantes(Restaurante *r) {
        printf("Dados dos Restaurantes:\n");
        printf("\n-----------------------------------------\n");
        printf("ID: %d\n", r->id);
        printf("Nome: %s\n", r->nome);
        printf("Endereco: %s\n", r -> endereco);
        printf("Preco medio: R$%.2f\n",  r -> precoMedio);
        printf("Tipo de comida: %s\n", r -> tipoComida);
    
}



int main() {
    Restaurante restaurantes[MAX];
    
    printf("         SISTEMA DE CADASTRO DE RESTAURANTES                  \n");
    printf("==============================================================\n\n");
    
    int count = lerRestaurantes(restaurantes);

    for (int i = 0; i < count; i++) {
      mostrarRestaurantes(&restaurantes[i]);    
    }
    printf("\n-----------------------------------------\n");
    return 0;
}
