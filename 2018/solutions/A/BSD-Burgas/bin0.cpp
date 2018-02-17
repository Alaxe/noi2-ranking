#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAXBINLEN 60
using namespace std;

int primesArr[MAXBINLEN];

long long unsigned s, t;
int z;
int sBin[MAXBINLEN], tBin[MAXBINLEN];
int sBinLen, tBinLen;

void FillSBin()
{
	long long unsigned tempS = s;
	int i;
	for (i=0; tempS!=0; i++)
	{
		sBin[i]=tempS%2;
		tempS/=2;
	}
	sBinLen=i;
}

void FillTBin()
{
    long long unsigned tempT = t;
    int i;
    for (i=0; tempT!=0; i++)
    {
        tBin[i]=tempT%2;
        tempT/=2;
    }
    tBinLen=i;
}

void SToFirst()
{
    int zerosNeeded = z;
    for (int i=0; i<sBinLen; i++)
    {
        if (sBin[i]==0) zerosNeeded--;
    }
    if (zerosNeeded==0) return;

    if (zerosNeeded>0)
    {
        for (int i=sBinLen-2; i>=0 && zerosNeeded>0; i--)
        {
            if (sBin[i]==1)
            {
                sBin[i]=0;
                zerosNeeded--;
            }
        }

        if (zerosNeeded>0)
        {
            for (int i=sBinLen-1; i>=0; i--)
            {
                sBin[i+zerosNeeded]=sBin[i];
            }
            for (int i=0; i<zerosNeeded; i++)
            {
                sBin[i]=0;
            }
            sBinLen+=zerosNeeded;
        }
    }
    else
    {
        for (int i=0; i<sBinLen && zerosNeeded<0; i++)
        {
            if (sBin[i]==0)
            {
                sBin[i]=1;
                zerosNeeded++;
            }
        }
    }
}

void TToLast()
{
    int zerosNeeded=z;
    for (int i=0; i<tBinLen; i++)
    {
        if (tBin[i]==0) zerosNeeded--;
    }

    if (zerosNeeded<0)
    {
        int firstSectionZeros=0;
        int firstOneIndex;
        for (int i=tBinLen-2; i>=0; i--)
        {
            if (tBin[i]==1)
            {
                firstOneIndex=i;
                break;
            }
            firstSectionZeros++;
        }
        if (firstSectionZeros < z)
        {
            tBin[firstOneIndex]=0;
            zerosNeeded=z-tBinLen+firstOneIndex+1;
            for (int i=0; i<firstOneIndex; i++)
            {
                if (zerosNeeded>0)
                {
                    tBin[i]=0;
                    zerosNeeded--;
                }
                else
                {
                    tBin[i]=1;
                }
            }
        }
        else
        {
            tBinLen--;
            zerosNeeded=z;
            for (int i=0; i<tBinLen; i++)
            {
                if (zerosNeeded>0)
                {
                    tBin[i]=0;
                    zerosNeeded--;
                }
                else
                {
                    tBin[i]=1;
                }
            }
        }
    }
    else
    {
        for (int i=0; i<tBinLen && zerosNeeded>0; i++)
        {
            if (tBin[i]==1)
            {
                tBin[i]=0;
                zerosNeeded--;
            }
        }
    }
}

void PrintSBin()
{
    for (int i=sBinLen-1; i>=0; i--)
    {
        printf("%d", sBin[i]);
    }
    printf("\n");
}

void PrintTBin()
{
    for (int i=tBinLen-1; i>=0; i--)
    {
        printf("%d", tBin[i]);
    }
    printf("\n");
}

long long unsigned CalcComb(int n, int k)
{
	if (n > k) return 0;
    int topPrimes[MAXBINLEN];
    for (int i=0; i<MAXBINLEN; i++) topPrimes[i]=0;
    int bottomPrimes[MAXBINLEN];
    for (int i=0; i<MAXBINLEN; i++) bottomPrimes[i]=0;
    int topPrimesCount=0, bottomPrimesCount=0;

    for (int i=k; i>=k-n+1; i--)
    {
        int currNum=i;
        for (int primeIndex=0; primeIndex<MAXBINLEN && currNum!=1; primeIndex++)
        {
            if (currNum % primesArr[primeIndex] == 0)
            {
                topPrimes[primeIndex]++;
                currNum /= primesArr[primeIndex];
                primeIndex--;
            }
        }
    }
    for (int i=2; i<=n; i++)
    {
        int currNum=i;
        for (int primeIndex=0; primeIndex<MAXBINLEN && currNum!=1; primeIndex++)
        {
            if (currNum % primesArr[primeIndex] == 0)
            {
                bottomPrimes[primeIndex]++;
                currNum /= primesArr[primeIndex];
                primeIndex--;
            }
        }
    }
	
    long long unsigned result=1;
    for (int i=0; i<MAXBINLEN; i++)
    {
    	if (topPrimes[i] - bottomPrimes[i] == 0) continue;
        result *= (topPrimes[i]-bottomPrimes[i]) * primesArr[i];
    }
    return result;
}

bool isPrime(int n)
{
    if (n == 1 || n % 2 == 0) return false;
    for (int i=3; i<=sqrt(n); i+=2)
    {
        if (n % i == 0) return false;
    }
    return true;
}

void FillPrimesArr()
{
    primesArr[0]=2;
    primesArr[1]=3;
    for (int i=2; i<MAXBINLEN; i++)
    {
        for (int j=primesArr[i-1]+2; true; j+=2)
        {
            if (isPrime(j))
            {
                primesArr[i]=j;
                break;
            }
        }
    }
}

long long unsigned CombIndex(int a[], int len)
{
    long long unsigned result=0;
    int currIntervalIndex=len-2, zerosLeft=z;
    for (int i=len-2; i>=0; i--)
    {
        if (a[i]==0)
        {
            zerosLeft--;
            for (int j=currIntervalIndex; j>i; j--)
            {
                result += CalcComb(zerosLeft, j);
            }
            currIntervalIndex=i-1;
        }
    }
    return result;	
}

int main()
{
    FillPrimesArr();
    scanf("%llu %llu %d", &s, &t, &z);
    FillSBin();
    FillTBin();
    SToFirst();
    TToLast();

    long long unsigned result=0;
    for (int i=sBinLen; i<tBinLen-1; i++)
    {
        result+=CalcComb(z, i);
    }
    if (sBinLen < tBinLen)
    {
    	result += CalcComb(z, sBinLen-1) - CombIndex(sBin, sBinLen);
    	result += CombIndex(tBin, tBinLen) + 1;
	}
	else if (sBinLen == tBinLen)
	{
		result += CombIndex(tBin, tBinLen) - CombIndex(sBin, sBinLen) + 1;
		if (result < 0) result=0;
	}
	
    printf("%llu\n", result);
    return 0;
}

