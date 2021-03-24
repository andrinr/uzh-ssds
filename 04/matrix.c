#include <stdio.h>
#include <stdlib.h>
#include <time.h>

# define N 3

float a[N][N];
float b[N][N];
float c[N][N];

int main(int argc, char *argv[])
{
    int i, j, k, t;

    clock_t start, end;

    puts("MM Sequential");

    printf("Input Matrix A_\n");
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            scanf("%f", &a[i][j]);
        }
    }
             
    printf("Input Matrix B \n");
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            scanf("%f", &b[i][j]); 
        }
    }

    start = clock();

    // Matrix multiplication
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            c[i][j] = 0.0;
            for (k = 0; k < N; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    end = clock();
    t = end - start;

    printf("Answer Matrix C:\n");
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            printf("%3f ", c[i][j]);
        }
        printf("\n");
    }

    printf("Elapsed time: %d microsecs \n", t);
    return 0;
}