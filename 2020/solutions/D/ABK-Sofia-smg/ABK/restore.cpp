#include<bits/stdc++.h>
using namespace std;
long long a[100000];
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
long long br;
cin>>br;
bool f=true;
for(long long i=0;i<br;i++){
    cin>>a[i];
    if( a[i]!=0){
        f=false;
    }
}
if(f==true){
    for(long long i=0;i<br;i++){
        cout<<br-i<<" ";
    }
}
else{
    for(long long i=0;i<br;i++){
        cout<<i+1<<" ";
    }
}


return 0;
}

