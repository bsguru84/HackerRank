#include <stdio.h>
#include <stdlib.h>

//https://www.hackerrank.com/challenges/maxsubarray
//The soln fails if N is very large, say 68k

int main()
{
	unsigned int i, j, t;
	unsigned int T, N, M;

	long *array = NULL;
	int **soln = NULL;
	long max = 0;
	long maxcontig = 0, maxnoncontig = 0,min =-10000;

	FILE *fp = freopen("Input.txt", "r", stdin);

	scanf("%d", &T);
	
	for (t = 0; t < T;t++)
	{
		maxcontig = -10000;
		maxnoncontig = 0;
		min = -10000;
		scanf("%d", &N);// N -> size of array
		//scanf("%d", &M);// M -> Number of distinct coins		
		array = (long*)calloc(1, sizeof(long)*N);
		
		for (i = 0; i < N; i++)
		{
			scanf("%ld", &array[i]);

			if (array[i] < 0 && min < array[i])
				min = array[i];

			if (array[i] > 0)
				maxnoncontig += array[i];
		}

		if (maxnoncontig == 0)
			maxnoncontig = min;

		if (N == 1)
		{
			maxnoncontig = array[0];
			maxcontig = array[0];
		}
		else
		{
			soln = (int**)calloc(1, sizeof(int*)*(N + 1));//rows
			for (j = 0; j < N + 1; j++)
			{
				if (j == 7513)
					j = j;
					 
				soln[j] = (int*)calloc(1, sizeof(int)*(N));//cols
			}

			for (j = 0; j < N; j++)//Cols
				for (i = 0; i < N + 1; i++)//rows
				{
					if (i == 0)
						soln[i][j] = 0;
					else if (j > i - 1)
						soln[i][j] = 0;
					else if (i - 1 == j)
					{
						soln[i][j] = array[i - 1];
						if (soln[i][j] > maxcontig)
							maxcontig = soln[i][j];
					}
					else
					{
						soln[i][j] = soln[i - 1][j] + array[i - 1];
						if (soln[i][j] > maxcontig)
							maxcontig = soln[i][j];
					}
				}

#if 0
			for (j = 0; j < N+1; j++)//rows
			{
				for (i = 0; i < N; i++)//cols
					printf("%ld\t", soln[j][i]);

				printf("\n");
			}
#endif

			//printf("\n\n\n");

			for (j = 0; j < N + 1; j++)
				free(soln[j]);

			free(soln);
		}

		free(array);

		printf("%ld %ld\n", maxcontig, maxnoncontig);		
	}
}


