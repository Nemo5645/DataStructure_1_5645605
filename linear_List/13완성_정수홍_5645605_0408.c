#include <stdio.h>
#include <stdlib.h>
#include "linearList.h"

listType* createList(int size) {
	listType* lptr = (listType*)malloc(sizeof(listType));
	lptr->array = (elementType*)malloc(sizeof(elementType) * size);
	lptr->size = size;
	lptr->last = -1;
	lptr->move = 0;
	return lptr;
}

int compare_item(elementType item1, elementType item2) {
	if (item1.row != item2.row) return item1.row - item2.row;
	return item1.col - item2.col;
}

int ordered_insertItem(listType* list, elementType item) {
	int i, j;
	for (i = 0; i <= list->last; i++) {
		if (compare_item(list->array[i], item) > 0) break;
	}
	for (j = list->last + 1; j > i; j--) {
		list->array[j] = list->array[j - 1];
		list->move++;
	}
	list->array[i] = item;
	list->last++;
	return 1;
}

int printList(listType* list) {
	printf("List: size = %d, last = %d, move = %d\n\t Items:", list->size, list->last, list->move);
	for (int i = 0; i <= list->last; i++) {
		printf(" [%d]{%d,%d,%d} ", i,
			list->array[i].row,
			list->array[i].col,
			list->array[i].val);
	}
	printf("\n");
	return 1;
}

int main() {
	listType* mat1 = createList(1000);
	listType* mat2 = createList(1000);
	listType* result = createList(1000);

	elementType item;
	int row, col, val;

	printf("행렬을 입력하시요? (-1 입력 시 행렬의 입력이 종료됨)\n");
	while (1) {
		scanf_s("%d", &row);
		if (row == -1) break;
		scanf_s("%d %d", &col, &val);
		item.row = row;
		item.col = col;
		item.val = val;
		ordered_insertItem(mat1, item);
	}

	printf("행렬을 입력하시요? (-1 입력 시 행렬의 입력이 종료됨)\n");
	while (1) {
		scanf_s("%d", &row);
		if (row == -1) break;
		scanf_s("%d %d", &col, &val);
		item.row = row;
		item.col = col;
		item.val = val;
		ordered_insertItem(mat2, item);
	}

	int i = 0, j = 0;
	while (i <= mat1->last && j <= mat2->last) {
		elementType a = mat1->array[i];
		elementType b = mat2->array[j];
		int cmp = compare_item(a, b);

		if (cmp == 0) {
			elementType sum = { a.row, a.col, a.val + b.val };
			ordered_insertItem(result, sum);
			i++; j++;
		}
		else if (cmp < 0) {
			ordered_insertItem(result, a);
			i++;
		}
		else {
			ordered_insertItem(result, b);
			j++;
		}
	}
	while (i <= mat1->last) ordered_insertItem(result, mat1->array[i++]);
	while (j <= mat2->last) ordered_insertItem(result, mat2->array[j++]);

	printf("두 행렬의 합\n");
	printList(result);

	return 0;
}
