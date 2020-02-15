#include<iostream>
using namespace std;
int main(){
    long long n,naiDulugOtrez=0,br_AB=0,br_CD=0;
    cin>>n;
    char bukvi[n];
    cin>>bukvi;
    for(int i=n/2;i>0;i--){
        for(int x=0;x<i*2;x++){
            if(bukvi[x]=='a' || bukvi[x]=='b')
                br_AB++;
            else
                br_CD++;
        }
        if(br_AB==br_CD)
            break;
        br_AB=0;
        br_CD=0;
    }
    cout<<br_AB*2;
return 0;}
