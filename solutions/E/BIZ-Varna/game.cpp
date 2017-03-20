#include<iostream>
using namespace std;
int main()
{
    int a[999];
    int M,K,sum,brc,min,i;
    cin>>M>>K;
    do
    {      cin>>a[i]; brc++;
        if(a[i]%2==0) sum+=a[i];
    }while(sum<K||brc>=200);
        for(i=1;i<=brc;i++)
        {
            if(M-a[i]<M-a[i+1]||a[i]-M<a[i+1]-M) min=a[i];
            else min=a[i+1];
        }
       cout<<min<<" "<<sum<<endl;
}
