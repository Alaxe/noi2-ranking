#include<iostream>
 using namespace std;
 int main(){
 char p[2048];
 long long l=0,m=0,sum=0,n;
 cin>>n;
 cin>>p;
 for(int i=0;p[i]!='\0';i++){
   if(p[i]=='a'||p[i]=='b'){
      l++;
   }
   else{
   if(p[i]=='c'||p[i]=='d'){
      m++;
   }
   }
   if(l==m){sum++;}
 }
 cout<<sum;
 }
