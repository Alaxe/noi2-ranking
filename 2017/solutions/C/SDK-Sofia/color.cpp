#include<iostream>
using namespace std;
int main(){
    int n, i;
    cin>>n;
    int m[n];
    for(i=0;i<n;i++){
        cin>>m[i];
        int mm[m[i]];
        for(int j=0;j<m[i];j++){
            cin>>mm[i];
        }
    }
    for(i=0;i<n;i++){
        if(m[i]%2==0){
            cout<<(m[i]/2)<<endl;
        }else{
            cout<<(m[i]/2)+1;
        }
    }
    return 0;
}
