#include<iostream>
#include<string.h>
#include<algorithm>
#include<stack>
#include<vector>
#include<stdio.h>
using namespace std;

int n,i,j,maks=0,l,key=0;
int a[1001];   
unsigned long long otg=0;
int main() 
{
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]<a[j]) 
            {
                if(a[j]-a[i]>maks) maks=a[j]-a[i];
                otg++;
            }
        }
    }
    cout<<otg<<endl;
    return 0;
}
