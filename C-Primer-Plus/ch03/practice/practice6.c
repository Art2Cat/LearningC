#include <stdio.h>

int main(void)
{
    double water_molecule = 3.0e-23;
    int quarts = 950;
    long double result = quarts / water_molecule;
    printf("%d quart water contains %.Lf molecule.\n", quarts, result);
    return 0;
}