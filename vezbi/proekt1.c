#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    int temp;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(arr[i] < arr[j]) {
                arr[i]=temp;
                temp=arr[j];
                arr[j]=arr[i];
            }
        }
    }
    printf("Sortirana niza:\n");
    for(int i=0;i<n;i++) {
        printf("%d", arr[i]);
    }
}

float srednaVrednost(int arr[], int n) {
    float sr=0.0;
    int sum;
    for(int i=0;i<n;i++) {
        sum+=arr[i];
    }
    sr=(float)sum/n;
    return sr;
}

float medijana(int arr[], int n) {
    int m;
    if(n%2==0) { //paren broj na elementi
        m= (arr[n/2]+ arr[n/2 +1])/2;
    }
    else {
        m=arr[(n+1)/2];
    }
    return m;
}

int najfrekventnaVrednost(int arr[],int n) {
    int poseteni[n];
    int najfrekventen = arr[0];
    int brojach = 0;

    printf("Pojavuvanja na sekoj element:");

    for (int i = 0; i < n; i++) {
        if (poseteni[i] == 1)
            continue;
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                poseteni[j] = 1;
            }
        }
        printf(" %d , %d pojavuvanja " ,arr[i], count);

        if (count > brojach) {
            brojach = count;
            najfrekventen = arr[i];
        }
    }
    return najfrekventen;
}


void histogram(int arr[], int n) {
    int i, j;
    printf( "%s%13s%17s\n", "Element", "Vrednost", "Histogram" );
    for ( i = 0; i < n; i++ ) {
        printf( "%7d%13d        ", i, arr[ i ]) ;
        for ( j = 1; j <= arr[ i ]; j++ ) {
            printf( "%c", '*' );
        }
        printf( "\n" );
    }
}

int main() {
    int array[100];
    int n;
    printf("Vnesi go brojot na elementi.\n");
    do {
        scanf("%d", &n);
    }while(n>100);
    for(int i=0;i<n;i++) {
        array[i]=rand() % 20;
    }
    sort(array, n);
    printf("Sredna vrednost: %f\n", srednaVrednost(array,n));
    printf("Medijana: %f\n", medijana(array,n));
    printf("Najfrekventna vrednost: %d\n", najfrekventnaVrednost(array,n));
    printf("Histogram\n");
    histogram(array,n);


}
