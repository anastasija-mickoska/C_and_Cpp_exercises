#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//zadaca 14 ???
void printIncreasing(int current, int n) {
    if (current > n) {
        return;
    }
    for (int i = current; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");

    printIncreasing(current + 1, n);
}
void printDecreasing(int current, int n) {
    if (current < 1) {
        return;
    }
    for (int i = current; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");

    printDecreasing(current - 1, n);
}
int main() {
    //1.	Да се најде обиколката и плоштината на правилен n-аголник.

    int n,a;
    int L;
    float P;
    scanf("%d %d", &n, &a);
    L=n*a;
    P=(L*(a/(2*tan(3.14/n))))/2;
    printf("Plostina: %f", P);
    printf("Perimetar: %d", L);

    //2.	Да се реши систем од три равенки со три непознати.
    //resenijata se baraat vo opseg od -100 do 100
    int x,y,z;
    for( x=-100; x<100;x++) {
        for(y=-100; y<100;y++) {
            for(z=-100;z<100;z++) {
                if((x+y+z == 3) && (2*x*x + 3*y*z == 10) && (2*x*y - 3*z == -2)) {
                    printf("{%d %d %d}\n", x,y,z);
                }
            }
        }
    }

    //3.Да се најде спротивен број на природниот број n. (Тоа е природниот број што ги има истите цифри со n, напишани во спротивен редослед.)
    int n1;
    int sprotiven=0;
    scanf("%d", &n1);
    while(n1!=0) {
        sprotiven+=n1%10;
        n1/=10;
        if(n1!=0) {
            sprotiven*=10;
        }
    }
    printf("Sprotiven broj na %d e %d\n", n1, sprotiven);

    //4.	Да се најдат совршените броеви помали од природниот број n.

    int n2;
    int sum;
    scanf("%d",&n2);
    for(int i=n2;i>0;i--) {
        sum=0;
        for(int j=1;j<i;j++) {
            if(i % j ==0) {
                sum+=j;
            }
        }
        if(sum == i) {
            printf("%d e sovrsen broj.\n", i);
        }
    }

    //5.Да се претстави природниот број n како производ од прости множители.
    //(n=p1^k1+p2^k2...+pr^kr , каде што p1, p2, ..., pr се прости броеви, а k1, k2, . . . , kr се природни броеви.)
        int n3;
        scanf("%d",&n3);
        int count = 0;
        while (n3 % 2 == 0) {
            count++;
            n3 /= 2;
        }
        if (count > 0) {
            printf("2^%d", count);
            if (n3 > 1) printf(" * ");
        }
        for (int i = 3; i * i <= n3; i += 2) {
            count = 0;
            while (n3 % i == 0) {
                count++;
                n3 /= i;
            }
            if (count > 0) {
                printf("%d^%d", i, count);
                if (n3 > 1) printf(" * ");
            }
        }
        if (n > 2) {
            printf("%d^1", n);
        }

        printf("\n");

    //6.	Да се најдат природните броеви помали од n, чиј збир на кубовите на цифри-те е еднаков на самиот број.
        int n4;
        int sum;
        scanf("%d",&n4);
        for(int i=n4;i>0;i--) {
            int pom=i;
            sum=0;
            while(pom!=0) {
                sum+=(pom%10)*(pom%10)*(pom%10);
                pom/=10;
            }
            if(sum == i) {
                printf("%d go ispolnuva uslovot.\n", i);
            }
        }
    //7.	Да се најдат природните броеви во интервалот [n1,n2], кои се деливи со сво-јот спротивен број.
        int n5,n6;
        int sprotiven1;
        scanf("%d %d", &n5, &n6);
        for(int i=n5;i<n6;i++) {
            sprotiven1=0;
            int pom=i;
            while(pom!=0) {
                sprotiven1 += pom %10;
                pom/=10;
                if(pom!=0) {
                    sprotiven1 *= 10;
                }
            }
            if(i % sprotiven1 == 0) {
                printf("%d go ispolnuva uslovot.\n", i);
            }
        }

    //8.Да се најдат природните броеви чиј квадрат и куб (заедно) ги содржат сите цифри 0,1, 2, .. , 9 по еднаш.
            int n7 = 0;
            while (n7 < 1000) {
                int sum1 = n7 * n7;
                int sum2 = n7 * n7 * n7;
                int digits[10] = {0};
                int j = 0;
                int isUnique = 1;

                int pom1 = sum1;
                while (pom1 != 0) {
                    int digit = pom1 % 10;
                    if (digits[digit]) {
                        isUnique = 0;
                        break;
                    }
                    digits[digit] = 1;
                    j++;
                    pom1 /= 10;
                }

                int pom2 = sum2;
                if (isUnique) {
                    while (pom2 != 0) {
                        int digit = pom2 % 10;
                        if (digits[digit]) {
                            isUnique = 0;
                            break;
                        }
                        digits[digit] = 1;
                        j++;
                        pom2 /= 10;
                    }
                }

                if (isUnique && j == 10) {
                    printf("%d ги задоволува условите\n", n7);
                }

                n7++;
            }

    //9.Секоја од n бактерии се дели на две на секои i минути,
    //додека на секои j минути изумираат x% од живите бактерии во тој момент. Колку бактерии ќе има по k минути?

            int n8, x1;
            int j1,k1,i1;

            scanf("%d %d %d %d %d", &n8, &i1, &j1, &x1,&k1);

            int b = n8;
            for (int t = 1; t <= k1; t++) {
                if (t % i1 == 0) {
                    b *= 2;
                }
                if (t % j1 == 0) {
                    b -= (int)(b * (x1 / 100));
                }
            }

            printf("Po %d minuti ima %d bakterii.\n", k1, b);

    //10.	Да се најдат сите растечки поднизи во низата броеви [ai]n. (Растечка подни¬за е онаа во која секој елемент е поголем од претходниот.)
            int n;
            scanf("%d", &n);
            int array[n];
            for (int i = 0; i < n; i++) {
                scanf("%d", &array[i]);
            }
            printf("Rastecki podnizi:\n");
            for (int i = 0; i < n; i++) {
                int start = i;
                while (i < n - 1 && array[i] < array[i + 1]) {
                    i++;
                }
                if (i > start) {
                    for (int j = start; j <= i; j++) {
                        printf("%d ", array[j]);
                    }
                    printf("\n");
                }
            }

    //11.	Да се најдат сите пилести поднизи во низата броеви [ai]n.
    //      (Пилеста подни¬за е онаа во која претходниот и следниот елемент на секој елемент се по¬мали (поголеми) од него.)

            int n;
            scanf("%d", &n);
            int array[n];
            for (int i = 0; i < n; i++) {
                scanf("%d", &array[i]);
            }
            printf("[Pilesti podnizi:\n");
            for (int i = 1; i < n; i++) {
                int start = i;
                while ((i < n - 1 && array[i] < array[i + 1] && array[i-1] > array[i]) || (i < n - 1 && array[i] > array[i + 1] && array[i-1] < array[i])) {
                    i++;
                }
                if (i > start) {
                    for (int j = start; j <= i; j++) {
                        printf("%d ", array[j]);
                    }
                    printf("\n");
                }
            }

    //12.	Да се внесат два полинома со степени n m соодветно. Да се внесат нивните коефициенти и да се најде нивниот збир.
            int N, M, R;

            scanf("%d %d", &N, &M);
            N++;
            M++;

            int p1[N], p2[M], z[R];

            printf("Vnesi go prviot polinom:\n");
            for (int i = N-1; i >=0 ; i--) {
                scanf("%d", &p1[i]);
            }

            printf("Vnesi go vtoriot polinom:\n");
            for (int i = M-1; i >= 0; i--) {
                scanf("%d", &p2[i]);
            }

            R = (N > M) ? N : M;

            for (int i = 0; i < R; i++) {
                if (i < N && i < M) {
                    z[i] = p1[i] + p2[i];
                } else if (i < N) {
                    z[i] = p1[i];
                } else {
                    z[i] = p2[i];
                }
            }
            printf("Zbir na polinomite:\n");
            for (int i = R-1; i >= 0; i--) {
                printf("%d ", z[i]);
            }
    //13.	Да се генерираат следниве дводимензионални полиња со m-редици и n-колони.

            int m,n;
            scanf("%d %d", &m, &n);
            int matrix[m][n];
            int current = 1;
            for (int j = 0; j < n; j++) {
                if (j % 2 == 0) {
                    for (int i = 0; i < m; i++) {
                        matrix[i][j] = current++;
                    }
                } else {
                    for (int i = m - 1; i >= 0; i--) {
                        matrix[i][j] = current++;
                    }
                }
            }
            for(int i=0;i<m;i++) {
                for(int j=0;j<n;j++) {
                    printf("%d ",matrix[i][j]);
                }
                printf("\n");
            }
    //14.	За даден природен број n да се испечатат следниве фигури со користење на рекурзија.
            // n
            // n-1 n
            // n-2 n-1 n
            // ...
            // 1 2 3 ... n-2 n-1 n
            // ...
            // n-2 n-1 n
            // n-1 n
            // n
            int n;
            printf("Enter the number: ");
            scanf("%d", &n);

            printIncreasing(n, n);

            printDecreasing(n - 1, n);

}
