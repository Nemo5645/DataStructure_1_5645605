#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linear.h"

listType* createList(int size) {
    listType* lptr = (listType*)malloc(sizeof(listType));
    lptr->array = (elementType*)malloc(sizeof(elementType) * size);
    lptr->size = size;
    lptr->last = -1;
    lptr->move = 0;
    return lptr;
}

elementType readItem(listType* list, int index) {
    if (index < 0 || index > list->last) {
        fprintf(stderr, "Index error %d in readItem\n", index);
        return NULL_ITEM;
    }
    return list->array[index];
}

int insertItem(listType* list, int index, elementType item) {
    if (index < 0 || index > list->last + 1 || list->last + 1 >= list->size) {
        fprintf(stderr, "Cannot insert at index %d\n", index);
        return -1;
    }

    for (int i = list->last + 1; i > index; i--) {
        list->array[i] = list->array[i - 1];
        list->move++;
    }
    list->array[index] = item;
    list->last++;
    return 0;
}

elementType deleteItem(listType* list, int index) {
    if (index < 0 || index > list->last) {
        fprintf(stderr, "Index error %d in deleteItem\n", index);
        return NULL_ITEM;
    }

    elementType r = list->array[index];
    for (int i = index; i < list->last; i++) {
        list->array[i] = list->array[i + 1];
        list->move++;
    }
    list->last--;
    return r;
}

int printList(listType* list) {
    printf("총 %d개의 연락처:\n", list->last + 1);
    for (int i = 0; i <= list->last; i++) {
        printf("[%d] 이름: %s, 전화번호: %s\n", i, list->array[i].name, list->array[i].number);
    }
    return 0;
}

int initList(listType* list) {
    list->last = -1;
    list->move = 0;
    return 0;
}

int searchList(listType* list, const char* name) {
    for (int i = 0; i <= list->last; i++) {
        if (strcmp(list->array[i].name, name) == 0) {
            printf("검색 결과: 이름: %s, 전화번호: %s\n", list->array[i].name, list->array[i].number);
            return i;
        }
    }
    printf("'%s'에 해당하는 연락처를 찾을 수 없습니다.\n", name);
    return -1;
}
