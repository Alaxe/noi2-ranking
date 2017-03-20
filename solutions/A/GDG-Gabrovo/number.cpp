#include<iostream>
#include<cmath>
#define ll long long
using namespace std;
ll m,n;
int main()
{
    int br = 0;
    ll firsts = 0;
    ll lasts = 0;
    cin>>m>>n;

    int s = sqrt((long double)m);
    if(s*(s+1) >= m){
        firsts = s;
    }else{
        firsts = s+1;
    }

    s = sqrt((long double)n);
   if(s*(s+1) <= n){
        lasts = s;
    }else{
        lasts = s-1;
    }


    if(firsts > lasts){
        cout<<0<<endl;
        return 0;
    }

    cout<<lasts-firsts+1<<endl;
    return 0;
}
