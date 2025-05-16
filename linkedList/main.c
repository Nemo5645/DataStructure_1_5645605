/*insertFirstCNode
* insertLastCNode
* insertMiddleCNode
*/
#include <stdio.h>
#include <stdlib.h>

#include "Linked List.h"

int main() {
    linkedList_h* mylist = createCLinkedList();
    int choice, value, position;
    listNode* temp = NULL;

    while (1) {
        printf("\n=== Circular Linked List Menu ===\n");
        printf("1) insertFirstCNode()\n");
        printf("2) insertLastCNode()\n");
        printf("3) insertNthCNode()\n");
        printf("4) deleteCNode()\n");
        printf("5) printCList()\n");
        printf("0) Exit\n");
        printf("Select menu: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("Insert value: ");
            scanf_s("%d", &value);
            insertFirstCNode(mylist, value);
            break;

        case 2:
            printf("Insert value: ");
            scanf_s("%d", &value);
            insertLastCNode(mylist, value);
            break;

        case 3:
            printf("Insert position (0-based index): ");
            scanf_s("%d", &position);
            printf("Insert value: ");
            scanf_s("%d", &value);
            insertNthCNode(mylist, position, value);
            break;

        case 4:
            printf("Delete value: ");
            scanf_s("%d", &value);
            temp = mylist->head;
            if (temp == NULL) {
                printf("List is empty.\n");
                break;
            }

            listNode* target = NULL;
            do {
                if (temp->data == value) {
                    target = temp;
                    break;
                }
                temp = temp->link;
            } while (temp != mylist->head);

            if (target != NULL) {
                deleteCNode(mylist, target);
                printf("Node with value %d deleted.\n", value);
            }
            else {
                printf("Value %d not found in list.\n", value);
            }
            break;

        case 5:
            printCList(mylist);
            break;

        case 0:
            destroyCLinkedList(mylist);
            printf("Program terminated.\n");
            return 0;

        default:
            printf("Invalid menu selection.\n");
        }
    }

    return 0;
}