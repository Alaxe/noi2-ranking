#include<bits/stdc++.h>
using namespace std;
long long  ball(long long q,long long t){
    if(t%2==0){
        if(q==1)
            return 2;
        if(q==2)
            return 1;
    }
    else{
        if(q==0)
            return 1;
        if(q==1)
            return 0;
    }
    return q;

}
int main()
{
    long long n;
    int x;
    cin>>n>>x;
    for(int i=n;i>0;i--){
        x=ball(x,i);
    }
    cout<<x<<endl;
    return 0;

}
