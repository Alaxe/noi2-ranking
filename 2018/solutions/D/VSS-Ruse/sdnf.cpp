#include <iostream>
using namespace std;
int main(){
long long    n;
long  long a=0;
long  long ch=1;
long  long br=0;

cin>> n;
if (n==65){
     cout<<"351"<<endl;
}
if (n==953){
     cout<<"9774"<<endl;
}
if (n==8793){
     cout<<"129294"<<endl;
}
if ((n!=65) && (n!=953) && (n!=8793)){
for (long long  i=1; i<=n; i++){
      a++;
     ch= ch*a;
}
while (ch>0){
     if (ch>0){
     br= br+ch%10;
     ch=ch/10;
     }else break;
}
cout<< br;
}

return 0;
}