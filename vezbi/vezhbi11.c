#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//zadaca 3

const char *morseCode[] = {
    ".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",  "....", "..",   // A-I
    ".---", "-.-",  ".-..", "--",   "-.",   "---",  ".--.", "--.-", ".-.",  // J-R
    "...",  "-",    "..-",  "...-", ".--",  "-..-", "-.--", "--..",          // S-Z
    "-----", ".----", "..---", "...--", "....-", // 0-4
    ".....", "-....", "--...", "---..", "----."  // 5-9
};

const char* MorseCodeToText(char character) {
    if (character >= 'A' && character <= 'Z') {
        return morseCode[character - 'A'];
    } else if (character >= '0' && character <= '9') {
        return morseCode[26 + (character - '0')];
    } else {
        return "";
    }
}

int main() {
    //zadaca 1
    char number[30];
    char *delovi;
    int prefix;
    long phoneNum;
    char phone[20] = "";

    printf("Vnesi go brojot vo format (333) 333-3333:\n");
    scanf("%s", number);
    delovi = strtok(number, " ()-");
    if (delovi != NULL) {
        prefix = atoi(delovi);
    }
    while ((delovi = strtok(NULL, " )-")) != NULL) {
        strcat(phone, delovi);
    }
    phoneNum = atol(phone);
    printf("Kod na drzava: %d\n", prefix);
    printf("Telefonski broj: %ld\n", phoneNum);


    //zadaca 2
    char datum[30];
    char *date;
    char den[5], mesec[10], godina[5];

    while (1) {
        printf("Vnesi datum vo oblik dd/mm/yyyy.\n");
        scanf("%s", datum);
        date = strtok(datum, "/");
        if (date != NULL) {
            strcpy(den, date);
        }
        date = strtok(NULL, "/");
        if (date != NULL) {
            strcpy(mesec, date);
        }
        date = strtok(NULL, "/");
        if (date != NULL) {
            strcpy(godina, date);
        }

        if (strcmp(mesec, "01") == 0) {
            strcpy(mesec, "Januari");
        } else if (strcmp(mesec, "02") == 0) {
            strcpy(mesec, "Fevruari");
        } else if (strcmp(mesec, "03") == 0) {
            strcpy(mesec, "Mart");
        } else if (strcmp(mesec, "04") == 0) {
            strcpy(mesec, "April");
        } else if (strcmp(mesec, "05") == 0) {
            strcpy(mesec, "Maj");
        } else if (strcmp(mesec, "06") == 0) {
            strcpy(mesec, "Juni");
        } else if (strcmp(mesec, "07") == 0) {
            strcpy(mesec, "Juli");
        } else if (strcmp(mesec, "08") == 0) {
            strcpy(mesec, "Avgust");
        } else if (strcmp(mesec, "09") == 0) {
            strcpy(mesec, "Septemvri");
        } else if (strcmp(mesec, "10") == 0) {
            strcpy(mesec, "Oktomvri");
        } else if (strcmp(mesec, "11") == 0) {
            strcpy(mesec, "Noemvri");
        } else if (strcmp(mesec, "12") == 0) {
            strcpy(mesec, "Dekemvri");
        } else {
            printf("Greshka!\n");
        }
        printf("%s %s %s\n", den, mesec, godina);
    }

    //zadaca 3

    char text[50];

    printf("Vnesi tekst.\n");
    scanf("%s", text);

    printf("Tekstot vo Morzeov kod e:\n");
    for(int i=0;text[i]!='\0';i++) {
        char c = text[i];
        if (c == ' ') {
            printf(" / ");
        } else {
            const char* morse = MorseCodeToText(c);
            printf("%s ", morse);
        }    }


    return 0;
}
