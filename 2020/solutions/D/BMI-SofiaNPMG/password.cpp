#include<iostream>
using namespace std;
char a[50000];
int main(){

    long long i=0,br=0,n;
    for(i=0;cin>>a[i];i++){
        br++;
    }
    for(i=0;i<br;i++){
        if(a[i]==a[i+2]&&a[i+2]==a[i+1]){
            if(a[i+1]!='a'&&a[i+2]!='a'||a[i+3]!='a'&&a[i+4]=='a'){
                a[i+2]='a';
            }else{
                a[i+2]='b';
            }
        }
    }
    for(i=0;i<br;i++){
        cout<<a[i];
    }
    cout<<endl;
return 0;
}
