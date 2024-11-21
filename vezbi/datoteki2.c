#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char* cifriBroevi[] = {
    "YZ", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQR", "STU", "VWX"
};

void generirajBroj(char string[]) {
    char mapa[26] = {'2', '2', '2',   // A, B, C -> 2
                     '3', '3', '3',   // D, E, F -> 3
                     '4', '4', '4',   // G, H, I -> 4
                     '5', '5', '5',   // J, K, L -> 5
                     '6', '6', '6',   // M, N, O -> 6
                     '7', '7', '7',   // P, Q, R -> 7
                     '8', '8', '8',   // S, T, U -> 8
                     '9', '9', '9',   // V, W, X -> 9
                     '0', '0', '0'};  // Y, Z -> 0

    for (int i = 0; i < strlen(string); i++) {
        char bukva = toupper(string[i]);
        if (bukva >= 'A' && bukva <= 'Z') {
            printf("%c", mapa[bukva - 'A']);
        } else {
            printf("Greshka! Obidete se povtorno.\n");
            return;
        }
    }
    printf("\n");
}

void generirajKombinacii(int num[], char res[], int i, int n) {
    if (i == n) {
        res[i] = '\0';
        printf("%s\n", res);
        return;
    }

    const char* bukvi = cifriBroevi[num[i]];
    for (int j = 0; bukvi[j] != '\0'; j++) {
        res[i] = bukvi[j];
        generirajKombinacii(num, res, i + 1, n);
    }
}

int main() {
    char string[8];
    int num;
    int cifri[7];
    char rezultat[8];

    printf("Vnesi broj.\n");
    scanf("%d", &num);

    int i = 6;
    while (num != 0) {
        cifri[i] = num % 10;
        num /= 10;
        i--;
    }

    printf("Vnesi sedumbukven string.\n");
    scanf("%s", string);
    printf("\n");

    generirajKombinacii(cifri, rezultat, 0, 7);

    generirajBroj(string);

    return 0;
}
