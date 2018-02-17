#include <iostream>
using namespace std;
int main (){
long long proverka=0,broiA=0,chislo=1,napechatani=0,broqchka,n,l;
cin>>n>>l;
long long a[l];
for(broqchka=0;broqchka<l;broqchka++){
    cin>>a[broqchka];
    broiA++;
}
while(napechatani<n){
        for(broqchka=0;broqchka<l;broqchka++){
    if(chislo!=a[broqchka] and chislo%10!=a[broqchka] and (chislo/10)%10!=a[broqchka] and ((chislo/10)/10)%10!=a[broqchka]  and (((chislo/10)/10)/10)%10!=a[broqchka] and ((((chislo/10)/10)/10)/10)%10!=a[broqchka] and (((((chislo/10)/10)/10)/10)/10)%10!=a[broqchka]) {
            proverka++;
       }
        }
    if(proverka==broiA){
        napechatani++;
    }
    chislo=chislo+1;
    proverka=0;
}
cout<<chislo-1;
return 0;
}
