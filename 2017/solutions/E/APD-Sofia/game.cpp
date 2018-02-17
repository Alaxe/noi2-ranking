#include <iostream>
using namespace std;
int main () {
    int m,k,sum=0,b,c,d,br=0;
    cin>>m>>k;
    while(sum<k and c!=200) {
        cin>>c;
        br++;
        if(c>m and br==1) {
            d=c-m;
        } else if(m>c and br==1) {
            d=m-c;
        }
        if(c%2==0) {
            sum=sum+c;
        }
        if((m-c)<=d and c<=m) {
            d=m-c;
            b=br;
        } else if(c>m and (c-m)<=d) {
            d=c-m;
            b=br;
        }
    }
    cout<<b<<" "<<sum;
    return 0;
}
