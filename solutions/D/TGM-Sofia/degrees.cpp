# include<iostream>
# include<cstring>
using namespace std;

int main(){
    char N[160001];
    cin >> N;
    long long a=0,i=0,st=1,p=1,k,b=0;
    while(a==0){
        p*=2;
        k=p;
        while(k!=0){
            k=k/10;
            i++;
        }
        if(i==strlen(N)){
            a++;
        }
        b++;
    }
    cout << b << endl;
return 0;
}
