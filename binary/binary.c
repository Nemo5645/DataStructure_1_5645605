#include <stdio.h>

void binary(int n) {
	for (int i = 31; i >= 0; i--) {
		printf("%d", (n >> i) & 1);
	}
}

int main() {
	int number;
	printf("����:");
	scanf_s("%d", &number);
	printf("������: ");
	binary(number);
	return 0;

}