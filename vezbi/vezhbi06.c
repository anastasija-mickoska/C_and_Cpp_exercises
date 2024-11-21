#include <stdio.h>

int main() {
    //zadaca 1
    float celsius[213];
    int fahrenheit[213];
    for(int i=0;i<213;i++) {
        celsius[i]=5.0/9.0 * ((float)fahrenheit[i]-32);
        printf("%.3.f\n", celsius[i]);
    }
    //zadaca 2
    int den, mesec, godina;
    char mesec1[10];
    printf("Vnesi datum vo oblik gg/mm/dd, gg-mm-dd ili gg+mm+dd \n");
    scanf("%d%*c%d%*c%d",&den, &mesec, &godina);

    switch(mesec) {
    case 1:  { mesec1="Januari"; break; }
    case 2:  { mesec1="Fevruari";break; }
    case 3:  { mesec1="Mart";break; }
    case 4:  { mesec1="April";break; }
    case 5:  { mesec1="Maj";break; }
    case 6:  { mesec1="Juni";break; }
    case 7:  { mesec1="Juli";break; }
    case 8:  { mesec1="Avgust";break; }
    case 9:  { mesec1="Septemvri";break; }
    case 10: { mesec1="Oktomvri";break; }
    case 11: { mesec1="Noemvri";break; }
    case 12: { mesec1="Dekemvri";break; }
    default: printf("Greshka!");
    }

    printf("Vneseniot datum e: %d %c %d\n", den, mesec1, godina);
    return 0;
}
