#include<iostream>
using namespace std;
long long den=0,mes=0,god=0,w;
long long months[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
long long monthsf[13]={0,0,31,59,90,120,151,181,212,243,273,304,334};
void uv() {
if (den+1>months[mes]) {
    if (den==28 and mes==2 and god==2020) den++;
    else {
            den=1;
            mes++;
           if (mes>12) {mes=1;god++;}
    }
}
else den++;
}
int main () {
string date;
cin>>date;
for ( w=0;date[w]!='/';w++) den=den*10+(date[w]-'0');
for (w=w+1;date[w]!='/';w++) mes=mes*10+(date[w]-'0');
for (w=w+1;w<date.size();w++)god=god*10+(date[w]-'0');
long long uchd;
cin>>uchd;
long long ds,td=0;
td=td+((god-2019)*365);
if (god==2020 and mes>2) td=td+monthsf[mes]+1;
else td=td+monthsf[mes];
td=td+den;
ds=td%7+1;
cout<<ds<<endl;
if (ds==7){ uv();ds=1;}
if (ds==6) {uv();uv();ds=1;}
for (int q=0;q<uchd;q++) {
  if (ds>5) {
    uv();uv();ds=1;
  }
 // cout<<den<<" "<<mes<<" "<<god<<" "<<ds<<endl;
  uv();
  ds++;
}
if (ds>5) {uv();uv();}
if (den<10) cout<<"0"<<den<<".";
else cout<<den<<".";
if (mes<10) cout<<"0"<<mes<<".";
else cout<<mes<<".";
cout<<god<<endl;
}
