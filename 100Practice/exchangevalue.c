#include<stdio.h>

int main(int argc, char **argv) 
{
    unsigned int a=60;         //0011 1100
    unsigned int b=13;         //0000 1101
    printf("a=%d,b=%d",a,b);   //输出a，b的值
    printf("\n");
    a^=b;                     //a=a^b=0011 0001
    b=a^b;                     //b=a^b=0011 1100
    a^=b;                     //a=a^b=0000 1101
    printf("a=%d,b=%d",a,b);   //输出a，b的值
}