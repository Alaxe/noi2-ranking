#include<iostream>

using namespace std;

int arr[100001];

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t,n,i,j,x,maxi=0;
    
    cin>>t;
    
    for(i=0;i<t;i++)
    {
        cin>>n;
        
        for(j=0;j<n;j++)
        {
            cin>>x;
            arr[x]++;
            if(arr[x]>maxi)maxi=arr[x];
        }
        
        cout<<maxi+1<<endl;
        
        maxi=0;
        
        for(j=1;j<=n;j++)arr[j]=0;
    }
    
    return 0;
}