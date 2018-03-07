#include <stdio.h>

int main()
{
    float fahr, celsius;
    float upper, step;
    float lower = -17.8; /* 温度表的下限*/
    upper = 300;     /* 温度表的上限*/
    step = 20;       /* 步长*/
    celsius = lower;
    while (celsius <= upper)
    {
        fahr = (celsius / (5.0 / 9.0)) + 32.0;
        printf("%3.1f\t%3.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
}