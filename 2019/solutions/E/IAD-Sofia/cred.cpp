#include<iostream>
using namespace std;
int cifri(int n){
int sbor=0;
while(n!=0){
    sbor+=n%10;
    n/=10;
}
return sbor;
}
int main()
{
    int n,m;
    int i;
    cin>>n>>m;
    int broach=0;
    int tek=n;
    for(i=n;i<=m;i+=tek-i){
            cout<<tek<<" ";
            tek=i+cifri(i);
            cout<<tek<<endl;
    broach++;

    }
    cout<<broach;
}
