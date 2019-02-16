#include<iostream>
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
 long long m[100];
int m2[100]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     long long n,i,j,a,br=0,rez=1;
    cin>>n;
    for(i=0;i<n;i++){
    cin>>a;
    j=0;br=0;
    while(a>1)
    {
        br=0;
        while(a%m2[j]==0){a/=m2[j];br++;}
        m[j]=max(m[j],br);
        j++;
    }

    }
    for(i=0;i<50;i++)
    {
        if(m[i]!=0)
        {
            rez*=pow(m2[i],(m[i]+1)/2);
        }
    }
    cout<<rez<<endl;
    return 0;
}


