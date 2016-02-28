#include <stdio.h>
#include <stdlib.h>
#if 0
unsigned int candies(int *candies, unsigned int N, int index)
{
	if (index < 0)
		return 1;
	else if (index > N - 1)
		return 1;
	else
		return candies[index];
}
unsigned int gencandiesCount(int *candies, unsigned int N,unsigned int id)
{

	if ((id > 0 && candies[id - 1] >= candies[id]) && ((id < N - 1) && candies[id + 1] >= candies[id]))
		return 1;
	else if (id == 0 && candies[id + 1] >= candies[id])
		return 1;
	else if (id == N - 1 && candies[id - 1] >= candies[id])
		return 1;

	if (id != N - 1 && candies[id + 1] < candies[id])//decresing order
		return 1 + gencandiesCount(candies, N, id + 1);
	else if (id != N-1 && candies[id] < candies[id+1])//increasing order
		return gencandiesCount(candies, N, id + 1) - 1;

}
#endif
void main()
{
	unsigned int N = 0;//children in class
	int i;
	unsigned int candiesLefttoRight = 0, candiesRighttoLeft = 0;
	unsigned int curRank,curIndex;

	int *rating = NULL, *candies = NULL;

	FILE *fp = freopen("Input.txt", "r", stdin);

	scanf("%d", &N);

	rating = (int*)calloc(1,sizeof(int)*N);
	candies = (int*)calloc(1, sizeof(int)*N);	

#if 0
	for (i = 0; i < N; i++)
		scanf("%d", &rating[i]);

	for (i = 0; i < N; i++)
	{
		if (i == 0)
		{
			candies[i] = 1;
		}
			
		else
		{
			if (rating[i]>rating[i - 1])
				candies[i] = candies[i - 1] + 1;
			else if (rating[i]>rating[i + 1])
				candies[i] = 2;
			else
				candies[i] = 1;
		}

		candiesLefttoRight += candies[i];
	}

	for (i = N-1; i >=0; i--)
	{
		if (i == N-1)
		{
			candies[i] = 1;
		}

		else
		{
			if (rating[i] > rating[i + 1])
				candies[i] = candies[i + 1] + 1;
			else if (rating[i] > rating[i - 1])
				candies[i] = 2;
			else
				candies[i] = 1;
		}

		candiesRighttoLeft += candies[i];
	}


	for (i = 0; i < N; i++)
	{
		candies[i] = gencandiesCount(rating,N,i);
	}
#endif

	for (i = 0; i < N; i++)
		scanf("%d", &rating[i]);

	for (i = 0; i < N; i++)
	{
		if (i == 0 && rating[i] <= rating[i + 1])
		{
			candies[i] = 1;
			curIndex = i;
			while (curIndex + 1 < N && rating[curIndex + 1] > rating[curIndex])
			{
				if (candies[curIndex] + 1 > candies[curIndex + 1])
					candies[curIndex + 1] = candies[curIndex] + 1;
				curIndex++;
			}
		}

		else if (i == N - 1 && rating[i] <= rating[i - 1])
		{
			candies[i] = 1;
			curIndex = i;
			while (curIndex - 1 >= 0 && rating[curIndex - 1] > rating[curIndex])
			{
				if (candies[curIndex] + 1 > candies[curIndex - 1])
					candies[curIndex - 1] = candies[curIndex] + 1;
				curIndex--;
			}
		}
		else if (rating[i] <= rating[i + 1] && rating[i] <= rating[i - 1])
		{
			candies[i] = 1;

			curIndex = i;
			curRank = rating[i];

			while (curIndex - 1 >= 0 && rating[curIndex - 1] > rating[curIndex])
			{
				if (candies[curIndex] + 1 > candies[curIndex - 1])
					candies[curIndex - 1] = candies[curIndex] + 1;
				curIndex--;
			}

			curIndex = i;
			while (curIndex + 1 < N && rating[curIndex + 1] > rating[curIndex])
			{
				if (candies[curIndex] + 1 > candies[curIndex + 1])
					candies[curIndex + 1] = candies[curIndex] + 1;
				curIndex++;
			}

		}



	}

	for (i = 0; i < N; i++)
		candiesRighttoLeft += candies[i];

	
	printf("%d\n", candiesRighttoLeft);
	

}