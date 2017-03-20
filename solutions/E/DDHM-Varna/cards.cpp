#include<iostream>
#include<cmath>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<cstring>
#include<cctype>
using namespace std;
int main()
{
    long long n,br=1,mbr=0,a,b,a1,b1;cin>>n;
    cin>>a>>b;a1=a;b1=b;
    for(long long i=2;i<=n;i++){
        cin>>a>>b;
        if((a<=a1&&b<=b1)||(a<=b1&&b<=a1))br++;
        else {
            if(br>mbr)mbr=br;
            br=1;
        }
        a1=a;b1=b;
    }
    if(br>mbr)mbr=br;
    cout<<mbr<<endl;
return 0;
}
