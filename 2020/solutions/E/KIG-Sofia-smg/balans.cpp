#include<iostream>
using namespace std;
int main(){
    int n,aib=0,cid=0,u=0;
    cin>>n;
    char a[n];
    cin>>a;
    for(int i=0;i<n;i++){
        if(a[i]=='a' || a[i]=='b'){
            aib++;
        }else{
            cid++;
        }
        if(aib==cid){
            u=aib+cid;
        }
    }
    cout<<u;
    return 0;
}
