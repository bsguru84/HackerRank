#include <stdio.h>
#include <stdlib.h>


void quickSort(unsigned int *arr, unsigned int *indexSorted, int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = indexSorted[i];
			indexSorted[i] = indexSorted[j];
			indexSorted[j] = tmp;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		quickSort(arr, indexSorted, left, j);
	if (i < right)
		quickSort(arr, indexSorted, i, right);
}

void main()
{
	unsigned int T = 0, N = 0, *prices = NULL,*indexSorted = NULL;//children in class
	int i,j,k;
	int max = 0;
	int ascentStreak = 0;
	int purchasePrice = 0;
	int profit = 0, borderIndex = 0, prevborderIndex = 0;
	

	int *rating = NULL, *candies = NULL;

	FILE *fp = freopen("Input.txt", "r", stdin);

	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		profit = 0;		
		purchasePrice = 0;
		ascentStreak = 0;
		borderIndex = 0;
		prevborderIndex = -1;
		scanf("%d", &N);
		prices = (unsigned int*)calloc(1, sizeof(unsigned int)*N);
		indexSorted = (unsigned int*)calloc(1, sizeof(unsigned int)*N);

		for (j = 0; j < N; j++)
		{
			scanf("%d", &prices[j]);
			indexSorted[j] = j;
		}

		quickSort(prices, indexSorted,0, N - 1);

		for (j = N - 1; j >= 0; j--)
		{
			int purchaseprice = 0;
			if (indexSorted[j] >= borderIndex)
			{
				prevborderIndex = borderIndex;
				k = borderIndex = indexSorted[j];

				while (--k > prevborderIndex)
				{
					purchaseprice += prices[k];
				}

				if (prevborderIndex == 0 && purchaseprice != 0)
					purchaseprice += prices[0];
				
				if (purchaseprice > 0)
					profit += (indexSorted[j] - borderIndex)*prices[indexSorted[j]] - purchaseprice;
				//borderIndex = indexSorted[j];
			}
		}

		printf("%d\n", profit);


	}


}