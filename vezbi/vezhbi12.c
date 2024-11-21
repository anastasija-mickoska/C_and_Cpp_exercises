#include <stdio.h>
#include <stdlib.h>

int mnoziSoStepenOdDva(int broj, int stepen) {
    return broj << stepen;
}

void prevrtiBitovi(unsigned num) {
    int bits = 16;
    unsigned reversed = 0;

    printf("Vrednost na bitovite pred prevrtuvanje:\n");
    for (int i = bits - 1; i >= 0; i--) {
        int bit = (num >> i) & 1;
        printf("%d", bit);
    }

    for (int i = 0; i < bits; i++) {
        reversed <<= 1;
        reversed |= (num & 1);
        num >>= 1;
    }

    printf("\nVrednost na bitovite posle prevrtuvanje:\n");
    for (int i = bits - 1; i >= 0; i--) {
        int bit = (reversed >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

int misterija( unsigned bitovi )
{
    unsigned i;
    unsigned maska = 1 << 31; //maska od 32 bita so MSB=1
    unsigned total = 0;

    for ( i = 1; i <= 32; i++, bitovi <<= 1 ) {
        if ( ( bitovi & maska ) == maska ) {
            total++;
        }
    }
    return !( total % 2 ) ? 1 : 0;
    //proveruva kolku biti se 1, i na kraj proveruva dali brojot na biti so vrednost 1 e paren ili neparen
}

int main() {
    //zadaca 1

    int br, st;
    while(1){
        scanf("%d %d", &br, &st);
        printf("%d\n", mnoziSoStepenOdDva(br,st));
    }

    //zadaca 2

    unsigned number;
    scanf("%u", &number);

    prevrtiBitovi(number);

    //zadaca 3

    unsigned x;
    printf( "Vnesi cel broj: " );
    scanf( "%u", &x );
    printf( "Rezultatot e %d\n", misterija( x ) );

}
