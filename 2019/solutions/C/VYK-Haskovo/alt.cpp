#include<iostream>

using namespace std;


int k,m,n;
int br = 1;
int ans=0;

void genRed(int x, int brp)
{
    if(brp == n) {ans++;return;}
    if(x+k < m) genRed(x+k,brp+1);
    if(x-k > 0)genRed(x-k,brp+1);
}



int main()
{
    cin >> k >> m >> n;

    for(int i  =1 ; i< m;i++)
    {
        genRed(i,1);
    }
    cout << ans << '\n';
}
