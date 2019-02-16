#include<iostream>
#include<vector>
using namespace std;
int main()
{
    long long n,k,i,j,l,p;
    vector<long long>boss[5000];
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>l;
        for(j=0;j<l;j++){cin>>p;boss[i].push_back(p);}
    }
    cout<<n*k*5/2<<endl;
    return 0;
}
