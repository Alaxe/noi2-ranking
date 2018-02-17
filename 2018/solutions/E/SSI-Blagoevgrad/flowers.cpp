#include <bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
    unsigned long long razlika=0,q,n;
    cin>>n;
    unsigned long long max;
    for(int i=0; i<n; i++) cin>>a[i];
    cin>>q;
    max=a[0];
    for(int i=0; i<n; i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    for(int i=0; i<n; i++) razlika+=max-a[i];
    cout<<razlika*q<<endl;
    return 0;
}
