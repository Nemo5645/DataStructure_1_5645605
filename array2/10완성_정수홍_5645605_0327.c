#include <stdlib.h>
#include <stdio.h>

int main() {
    int** A = (int**)malloc(2 * sizeof(int*));
    int** B = (int**)malloc(2 * sizeof(int*));
    int** result = (int**)malloc(2 * sizeof(int*));

    for (int i = 0; i < 2; i++) {
        A[i] = (int*)malloc(2 * sizeof(int));
        B[i] = (int*)malloc(2 * sizeof(int));
        result[i] = (int*)malloc(2 * sizeof(int));
    }

    printf("첫 번째 2 X 2 행렬 입력:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf_s("%d", &A[i][j]);
        }
    }

    printf("두 번째 2 X 2 행렬 입력:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf_s("%d", &B[i][j]);
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("행렬 덧셈 결과:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 2; i++) {
        free(A[i]);
        free(B[i]);
        free(result[i]);
    }
    free(A);
    free(B);
    free(result);

    return 0;
}