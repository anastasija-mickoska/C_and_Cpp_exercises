#include <stdio.h>

//zadaca 2
void prosti(int arr[], int n) {
    int t[n];
    for(int i=0;i<n;i++) {
        t[i]=1;
    }
    arr[0] = arr[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (i % 2==0) {
            t[i]=0;
            break;
        }
    }
    for(int i=0;i<n;i++) {
        if(t[i]==1) {
            arr[i]=0;
            printf("%d,",i);
        }
    }
}

//zadaca 3
void palindrom(char arr) {
    int t=1;
    for(int i=0;i<(strlen(arr)+1)/2;i++) {
        if(arr[i] != arr[strlen(arr)-i]) {
            printf("Ne e palindrom!\n");
            t=0;
            break;
        }
    }
    if(t) {
        printf("Palindrom!\n");
    }
}

//zadaca 4

void vnesiMatrica(int m[][], int a, int b) {
    for(int i=0;i<a;i++) {
        for(int j=0;j<b;j++) {
            scanf("%d", &m[i][j]);
        }
    }
}

void pechatiMatrica(int m[][], int a, int b) {
    for(int i=0;i<a;i++) {
        for(int j=0;j<b;j++) {
            printf("%d", m[i][j]);
        }
        printf("\n");
    }
}

void vnesiMatrica1(int m[][], int a, int b, int i, int j) {
    if (i == a) {
    }
    if (j == b) {
        vnesiMatrica1(m, a, b, i + 1, 0);
        return;
    }
    scanf("%d", &m[i][j]);
    vnesiMatrica1(m, a, b, i, j + 1);
}

void pechatiMatrica1(int m[][], int a, int b, int i, int j) {
    if (i == a) {
    }
    if (j == b) {
        pechatiMatrica1(m, a, b, i + 1, 0);
        return;
    }
    scanf("%d", &m[i][j]);
    pechatiMatrica1(m, a, b, i, j + 1);
}

//zadaca 5

void selekcija(int arr[], int n) {
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void selekcijaR(int arr[], int n, int start) {
    if (start == n - 1)
        return;

    int min = start;
    for (int i = start + 1; i < n; i++) {
        if (arr[i] < arr[min]) {
            min = i;
        }
    }
    if (min != start) {
        int temp = arr[start];
        arr[start] = arr[min];
        arr[min] = temp;
    }
    selekcijaR(arr, n, start + 1);
}

int main() {
    //zadaca 1

    int month;
    int days, temp_sum;
    int temp[31];

    printf("Month:");
    scanf("%d", &month);

    switch(month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    {
        days=31;
        break;
    }
    case 2:
    {
        days=28;
    }
    case 4:
    case 6:
    case 9:
    case 11:
    {
        days=30;
        break;
    }
    default: printf("Greshka!");
    }

    for(int i=0;i<days;i++) {
        scanf("%d", temp[i]);
        temp_sum+=temp[i];
    }
    printf("Average month temperature: %f\n", (float)temp_sum / days);

    //zadaca 2

    int n;
    int array[]={};
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        array[i]=1;
    }
    prosti(array,n);

    //zadaca 3

    char niza[20];
    scanf("%c", niza);
    palindrom(niza);

    return 0;
}
