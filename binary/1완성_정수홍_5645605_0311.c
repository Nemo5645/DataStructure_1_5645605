#include <stdio.h>

void binary(int n) {// 정수를 32비트(2의 보수) 이진수로 변환하여 출력하는 함수
	for (int i = 31; i >= 0; i--) {// 31번째 비트부터 0번째 비트까지 검사
		printf("%d", (n >> i) & 1);// 비트 출력
	}
}

int main() {
	int number;
	printf("정수:");
	scanf_s("%d", &number);//정수입력
	printf("이진수: ");
	binary(number);//정수의 2진수를 출력
	return 0;

}