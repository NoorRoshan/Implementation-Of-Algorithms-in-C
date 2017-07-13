//Works for any value of n

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long int ** multiply(long int ** a, long int ** b, long int ** c, int l, int h);
unsigned int checkN(unsigned int n);

int main() {
    long int ** a, ** b, ** c;
    unsigned int n, i, j, k;
    char d = 65;
    FILE * f;

    printf("Enter the dimension for the square matrix A and B \n");
    scanf("%u", &n);

    if(n > 0) {

        f = fopen("Matrix.txt", "w");

        k = n + checkN(n);

        a = (long int **)calloc(k,sizeof(long int));
        b = (long int **)calloc(k,sizeof(long int));
        c = (long int **)calloc(k,sizeof(long int));

        for( i = 0; i < k; i ++ ) {
            a[i] = (long int *)calloc(k, sizeof(long int));
            b[i] = (long int *)calloc(k, sizeof(long int));
            c[i] = (long int *)calloc(k, sizeof(long int));
        }

        printf("Enter the data in the matrix:\n");
        L:
            printf("Matrix %c:\n", d);
            for( i = 0; i < n; i ++ ) {
                for( j = 0; j < n; j ++ ) {
                    printf("%c[%u][%u] = ", d, i, j);
                    if( d == 65 )
                        scanf("%d", &a[i][j]);
                    else
                        scanf("%d", &b[i][j]);
                }
            }
        d = d + 1;
        if( d == 66 ) goto L;
        d = 65;
        c = multiply(a, b, c, 0, k - 1);

        L1:
            printf("\n\n");
            printf("Matrix %c:\n", d);
            for( i = 0; i < n; i ++ ) {
                for( j = 0; j < n; j ++ ) {
                    printf("%c[%u][%u] = ", d, i, j);
                    switch(d){
                        case 65 : printf("%d\t", a[i][j]);
                                fprintf(f, "%c[%u][%u] = %d\t", d, i + 1, j + 1, a[i][j]);
                                break;
                        case 66 : printf("%d\t", b[i][j]);
                                fprintf(f, "%c[%u][%u] = %d\t", d, i + 1, j + 1, b[i][j]);
                                break;
                        case 67 : printf("%d\t", c[i][j]);
                                fprintf(f, "%c[%u][%u] = %d\t", d, i + 1, j + 1, c[i][j]);
                                break;
                    }
                }
                printf("\n");
                fprintf(f, "\n");
            }
            printf("\n\n");
            fprintf(f, "\n\n");
            d = d + 1;
            if( d == 66 || d == 67)   goto L1;

        fclose(f);
        free(a);
        free(b);
        free(c);
    }

    return(0);
}

unsigned int checkN(unsigned int n) {
    unsigned int i = 0;
    for( i = 0; ;i ++ ) {
        if( n <= pow(2, i))
            return(pow(2,i) - n);
    }
}

