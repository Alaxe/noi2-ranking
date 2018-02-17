#include<iostream>
#include<cstdio>
using namespace std;
int main()
{int n,k;
cin>>n>>k;
int des=n/10%10;
int ed=n/1%10;
if(des*10+ed+1/k) cout<<12<<endl;
else cout<<"NO"<<endl;
    return 0;
}
