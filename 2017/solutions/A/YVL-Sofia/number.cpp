#include<iostream>
#include<cmath>

using namespace std;
int main(){
    int m, n;
    cin>>m>>n;
    long long ma=ceil((sqrt(1+4*m)-1)/2.0);
    long long na=floor((sqrt(1+4*n)-1)/2.0);
    cout<<na-ma+1<<"\n";
    return 0;
}
