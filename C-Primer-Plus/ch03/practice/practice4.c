#include <stdio.h>

int main(void)
{
    float f = 64.25;
    printf("Enter a floating-point value:\b 64.25\n");
    // scanf("%f", &f);
    printf("fixed-point notation: %.6f\n", f);
    printf("fixed-point notation: %e\n", f);
    printf("p notation: %2.5a", f);
    return 0;
}