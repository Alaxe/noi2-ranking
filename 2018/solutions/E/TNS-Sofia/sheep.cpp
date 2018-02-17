#include <iostream>
using namespace std;
int main () {
long long n, l, zagubeni[3], edn, ost, ed, d, s, h, dh, sh, m, a;
cin>>n;
cin>>l;
for(int i=0; i<=l-1; i++){
    cin>>zagubeni[i];
}
edn=9-l;
ost=n-edn;
for(int k=10; k<=1000000; k++){
ed=k%10;
d=(k%100)/10;
s=(k%1000)/100;
h=(k%10000)/1000;
dh=(k%100000)/10000;
sh=(k%1000000)/100000;
m=(k%10000000)/1000000;
if((zagubeni[0]!=ed) and (zagubeni[0]!=d) and (zagubeni[0]!=s) and (zagubeni[0]!=h)and(zagubeni[0]!=dh) and (zagubeni[0]!=sh) and (zagubeni[0]!=m)){
    if((zagubeni[1]!=ed) and (zagubeni[1]!=d) and (zagubeni[1]!=s) and (zagubeni[1]!=h) and (zagubeni[1]!=dh) and (zagubeni[1]!=sh) and (zagubeni[1]!=m)){
        if((zagubeni[2]!=ed) and (zagubeni[2]!=d) and (zagubeni[2]!=s) and (zagubeni[2]!=h)and (zagubeni[2]!=dh) and (zagubeni[2]!=sh) and (zagubeni[2]!=m)){
                ost--;

}
}
}
if(ost==0){
    break;
}
a=k;
}
cout<<a+1;
return 0;
}
