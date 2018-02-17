#include<iostream>
using namespace std;
int main(){
    long long a,br,malk=1,golqm=9;
    cin>>br>>a;
    for(int p=1;p<br;p++){
        malk=malk*10;
        golqm=golqm+9*malk;
    }
    for(long long h=malk;h<=golqm;h++){
        if(h%a==0){
            cout<<h;
            h=golqm+1;
        }
    }
    return 0;
}
