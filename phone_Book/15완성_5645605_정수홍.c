#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linear.h"

void str_copy(char* dest, const char* src, int size) {
    int i = 0;
    while (src[i] != '\0' && i < size - 1) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int main() {
    int menu;
    char name[20], number[14];
    elementType person;
    listType* phoneBook = createList(100);

    while (1) {
        printf("\n===== 전화번호부 메뉴 =====\n");
        printf("1. 연락처 추가\n");
        printf("2. 연락처 삭제\n");
        printf("3. 연락처 검색\n");
        printf("4. 전체 연락처 출력\n");
        printf("0. 종료\n");
        printf("메뉴를 선택하세요: ");
        scanf_s("%d", &menu);
        getchar();

        switch (menu) {
        case 1:
            printf("이름 입력: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';

            printf("전화번호 입력: ");
            fgets(number, sizeof(number), stdin);
            number[strcspn(number, "\n")] = '\0';

            str_copy(person.name, name, sizeof(person.name));
            str_copy(person.number, number, sizeof(person.number));

            if (insertItem(phoneBook, phoneBook->last + 1, person) == 0)
                printf("연락처가 추가되었습니다.\n");
            break;
        case 2:
            printf("삭제할 이름을 입력하세요: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';

            {
                int idx = searchList(phoneBook, name);
                if (idx != -1) {
                    deleteItem(phoneBook, idx);
                    printf("연락처가 삭제되었습니다.\n");
                }
            }
            break;
        case 3:
            printf("검색할 이름을 입력하세요: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';

            searchList(phoneBook, name);
            break;
        case 4:
            printf("----- 전체 연락처 -----\n");
            printList(phoneBook);
            break;
        case 0:
            printf("프로그램을 종료합니다.\n");
            free(phoneBook->array);
            free(phoneBook);
            exit(0);
        default:
            printf("잘못된 입력입니다.\n");
            break;
        }
    }

    return 0;
}
