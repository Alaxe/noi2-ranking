#include<iostream>
using namespace std;
int a[1000009];
int main()
{
    int n,k,i=1,num=0;
    cin>>n>>k;
    {
    if(n!=a[i]) num++, k=k;
    else k++, num++;
    }
    if(k=k) cout<<num<<endl;
    return 0;
}
