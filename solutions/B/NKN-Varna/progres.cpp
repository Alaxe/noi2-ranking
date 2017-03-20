#include<iostream>
#include<vector>
using namespace std;
int main(){
    int d,n,red[1024],br=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>red[i];
    }
       int suma[1024]={0},maxi[1024]={0};
    for(int i=0;i<n;i++){
       for(int j=i;j<=n;j++){
            if(red[i]<red[j]) {
                br++;
                if(red[j]>maxi[red[j]-red[i]] && red[i]==maxi[red[j]-red[i]] || suma[red[j]-red[i]]==0) {
                    maxi[red[j]-red[i]]=red[j];
                    suma[red[j]-red[i]]++;
                }
                if(suma[red[j]-red[i]]>1){
                    br++;
                }
            }
        }
    }
    cout<<br<<endl;
    return 0;
}
