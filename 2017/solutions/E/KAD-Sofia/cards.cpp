#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int raz[n*2],i,i2,broi=0,naigolqm=-1;
    for(i=0;i<n*2;i++){
            cin>>raz[i];
    }
    i2=3;
    for(i=2;i<n*2;i=i+2){
            if((raz[i]<=raz[i-2] and raz[i2]<=raz[i2-2]) or (raz[i]<=raz[i2-2] and raz[i2]<=raz[i-2])){
                    broi++;
            }else{
                    if(broi>0){
                            broi++;
                    }
                    if(broi>naigolqm){
                            naigolqm=broi;
                    }
                    broi=0;
            }
            i2=i2+2;
    }

    if(broi==n-1){
            naigolqm=n;
    }
    if(broi>0){
            broi++;
            if(broi>naigolqm){
                    naigolqm=broi;
            }
    }
    cout<<naigolqm<<endl;
return 0;
}
