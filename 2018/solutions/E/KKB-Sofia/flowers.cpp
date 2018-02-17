#include <iostream>
using namespace std;
int main(){
long long a;
cin>>a;
long long flowersHight[a-1],water,milimeters,kapki=0;;
for(long h=0;h<a;h++){
    cin>>flowersHight[h];
}
cin>>water;
for(long k=0;k<a;k++){
    if(flowersHight[k]>flowersHight[k+1]){
        milimeters=flowersHight[k];
        flowersHight[k]=flowersHight[k+1];
        flowersHight[k+1]=milimeters;
    }
    kapki=(flowersHight[a-1]-flowersHight[k])*water+kapki;
}
cout<<kapki;
return 0;
}
