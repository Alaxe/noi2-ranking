#include<bits/stdc++.h>
using namespace std;
string a,mini,maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>a;
    long long n=a.size();
    for(long long i=0; i<n; i++)
        mini=mini+'A';
    bool flag=false;
    long long j,i=0;
    do
    {
        j=i+1;
        do
        {
            if(a[i]<a[j] && !(mini[i]<mini[j])){
                mini[j]=char(mini[i]+1);

                flag=true;

                i=0;break;
            }
            if(a[i]>a[j] && !(mini[i]>mini[j]))
            {
                mini[i]=char(mini[i]+1);

                flag=true;
                i=0;break;
            }
            if(a[i]==a[j] && !(mini[i]==mini[j]))
            {
                mini[j]=mini[i];
            }


                j++;
        }
        while(j<n);
        if(!flag)i++;
        else flag=false;
    }while(i<n-1);

    int chmax=0;
    for(long long i=0; i<n; i++)
    {
        if(chmax<int(mini[i]-'A'))
            chmax=int(mini[i]-'A');
    }
    for(long long i=0; i<n; i++)
    {
        maxi=maxi+char('Z'-(chmax-int(mini[i]-'A')));
    }
    cout<<mini<<endl;
    cout<<maxi<<endl;
    return 0;
}


