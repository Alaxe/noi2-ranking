#include<iostream>
using namespace std;
int main ()
{
    int n,u,v,arr[101];
    int obshto=0;
    cin>>n>>u>>v;
    for(long long i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(long long i=0; i<n; i++)
    {
        if(arr[i]<arr[i+1] )
        {
            obshto=obshto+arr[i];
        }
        else
        {
            if(arr[i]>arr[i+1] and arr[i+2]>=arr[i+1] and arr[i+2]<=arr[i])
            {
                obshto=obshto+arr[i+2]-arr[i+1];
            }
            else
            {
                if(arr[i]>arr[i+1] and arr[i+2]>=arr[i+1] and arr[i+2]>=arr[i])
                {
                    obshto=obshto+arr[i]-arr[i+1];
                    obshto=obshto-1;
                }
            }
        }
    }
    cout<<(obshto/u)*v<<endl;
    return 0;
}
