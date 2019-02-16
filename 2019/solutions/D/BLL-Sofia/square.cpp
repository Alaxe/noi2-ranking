#include<iostream>
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
long long n,i1,i,broiDelqshtiSeChilsa=0,nok,deliteli[100000],broiRaslichniDeliteli,otg=1;
long long broiD=0,a;
bool naPredenPutLiE=false;
cin>>n;
long long chisla[n];
for(i=0;i<n;i++){
    cin>>chisla[i];
}
for(i1=1;broiDelqshtiSeChilsa!=n;i1++){
    for(i=0;i<n and broiDelqshtiSeChilsa!=n;i++){
        if(i1%chisla[i]==0){
            broiDelqshtiSeChilsa++;
        }else{
            broiDelqshtiSeChilsa=0;
            i=n;
        }
    }
}
nok=i1-1;
i1=0;
broiRaslichniDeliteli=0;
long long nok1=nok;
for(i=2;nok1>1;){
    if(nok1%i==0){
        deliteli[i1]=i;
        i1++;
        nok1/=i;
        if(deliteli[i1-2]!=deliteli[i1-1]){
            broiRaslichniDeliteli++;
        }
    }else{
        i++;
    }
}
i=0;
i1=0;
long long kolkoPutiSeSreshta[broiRaslichniDeliteli],koiE[broiRaslichniDeliteli];
for(long long n=0;n<broiRaslichniDeliteli;n++){
    kolkoPutiSeSreshta[n]=0;
}
for(long long f=2;deliteli[i]!=0;){
    if(deliteli[i]==f){
        naPredenPutLiE=true;
        kolkoPutiSeSreshta[i1]++;
        koiE[i1]=f;
        i++;
    }else{
        if(naPredenPutLiE){
            i1++;
        }
        f++;
        naPredenPutLiE=false;
    }
}
for(i=0;i<broiRaslichniDeliteli;i++){
    if(kolkoPutiSeSreshta[i]%2!=0){
        kolkoPutiSeSreshta[i]++;
        kolkoPutiSeSreshta[i]/=2;
    }else{
        kolkoPutiSeSreshta[i]/=2;
    }
}
i=0;
for(broiD=0;deliteli[broiD]!=0;broiD++){}
for(a=0;a<broiRaslichniDeliteli;a++){
    for(i1=0;i1<kolkoPutiSeSreshta[i];i1++){
        otg=koiE[i]*otg;
    }
    i++;
}
cout<<otg<<endl;
return 0;
}
