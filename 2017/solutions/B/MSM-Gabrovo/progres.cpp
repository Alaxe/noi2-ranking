#include<iostream>
using namespace std;
int n,a[1002];
long long br;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[j]>a[i]) br++;
        }
    }

    cout<<br<<endl;

    return 0;
}
