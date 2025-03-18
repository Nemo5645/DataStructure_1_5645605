/*정수를입력받는다
2부터 N까지 의 수에 대해 반복한다.
나누어 지는 수가있는지확인한다 없다면
출력한다
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
