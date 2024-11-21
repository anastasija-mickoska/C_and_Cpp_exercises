#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int kod;
    char ime[30];
    int kolicina;
    float cena;
} hardware;

void listajProizvod(FILE *fptr, int code) {
    rewind(fptr);
    hardware temp;
    int t = 0;

    while (fread(&temp, sizeof(hardware), 1, fptr)) {
        if (temp.kod == code) {
            printf("Proizvod so kod %d\n", code);
            printf("Ime: %s\n", temp.ime);
            printf("Kolicina: %d\n", temp.kolicina);
            printf("Cena: %.2f\n", temp.cena);
            t = 1;
            break;
        }
    }
    if (!t) {
        printf("Proizvodot so ovoj kod ne e pronajden.\n");
    }
}

void listing(FILE *fptr) {
    rewind(fptr);
    hardware temp;

    printf("Listing na sostojba vo prodavnicata:\n");
    while (fread(&temp, sizeof(hardware), 1, fptr)) {
        printf("Kod: %d, Ime: %s, Kolicina: %d, Cena: %.2f\n",
               temp.kod, temp.ime, temp.kolicina, temp.cena);
    }
}

void brishi(FILE *fptr) {
    rewind(fptr);
    hardware temp, prazen = {0, "", 0, 0.0};

    while (fread(&temp, sizeof(hardware), 1, fptr)) {
        if (temp.kolicina == 0) {
            fseek(fptr, -sizeof(hardware), SEEK_CUR);
            fwrite(&prazen, sizeof(hardware), 1, fptr);
            printf("Proizvodot so kod %d e izbrisan.\n", temp.kod);
            break;
        }
    }
}

void azuriraj(FILE *fptr, int code) {
    hardware nov;
    int t = 0;
    rewind(fptr);

    while (fread(&nov, sizeof(hardware), 1, fptr) == 1) {
        if (nov.kod == code) {
            printf("Vnesi novi podatoci za proizvodot.\n");
            printf("Vnesi ime:\n");
            scanf("%s", nov.ime);
            printf("Vnesi kolicina:\n");
            scanf("%d", &nov.kolicina);
            printf("Vnesi cena:\n");
            scanf("%f", &nov.cena);

            fseek(fptr, -sizeof(hardware), SEEK_CUR);
            fwrite(&nov, sizeof(hardware), 1, fptr);
            fflush(fptr);
            t = 1;
            printf("Proizvodot so kod %d e azuriran.\n", code);
            break;
        }
    }

    if (!t) {
        printf("Proizvodot so kod %d ne postoi.\n", code);
    }
}

void prodazba(FILE *fptr, int code, int quantity) {
    hardware nov;
    int t = 0;
    rewind(fptr);

    while (fread(&nov, sizeof(hardware), 1, fptr) == 1) {
        if (nov.kod == code) {
            t = 1;
            if (nov.kolicina < quantity) {
                printf("Nema dovolno kolicina od ovoj proizvod.\n");
                return;
            }

            nov.kolicina -= quantity;
            fseek(fptr, -sizeof(hardware), SEEK_CUR);
            fwrite(&nov, sizeof(hardware), 1, fptr);
            fflush(fptr);

            printf("Prodazbata e uspeshna. Kolicinata e namalena.\n");
            break;
        }
    }

    if (!t) {
        printf("Proizvodot so kod %d ne postoi.\n", code);
    }
}

int main() {
    hardware elementi[4] = {};
    FILE *fptr;
    int izbor;

    fptr = fopen("hardware.txt", "w");
    if (fptr == NULL) {
        perror("Datotekata ne moze da se otvori");
        return 1;
    }

    for (int i = 0; i < 4; i++) {
        printf("Vnesi kod na proizvodot: ");
        scanf("%d", &elementi[i].kod);

        printf("Vnesi ime na proizvodot: ");
        scanf("%s", elementi[i].ime);

        printf("Vnesi kolicina na proizvodot: ");
        scanf("%d", &elementi[i].kolicina);

        printf("Vnesi cena na proizvodot: ");
        scanf("%f", &elementi[i].cena);

        printf("Zapishuvanje: Kod:%d\n Ime:%s\n Kolicina:%d\n Cena:%.2f\n", elementi[i].kod, elementi[i].ime, elementi[i].kolicina, elementi[i].cena);

       fprintf(fptr, "%d\n %s\n %d\n %f\n", elementi[i].kod, elementi[i].ime, elementi[i].kolicina, elementi[i].cena);
        fflush(fptr);
    }
    fclose(fptr);
    printf("Podatocite se zapishani vo datotekata.\n");

    fptr = fopen("hardware.txt", "r+");
    if (fptr == NULL) {
        printf("Datotekata ne moze da se otvori.\n");
        return 1;
    }

    while (1) {
        printf("Izberete od korisnicko meni (1-5)\n");
        printf("1) Listaj podatoci za proizvod.\n");
        printf("2) Listing na sostojba vo prodavnicata.\n");
        printf("3) Izbrisi podatoci za proizvodi cija kolicina e 0.\n");
        printf("4) Azuriraj podatoci za proizvod.\n");
        printf("5) Prodazba\n");

        scanf("%d", &izbor);
        switch (izbor) {
        case 1: {
            int code;
            printf("Vnesete go kodot na proizvodot.\n");
            scanf("%d", &code);
            listajProizvod(fptr, code);
            break;
        }
        case 2: {
            listing(fptr);
            break;
        }
        case 3: {
            brishi(fptr);
            break;
        }
        case 4: {
            int code;
            printf("Vnesete go kodot na proizvodot.\n");
            scanf("%d", &code);
            azuriraj(fptr, code);
            break;
        }
        case 5: {
            int quantity, code;
            printf("Vnesi go kodot na proizvodot.\n");
            scanf("%d", &code);
            printf("Vnesi ja baranata kolicina:\n");
            scanf("%d", &quantity);
            prodazba(fptr, code, quantity);
            break;
        }
        default: {
            printf("Greshka! Obidete se povtorno.\n");
            break;
        }
        }
    }

    fclose(fptr);
    return 0;
}
