#include<iostream>
using namespace std;
int main(){
    long long kris, eva;
    cin>>kris>>eva;
    long long sum=0;
    long long vuv;
    long long razl;
    long long index=1;
    long long hidi;
    while(true){
            cin>>vuv;
            if(index==1){
                    if(vuv>=kris) razl=vuv-kris;
                    else razl=kris-vuv;
                    hidi=index;
            }else{
                if(vuv>=kris){
                        if(vuv-kris<=razl){

                                hidi=index;
                                razl=vuv-kris;
                        }
                }else{
                    if(kris-vuv<=razl){

                            hidi=index;
                            razl=kris-vuv;
                    }
                }
            }
            if(vuv%2==0){
                    sum+=vuv;
            }
            if(sum>eva || index==200) goto exit;
            index++;
    }
    exit:
    cout<<hidi<<" "<<sum;
    return 0;
}



