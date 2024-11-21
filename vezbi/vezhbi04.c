#include <stdio.h>

int main() {
    //zadaca 1
    int mesec;

    printf("Vnesi go mesecot so negoviot reden broj: ");
    scanf("%d", &mesec);

    switch (mesec) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        printf("Ima 31 den\n");
    case 4:
    case 6:
    case 9:
    case 11:
        printf("Ima 30 dena\n");
    case 2:
        printf("Vo prestapni godini ima 29, a vo obichni 28 dena\n");
    default:
        printf("Greshen broj na mesec!\n");
    }
    //ako se ispusti break, kje prodolzi da gi proveruva narednite case

    //zadaca 2 i 3
    int counter;
    int grade;
    int total;
    float average;
    int numberOfStudents;

    scanf("%d", &numberOfStudents);
    total = 0;
    counter = 1;

    while ( counter <= numberOfStudents ) {
        printf( "Vnesi ocena: " );
        scanf( "%d", &grade );
        total = total + grade;
        counter = counter + 1;
    }

    average = total / numberOfStudents;

    printf( "Srednata vrednost na klasot e %.3f\n", average );

    //zadaca 4

    int sum=0;
    int counter=1;

    while(counter<=10) {
        sum+=counter;
        counter++;
    }
    printf("Sum: %d\n", sum );

    //zadaca 5

    int product=1;
    int counter=1;
    int num;

    while(counter<=10) {
        scanf("%d", &num);
        product *= num;
        counter++;
    }
    printf("Product: %d\n", product);

    //zadaca 6

    int suma=0;
    int broj;

    while(broj != -1) {
        scanf("%d", &broj);
        suma+=broj;
    }
    printf("Suma: %d \n", suma);

    //zadaca 7

    int suma1=0;
    int broj1;
    char ch;

    while(ch != 'n') {
        printf("Vnesi broj.");
        scanf("%d", &broj1);
        printf("Ushte? (d/n)");
        scanf("%c", &ch);
        suma1+=broj1;
    }

    printf("Suma: %d \n", suma);

    //zadaca 8

    int brP[5], kolicina[5];
    float cena[5], cena1[5], total;
    int i=0;

    while(i < 5) {
        printf("Vnesi broj na proizvod.");
        scanf("%d", &brP[i]);
        printf("Vnesi kolicina na proizvodot.");
        scanf("%d", kolicina[i]);
    }
    switch(brP) {
    case 1: {
        cena[1]=50.5;
        break;
    }
    case 2: {
        cena[2]=45.6;
        break;
    }
    case 1: {
        cena[3]=32.8;
        break;
    }
    case 1: {
        cena[4]=65.3;
        break;
    }
    case 1: {
        cena[5]=20.0;
        break;
    }
    default: printf("Greshka!");
    }

    for(int i=0;i<5;i++) {
        cena1[i]= cena[i] * brP[i];
        total+=cena1[i];
        printf("Proizvod %d, total %d\n", i, cena1[i] );
    }
    printf("Total: %d\n", total);

    //zadaca 9

    float osnovnaPlata= 200.00;
    float prodazba;

    while(prodazba != -1) {
        printf("Vnesi promet vo evra (-1 za kraj)\n");
        scanf("%d", &prodazba);

        printf("Platata e: %d\n", prodazba*0.09 +osnovnaPlata);
    }
    return 0;
}
