#include <stdio.h>

int add(int a, int b);// °¢ ¼À¿¡ ´ëÇÑ Ãß»ó ÀÚ·áÇü »ý¼º
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);

int add(int a, int b) {// °¢ ¼À¿¡ ÇÔ¼ö¸¦ »ðÀÔ
    return a + b;
}
int sub(int a, int b) {
    return a - b;
}
int mul(int a, int b) {
    return a * b;
}
int div(int a, int b) {// 0À¸·Î ³ª´­ ¼ö ¾ø´Ù´Â º¯¼ö Ãß°¡
    if (b == 0) {
        printf("0À¸·Î ³ª´­ ¼ö ¾ø½À´Ï´Ù.\n");
        return 0;
    }
    return a / b;
}

int main() {
    int x, y;
    printf("x: ");
    scanf_s("%d", &x);

    printf("y: ");
    scanf_s("%d", &y);

    printf("µ¡¼À %d + %d = %d\n", x, y, add(x, y));
    printf("»¬¼À %d - %d = %d\n", x, y, sub(x, y));
    printf("°ö¼À %d * %d = %d\n", x, y, mul(x, y));
    if (y != 0) {
        printf("³ª´°¼À %d / %d = %d\n", x, y, div(x, y));
    }

    return 0;
}