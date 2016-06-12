#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//https://www.hackerrank.com/contests/5-days-of-game-theory/challenges/a-game-of-stones


int main()
{
	unsigned int i, j, k;
	unsigned int T, N,M;// N -> No of bricks  , T -> Test cases
	unsigned int *cost = NULL;
	unsigned int ans = 0;
	unsigned int stones = 0;


	FILE *fp = freopen("Input.txt", "r", stdin);

	scanf("%d", &T);// T -> Test cases

	//int test = MAX3(1, 2, 2);

	for (j = 0; j < T; j++)
	{
		scanf("%d", &M);

		cost = (unsigned int*)malloc(M*sizeof(unsigned int));
		memset(cost, 0x0, sizeof(unsigned int)*M);

		for (i = 0; i < M; i++)
			scanf("%d", &cost[i]);
	}
}


