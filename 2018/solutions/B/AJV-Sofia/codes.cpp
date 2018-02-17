#include<iostream>
#include<cmath>
using namespace std;
long long n,k,a,b,otg,cifri[101],zapis[10001],f=0,st,ngo,nmo=10;
long long pusni(long long c,long long d,long long dg,long long ch){
    //cout<<c<<" "<<d<<" "<<dg<<" "<<ch<<"\n";
    if(f==k){
        return 0;
    }
    st/=n;
   // cin>>otg;
if(c==d){
        for(long long i=f;i<k;i++){
            if(ch==-1){
                zapis[i]=cifri[0];
            }else{
                zapis[i]=cifri[n-1];
            }
        }
    return c;
}
long long z1=dg,br=0,ng=0,bre,dobavi=ch,chbre,brech;
if(dobavi==-1){
while(z1<c){
        //cout<<z1;
z1+=st;
br+=ch;
}

bre=z1;
ng=cifri[(n-1+br)%n];
brech=br%2;
if((brech==0 and ch==1) or (abs(brech)==1 and ch==-1)){
    brech=1;
}else{
    brech=-1;
}//cout<<z1<<" "<<bre<<" "<<brech<<"\n";
//cin>>a;

bool dali=true;
if((d-c+1)>st){
        otg=(ngo-nmo);
        //cout<<ng;
while(z1<d){
    //cout<<ng<<"z1"<<z1;
if(cifri[(n-1+br)%n]>ng){
        ng=cifri[(n-1+br)%n];
    dali=false;
}
br+=ch;
z1+=st;
}
//cout<<"oiqdwqdjqwj"<<ng<<br<<" "<<cifri[(n-1+br)%n];
if(cifri[(n-1+br)%n]>ng and (z1-st)!=d){
        //cout<<"tak";
zapis[f]=cifri[(n-1+br)%n];
f++;
if((br%2==0 and ch==1) or (abs(br%2)==1 and ch==-1)){
return pusni(z1,d,z1,ch);
}else{
return pusni(z1,d,z1,((-1)*ch));
}
}
if(dali==false){
        zapis[f]=ng;
for(long long i=f+1;i<n;i++){
zapis[i]=ngo;
}
return 0;
}else{
    //cout<<"tuk";
zapis[f]=ng;
f++;
return pusni(a,min((bre+st),d),bre,brech);
}
}else{
    //cout<<"tuk";
zapis[f]=ng;
//cout<<zapis[f];
f++;
return pusni(a,min((bre+st),d),bre,brech);
}
}else{
    while(z1<c){
        //cout<<z1;
z1+=st;
br+=ch;
}

bre=z1;
if(z1!=c){
ng=cifri[br-1];
}else{
ng=cifri[br];
}
brech=br%2;
if((brech==0 and ch==1) or (abs(brech)==1 and ch==-1)){
    brech=1;
}else{
    brech=-1;
}//cout<<z1<<" "<<bre<<" "<<brech<<"\n";
//cin>>a;

bool dali=true;
if((d-c+1)>st){
        //cout<<ng;
while(z1<d){
    //cout<<ng<<"z1"<<z1;
if(cifri[br]>ng){
        ng=cifri[br];
    dali=false;
}
br+=ch;
z1+=st;
}
//cout<<"oiqdwqdjqwj"<<ng<<br<<" "<<cifri[br];
if(cifri[br]>ng and (z1-st)!=d){
        //cout<<"tak";
zapis[f]=cifri[br];
f++;
if((br%2==0 and ch==1) or (abs(br%2)==1 and ch==-1)){
return pusni(z1,d,z1,ch);
}else{
return pusni(z1,d,z1,((-1)*ch));
}
}
if(dali==false){
        zapis[f]=ng;
for(long long i=f+1;i<n;i++){
zapis[i]=ngo;
}
return 0;
}else{
    //cout<<"tuk";
zapis[f]=ng;
f++;
return pusni(a,min((bre+st),d),bre,brech);
}
}else{
    //cout<<"tuk";
zapis[f]=ng;
//cout<<zapis[f];
f++;
return pusni(a,min((bre+st),d),bre,brech);
}
}
}
int main(){
cin>>n>>k>>a>>b;
a--;
b--;
for(long long i=0;i<n;i++){
    cin>>cifri[i];
    ngo=max(ngo,cifri[i]);
    nmo=min(nmo,cifri[i]);
}
otg=(ngo-nmo);
st=n;
for(long long i=0;i<(k-1);i++){
    st*=n;
}
pusni(a,b,0,1);
for(long long i=0;i<k;i++){
    cout<<zapis[i];
}
cout<<" "<<otg<<"\n";
return 0;
}
// 3 2 3 5 7 1 5
// 3 3 10 16 7 1 5
