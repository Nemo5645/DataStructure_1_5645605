/*
사용자로 부터 정수를 입력받는다.
2부터 Number까지의 수에 대해 나누기를 반복한다.
나누어 지는 수가 있는지 확인한다.
나누어지지 않는다면 i는 소수 이므로 출력한다.
total에 1을 추가한다.
소수의 갯수를 출력한다.

시간 복잡도 O(n^2)
외부 반복문을 n번 반복하고 
내부 반복문울 n/2번 반복하기 때문에
전체적으로 O(n^2)
*/

#include <stdio.h>

int main() {
    int number;
    int i, j;
    int count = 0;
    int total = 0;

    printf("숫자를 입력하세요: ");
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

    printf("\n1부터 %d까지의 소수는 %d개 입니다.\n", number, total);

    return 0;
}