long int ** multiply(long int ** a, long int ** b, long int ** c, int l, int h) {
    long int ***s, ***p;
    int i, j, k, m, end = floor( (h - l + 1)/2 );

    if( h - l == 0 ) {
        c[l][h] = a[l][h] * b[l][h];
    }

    else {

        s = (long int ***)calloc(14, sizeof(long int));

        for( i = 0; i < 14; i ++ )
            s[i] = (long int **)calloc(end, sizeof(long int));

        for( i = 0; i < 14; i ++ )
            for( j = 0; j < end; j ++ )
                s[i][j] = (long int *)calloc(end, sizeof(long int));

        p = (long int ***)calloc(7, sizeof(long int));

        for( i = 0; i < 7; i ++ )
            p[i] = (long int **)calloc(end, sizeof(long int));

        for( i = 0; i < 7; i ++ )
            for( j = 0; j < end; j ++ )
            p[i][j] = (long int *)calloc(end, sizeof(long int));

        //loop 1 for s1;

        k = end, m = 0;
        for( i = 0; i < end; i ++ ) {
            for( j = 0; j < end; j ++ ) {
                s[0][i][j] = b[m + i][k + j] - b[k + i][k + j];
            }
        }

        //loop 2 for s2;

        for( i = 0; i < end; i ++ ) {
            for( j = 0; j < end; j ++ ) {
                s[1][i][j] = a[m + i][m + j] + a[m + i][k + j];
            }
        }

        //loop 3 for s3;
        for( i = 0; i < end; i ++ ) {
            for( j = 0; j < end; j ++ ) {
                s[2][i][j] = a[k + i][m + j] + a[k + i][k + j];
            }
        }

        //loop4 for s4;

        for( i = 0; i < end; i ++ ) {
            for( j = 0; j < end; j ++ ) {
                s[3][i][j] = b[k + i][m + j] - b[m + i][m + j];
            }
        }

        //loop5 for s5;

        for( i = 0; i < end; i ++ ) {
            for( j = 0; j < end; j ++ ) {
                s[4][i][j] = a[m + i][m + j] + a[k + i][k + j];
            }
        }

        //loop 6 for s6;

        for( i = 0; i < end; i ++ ) {
            for( j = 0; j < end; j ++ ) {
                s[5][i][j] = b[m + i][m + j] + b[k + i][k + j];
            }
        }

        //loop 7 for s7;

        for( i = 0; i < end; i ++ ) {
            for( j = 0; j < end; j ++ ) {
                s[6][i][j] = a[m + i][k + j] - a[k + i][k + j];
            }
        }

        //loop 8 for s8;

        for( i = 0; i < end; i ++ ) {
            for( j = 0; j < end; j ++ ) {
                s[7][i][j] = b[k + i][m + j] + b[k + i][k + j];
            }
        }

        //loop 9 for s9;

        for( i = 0; i < end; i ++ ) {
            for( j = 0; j < end; j ++ ) {
                s[8][i][j] = a[m + i][m + j] - a[k + i][m + j];
            }
        }

        //loop 10 for s10;

        for( i = 0; i < end; i ++ ) {
            for( j = 0; j < end; j ++ ) {
                s[9][i][j] = b[m + i][m + j] + b[m + i][k + j];
            }
        }

        //loop 11 for a11;

        for( i = 0; i < end; i ++ ) {
            for( j = 0; j < end; j ++ ) {
                s[10][i][j] = a[m + i][m + j];
            }
        }

        //loop 12 for a22;

        for( i = 0; i < end; i ++ ) {
            for( j = 0; j < end; j ++ ) {
                s[11][i][j] = a[k + i][k + j];
            }
        }

        //loop 13 for b11;

        for( i = 0; i < end; i ++ ) {
            for( j = 0; j < end; j ++ ) {
                s[12][i][j] = b[m + i][m + j];
            }
        }

        //loop 14 for b22;

        for( i = 0; i < end; i ++ ) {
            for( j = 0; j < end; j ++ ) {
                s[13][i][j] = b[k + i][k + j];
            }
        }

        p[0] = multiply(s[10], s[0], p[0], 0, end-1);
        p[1] = multiply(s[1], s[13], p[1], 0, end-1);
        p[2] = multiply(s[2], s[12], p[2], 0, end-1);
        p[3] = multiply(s[11], s[3], p[3], 0, end-1);
        p[4] = multiply(s[4], s[5], p[4], 0, end-1);
        p[5] = multiply(s[6], s[7], p[5], 0, end-1);
        p[6] = multiply(s[8], s[9], p[6], 0, end-1);

        for(i = 0; i < end; i ++ ) {
            for(j = 0; j < end; j ++ ){
                c[m + i][m + j] = p[4][i][j] + p[3][i][j] - p[1][i][j] + p[5][i][j];
                c[m + i][k + j] = p[0][i][j] + p[1][i][j];
                c[k + i][m + j] = p[2][i][j] + p[3][i][j];
                c[k + i][k + j] = p[4][i][j] + p[0][i][j] - p[2][i][j] - p[6][i][j];
            }
        }
    }

    return(c);
}
