#include<iostream>
using namespace std;
int main()
{
    long long k,n,ch,br=0;
    cin>>n;
    for(ch=1;ch>0;ch++)
        if(ch==n) br++;
        else {br++;ch+1;}
    cout<<br<<endl;
    return 0;
}
