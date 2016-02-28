#include <stdio.h>
#include <stdlib.h>

//https://www.hackerrank.com/challenges/coin-change

int main()
{	
	unsigned int i,j,k;
	unsigned int T,N,M;// N -> The amount needed , M -> Number of distinct coins

	int *coins = NULL;
	unsigned long **soln = NULL;

	FILE *fp = freopen("Input.txt", "r", stdin);
	
	scanf("%d", &N);// N -> The amount needed 
	scanf("%d", &M);// M -> Number of distinct coins		

	coins = (int*)calloc(1, sizeof(unsigned int)*M);

	for (j = 0; j < M; j++)
		scanf("%d", &coins[j]);

	soln = (unsigned long**)calloc(1, sizeof(unsigned long*)*(M + 1));//rows
	for (j = 0; j < M+1; j++)
		soln[j] = (unsigned long*)calloc(1, sizeof(unsigned long)*(N + 1));//cols

	soln[0][0] = 0;

	for (j = 0; j < M + 1;j++)//rows -> Coins
		for (k = 0; k < N + 1; k++)//cols -> Amount
		{
			if (j == 0)
				soln[j][k] = 0;
			else if (k == 0)
				soln[j][k] = 1;
			else//The headache now begins
			{
				if (coins[j - 1] > k)
					soln[j][k] = soln[j - 1][k];
				else
					soln[j][k] = soln[j - 1][k] + soln[j][k - coins[j - 1]];

			}

		}

		free(coins);

		printf("%d\n", soln[M][N]);

		for (j = 0; j < M + 1; j++)
			free(soln[j]);

		free(soln);
	}


