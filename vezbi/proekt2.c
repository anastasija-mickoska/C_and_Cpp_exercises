#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void meshaj(int wDeck[][13]);
void deli(int wDeck[][13], const char *wFace[], const char *wSuit[], int hand[2][5]);
int proveriPar(int hand[5]);
bool proveriDvaPara(int hand[5]);
int proveriTriling(int hand[5]);
int proveriCetiri(int hand[5]);
int proveriBoja(int hand[5], int wDeck[4][13]);
int proveriKenta(int hand[5], int wDeck[4][13]);

const char *boja[4] = { "Srce", "Karo", "List", "Detelina" };
const char *brojka[13] = { "As", "Dva", "Tri", "Chetiri", "Pet", "Shest", "Sedum", "Osum", "Devet", "Deset", "Dzandar", "Dama", "Pop" };
int spil[4][13] = { 0 };

int main() {
    //zadaca 1
    /*1.      Кога ги дефинираме функциите copy1 и copy2 во p09_13.c,
          првиот аргумент мора да е доволно голем за да ги добие вредностите на вториот аргумент. Што тоа значи? */
    // bidejki vtoriot argument e pokazuvac kon konstantna niza, prviot argument mora da e dovolno golem za da moze taa niza da se kopira
    //inaku ako prviot argument e so pomala golemina, kje ne moze da se izvrshi kopiranjeto na nizata

    //2.      Зошто вториот аргумент на двете функции во р09_13.с е деклариран како const char *?
    // bidejki nizata ne treba da ja izmenuvame, tuku samo da ja kopirame

    //proekt 2
    /* Да се модифицира програмот за делење карти така да по мешањето подели 5 карти од рака за покер. Да се одреди дали раката содржи:
        а) пар.
        б) два пара
        в) трилинг (пр. три десетки)
        г) четири карти од ист број (пр. четири асови)
        д) боја (сите пет карти да се од иста боја, на пр, детелина)
        ѓ) кента (5 подредени карти од иста боја, пр. 3,4,5,6,7 срце)
        Претходниот проект да се дополни со делење на карти на двајца играчи (две раце) и при тоа да се одреди кој од нив победил.*/
    srand(time(0));

    meshaj(spil);

    int hand[2][5] = {0}; // Cards for two players
    deli(spil, brojka, boja, hand);

    for (int j = 0; j < 2; j++) {
        printf("\nKoja e rakata - igrac %d:\n", j + 1);
        for (int i = 0; i < 5; i++) {
            int row = hand[j][i] / 13;  // row (boja)
            int col = hand[j][i] % 13;  // column (brojka)
            printf("%s %s\n", brojka[col], boja[row]);
        }

        // Check the hand for each player
        if (proveriPar(hand[j])) {
            printf("Ima par!\n");
        }
        if (proveriDvaPara(hand[j])) {
            printf("Ima dva para!\n");
        }
        if (proveriTriling(hand[j])) {
            printf("Ima triling!\n");
        }
        if (proveriCetiri(hand[j])) {
            printf("Ima cetiri karti od isti broj!\n");
        }
        if (proveriBoja(hand[j], spil)) {
            printf("Ima boja!\n");
        }
        if (proveriKenta(hand[j], spil)) {
            printf("Ima kenta!\n");
        }
    }

    return 0;
}

void meshaj(int wDeck[][13]) {
    int row, column, card;
    for (card = 1; card <= 52; card++) {
        do {
            row = rand() % 4;
            column = rand() % 13;
        } while (wDeck[row][column] != 0);
        wDeck[row][column] = card;
    }
}

void deli(int wDeck[][13], const char *wFace[], const char *wSuit[], int hand[2][5]) {
    int card = 0;
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < 5; i++) {
            int row, column;
            do {
                row = rand() % 4;
                column = rand() % 13;
            } while (wDeck[row][column] == 0);  // Find an unused card
            hand[j][i] = wDeck[row][column] - 1;  // Assign card to player
            wDeck[row][column] = 0;  // Mark card as used
        }
    }
}

int proveriPar(int hand[5]) {
    int counts[13] = {0};
    for (int i = 0; i < 5; i++) {
        counts[hand[i] % 13]++;
    }
    for (int i = 0; i < 13; i++) {
        if (counts[i] == 2) return 1;
    }
    return 0;
}

bool proveriDvaPara(int hand[5]) {
    int counts[13] = {0};
    int pairCount = 0;
    for (int i = 0; i < 5; i++) {
        counts[hand[i] % 13]++;
    }
    for (int i = 0; i < 13; i++) {
        if (counts[i] == 2) pairCount++;
    }
    return (pairCount == 2);
}

int proveriTriling(int hand[5]) {
    int counts[13] = {0};
    for (int i = 0; i < 5; i++) {
        counts[hand[i] % 13]++;
    }
    for (int i = 0; i < 13; i++) {
        if (counts[i] == 3) return 1;
    }
    return 0;
}

int proveriCetiri(int hand[5]) {
    int counts[13] = {0};
    for (int i = 0; i < 5; i++) {
        counts[hand[i] % 13]++;
    }
    for (int i = 0; i < 13; i++) {
        if (counts[i] == 4) return 1;
    }
    return 0;
}

int proveriBoja(int hand[5], int wDeck[4][13]) {
    int color = hand[0] / 13;  // Determine color from the first card
    for (int i = 1; i < 5; i++) {
        if (hand[i] / 13 != color) return 0;
    }
    return 1;
}

int proveriKenta(int hand[5], int wDeck[4][13]) {
    int values[5];
    for (int i = 0; i < 5; i++) {
        values[i] = hand[i] % 13;
    }
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (values[i] > values[j]) {
                int temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        if (values[i] + 1 != values[i + 1]) return 0;
    }
    return proveriBoja(hand, wDeck);
}
