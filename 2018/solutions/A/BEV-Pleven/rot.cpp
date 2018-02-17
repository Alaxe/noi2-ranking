#include<iostream>
#include<cmath>
using namespace std;
int b,num1,num2,num3,num4,ans1,ans2,ans3,ans4;


long long rot(long long x,long long del)
{
    long long first=x/del;
    //cout<<del<<" "<<first<<" "<<x<<endl;
    long long newx=(x%del)*10+first;
    return newx;
}

void solve()
{
    int send=1;

    for(int i=10;i<=1000000;i++)
    {
        if(i/send==10)send*=10;
        long long newx=rot(i,send);
        //cout<<newx<<endl;
        if(ans1==0&&newx-i==num1)ans1=i;
        if(ans2==0&&newx-i==num2)ans2=i;
        if(ans3==0&&newx-i==num3)ans3=i;
        if(ans4==0&&newx-i==num4)ans4=i;

    }
        cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4;
}
int main()
{

    cin>>b;
    cin>>num1>>num2>>num3>>num4;
    solve();
    return 0;
}

