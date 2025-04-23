#include <stdio.h>
#include <string.h>

#define MAX 1000
#define MAX_SIZE 100

void mark_presence(int *vector, int size, char *presence) {
    for (int i = 0; i < size; i++) {
        presence[vector[i]] = 1;
    }
}

int intersection(int *a, int size_a, int *b, int size_b, int *result) {
    char present_b[MAX] = {0};
    char already_added[MAX] = {0};
    mark_presence(b, size_b, present_b);

    int k = 0;
    for (int i = 0; i < size_a; i++) {
        int val = a[i];
        if (val >= 0 && val < MAX && present_b[val] && !already_added[val]) {
            result[k++] = val;
            already_added[val] = 1;
        }
    }
    return k;
}

int union_set(int *a, int size_a, int *b, int size_b, int *result) {
    char added[MAX] = {0};
    int k = 0;
    for (int i = 0; i < size_a; i++) {
        if (!added[a[i]]) {
            result[k++] = a[i];
            added[a[i]] = 1;
        }
    }
    for (int i = 0; i < size_b; i++) {
        if (!added[b[i]]) {
            result[k++] = b[i];
            added[b[i]] = 1;
        }
    }
    return k;
}

int difference(int *a, int size_a, int *b, int size_b, int *result) {
    char present_b[MAX] = {0};
    char already_added[MAX] = {0};
    mark_presence(b, size_b, present_b);

    int k = 0;
    for (int i = 0; i < size_a; i++) {
        int val = a[i];
        if (!present_b[val] && !already_added[val]) {
            result[k++] = val;
            already_added[val] = 1;
        }
    }
    return k;
}

void print_vector(int *vector, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

int exists(int *vector, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (vector[i] == value) return 1;
    }
    return 0;
}

int main() {
    int set1[MAX_SIZE], set2[MAX_SIZE];
    int size1 = 0, size2 = 0;
    int num;

    printf("Digite os elementos do primeiro conjunto (termine com -1): ");
    while (scanf("%d", &num) && num != -1) {
        if (!exists(set1, size1, num)) {
            set1[size1++] = num;
        }
    }

    printf("Digite os elementos do segundo conjunto (termine com -1): ");
    while (scanf("%d", &num) && num != -1) {
        if (!exists(set2, size2, num)) {
            set2[size2++] = num;
        }
    }

    int result_intersection[MAX_SIZE], result_union[MAX_SIZE], result_difference[MAX_SIZE];

    int size_intersection = intersection(set1, size1, set2, size2, result_intersection);
    int size_union = union_set(set1, size1, set2, size2, result_union);
    int size_difference = difference(set1, size1, set2, size2, result_difference);

    printf("Interseção: ");
    print_vector(result_intersection, size_intersection);
    printf("União: ");
    print_vector(result_union, size_union);
    printf("Diferença: ");
    print_vector(result_difference, size_difference);

    return 0;
}
