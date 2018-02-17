#include<iostream>
#include<cstring>
using namespace std;
char n[1302];
int main(){
    cin>>n;
    int d=strlen(n);
    for(int i=0;i<d-i;i++){
        while(n[i]!=n[d-i-1]){
            n[d-i-1]+=1;
            for(int k=0;n[d-i-1-k]>'9';k++){
                n[d-i-k-1]='0';
                n[d-i-k-2]++;
            }
        }
    }
    for(int i=0;i<d;i++){
        cout<<n[i];
    }
    cout<<endl;
return 0;
}
