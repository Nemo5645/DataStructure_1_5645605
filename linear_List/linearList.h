#pragma once

typedef struct ElementType {
	int row;
	int col;
	int val;
} elementType;

typedef struct ListType {
	int size;
	int last;
	int move;
	elementType* array;
} listType;

listType* createList(int size);
int compare_item(elementType item1, elementType item2);
int ordered_insertItem(listType* list, elementType item);
int printList(listType* list);
