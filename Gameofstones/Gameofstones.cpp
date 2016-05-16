#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//https://www.hackerrank.com/contests/5-days-of-game-theory/challenges/a-game-of-stones


int main()
{
	unsigned int i, j, k;
	unsigned int T,N;// N -> No of bricks  , T -> Test cases
	unsigned int *dp = NULL;
	unsigned int ans = 0;
	unsigned int stones = 0;


	FILE *fp = freopen("Input.txt", "r", stdin);

	scanf("%d", &T);// T -> Test cases

	//int test = MAX3(1, 2, 2);

	for (j = 0; j < T; j++)
	{
		scanf("%d", &N);

		dp = (unsigned int*)malloc(N*sizeof(unsigned int));
		memset(dp, 0x0, sizeof(unsigned int)*N);

		for (i = 0; i < N; i++)
		{
			if (i == 0)
				dp[i] = 0;
			else if (i == 1)
				dp[i] = 1;
			else if (i == 2)
				dp[i] = 1;
			else if (i == 3)
				dp[i] = 1;
			else if (i == 4)
				dp[i] = 1;
			else if (i == 5)
				dp[i] = 1;
			else
			{
				if (dp[i - 2] % 2 == 0)
					dp[i] = dp[i - 2] + 1;
				else if (dp[i - 3] % 2 == 0)
					dp[i] = dp[i - 3] + 1;
				else if (dp[i - 5] % 2 == 0)
					dp[i] = dp[i - 5] + 1;
				else dp[i] = dp[i - 5] + 1;

			}
		}

		if (dp[N - 1] % 2 == 1)
			printf("First\n");
		else
			printf("Second\n");

		free(dp);
	}
}


