#include<iostream>
using namespace std;
int main() {
    long long a,b,i,j,c,s,o=0,p;
    cin>>a>>b;
    i=a;
    while(i<=b) {
            s=0;
        for(p=i;p>0;p=p/10) {
            c=p%10;
            s=s+c;
        }
        i=i+s;
        //cout<<i<<" "<<endl;
        o++;
    }
    cout<<o<<endl;


return 0;
}
