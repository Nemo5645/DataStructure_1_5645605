#pragma once

typedef struct Item {
    float coef;
    int exp;
    struct Item* next;
} Item;

typedef struct Polynomial {
    Item* head;
    int size;
} Polynomial;

Polynomial* create_polynomial();
void free_polynomial(Polynomial* poly);
void insert_item(Polynomial* poly, float coef, int exp);
void print_polynomial(Polynomial* poly);

Polynomial* multiply_polynomials(Polynomial* poly1, Polynomial* poly2);