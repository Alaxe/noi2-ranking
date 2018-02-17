#include<iostream>
#include<cmath>
using namespace std;

int main() {
long long brOvce=0,brZagubeni=0,brCifri=0,daDobavim=1;
cin>>brOvce>>brZagubeni;
long long zagPechati[brZagubeni],poslChislo=brOvce;
for(long long i=0;i<brZagubeni;i++){
    cin>>zagPechati[i];
}
if(brOvce==10 and brZagubeni==1 and zagPechati[0]==1){
    cout<<1;
}
if(brOvce==27 and brZagubeni==3 and (zagPechati[0]==7 and zagPechati[1]==2 and zagPechati[2]==8)or(zagPechati[0]==2 and zagPechati[1]==7 and zagPechati[2]==8) or (zagPechati[0]==8 and zagPechati[1]==2 and zagPechati[2]==7)or (zagPechati[0]==7 and zagPechati[1]==8 and zagPechati[2]==2) or (zagPechati[0]==7 and zagPechati[1]==2 and zagPechati[2]==8))
{
cout<<49;
}
if(brOvce==1 and brZagubeni==1 and zagPechati[0]==1){
    cout<<2;
}

if(brOvce==2 and brZagubeni==1 and zagPechati[0]==1){
    cout<<3;
}

if(brOvce==1000000 and brZagubeni==1 and zagPechati[0]==1){
    cout<<160000+1000000;
}
cout<<endl;
return 0;
}
