#include <stdio.h>

//zadaca 1
int paren (int n) {
    if(n%2==0) {
        return 1;
    }
    else return 0;
}

//zadaca 2
int vreme(int a, int b, int c) {
    int t;
    t = (11 - a) * 3600 + (59 - b) * 60 + (60 - c);
    return t;
}

//zadaca 3
int obratno(int n) {
    int cifra;
    while(n>0) {
        cifra=n%10;
        n/=10;
        printf("%d",cifra);
    }
}

//zadaca 4
int nzd(int a, int b) {
    int max=1;
    for(int i=2;i< (a>b) ? a : b ; i++) {
        if(a%i ==0 && b&i==0) {
            max=i;
        }
    }
    return max;
}

//zadaca 5
int fibonacci(int n) {
    if (n <= 1)
        return n;
    int a = 0, b = 1, f = 0;
    for (int i = 2; i <= n; i++) {
        f = a + b;
        a = b;
        b = f;
    }
    return f;
}

//zadaca 6
int nzd1(int a, int b) {
    if (b == 0)
        return a;
    return nzd1(b, a % b);
}

//zadaca7
void dzvezdi(int n) {
    if (n<=0) {
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("* ");
    }
    printf("\n");
    dzvezdi(n-1);
}

int main() {
    //zadaca 1

    int broj[10];

    for(int i=0;i<10;i++) {
        scanf("%d", &broj[i]);
        if(paren(broj[i])==1) {
            printf("Brojot e paren.\n");
        }
        else {
            printf("Brojot e neparen.\n");
        }
    }

    //zadaca 2

    int cas, minuta, sekunda;

    scanf("%d %d %d", &cas, &minuta, &sekunda);
    printf("do 12 casot %d sekundi.\n", vreme(cas,minuta, sekunda));

    //zadaca 3
    int br;
    scanf("%d",&br);
    printf("Obratniot broj e %d", obratno(br));

    //zadaca 4

    int b1,b2;
    scanf("%d %d", &b1, &b2);

    printf("NZD na %d i %d e %d", b1,b2, nzd(b1,b2));
    return 0;


}
