/*�������Է¹޴´�
2���� N���� �� ���� ���� �ݺ��Ѵ�.
������ ���� �����ִ���Ȯ���Ѵ� ���ٸ�
����Ѵ�
*/

#include <stdio.h>

int main() {
    int number;
    int i, j;
    int count = 0;
    int total = 0;

    printf("���ڸ� �Է��ϼ���: ");
    scanf_s("%d", &number);

    for (i = 2; i <= number; i++) {
        count = 0;
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                count++;
                break;
            }
        }
        if (count == 0) {
            printf("%d\t", i);
            total++;
        }
    }

    printf("\n1���� %d������ �Ҽ��� %d�� �Դϴ�.\n", number, total);

    return 0;
}
