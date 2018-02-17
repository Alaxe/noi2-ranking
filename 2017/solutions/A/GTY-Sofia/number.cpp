#include<iostream>
#include<cmath>
using namespace std;


int main()
{
    long long M,N;
    cin>>M>>N;
    long long sqrtm =sqrt(M);
    long long sqrtn =sqrt(N);
    long long f ;
    if(sqrtm * (sqrtm+1) >=M ){f = sqrtm * (sqrtm+1);}
    else {f = (sqrtm+1) * (sqrtm+2);sqrtm = sqrtm+1;}
    //cout<<f<<" "<<sqrtm<<endl;
    long long l;
    if(sqrtn * (sqrtn+1) <=N )l = sqrtn * (sqrtn+1);
    else {l = (sqrtn-1) * (sqrtn);sqrtn = sqrtn-1;}
    //cout<<l<<" "<<sqrtn<<endl;
    long long x = l-f;
    if((x-(sqrtn-sqrtm)*(sqrtn-sqrtm+1))/(2*sqrtm)+1<=0) {cout<<0<<endl;return 0;}
    cout<<(x-(sqrtn-sqrtm)*(sqrtn-sqrtm+1))/(2*sqrtm)+1<<endl;

    return 0;
}
