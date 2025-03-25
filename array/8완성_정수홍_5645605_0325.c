/*
for i from 0 to 1 do 
for j from 0 to 1 do
inputA[i][j]
end for

for i from 0 to 1 do
for j from 0 to 1 do
inputB[i][j]
end for

for i from 0 to 1 do
for j from 0 to 1 do
reslut[i][j]<-A[i][j]+b[i][j]
for end

*/
#include<stdlib.h>
#include<stdio.h>

int main() {
	int A[2][2];
	int B[2][2];
	int result[2][2];

	printf("첫 번째 2 X 2 행렬 입력:\n");
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++) {
			scanf_s("%d", &A[i][j]);
		}
	}

	printf("두 번째 2 X 2 행렬 입력:\n");
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 2; j++) {
			scanf_s("%d", &B[i][j]);
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			result[i][j] = A[i][j] + B[i][j];
		}
	}

	printf("행력 덧셈 결과: \n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}

}
