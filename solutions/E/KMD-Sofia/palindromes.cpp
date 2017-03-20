#include <iostream>

using namespace std;
int main (){
long long seg,chislo1,chislo2,n;
cin>>n;
for(long long g=n-1;g>0;g--){
    for(long long h=n-1;h>0;h--){
        seg=g*h;
        //cout<<1;
        if(seg<100 and seg>9){//2
            if(seg%10==seg/10){if(g<=h){cout<<g<<" "<<h<<endl;}else{cout<<h<<" "<<g<<endl;}cout<<seg<<endl;return 0;}
        }
        if(seg<1000 and seg>99){//3
            if(seg/100==seg%10){if(g<=h){cout<<g<<" "<<h<<endl;}else{cout<<h<<" "<<g<<endl;}cout<<seg<<endl;return 0;}
        }
        if(seg<10000 and seg>999){//4
            if(seg/1000==seg%10 and seg/10%10==seg/100%10){if(g<=h){cout<<g<<" "<<h<<endl;}else{cout<<h<<" "<<g<<endl;}cout<<seg<<endl;return 0;}
        }
        if(seg<100000 and seg>9999){//5
            if(seg/10000==seg%10 and seg/10%10==seg/1000%10){if(g<=h){cout<<g<<" "<<h<<endl;}else{cout<<h<<" "<<g<<endl;}cout<<seg<<endl;return 0;}
        }
        if(seg<1000000 and seg>9999){//6
            if(seg/100000==seg/10 and seg/10%10==seg/10000%10 and seg/100%10==seg/1000%10){if(g<=h){cout<<g<<" "<<h<<endl;}else{cout<<h<<" "<<g<<endl;}cout<<seg<<endl;return 0;}
        }
    }
}
return 0;
}
