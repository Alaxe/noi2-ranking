#include<iostream>
using namespace std;
long long razmerDulj[100000],razmerShir[100000];
int main(){
    long long NkolkoKarti, indexCin, posl=1, index, maxPosl=0;
    cin>>NkolkoKarti;
    for(indexCin=0;indexCin<NkolkoKarti;indexCin++){
        cin>>razmerDulj[indexCin]>>razmerShir[indexCin];
    }
    for(index=0;index<NkolkoKarti;index++){
        if((razmerDulj[index]==razmerDulj[index+1] || razmerDulj[index]==razmerShir[index+1] || razmerShir[index]==razmerShir[index+1] || razmerDulj[index]==razmerDulj[index+1]) && razmerDulj[index]*razmerShir[index]>=razmerDulj[index+1]*razmerShir[index+1]){
            posl++;
        }else{
            if(maxPosl<posl){
                maxPosl=posl;
            }
            posl=1;
        }
    }
    cout<<maxPosl;
    cout<<endl;
return 0;
}
