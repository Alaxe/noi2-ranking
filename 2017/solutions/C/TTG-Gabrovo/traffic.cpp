#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
//char dig[26] = {'1','A','B','C','D','E','F','G','H','I','G','K','L','M','N','O','P',}
int n,m;
int a[650][650];
int startx,starty;


void Init()
{
    char t;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin.get(t);
            if(t == '*')a[i][j] = -1;
            if(t == '#'){a[i][j] = 0;startx = i;starty = j;}
            if(t!='*' && t!='*')a[i][j] = t - 'A' + 1;
        }
    }
}
//
//

int main ()
{
    Init();
    cout<<"Tova e nai otvratitelnata zadacha koqto sym reshaval nqkoga!!"<<endl;
    return 0;
}
