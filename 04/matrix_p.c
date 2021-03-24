#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

# define N 3

float a[N][N];
float b[N][N];
float c[N][N];


struct mat_pos {
    int i;
    int j;
}

void *matrix_multiplication_part(void *input){
    int i = ((struct mat_pos*)input)->i;
    int j = ((struct mat_pos*)input)->j;
    int k;
    for (k = 0; k < N; k++){
        c[i][j] += a[i][k] * b[k][j];
    }
}

int main(int argc, char *argv[])
{
    int i, j, k, t;

    pthread_t threads[N][N];

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
            struct mat_pos *p = (struct mat_pos *)malloc(sizeof(struct mat_pos));
            p->i = i;
            p->j = j;
            pthread_create(&threads[i][j], NULL, matrix_multiplication_part, (void*)p);
        }
    }

    // Matrix multiplication
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            pthread_join(&threads[i][j], NULL);
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
