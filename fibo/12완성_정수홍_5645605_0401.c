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
        printf("피보나치 수열 방법 선택 (1: 재귀적, 2: 반복적, 3: 종료): ");
        if (scanf_s("%d", &f) != 1) {
            printf("잘못된 입력입니다. 다시 입력하세요.\n");
            while (getchar() != '\n');
            continue;
        }

        if (f == 3) {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        printf("정수 N을 입력하세요: ");
        if (scanf_s("%d", &m) != 1 || m < 0) {
            printf("잘못된 입력입니다. 양의 정수를 입력하세요.\n");
            while (getchar() != '\n');
            continue;
        }

        if (f == 1) {
            printf("재귀적 방법: F(%d) = %d\n", m, fibo_recu(m));
        }
        else if (f == 2) {
            printf("반복적 방법: F(%d) = %d\n", m, fibo_itr(m));
        }
        else {
            printf("잘못된 선택입니다. 1 또는 2를 입력하세요.\n");
        }
    }
    return 0;
}