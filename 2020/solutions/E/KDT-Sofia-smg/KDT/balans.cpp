#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char a[1000000];
    long long n,razlika=0,ans=0;
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a[i];
        if(a[i]=='a' || a[i]=='b'){
            razlika++;
        }else{
            razlika--;
        }
        if(razlika==0){
            ans=i+1;
        }
    }
    cout<<ans;

    return 0;
}

