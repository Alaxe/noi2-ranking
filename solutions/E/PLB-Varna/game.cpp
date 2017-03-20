#include <iostream>
using namespace std;
int main ()
{
    int k, m, sum=0, j, br=0, i;
    cin>>m>>k;
    cin>>j;
    for(i=1; i<=10; i++)
    {
        if(j%2==0) sum+=j;
        if(sum>=k || j>k)
        {
            break;
            cout<<i<<" "<<sum;
        }
        if(m+1==j || m-1==j) cout<<i;
        cin>>j;
    }
    cout<<i<<" "<<sum;
    return 0;
}
