#include <stdio.h>
#include <string.h>
#define MAXN 100
#define MOD 1000000007
using namespace std;

int table[MAXN][MAXN];

char s[MAXN];
int sLen; 

void FillZerosAndOnes()
{
    for (int i=0; i<sLen; i++)
    {
        for (int j=0; j<i; j++)
        {
            table[i][j]=0;
        }
        table[i][i]=1;
    }
}

void FillTable()
{
    FillZerosAndOnes();
    for (int len=2; len<=sLen; len++)
    {
        int to=len-1;
        for (int from=0; to<sLen; from++, to++)
        {
            table[from][to]=(table[from][to-1]+1) % MOD;
            for (int twin=from; twin<to; twin++)
            {
                if (s[twin]==s[to])
                {
                    table[from][to]=(table[from][to] + table[twin+1][to-1]+1) % MOD;
                }
            }
        }
    }    
}

int main()
{
    scanf("%s", &s);
    sLen=strlen(s);
    FillTable();
    printf("%d\n", table[0][sLen-1]);
    return 0;
}
