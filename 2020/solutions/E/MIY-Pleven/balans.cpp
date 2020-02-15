#include<iostream>
using namespace std;
long long n,br1,i,br2,br3,br4,s1,s2,max1,min1;
int main()
{
    char ch;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>ch;
        if(ch=='a') br1++;
        if(ch=='b') br2++;
        if(ch=='c') br3++;
        if(ch=='d') br4++;
    }
    if(br1==0) {cout<<0<<endl;return 0;}
    if(br2==0) {cout<<0<<endl;return 0;}
    if(br3==0) {cout<<0<<endl;return 0;}
    if(br4==0) {cout<<0<<endl;return 0;}
    s1=br1+br2;
    s2=br3+br4;
    max1=s1;
    if(s2>max1) max1=s2;
    min1=s1;
    if(s2<min1) min1=s2;
    while (max1!=min1)
    if(max1>min1) max1--;
    cout<<max1+min1<<endl;

    return 0;
}
