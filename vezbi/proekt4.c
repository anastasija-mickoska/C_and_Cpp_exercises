#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXEMPLOYEES 50

typedef struct vraboten {
    int ID;
    char ime[20];
    char prezime[20];
    int vozrast;
    char pol;
    char brachnaSostojba[20];
    int kredibilnost;
    char adresa[50];
    int tekovnaPlata;
    int poraneshnaPlata;
} vraboten;

void sort_kred(vraboten niza[], int n) {
    vraboten temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (niza[i].kredibilnost > niza[j].kredibilnost) {
                temp = niza[i];
                niza[i] = niza[j];
                niza[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Ime: %s, Prezime: %s, Kredibilnost: %d, Tekovna Plata: %d\n",
               niza[i].ID, niza[i].ime, niza[i].prezime, niza[i].kredibilnost, niza[i].tekovnaPlata);
    }
}

void sort_tekovnaPlata(vraboten niza[], int n) {
    vraboten temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (niza[i].tekovnaPlata > niza[j].tekovnaPlata) {
                temp = niza[i];
                niza[i] = niza[j];
                niza[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Ime: %s, Prezime: %s, Kredibilnost: %d, Tekovna Plata: %d\n",
               niza[i].ID, niza[i].ime, niza[i].prezime, niza[i].kredibilnost, niza[i].tekovnaPlata);
    }
}

void sort_minataPlata(vraboten niza[], int n) {
    vraboten temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (niza[i].poraneshnaPlata > niza[j].poraneshnaPlata) {
                temp = niza[i];
                niza[i] = niza[j];
                niza[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Ime: %s, Prezime: %s, Kredibilnost: %d, Tekovna Plata: %d\n",
               niza[i].ID, niza[i].ime, niza[i].prezime, niza[i].kredibilnost, niza[i].tekovnaPlata);
    }
}

void koregiraj_vraboten(vraboten vraboteni[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (vraboteni[i].ID == id) {
            printf("Vraboten so ID %d najden. Vnesi gi novite podatoci.\n", id);
            printf("Novo ime: ");
            scanf("%s", vraboteni[i].ime);
            printf("Novo prezime: ");
            scanf("%s", vraboteni[i].prezime);
            printf("Nova vozrast: ");
            scanf("%d", &vraboteni[i].vozrast);
            printf("Nova brachna sostojba: ");
            scanf("%s", vraboteni[i].brachnaSostojba);
            printf("Nova kredibilnost: ");
            scanf("%d", &vraboteni[i].kredibilnost);
            printf("Nova adresa: ");
            scanf("%s", vraboteni[i].adresa);
            printf("Podatocite bea uspesno izmeneti.\n");
            return;
        }
    }
    printf("Vrabotenot so ID %d ne e najden.\n", id);
}

void koregiraj_kredibilnost(vraboten vr[], int n) {
    for (int i = 0; i < n; i++) {
        if (vr[i].tekovnaPlata > vr[i].poraneshnaPlata) {
            vr[i].kredibilnost += 3;
            vr[i].tekovnaPlata = vr[i].poraneshnaPlata;
        } else if (vr[i].tekovnaPlata < vr[i].poraneshnaPlata) {
            vr[i].kredibilnost -= 3;
            vr[i].poraneshnaPlata = vr[i].tekovnaPlata;
        }
    }
}

int main() {
    vraboten vraboteni[MAXEMPLOYEES];
    int n;
    int izbor;
    int id;

    printf("Vnesi broj na vraboteni: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        vraboteni[i].ID = i + 1;
        printf("Vnesi ime: ");
        scanf("%s", vraboteni[i].ime);
        printf("Vnesi prezime: ");
        scanf("%s", vraboteni[i].prezime);
        printf("Vnesi vozrast: ");
        scanf("%d", &vraboteni[i].vozrast);
        do {
            printf("Vnesi pol (m/z): ");
            scanf(" %c", &vraboteni[i].pol);
        } while (vraboteni[i].pol != 'm' && vraboteni[i].pol != 'z');
        printf("Vnesi brachna sostojba: ");
        scanf("%s", vraboteni[i].brachnaSostojba);
        printf("Vnesi kredibilnost: ");
        scanf("%d", &vraboteni[i].kredibilnost);
        printf("Vnesi adresa: ");
        scanf("%s", vraboteni[i].adresa);
        printf("Vnesi tekovna plata: ");
        scanf("%d", &vraboteni[i].tekovnaPlata);
        printf("Vnesi poraneshna plata: ");
        scanf("%d", &vraboteni[i].poraneshnaPlata);
    }

    printf("Odberi broj od menito za slednite funkcii (1-5).\n");
    printf("1) Koregiraj vraboten.\n");
    printf("2) Koregiraj kredibilnost.\n");
    printf("3) Sortiraj po kredibilnost.\n");
    printf("4) Sortiraj po tekovna plata.\n");
    printf("5) Sortiraj po poraneshna plata.\n");
    scanf("%d", &izbor);

    switch (izbor) {
    case 1:
        printf("Vnesi ID na vraboten za korekcija: ");
        scanf("%d", &id);
        koregiraj_vraboten(vraboteni, n, id);
        break;
    case 2:
        koregiraj_kredibilnost(vraboteni, n);
        break;
    case 3:
        sort_kred(vraboteni, n);
        break;
    case 4:
        sort_tekovnaPlata(vraboteni, n);
        break;
    case 5:
        sort_minataPlata(vraboteni, n);
        break;
    default:
        printf("Greshka! Birajte povtorno.\n");
    }
    return 0;
}
