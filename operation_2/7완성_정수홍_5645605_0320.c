#include <stdio.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divide(int a, int b) {
    if (b == 0) {
        printf("0으로 나눌 수 없습니다.\n");
        return 0;
    }
    return a / b;
}//실습 5번의 추상자료형을 사용

int main() {
    int result, num;
    char op;

    printf("첫 번째 숫자를 입력하세요: ");
    scanf_s("%d", &result);//첫번째 변수 입력

    while (1) {
        printf("연산자를 입력하세요 (+, -, *, /) (끝내려면 = 입력): ");
        scanf_s(" %c", &op, 1);//연산자 입력

        if (op == '=') break;

        printf("다음 숫자를 입력하세요: ");
        scanf_s("%d", &num);//다음 변수를 입력

        if (op == '+') result = add(result, num);
        else if (op == '-') result = sub(result, num);
        else if (op == '*') result = mul(result, num);
        else if (op == '/') result = divide(result, num);
        else {
            printf("잘못된 연산자입니다.\n");
            continue;//잘못된 연산자일경우 다시 시도
        }
    }
    printf("결과: %d\n", result);
    return 0;
}