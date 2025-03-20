#include <stdio.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divide(int a, int b) {
    if (b == 0) {
        printf("0���� ���� �� �����ϴ�.\n");
        return 0;
    }
    return a / b;
}//�ǽ� 5���� �߻��ڷ����� ���

int main() {
    int result, num;
    char op;

    printf("ù ��° ���ڸ� �Է��ϼ���: ");
    scanf_s("%d", &result);//ù��° ���� �Է�

    while (1) {
        printf("�����ڸ� �Է��ϼ��� (+, -, *, /) (�������� = �Է�): ");
        scanf_s(" %c", &op, 1);//������ �Է�

        if (op == '=') break;

        printf("���� ���ڸ� �Է��ϼ���: ");
        scanf_s("%d", &num);//���� ������ �Է�

        if (op == '+') result = add(result, num);
        else if (op == '-') result = sub(result, num);
        else if (op == '*') result = mul(result, num);
        else if (op == '/') result = divide(result, num);
        else {
            printf("�߸��� �������Դϴ�.\n");
            continue;//�߸��� �������ϰ�� �ٽ� �õ�
        }
    }
    printf("���: %d\n", result);
    return 0;
}