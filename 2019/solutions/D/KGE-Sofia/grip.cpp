#include<iostream>
using namespace std;
long long mes[12]{31,29,31,30,31,30,31,31,30,31,30,31};
long long stch(string s){
  long long chislo=0,des=1;
  for(long long j=s.size()-1;j>=0;j--){
      chislo+=(s[j]-'0')*des;
  des*=10;
  }
  return chislo;
}
int main(){
long long dens=5,gode,me,de,broi=0,ko=0,broi2=0;
string a,chi;
cin>>a>>broi;
for(long long d=0;d<a.size();d++){
    if(a[d]=='/' || d==a.size()-1){
       if(ko==0){
        de=stch(chi);
       }if(ko==1){
       me=stch(chi);
       }if(ko==2){
       chi+=a[d];
       gode=stch(chi);
       }
       chi="";
       ko++;
    }else{
       chi+=a[d];
    }
}
bool koga=0,dali=1;
for(long long godina=2019;godina<2020 && dali;godina++){
    for(long long meso=0;meso<12 && dali;meso++){
      for(long long den=1;den<=mes[meso] && dali;den++){
        if(den==29 && meso==1){
            if((godina%4==0 && !(godina%100==0)) || (godina%400==0)){
                 if(godina==gode && meso==me-1 && den==de){
                    koga=1;

                 }
                 if(koga && dens!=6 && dens!=7){
                    broi2++;
                 }
                 if(dens+1==8){
                    dens=1;
                 }else{
                    dens++;
                 }
            }
            }else{
                 if(godina==gode && meso==me-1 && den==de){
                    koga=1;
                 }
                 if(koga && dens!=6 && dens!=7){
                    broi2++;
                 }
                 if(dens+1==8){
                    dens=1;
                 }else{
                    dens++;
                 }
             }
             if(broi2==broi+1){
                if(den<10){
                    cout<<"0"<<den<<".";
                }else{
                cout<<den<<".";
                }if(meso<10){
                    cout<<"0"<<meso+1<<".";
                }else{
                cout<<meso+1<<".";
                }
                cout<<godina;
                    dali=0;
                    break;
             }
        }
     }
}
return 0;
}
