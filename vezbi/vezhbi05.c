#include <stdio.h>

int main() {
    //zadaca 1
    int sum;
    for ( int number = 2, sum = 0; number <= 100; number += 2 ) {
        sum += number;
    }
    printf( "Sumata e %d\n", sum );

    //zadaca 2

    double amount;
    double principal = 1000.0;
    double rate = .05;
    int year;

        printf( "%4s%25s\n", "Godina", "Vrednost na depozitot" );

    for ( year = 1; year <= 10; year++ ) {

        amount = principal * pow( 1.0 + rate, year );

        printf("%-4d%-25.2f\n", year, amount);
    }

    //zadaca 3

    for(int a=1; a<100; a++) {
        for(int b=0;b<100;b++) {
            for(int c=0;c<100;c++) {
                if(c*c == a*a + b*b) {
                    printf("{%d %d %d}\n", a,b,c);
                }
            }
        }
    }

    //zadaca 4

    int number;

    char iljada[4] = {"", "M", "MM", "MMM"};
    char stotki[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char desetki[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char edinici[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

    scanf("%d", &number);

    printf("%s", iljada[number / 1000]);
    printf("%s", stotki[(number % 1000) / 100]);
    printf("%s", desetki[(number % 100) / 10]);
    printf("%s\n", edinici[number % 10]);

    //zadaca 5

    for(int i=0;i<=100;i++) {
        if(i%3==0) {
            continue;
        }
        else {
            printf("%d ne e deliv so 3.\n", i);
        }
    }
}
