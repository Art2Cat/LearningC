#include <stdio.h>

int main(void) {
    float pint = 0.5;
    float ounce = 8;
    float big_spoon = 16;
    float spoon = 48;
    int cups = 5;
    printf("Please enter cup(s): \n");
    // scanf("%d", &cups);
    printf("%d cups equals %.2f pint(s).\n", cups, pint * cups);
    printf("%d cups equals %.2f ounce(s).\n", cups, ounce * cups);
    printf("%d cups equals %.2f big spoon(s).\n", cups, big_spoon * cups);
    printf("%d cups equals %.2f spoon(s).\n", cups, spoon * cups);
    return 0;
}