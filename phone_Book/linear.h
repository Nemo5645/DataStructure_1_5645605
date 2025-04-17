#pragma once

#define NULL_ITEM (elementType){"", ""}

typedef struct Phone {
    char number[14];
    char name[20];
} phone;

typedef phone elementType;

typedef struct ListType {
    int size;
    int last;
    int move;
    elementType* array;
} listType;

listType* createList(int size);
elementType readItem(listType* list, int index);
elementType deleteItem(listType* list, int index);
int insertItem(listType* list, int index, elementType item);
int printList(listType* list);
int initList(listType* list);
int searchList(listType* list, const char* name);

