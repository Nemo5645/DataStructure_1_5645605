#include <stdio.h>

void binary(int n) {
	for (int i = 31; i >= 0; i--) {
		printf("%d", (n >> i) & 1);
	}
}

int main() {
	int number;
	printf("정수:");
	scanf_s("%d", &number);
	printf("이진수: ");
	binary(number);
	return 0;

}