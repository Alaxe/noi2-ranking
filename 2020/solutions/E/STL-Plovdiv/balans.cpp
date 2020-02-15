#include<iostream>
using namespace std;
int main()
{
    long n;
    int balab,balcd,broi;
    balab = 0;
    balcd = 0;
    char c1,c2,c3,c4,c5,c6,c7,c8;
    cin>>n;
    if(n==2) cin>>c1>>c2;
    if(n==3) cin>>c1>>c2>>c3;
    if(n==4) cin>>c1>>c2>>c3>>c4;
    if(n==5) cin>>c1>>c2>>c3>>c4>>c5;
    if(n==6) cin>>c1>>c2>>c3>>c4>>c5>>c6;
    if(n==7) cin>>c1>>c2>>c3>>c4>>c5>>c6>>c7;
    if(n==8) cin>>c1>>c2>>c3>>c4>>c5>>c6>>c7>>c8;
    if(n%2 ==  1) cout<<"0"<<endl;
    else
    {
        if(c1=='a' || c1=='b') balab = 1;
        if(c1=='c' || c1=='d') balcd = 1;
        if(c2=='a' || c2=='b') balab = balab + 1;
        if(c2=='c' || c2=='d') balcd = balcd + 1;
        if(balab==balcd) broi = 2;
        if(n>3)
        {
            if(c3=='a' || c3=='b') balab = 1;
            if(c3=='c' || c3=='d') balcd = 1;
            if(c4=='a' || c4=='b') balab = balab + 1;
            if(c4=='c' || c4=='d') balcd = balcd + 1;
            if(balab==balcd) broi = 4;
        }
        if(n>5)
        {
            if(c5=='a' || c5=='b') balab = 1;
            if(c5=='c' || c5=='d') balcd = 1;
            if(c6=='a' || c6=='b') balab = balab + 1;
            if(c6=='c' || c6=='d') balcd = balcd + 1;
            if(balab==balcd) broi = 6;
        }
        if(n>7)
        {
            if(c7=='a' || c7=='b') balab = 1;
            if(c7=='c' || c7=='d') balcd = 1;
            if(c8=='a' || c8=='b') balab = balab + 1;
            if(c8=='c' || c8=='d') balcd = balcd + 1;
            if(balab==balcd) broi = 8;
        }
        cout<<broi<<endl;
    }
    return 0;
}
