#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    /*vezbi 01, zadaca 1
        a) scanf("%d", &vrednost);
        b) printf("Proizvodot na %d i %d e %d\n", x,y,z);
        c) sumaBroevi = prvBroj + vtorBroj
        d) /*Programata naogja maksimum od dva broja
        e) scanf("%d", &nekojBroj);
    */
    //zadaca 2
    int b1,b2,b3,b4, sum;
    scanf("%d", &b1);
    scanf("%d", &b2);
    scanf("%d", &b3);
    scanf("%d", &b4);
    sum=b1+b2+b3+b4;
    printf("Sum: %d\n", sum);

    //zadaca 3
    int a1=1,a2=2,a3=3,a4=4;
    printf("1 2 3 4\n");
    printf("%d %d %d %d", a1,a2,a3,a4);
    printf("%d",a1);
    printf("%d",a2);
    printf("%d",a3);
    printf("%d\n",a4);

    //zadaca 4
    int a,b,c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    printf("Average: %d\n", (a+b+c)/3);
    printf("Sum: %d\n", a+b+c);
    printf("Product: %d\n", a*b*c);

    //zadaca 5
    printf("*****\n");
    for(int i=0;i<5;i++) {
        printf("*   *\n");
    }
    printf("*****\n");

    printf(" *** \n");
    printf("*    *\n");
    for(int i=0;i<3;i++) {
        printf("*   *\n");
    }
    printf("*   *\n");
    printf(" *** \n");

    //zadaca 6
    int c1,c2,c3,c4,c5;
    scanf("%d%d%d%d%d",&c1,&c2,&c3,&c4,&c5);
    printf("%d   %d   %d   %d   %d", c1, c2, c3, c4, c5);

    return 0;
}
