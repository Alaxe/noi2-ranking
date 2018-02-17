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
    long long sum=0,number=0,mraz=1000000,br=0,a,k,m;cin>>m>>k;
    while(sum<=k&&br<200){
        cin>>a;br++;
        if(a%2==0)sum+=a;
        if(a>m){if(a-m<=mraz){number=br;mraz=a-m;}}
        else if(m-a<=mraz){number=br;mraz=m-a;}
    }
    cout<<number<<" "<<sum<<endl;
return 0;
}
