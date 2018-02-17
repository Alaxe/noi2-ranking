#include<iostream>
using namespace std;

const int maxi=10002;
const int maxi2=2;
int wStart, wEnd, in, out;
unsigned long long int matrix[maxi][maxi2];

unsigned long long int rek(int wNow, bool last)
{
    if(wNow>=wEnd)
    {
        return 1;
    }
    if(matrix[wNow][last]==0)
    {
        if(last)
        {
            int n=rek(wNow+in, true)+rek(wNow-out, false);
            matrix[wNow][last]=n;
        }
        else
        {
            int n=rek(wNow+in, true);
            matrix[wNow][last]=n;
        }
    }
    return matrix[wNow][last];
}

int main()
{
    for(int i=0; i<maxi; i++)
    {
        for(int j=0; j<maxi2; j++)
        {
            matrix[i][j]=0;
        }
    }
    cin>>wStart>>wEnd>>in>>out;
    cout<<rek(wStart+in, true)<<endl;
    return 0;
}

