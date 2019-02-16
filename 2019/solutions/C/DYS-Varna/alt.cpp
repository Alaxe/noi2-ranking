#include<iostream>
using namespace std;
int a[51];
long long br=0;
int main()
{
    int k, m, n;
    cin>>k>>m>>n;
    for(int i=1;i<m;i++)
    {
        int brd=(m-i-1)/k;
        int brg=(i-1)/k;
        if(brd>0 && brg>0) br+=(brd+brg)*2;
        else if(brg>0) br+=brg;
        else if(brd>0) br+=brd;
    }
    cout<<br<<endl;
    return 0;
}
