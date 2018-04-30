#include <stdio.h>

void figurinhas(int qf, int i, int nf[], int fm, int fj, int bm, int bj, int bitset[])
{
	if(i == qf)
	{
		if(bm > bj)
		{
			printf("%d\n%d\n%d", fj, fm, bm);
		}
		else
		{
			printf("%d\n%d\n%d", fj, fm, bj);
		}
		
	}
	else
	{
		scanf("%d", &nf[i]);

		int num = nf[i];
		
		if (bitset[num] == 0)
		{
			bitset[num] = 1;
		}
		else
		{
			num = 0;
		}

		if(nf[i]%2 == 0)
		{
			fj++;

			bj = bj + num;
			figurinhas(qf, i+1, nf, fm, fj, bm, bj, bitset);
		}
		else
		{
			fm++;

			bm = bm + num;

			figurinhas(qf, i+1, nf, fm, fj, bm, bj, bitset);
		}
	}
}

int main()
{
	int qf;
	scanf("%d", &qf);
	int nf[qf];
	int bitset[50000] = {};
	figurinhas(qf, 0, nf, 0, 0, 0, 0, bitset);
}