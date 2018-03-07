#include <stdio.h>

int main()
{
    float fahr, celsius;
    float upper, step;
    float lower = 0; /* 温度表的下限*/
    upper = 300;     /* 温度表的上限*/
    step = 20;       /* 步长*/
    fahr = lower;
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}