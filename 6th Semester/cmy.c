#include <stdio.h>

void main() {
    float r, g, b;
    printf("Enter the value of R, G, B: ");
    scanf("%f%f%f", &r, &g, &b);
    if (r < 0 || r > 255) {
        printf("Enter R value: ");
        scanf("%f", &r);
    }
    if (g < 0 || g > 255) {
        printf("Enter G value: ");
        scanf("%f", &g);
    }
    if (b < 0 || b > 255) {
        printf("Enter B value: ");
        scanf("%f", &b);
    }
    printf("***RGB to CMY***\n");
    float w = 1;
    float rf = r / 255;
    float gf = g / 255;
    float bf = b / 255;

    float c = w - rf;
    float m = w - gf;
    float y = w - bf;
    printf("White: %f\n", w);
    printf("C, M, Y: %f, %f, %f\n", c, m, y);

    printf("***RGB to CMY***\n");
    if (r == 0 && g == 0 && b == 0) {
        printf("C, M, Y, K: 0, 0, 0, 1\n");
    } else {
        float max = rf;
        if (gf > max) max = gf;
        if (bf > max) max = bf;
        w = max;
        c = (w - rf) / w;
        m = (w - gf) / w;
        y = (w - bf) / w;
        float k = 1 - w;
        printf("C, M, Y, K: %f, %f, %f, %f", c, m, y, k);
    }
}