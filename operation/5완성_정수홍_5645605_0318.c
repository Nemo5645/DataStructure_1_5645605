#include <stdio.h>

int add(int a, int b);// �� ���� ���� �߻� �ڷ��� ����
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);

int add(int a, int b) {// �� ���� �Լ��� ����
    return a + b;
}
int sub(int a, int b) {
    return a - b;
}
int mul(int a, int b) {
    return a * b;
}
int div(int a, int b) {// 0���� ���� �� ���ٴ� ���� �߰�
    if (b == 0) {
        printf("0���� ���� �� �����ϴ�.\n");
        return 0;
    }
    return a / b;
}

int main() {
    int x, y;
    printf("x: ");
    scanf_s("%d", &x);

    printf("y: ");
    scanf_s("%d", &y);

    printf("���� %d + %d = %d\n", x, y, add(x, y));
    printf("���� %d - %d = %d\n", x, y, sub(x, y));
    printf("���� %d * %d = %d\n", x, y, mul(x, y));
    if (y != 0) {
        printf("������ %d / %d = %d\n", x, y, div(x, y));
    }

    return 0;
}