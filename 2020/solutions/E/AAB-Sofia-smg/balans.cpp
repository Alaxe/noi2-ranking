#include<iostream>
#include<string>
using namespace std;
int main(){
 string s;
 int n,nai_G=0,a_b=0,c_d=0;
 cin>>n;
 cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='a'||s[i]=='b'){
            a_b++;
        }
        if(s[i]=='c'||s[i]=='d'){
            c_d++;
        }
        if(a_b==c_d){

            nai_G=a_b+c_d;
        }
    }

cout<<nai_G;
return 0;
}
