#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

Polynomial* create_polynomial() {
    Polynomial* poly = (Polynomial*)malloc(sizeof(Polynomial));
    poly->head = NULL;
    poly->size = 0;
    return poly;
}

void free_polynomial(Polynomial* poly) {
    Item* current = poly->head;
    while (current != NULL) {
        Item* temp = current;
        current = current->next;
        free(temp);
    }
    free(poly);
}

void insert_item(Polynomial* poly, float coef, int exp) {
    Item* current = poly->head;
    while (current != NULL) {
        if (current->exp == exp) {
            current->coef += coef;
            return;
        }
        current = current->next;
    }


    Item* new_item = (Item*)malloc(sizeof(Item));
    new_item->coef = coef;
    new_item->exp = exp;
    new_item->next = NULL;

    if (poly->head == NULL || exp > poly->head->exp) {
        new_item->next = poly->head;
        poly->head = new_item;
    }
    else {
        current = poly->head;
        while (current->next != NULL && current->next->exp > exp) {
            current = current->next;
        }
        new_item->next = current->next;
        current->next = new_item;
    }
    poly->size++;
}

Polynomial* multiply_polynomials(Polynomial* poly1, Polynomial* poly2) {
    Polynomial* result = create_polynomial();

    Item* item1 = poly1->head;
    while (item1 != NULL) {
        Item* item2 = poly2->head;
        while (item2 != NULL) {
            float new_coef = item1->coef * item2->coef;
            int new_exp = item1->exp + item2->exp;
            insert_item(result, new_coef, new_exp);
            item2 = item2->next;
        }
        item1 = item1->next;
    }

    return result;
}

void print_polynomial(Polynomial* poly) {
    Item* current = poly->head;
    int first_item = 1;

    while (current != NULL) {
        if (!first_item) {
            if (current->coef > 0) printf(" + ");
            else printf(" - ");
        }
        else {
            if (current->coef < 0) printf("-");
        }

        float abs_coef = current->coef > 0 ? current->coef : -current->coef;

        if (current->exp == 0) {
            printf("%.0f", abs_coef);
        }
        else if (current->exp == 1) {
            if (abs_coef == 1) printf("x");
            else printf("%.0fx", abs_coef);
        }
        else {
            if (abs_coef == 1) printf("x^%d", current->exp);
            else printf("%.0fx^%d", abs_coef, current->exp);
        }

        first_item = 0;
        current = current->next;
    }
    printf("\n");
}

Polynomial* input_polynomial() {
    Polynomial* poly = create_polynomial();
    int terms;
    float coef;
    int exp;

    printf("다항식의 항 개수를 입력하세요: ");
    scanf_s("%d", &terms);

    for (int i = 0; i < terms; i++) {
        printf("%d번째 항의 계수와 지수 입력 (예: 3 2): ", i + 1);
        scanf_s("%f %d", &coef, &exp);
        insert_item(poly, coef, exp);
    }
    return poly;
}

int main() {
    printf("첫 번째 다항식 입력\n");
    Polynomial* poly1 = input_polynomial();

    printf("\n두 번째 다항식 입력\n");
    Polynomial* poly2 = input_polynomial();


    printf("첫 번째 다항식: ");
    print_polynomial(poly1);

    printf("두 번째 다항식: ");
    print_polynomial(poly2);

    Polynomial* poly3 = multiply_polynomials(poly1, poly2);
    printf("\n곱셈 결과: ");
    print_polynomial(poly3);

    free_polynomial(poly1);
    free_polynomial(poly2);
    free_polynomial(poly3);

    return 0;
}
