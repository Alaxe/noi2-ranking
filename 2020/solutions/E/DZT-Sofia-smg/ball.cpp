#include<iostream>
using namespace std;
int main(){
long long mas[3]={0,1,2},br_dejstwiq,x,kopienaneshto;
cin>>br_dejstwiq>>x;
for(long long g=1;g<=br_dejstwiq;g++){
    if(g%2==0){
       kopienaneshto=mas[2];
       mas[2]=mas[1];
       mas[1]=kopienaneshto;
    }
    else{
        kopienaneshto=mas[0];
        mas[0]=mas[1];
        mas[1]=kopienaneshto;
    }
}
cout<<mas[x]<<endl;
return 0;
}
