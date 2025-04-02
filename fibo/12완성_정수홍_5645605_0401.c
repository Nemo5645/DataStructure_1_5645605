#include<stdlib.h>
#include<stdio.h>

int fibo_itr(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int f_n_2 = 0;
    int f_n_1 = 1;
    int f_n = 0;
    for (int i = 2; i <= n; i++) {
        f_n = f_n_1 + f_n_2;
        f_n_2 = f_n_1;
        f_n_1 = f_n;
    }
    return f_n;
}

int fibo_recu(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibo_recu(n - 1) + fibo_recu(n - 2);
}

int main() {
    int f;
    int m;

    while (1) {
        printf("�Ǻ���ġ ���� ��� ���� (1: �����, 2: �ݺ���, 3: ����): ");
        if (scanf_s("%d", &f) != 1) {
            printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
            while (getchar() != '\n');
            continue;
        }

        if (f == 3) {
            printf("���α׷��� �����մϴ�.\n");
            break;
        }

        printf("���� N�� �Է��ϼ���: ");
        if (scanf_s("%d", &m) != 1 || m < 0) {
            printf("�߸��� �Է��Դϴ�. ���� ������ �Է��ϼ���.\n");
            while (getchar() != '\n');
            continue;
        }

        if (f == 1) {
            printf("����� ���: F(%d) = %d\n", m, fibo_recu(m));
        }
        else if (f == 2) {
            printf("�ݺ��� ���: F(%d) = %d\n", m, fibo_itr(m));
        }
        else {
            printf("�߸��� �����Դϴ�. 1 �Ǵ� 2�� �Է��ϼ���.\n");
        }
    }
    return 0;
}