#include<iostream>
using namespace std;
int main()
{
    long long m,k,sum=0,br=0,ch,blizo,razl,x;
    ///m-Kris
    ///k-Eva
    cin>>m>>k;
    while(sum<=k)
    {
        br++;
        cin>>ch;
        if(ch%2==0) {sum=sum+ch;}
        if(m>ch) {razl=m-ch;}
        else {razl=ch-m;}
        if(br==1) {blizo=razl;}
        if(razl<=blizo) {blizo=razl; x=br;}
    }
    cout<<x<<" "<<sum<<endl;
    return 0;
}
