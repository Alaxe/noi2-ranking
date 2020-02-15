#include <iostream>
#include <stdio.h>
using namespace std;
long long i,n,a[100001],j,b[100001];
int main()
{
    cin>>n;
    for(i=0;i<n;i++){
        cin>>b[i];
    }
    for(i=n-1;i>=0;i--){
        a[i]=n-(b[i]+i);
        for(j=i;j<n;j++){
            if(a[j]>=a[i]){a[j]++;}
        }
    }
    for(i=0;i<n;i++){
        cout<<a[i]-1<<" ";
    }









    return 0;
}
/*
6
2 3 0 0 1 0





*/
