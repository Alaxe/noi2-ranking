#include<iostream>
using namespace std;
int main(){
long long o,l,i,b=0,ch=0,h,chis,m;
bool flag=true;
cin>>o;
cin>>l;
long long z[l];
for(i=1;i<=l;i++){
cin>>z[i];
}
while(b<o){
ch++;
h=ch;
while(h!=0){
chis=h%10;
for(m=1;m<=l;m++){
if(chis==z[m]){
flag=false;
break;
}
}
if(flag==false)break;
else{
h=h/10;
}
}
if(flag==true)b++;
else{
flag=true;
}
}
cout<<ch<<endl;
return 0;
}

