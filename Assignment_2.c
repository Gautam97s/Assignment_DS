#include <stdio.h>
#include <stdlib.h>

void acceptMatrix(int A[100][100], int m, int n)
{
    printf("\nEnter data for matrix:\n\n");

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter element for index (%d, %d): ", i, j);
            scanf("%d", &A[i][j]);
        }
        printf("\n");
    }
}

void displayMatrix(int A[100][100], int m, int n)
{
    printf("\nInput matrix:\n\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void compact(int A[100][100], int m, int n, int B[100][3])
{
    B[0][0] = m;
    B[0][1] = n;

    int k = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] != 0)
            {
                B[k][0] = i;
                B[k][1] = j;
                B[k][2] = A[i][j];
                k++;
            }
        }
    }

    B[0][2] = k - 1;

    printf("\nCompact form of the matrix:\n\n");
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void simpleTranspose(int B[100][3], int C[100][3], int m, int n, int t)
{
	  int new_m = n;
	    int new_n = m;
	    int new_t = t;

	    C[0][0] = new_m;
	    C[0][1] = new_n;
	    C[0][2] = new_t;

	if(t <= 0){
		return;
	}
	int q=1;
	for(int col = 0; col<=n ; col++){
		for(int p=1; p<=t; p++){
			if(B[p][1] == col){
				 C[q][0] = B[p][1];
				 C[q][1] = B[p][0];
				 C[q][2] = B[p][2];
				q++;
			}
		}
	}

	printf("\nTransposed compact form of the matrix:\n\n");
	    for (int i = 0; i <= new_t; i++) {
	        for (int j = 0; j < 3; j++) {
	            printf("%d ", C[i][j]);
	        }
	        printf("\n");
	    }
	    printf("\n");

}

void fastTranspose(int B[100][3], int C[100][3] ){
    int rowTerms[100] = {0}, startPos[100] = {0};
    int m = B[0][0], n = B[0][1], t = B[0][2];

    C[0][0] = n;
    C[0][1] = m;
    C[0][2] = t;

    if (t <= 0)
    {
        return;
    }

    for (int i = 1; i <= t; i++)
    {
        rowTerms[B[i][1]]++;
    }

    startPos[0] = 1;
    for (int i = 1; i < n; i++)
    {
        startPos[i] = startPos[i - 1] + rowTerms[i - 1];
    }

    for (int i = 1; i <= t; i++)
    {
        int j = startPos[B[i][1]]++;
        C[j][0] = B[i][1];
        C[j][1] = B[i][0];
        C[j][2] = B[i][2];
    }

    printf("\nFast transposed compact form of the matrix:\n\n");
    for (int i = 0; i <= t; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main(void)
{
    int m, n, t;
    printf("\nEnter number of rows: ");
    scanf("%d", &m);
    printf("Enter number of columns: ");
    scanf("%d", &n);
    int A[m][n];
    int B[m * n][3];
    int C[m * n][3];

    acceptMatrix(A, m, n);
    displayMatrix(A, m, n);

    int option;
    printf("What do you want?\n");
    printf("1-compact form\n");
    printf("2-Simple transpose\n");
    printf("3-fastTranspose\n");
    printf("Enter your choice\n");
    scanf("%d", &option);

    switch(option){
    case 1:
    compact(A, m, n, B);
    break;

    case 2:
    compact(A, m, n, B);
    t = B[0][2];
    simpleTranspose(B, C, m, n, t);
    break;

    case 3:
    compact(A,m,n,B);
    fastTranspose(B,C);
    default :
    	printf("you entered the wrong output");

    }



    return 0;
}