/*
for i form 0 to n-1 do
input array[i]
end for

for i form 0 to n-1 do
for j form 0 to n-1 do
if array[j]> array[j+1]
temp <- array[j]
array[j] = array[j + 1];
array[j + 1] <- temp;
end if
end for

*/
#include<stdlib.h>
#include<stdio.h>

int main() {
    int n;
    int temp;

    printf("�Է��� ���� ����: ");
    scanf_s("%d", &n);

    int* array = (int*)malloc(n* sizeof(int));
    if (array == NULL) {
        printf("�޸� �Ҵ� ����\n");
        return 1;
    }

    printf("�������� �Է�: ");
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &array[i]);
    }
    
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    printf("���� ������ ����Ͽ� ���������� ��� : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;

}