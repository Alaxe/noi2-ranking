#include<iostream>
using namespace std;

long long fact(long long a){
    if(a>1){
        long long buf=a*fact(a-1);
        while(buf%10==0){
            buf/=10;
        }
        return(buf);
    }else{
        return 1;
    }
}
int main(){
    long long n;
    cin >> n;
    long long otg=0;
    if(n%3==0 and n%12!=0 and n!=3 and n!=6){
        otg=n*3;
    }else{
        long long rez=fact(n);
        while(rez>0){
            otg+=rez%10;
            rez/=10;
        }
    }
    cout << otg << endl;
return 0;
}

