#include <iostream>
using namespace std;
int main (){
long long nomernamin,minrazlika,chislo,suma,m,k;
cin>>m>>k;
bool dasprali=false;
long long nomer=0;
minrazlika=1000000000000;
suma=0;
for(;dasprali==false and nomer<200;){
    nomer++;
    cin>>chislo;
    if(chislo>m){
        if(chislo-m<=minrazlika){nomernamin=nomer;minrazlika=chislo-m;/*cout<<minrazlika;*/}
    }
    else{
        if(m-chislo<=minrazlika){nomernamin=nomer;minrazlika=m-chislo;/*cout<<minrazlika;*/}
    }
    if(chislo%2==0)suma+=chislo;
    if(suma>k)dasprali=true;
}
//cout<<nomer;
cout<<nomernamin<<" ";
cout<<suma;
cout<<endl;
return 0;
}
/*
7 30
1
3
12
8
25
6
14
*/
