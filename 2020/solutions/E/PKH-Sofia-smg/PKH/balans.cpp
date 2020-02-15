#include<iostream>
using namespace std;
int main()
{
long long n;
char a[1000000];
long long ata=0,bta=0,cta=0,dta=0,kata,kbta,kcta,kdta,x=0;
bool minavai=true;
cin>>n;
for(int i=0;i<n;i=i+1){
    cin>>a[i];
    if(a[i]=='a'){
        ata++;
    }
    if(a[i]=='b'){
        bta++;
    }
    if(a[i]=='c'){
        cta++;
    }
    if(a[i]=='d'){
        dta++;
    }
}
kata=ata;
kbta=bta;
kcta=cta;
kdta=dta;
ata=0;
bta=0;
cta=0;
dta=0;
while(minavai==true){
if(ata!=kata&&bta!=kbta&&cta!=kcta&&dta!=kdta){
    ata=ata+1;
    bta=bta+1;
    cta=cta+1;
    dta=dta+1;
}
x=x+1;
if(ata+x+x+x+bta+x+x+x==cta+x+x+x+dta+x+x+x&&ata+x+x+x<=kata&&bta+x+x+x<=kbta&&cta+x+x+x<=kcta&&dta+x+x+x<=kdta){
   cout<<ata+bta+cta+dta+x*12;
   minavai=false;
}else{
if(ata+x+x+bta+x+x==cta+x+x+dta+x+x&&ata+x+x<=kata&&bta+x+x<=kbta&&cta+x+x<=kcta&&dta+x+x<=kdta){
   cout<<ata+bta+cta+dta+x*8;
   minavai=false;
}else{
if(ata+x+bta+x==cta+x+dta+x&&ata+x<=kata&&bta+x<=kbta&&cta+x<=kcta&&dta+x<=kdta){
   cout<<ata+bta+cta+dta+x*4;
   minavai=false;
}else{
if(ata+bta==cta+dta&&ata!=0&&bta!=0&&cta!=0&&dta!=0){
    cout<<ata+bta+cta+dta;
    minavai=false;
}else{
    minavai=false;
    cout<<0;
}
}
}
}
}
return 0;
}
