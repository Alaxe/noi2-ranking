#include<iostream>
using namespace std;
int main()
{
long long n,k,c=0,br=0;
cin>>n>>k;
if(n==1)
c=k;
else if(n==0)
c=0;
if(n==2)
    br=10;
else if(n==3)
    br=100;
else if(n==4)
    br=1000;
    else if(n==5)
    br=10000;
    else if(n==6)
    br=100000;
    else if(n==7)
    br=1000000;
    else if(n==8)
    br=10000000;
    else if(n==9)
    br=100000000;
    else if(n==10)
    br=1000000000;
    else if(n==11)
    br=10000000000;
    else if(n==12)
    br=100000000000;
    else if(n==13)
    br=1000000000000;
    else if(n==14)
    br=10000000000000;
    else if(n==15)
    br=100000000000000;
    else if(n==16)
    br=1000000000000000;
    else if(n==17)
    br=10000000000000000;
    else if(n==18)
    br=100000000000000000;
for(n=2;c%k!=0;br++)
{
    c=10;
    if(c%k!=0)
        c++;

}
for(n=3;c%k!=0;br++)
{
    c=100;

    if(c%k!=0)
        c++;


}
for(n=4;c%k!=0;br++)
{
    c=1000;

    if(c%k!=0)
        c++;


}
for(n=5;c%k!=0;br++)
{
    c=10000;

    if(c%k!=0)
        c++;



}
for(n=6;c%k!=0;br++)
{
    c=100000;

    if(c%k!=0)
        c++;

}
for(n=7;c%k!=0;br++)
{
    c=1000000;

    if(c%k!=0)
        c++;



}
for(n=8;c%k!=0;br++)
{
    c=10000000;

    if(c%k!=0)
        c++;



}
for(n=9;c%k!=0;br++)
{
    c=100000000;

    if(c%k!=0)
        c++;



}
for(n=10;c%k!=0;br++)
{
    c=1000000000;

    if(c%k!=0)
        c++;


}
for(n=11;c%k!=0;br++)
{
    c=10000000000;

    if(c%k!=0)
        c++;



}
for(n=12;c%k!=0;br++)
{
    c=100000000000;

    if(c%k!=0)
        c++;



}
for(n=13;c%k!=0;br++)
{
    c=1000000000000;

    if(c%k!=0)
        c++;



}
for(n=14;c%k!=0;br++)
{
    c=10000000000000;

    if(c%k!=0)
        c++;



}
for(n=15;c%k!=0;br++)
{
    c=100000000000000;

    if(c%k!=0)
        c++;


}
for(n=16;c%k!=0;br++)
{
    c=1000000000000000;

    if(c%k!=0)
        c++;



}
for(n=17;c%k!=0;br++)
{
    c=10000000000000000;

    if(c%k!=0)
        c++;

}
for(n=18;c%k!=0;br++)
{
    c=100000000000000000;

    if(c%k!=0)
        c++;
}
cout<<br<<endl;
return 0;
}
