#include<iostream>
using namespace std;
int main ()
{
    int n,s,brAB=0,brCD=0;
    cin >> n;
    for(int br=1; br<=n-1; br++)
    {
        cin >> s;
        if(s=='a' || s=='b')
            brAB++;
        else if(s=='c' || s=='d')
            brCD++;
    }
    if(brAB==brCD)
        cout << brAB;
    return 0;
}


