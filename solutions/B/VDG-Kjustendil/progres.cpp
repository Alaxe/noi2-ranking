#include<iostream>
using namespace std;
int main()
{
    int A[1000];
    int n,p,i;
    int count = 0;
    do{cin>>n;}
    while(n<1||n>1000);
    for(i=0;i<n;i++)
    {
        cin >>A[i];
    }
    int d=-1;
    for(i=0;i<n;i++)
    {
        d=A[i];
        for(p = 0;p < n-1; p++)
        {
            if(d + A[p] == A[p+1])
            {
                count++;
            }
        }
    }
    cout<<count;
}
