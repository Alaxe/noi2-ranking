#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long t,n,i,j,a;
    long long br[100000];
    long long res[10];
    cin>>t;
    for(i=0;i<100000;i++)br[i]=0;
    for(i=0;i<10;i++)res[i]=0;
    for(j=0;j<t;j++)
    {
        cin>>n;
        for(i=0;i<n;i++){cin>>a;br[a]++;br[i]++;}
        sort(br,br+100000);
        res[j]=br[99999];
        i=99999;
        while(br[i]>0){br[i]=0;i--;}
    }
    for(i=0;i<t;i++)cout<<res[i]<<endl;
    return 0;
}