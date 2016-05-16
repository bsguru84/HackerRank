#include <stdio.h>
#include <stdlib.h>

//https://www.hackerrank.com/challenges/coin-change

unsigned int N;

unsigned int max = 0;

int MAX3(int a, int  b, int c)
{
	int max2 = (a > b) ? a : b;

	return (max2 > c) ? max2 : c;

}
int Maxscore(unsigned int *score, int startindex,bool firstplayer)
{
	if (startindex > N - 1)
		return 0;

	int score1, score2 = -1, score3 = -1;
	int maxscore = 0;
	int scoreadd = 0;

	score1 = score[startindex] + Maxscore(score, startindex + 1, !firstplayer);

	if (startindex + 1 < N-1)
		score2 = score[startindex] + score[startindex + 1] + Maxscore(score, startindex + 2, !firstplayer);

	if (startindex + 2 < N-1)
		score3 = score[startindex] + score[startindex + 1] + score[startindex + 2] + Maxscore(score, startindex + 3, !firstplayer);

	maxscore = MAX3(score1, score2, score3);

	if (maxscore == score1)
		scoreadd = score[startindex];
	else if (maxscore == score2)
		scoreadd = score[startindex] + score[startindex + 1];
	else
		scoreadd = score[startindex] + score[startindex + 1] + score[startindex + 2];

	if (firstplayer)
		max += scoreadd;

	return maxscore;



}
int main()
{
	unsigned int i, j, k;
	unsigned int T;// N -> No of bricks  , T -> Test cases
	unsigned int *score = NULL;
	unsigned int ans = 0;
	

	FILE *fp = freopen("Input.txt", "r", stdin);

	scanf("%d", &T);// T -> Test cases

	//int test = MAX3(1, 2, 2);

	for (i = 0; i < T; i++)
	{
		scanf("%d", &N);

		score = (unsigned int*)malloc(N*sizeof(unsigned int));

		for (j = 0; j < N; j++)
		{
			scanf("%d", &score[j]);
		}

		max = 0;

		ans = Maxscore(score, 0,true);

	}
}


