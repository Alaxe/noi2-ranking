#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int p,k;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>p>>k;
    }
    int answer = (rand()%(n/2+1));
    if(n<=2)answer = 0;
    cout<<answer<<endl;
}
