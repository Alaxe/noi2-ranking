#include<iostream>
using namespace std;
int n,bigger_than[100005],original[100005],biggest_free;
int main(){
ios_base::sync_with_stdio(NULL);
cin.tie(NULL);
cout.tie(NULL);
cin>>n;
biggest_free=n;
for(int i=0;i<n;i++) cin>>bigger_than[i];
for(int i=0;i<n;i++){
    for(int k=0;true;k++){
        if(bigger_than[k]==0){
            original[k]=biggest_free;
            bigger_than[k]=-1;
            biggest_free--;
            for(int j=0;j<k;j++) bigger_than[j]--;
            break;
        }
    }
}
for(int i=0;i<n;i++){
    if(i==0) cout<<original[i];
    else cout<<" "<<original[i];
}
return 0;
}
