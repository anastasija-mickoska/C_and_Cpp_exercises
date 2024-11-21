#include <stdio.h>

int main() {
    //zadaca 1
    int b1,b2;
    scanf("%d %d", &b1, &b2);
    if(b1>b2) {
        printf("%d e pogolem od %d", b1, b2);
    }
    else if(b2>b1) {
        printf("%D e pogolem od %d", b2,b1);
    }
    else {
        printf("Broevite se ednakvi.");
    }

    //zadaca 2
    int a,b;
    scanf("%d %d", &a, &b);
    if(a%2==0) {
        printf("%d e paren broj.", a);
    }
    else {
        printf("%d e neparen broj.", a);
    }
    if(b%2==0) {
        printf("%d e paren broj.", b);
    }
    else {
        printf("%d e neparen broj.", b);
    }

    //zadaca 3
    printf("%d", 'A');
    printf("%d", 'b');
    printf("%d", 'c');
    printf("%d", '0');
    printf("%d", '1');
    printf("%d", '2');
    printf("%d", '$');
    printf("%d", '*');
    printf("%d", '+');
    printf("%d", '/');
    printf("%d", ' ');

    //zadaca 4
    float result = 7.0 / 22.0;
    printf("Rezultatot e %d\n", result);
    //celobrojno delenje, rezultatot kje bide 0

    //zadaca 5
    int radius;
    printf("Plostina: %d\n", radius*radius*3.14);
    printf("Perimetar: %d\n", 2*radius*3.14);

    //zadaca 6
    char c1,c2,c3,c4,c5;
    scanf("%c%c%c%c%c", &c1,&c2,&c3,&c4,&c5);
    printf("prva bukva: %c", c1);
    printf("vtora bukva: %c", c2);
    printf("treta bukva: %c", c3);
    printf("cetvrta bukva: %c", c4);
    printf("petta bukva: %c", c5);
    printf("Rezultat: %c%c%c%c%c", c5,c3,c2,c1,c4);

    //zadaca 7
    float data[5];
    float total, average;
    data[0] = 34.0;
    data[1] = 27.0;
    data[2] = 45.0;
    data[3] = 82.0;
    data[4] = 22.0;
    total = data[0] + data[1] + data[2] + data[3] + data[4];
    average = total / 5.0;
    printf("Vkupno %.3f Sredna vrednost %.3f\n", total, average);

    //zadaca 8
    int x;
    x++;
    x=x+1;
    ++x;
    x+=1;

    return 0;
}
