#include<iostream>
#include<cstring>
using namespace std;
int main (){

int br=0,br2=0;
char password[5001];

cin>>password;

for(int i=1;i<strlen(password);i++){
    if(password[i]==password[i-1]){
        br++;
    }else{
        br=0;
    }
    if(br>=2){
        if(password[i]=='a'+br2){
            br2++;
        }
        password[i]='a'+br2;
        br2++;
    }
}

cout<<password;

return 0;
}
