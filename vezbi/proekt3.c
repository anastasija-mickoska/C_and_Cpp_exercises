#include <stdio.h>
#include <stdlib.h>

#define MAXSTUDENTS 100
#define OCENI 5

void pecatiNiza(int oceni[][5], int studenti);
void max(int oceni[][5], int studenti);
void min(int oceni[][5], int studenti);
void prosek(int oceni[][5], int studenti);


int main() {
    int numStudents, izbor;
    scanf("%d", &numStudents);

    int oceni[MAXSTUDENTS][OCENI];

    for(int i=0;i<numStudents;i++ ){
        for(int j=0;j<OCENI;j++) {
            oceni[i][j]=rand() % 6 + 5; //se popolnuva matricata so ocenki
        }
    }

    void (*izborMeni[])(int [][OCENI], int) = { pecatiNiza, max, min, prosek};
    while(1) {
        scanf("Odberi broj od korisnickoto meni. (0-4)\n");
        printf("0) Ispechati ja nizata so oceni\n");
        printf("1) Najdi ja maksimalnata ocena\n");
        printf("2) Najdi ja minimalnata ocena\n");
        printf("3) Ispecati ja prosechnata ocena za sekoja student\n");
        printf("4) Kraj\n");
        printf("Izbor: ");
        scanf("%d" , &izbor);

        if(izbor == 4) {
            printf("Kraj na programata.\n");
        }
        else if(izbor <= 0 && izbor >= 3) {
            printf("Greshka! Obidete se povtorno.\n");
        }
        else {
            (*izborMeni[izbor])(oceni, numStudents);
        }
    }

    return 0;
}

void pecatiNiza(int oceni[][OCENI], int studenti) {
    printf("Matricata so oceni:\n");
    for(int i=0;i<studenti;i++ ){
        for(int j=0;j<OCENI;j++) {
            printf("%d ",oceni[i][j]);
        }
        printf("\n");
    }
}
void max(int oceni[][5], int studenti) {
    int maximum=oceni[0][0];
    for(int i=0;i<studenti;i++ ){
        for(int j=0;j<OCENI;j++) {
            if(oceni[i][j] >maximum) {
                maximum=oceni[i][j];
            }
        }
    }
    printf("Maksimalnata ocena e:%d\n", maximum);
}
void min(int oceni[][5], int studenti) {
    int minimum=oceni[0][0];
    for(int i=0;i<studenti;i++ ){
        for(int j=0;j<OCENI;j++) {
            if(oceni[i][j] < minimum) {
                minimum=oceni[i][j];
            }
        }
    }
    printf("Minimalnata ocena e:%d\n", minimum);
}
void prosek(int oceni[][5], int studenti) {
    for(int i=0;i<studenti;i++) {
        int sum=0;
        for(int j=0;j<OCENI;j++) {
            sum+=oceni[i][j];
        }
        printf("Prosek za student %d e %f\n", i, (float)sum/OCENI);
    }
}
