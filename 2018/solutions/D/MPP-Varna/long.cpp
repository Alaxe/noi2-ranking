#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,k,r=1;
    cin >> n >> k;

    while(n>1)
    {
        r*=10;
        n--;
    }

    for(int i=r; i<r*10; i++)
    {
        if(i%k==0)
        {
            cout << i <<endl;

    }

    return 0;

}
}
