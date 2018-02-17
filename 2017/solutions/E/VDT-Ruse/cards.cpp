#include<iostream>
using namespace std;
int main()
{
    long long N,a[100000],b[100000],i,count=1,maxcount=0;
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(i=0;i<N-1;i++)
    {
        if((a[i]>=a[i+1] && b[i]>=b[i+1]) || (a[i]>=b[i+1] && b[i]>=a[i+1]))
        {
            count++;
        }
        else 
        {
            if(count>maxcount)  maxcount=count;
            count=1;
        }
        
    }
    if(count>maxcount)  maxcount=count;
    cout<<maxcount<<endl;
    return 0;
}