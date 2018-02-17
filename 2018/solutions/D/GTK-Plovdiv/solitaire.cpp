#include<iostream>
using namespace std;
int n;
int cards[101][101];
int sum=0,maxSum=-1, specSum=0, br2=0, specNum=0;
int solitaire(int x, int y)
{
    sum+=cards[x][y];
    //cout<<cards[x][y]<<" ";
    if(y==3&&x==0)
    {
        if(sum>maxSum)
            maxSum=sum;
        sum=specSum;
        br2=0;
        return maxSum;
    }
    else if(y==3)
    {
        if(br2==0)
            specSum=sum;
        br2++;
        solitaire(x-1, y);
    }
    else if(x==0)
    {
        if(br2==0)
            specSum=sum;
        br2++;
        solitaire(x, y+1);
    }
    else
    {
        if(br2==0)
            specSum=sum;
        br2++;
        solitaire(x, y+1); solitaire(x-1, y);
        if(y==3&&x==0)
        {
            return maxSum;
        }
    }
}

int main()
{
    cin>>n;
    string c;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>c;
            char spec=c[0];
            switch(spec)
            {
                case 'T': cards[i][j]=10; break;
                case 'J': cards[i][j]=11; break;
                case 'Q': cards[i][j]=12; break;
                case 'K': cards[i][j]=13; break;
                case 'A': cards[i][j]=1; break;
                default: cards[i][j]=spec-'0';
            }
        }
    }
    cout<<solitaire(n-1, 0)<<endl;
    return 0;
}
