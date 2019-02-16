#include<iostream>
#pragma optimize GCC ofast
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned int dp_less[100002];
    unsigned int dp_more[100002];
    unsigned int arr[100002];
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    dp_less[0]=1;
    for(int i=1; i<n; i++)
    {
        dp_less[i]=1;
        for(int j=i-1; j>=0; j--)
        {
            //cout<<dp_less[j]<<" ";
            if(arr[i]>arr[j])
            {
                dp_less[i]=max(dp_less[i],dp_less[j]+1);

            }
        }
        //cout<<endl;
    }
    dp_more[n-1]=1;
    for(int i=n-2; i>=0; i--)
    {
        dp_more[i]=1;
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]>arr[j])
            {
                dp_more[i]=max(dp_more[i],dp_more[j]+1);

            }
        }
    }
    unsigned int res=0;
    for(int i=0; i<n; i++)
    {
        res=max(res,dp_less[i]+dp_more[i]-1);
        ///cout<<dp_less[i]<<" "<<dp_more[i]<<endl;
    }
    cout<<res<<endl;
}
