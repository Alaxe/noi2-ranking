#include <iostream>

#define MAX 10000001
using namespace std;

long long k=666ll, n=133742ll, first=20ll, mul=3ll, add=17ll, mod=1000000007ll;
long long sols1[MAX];
long long sols2[MAX];

void inp()
{
    cin>>n>>k>>first>>mul>>add>>mod;
}

template <typename T>
void show(T *a, int n)
{
    for (int i=0; i<n; i++) cout<<a[i]<<' ';
    cout<<endl;
}

void prep()
{
    sols1[0] = first;
    sols2[0] = first;
    for (int i=1; i<n; i++) sols1[i] = (sols1[i-1]*mul+add)%mod;
    //show(sols1, n);
}

template <typename T>
long long getSum(T *a, int n)
{
    T c=0ll;
    for (int i=0; i<n; i++) c+=a[i];
    return c;
}

long long sol()
{
    for (int i=2; i<=k; i+=2)
    {
        for (int j=1; j<n; j++) sols2[j] = max(sols1[j], sols1[j-1]);
        //show(sols2, n);
        if (i+1>k) return getSum(sols2, n);
        for (int j=1; j<n; j++) sols1[j] = max(sols2[j], sols2[j-1]);
        //show(sols1, n);
    } 
    return getSum(sols1, n);
}

int main()
{
    inp();
    prep();
    cout<<sol()<<endl;
    return 0;
}