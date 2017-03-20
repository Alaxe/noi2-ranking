#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
using namespace std;
long long i,br,n1,v1,ch,brc1,d;
int brc(int ch2){
    int ch1=0,br1=0;
    ch1=ch2;
    while(ch1>=1){
        ch1/=10;
        br1++;
      //  cout<<ch1<<" "<<br1<<endl;
    }
    return br1;
}
string s;
int main()
{
    cin>>s;
    d=s.size();
    brc1=1;
    ch=2;
    br=1;
    //cout<<brc(24)<<endl;
    while(brc1!=d){
        br++;
        ch=ch*2;
        brc1=brc1+brc(ch);
      //  cout<<br<<" "<<ch<<" "<<brc1<<endl;
    }

    cout<<br<<endl;
    return 0;
}
/*
248163264128256512
*/
