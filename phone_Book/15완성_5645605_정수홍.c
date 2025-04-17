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
        printf("\n===== ��ȭ��ȣ�� �޴� =====\n");
        printf("1. ����ó �߰�\n");
        printf("2. ����ó ����\n");
        printf("3. ����ó �˻�\n");
        printf("4. ��ü ����ó ���\n");
        printf("0. ����\n");
        printf("�޴��� �����ϼ���: ");
        scanf_s("%d", &menu);
        getchar();

        switch (menu) {
        case 1:
            printf("�̸� �Է�: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';

            printf("��ȭ��ȣ �Է�: ");
            fgets(number, sizeof(number), stdin);
            number[strcspn(number, "\n")] = '\0';

            str_copy(person.name, name, sizeof(person.name));
            str_copy(person.number, number, sizeof(person.number));

            if (insertItem(phoneBook, phoneBook->last + 1, person) == 0)
                printf("����ó�� �߰��Ǿ����ϴ�.\n");
            break;
        case 2:
            printf("������ �̸��� �Է��ϼ���: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';

            {
                int idx = searchList(phoneBook, name);
                if (idx != -1) {
                    deleteItem(phoneBook, idx);
                    printf("����ó�� �����Ǿ����ϴ�.\n");
                }
            }
            break;
        case 3:
            printf("�˻��� �̸��� �Է��ϼ���: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';

            searchList(phoneBook, name);
            break;
        case 4:
            printf("----- ��ü ����ó -----\n");
            printList(phoneBook);
            break;
        case 0:
            printf("���α׷��� �����մϴ�.\n");
            free(phoneBook->array);
            free(phoneBook);
            exit(0);
        default:
            printf("�߸��� �Է��Դϴ�.\n");
            break;
        }
    }

    return 0;
}
