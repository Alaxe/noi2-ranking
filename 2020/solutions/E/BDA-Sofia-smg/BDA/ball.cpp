#include<iostream>
using namespace std;
int main(){
long long n,x,hod,topchetoEVchasha;
cin>>n>>x;
topchetoEVchasha=x;
for(hod=n;hod>=1;hod=hod-1){
    if(hod%2==0){
        if(topchetoEVchasha==2){
            topchetoEVchasha=1;
        }else{
            if(topchetoEVchasha==1){
                topchetoEVchasha=2;
            }else{
               if(topchetoEVchasha==0){
                   topchetoEVchasha=0;
               }
            }
        }
    }else{
        if(topchetoEVchasha==2){
            topchetoEVchasha=2;
        }else{
            if(topchetoEVchasha==1){
                topchetoEVchasha=0;
            }else{
                 if(topchetoEVchasha==0){
                    topchetoEVchasha=1;
                 }
            }
        }
    }
}
cout<<topchetoEVchasha<<endl;
return 0;
}
