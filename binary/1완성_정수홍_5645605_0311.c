#include <stdio.h>

void binary(int n) {// ������ 32��Ʈ(2�� ����) �������� ��ȯ�Ͽ� ����ϴ� �Լ�
	for (int i = 31; i >= 0; i--) {// 31��° ��Ʈ���� 0��° ��Ʈ���� �˻�
		printf("%d", (n >> i) & 1);// ��Ʈ ���
	}
}

int main() {
	int number;
	printf("����:");
	scanf_s("%d", &number);//�����Է�
	printf("������: ");
	binary(number);//������ 2������ ���
	return 0;

}