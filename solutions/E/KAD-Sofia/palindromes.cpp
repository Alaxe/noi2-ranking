#include<iostream>
using namespace std;
int main(){
    int n,i,i2,naigolqmo=-1,proizvedenie,ni=-1,ni2=-1;
    cin>>n;
    for(i=0;i<n;i++){
            for(i2=0;i2<n;i2++){
                        proizvedenie=i*i2;
                        if(proizvedenie/1>=1 and proizvedenie/1<=9){
                                if(proizvedenie>naigolqmo){
                                        ni=i;
                                        ni2=i2;
                                        naigolqmo=proizvedenie;
                                }
                        }
                        if(proizvedenie/10>=1 and proizvedenie/10<=9){
                                if(proizvedenie/10==proizvedenie%10){
                                        if(proizvedenie>naigolqmo){
                                                ni=i;
                                                ni2=i2;
                                                naigolqmo=proizvedenie;
                                        }
                                }

                        }
                        if(proizvedenie/100>=1 and proizvedenie/100<=9){
                                if(proizvedenie/100==proizvedenie%100%10){
                                        if(proizvedenie>naigolqmo){
                                                ni=i;
                                                ni2=i2;
                                                naigolqmo=proizvedenie;
                                        }
                                }
                        }
                        if(proizvedenie/1000>=1 and proizvedenie/1000<=9){
                                if(proizvedenie/1000==proizvedenie%1000%100%10 and proizvedenie%1000/100==proizvedenie%1000%100/10){
                                        if(proizvedenie>naigolqmo){
                                                ni=i;
                                                ni2=i2;
                                                naigolqmo=proizvedenie;
                                        }
                                }
                        }
                        if(proizvedenie/10000>=1 and proizvedenie/10000<=9){
                                if(proizvedenie/10000==proizvedenie%10000%1000%100%10 and proizvedenie%10000/1000==proizvedenie%10000%1000%100/10){
                                        if(proizvedenie>naigolqmo){
                                                ni=i;
                                                ni2=i2;
                                                naigolqmo=proizvedenie;
                                        }
                                }
                        }
                        if(proizvedenie/100000>=1 and proizvedenie/100000<=9){
                                if(proizvedenie/100000==proizvedenie%100000%10000%1000%100%10 and proizvedenie%100000/10000==proizvedenie%100000%10000%1000%100/10 and proizvedenie%100000%10000/1000==proizvedenie%100000%10000%1000/100){
                                        if(proizvedenie>naigolqmo){
                                                ni=i;
                                                ni2=i2;
                                                naigolqmo=proizvedenie;
                                        }
                                }
                        }
                        if(proizvedenie/1000000>=1 and proizvedenie/1000000<=9){
                                if(proizvedenie/1000000==proizvedenie%1000000%100000%10000%1000%100%10 and proizvedenie%1000000/100000==proizvedenie%1000000%100000%10000%1000%100/10 and proizvedenie%1000000%100000%10000/10000==proizvedenie%1000000%100000%10000%1000/100){
                                        if(proizvedenie>naigolqmo){
                                                ni=i;
                                                ni2=i2;
                                                naigolqmo=proizvedenie;
                                        }
                                }
                        }
            }
    }
    cout<<ni<<" "<<ni2<<endl<<naigolqmo<<endl;
return 0;
}
