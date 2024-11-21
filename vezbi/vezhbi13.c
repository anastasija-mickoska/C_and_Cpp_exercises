#include <stdio.h>
#include <stdlib.h>

//zadaca 1
typedef struct ListNode {
    int broj;
    char karakter;
    struct ListNode* next;
} ListNode;

//za zadaca 2
typedef struct ListNode1 {
    int broj;
    struct ListNode1* next;
} ListNode1;

ListNode* kreirajJazol(int broj, char karakter) {
    ListNode* new = (ListNode*)malloc(sizeof(ListNode));
    if (!new) {
        printf("Error!\n");
        exit(1);
    }
    new->broj = broj;
    new->karakter = karakter;
    new->next = NULL;
    return new;
}

void pecatiLista(ListNode* head) {
    if (head == NULL) {
        return;
    }
    pecatiLista(head->next);
    printf("%d %c\n", head->broj, head->karakter);
}

void dodadi(ListNode** head, int broj, char karakter) {
    ListNode* new = kreirajJazol(broj, karakter);
    if (*head == NULL) {
        *head = new; //ako listata e prazna, znaci ovoj jazol kje bide head jazol
        return;
    }
    ListNode* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next; //stignuvame do posledniot jazol
    }
    temp->next = new; //na kraj go dodavame noviot jazol
}

//zadaca 2

ListNode1* kreirajJazol1(int broj) {
    ListNode1* new = (ListNode1*)malloc(sizeof(ListNode1));
    if (!new) {
        printf("Error!\n");
        exit(1);
    }
    new->broj = broj;
    new->next = NULL;
    return new;
}

ListNode1* kreirajJazol1(int broj) {
    ListNode1* new = (ListNode1*)malloc(sizeof(ListNode1));
    if (!new) {
        printf("Error!\n");
        exit(1);
    }
    new->broj = broj;
    new->next = NULL;
    return new;
}
void vnesi(ListNode1** head, int broj) {
    ListNode1* new = kreirajJazol1(broj);
    if (*head == NULL) {
        *head = new; //ako listata e prazna, znaci ovoj jazol kje bide head jazol
        return;
    }
    ListNode1* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next; //stignuvame do posledniot jazol
    }
    temp->next = new; //na kraj go dodavame noviot jazol
}

void sortOpagjanje(ListNode1** head) {
    ListNode1* temp=*head;
    ListNode1* temp1;
    if (*head == NULL) return;
    while(temp!= NULL) {
        ListNode1* temp2 = temp->next;
        while(temp2 != NULL) {
            if(temp->broj < temp2->broj) {
                int pom=temp->broj;
                temp->broj = temp2->broj;
                temp2->broj=pom;
            }
            temp2=temp2->next;
        }
        temp=temp->next;
    }
    temp=*head;
    while(temp!= NULL) {
        printf("%d,", temp->broj);
        temp=temp->next;
    }
}
void sortRastenje(ListNode1** head) {
    ListNode1* temp=*head;
    ListNode1* temp1;
    if (*head == NULL) return;
    while(temp!= NULL) {
        ListNode1* temp2 = temp->next;
        while(temp2 != NULL) {
            if(temp->broj > temp2->broj) {
                int pom=temp->broj;
                temp->broj = temp2->broj;
                temp2->broj=pom;
            }
            temp2=temp2->next;
        }
        temp=temp->next;
    }
    temp=*head;
    while(temp!= NULL) {
        printf("%d,", temp->broj);
        temp=temp->next;
    }
}

void brisi(ListNode1** head, int br) {
    if (*head == NULL) return;
    ListNode1* temp=*head;
    ListNode1* temp1;
    ListNode1* prev = NULL;

    if (temp != NULL && temp->broj == br) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->broj != br) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

int main() {
    //zadaca 1
    ListNode* lista = NULL;
    char ch='y',b;
    int num;
    while(ch!='n') {
        printf("Vnesete broj i bukva.\n");
        scanf("%d %c", &num, &b);
        dodadi(&lista, num, b);
        fflush(stdout);
        printf("Dali sakate seuste da vnesuvate podatoci? (y/n)\n");
        scanf(" %c",&ch);
    }

    printf("Listata ispecatena nanazad e:\n");
    pecatiLista(lista);

    ListNode* temp;
    while (lista != NULL) { // za da ja oslobodime memorijata
        temp = lista;
        lista = lista->next;
        free(temp);
    }

    //zadaca 2

    ListNode1* lista1 = NULL;
    int n;

    while(ch!='n') {
        printf("Vnesete broj.\n");
        scanf("%d", &num);
        vnesi(&lista1, num);
        fflush(stdout);
        printf("Dali sakate seuste da vnesuvate podatoci? (y/n)\n");
        scanf(" %c",&ch);
    }

    printf("Listata vo opagjacki redosled e:\n");
    sortOpagjanje(&lista1);
    printf("Listata vo rastechki redosled e:\n");
    sortRastenje(&lista1);

    printf("Vnesi broj za brishenje.\n");
    scanf("%d", &num);
    brisi(&lista1, num);

    printf("Listata posle brisenje e:\n");
    ListNode1* temp = lista1;
    while (temp != NULL) {
        printf("%d ", temp->broj);
        temp = temp->next;
    }
    printf("\n");

    while (lista1 != NULL) {
        temp = lista1;
        lista1 = lista1->next;
        free(temp);
    }

    return 0;
}
