#include<iostream>
using namespace std;
int main(){
    char i[4];
    cin>>i;
    long r, o, sc = 0, res[1000][3], finv = 0, finid = 0, d;
    for(short c=999;c>1;c--){
        for(short n=999;n>1;n--){
            r = c*n;
            d = 1;
            o = 0;
            for(long c=3;c>=0;c--){
                if(!(i[c]==119||i[c]==0)){
                    o += (i[c]-'0')*d;
                    d*=10;
                }
            }

            if(r==o){
                res[sc][0] = c;
                res[sc][1] = n;
                res[sc][2] = r;
            }
        }
    }
    for(short c=0;c<=sc;c++)
        if(res[c][2]>finv){finv = res[c][2];finid = c;}
    cout<<res[finid][0]<<' '<<res[finid][1]<<endl<<finv;

    return 0;
}
