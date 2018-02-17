#include <iostream>
using namespace std;
string last="0";
string add(int n, string k, string start)
{
    //uzhasno neefektivno
    string out;
    int naum=0, neshto, br=0;
    while (k.size()<n){
        k="0"+k;
    }
    while (start.size()<n){
        start="0"+start;
    }
    out=start;
    while (br<n){
        last=out;
        br=0;
        for (int i=n-1; i>=0; i--){
            neshto=(int)k[i]-48+(int)out[i]-48;
            out[i]=neshto%10+48;
            //if (neshto+naum>9) naum=1;
            //else naum=0;
            naum=0;
            naum+=neshto/10;
            if (i-1>=0) out[i-1]+=naum;
            for (int j=i-1; j>=0; j--){
                if ((int)out[j]-48>9) {
                    out[j-1]=out[j-1]+1;
                    out[j]-=10;
                }
            }
        }
        //cout<<out<<endl;
        for (int i=0; i<n; i++){
            br=n-i;
            if (out[i]!='0') break;
        }
    }
    //cout<<k<<endl;
    return out;
}
int main()
{
    string k, neshto="0", k1, lastNeshto="!";
    int n, nuli, br;
    cin>>n>>k;
    nuli=n;
    while (nuli>=0){
        k1=k;
        nuli--;
        for (int i=0; i<nuli; i++){
            k1+="0";
        }
        if (k1.size()>n) continue;
        neshto=last;
        neshto=add(n, k1, neshto);
        if (neshto!=lastNeshto) br=0;
        if (neshto==lastNeshto) br++;
        if (br>2) break;
        lastNeshto=neshto;
    }
    cout<<neshto<<endl;

    return 0;
}
