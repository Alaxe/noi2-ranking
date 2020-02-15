#include <iostream>
using namespace std;
int main(){
int n;
cin>>n;
char x[n];
for(int i=0;i<n;i++){
    cin>>x[i];
}
int naiDulOts=0;
int br[2]={0,0};
for(int i=0;i<n;i++){
    if(x[i]=='a' || x[i]=='b'){
        br[0]++;
    }else{
        br[1]++;
    }
    if(br[0]==br[1]){
        naiDulOts=br[1]+br[0];
    }
}
cout<<naiDulOts<<endl;
return 0;
}

