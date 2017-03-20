#include<iostream>

using namespace std;

int main(){
int t,n[100000],x[10000];
int otgs[10000];
int koko=0;

cin>>t;
for(int i=0;i<t;i++){
    cin>>n[i];
    for(int j=0;j<n[i];j++){
        cin>>x[j];
    }
}
for(int i=0;i<t;i++){
    if(n[i]%2==0){
        cout<<n[i]/2<<endl;
    }else{
        cout<<(n[i]/2)+1<<endl;
    }
}


return 0;
}
