#include<iostream>
#include<string>
using namespace std;
string password;
int seenCounter[26];
char letterForChanging(char letter){
    for(long long i=0;true;i++){
        if(password[letter]!='a'+i and seenCounter[i]<password.size()/2){
            seenCounter[i]++;
            return 'a'+i;
        }
    }
}
int main(){
ios_base::sync_with_stdio(NULL);
cin.tie(NULL);
cout.tie(NULL);
cin>>password;
for(int i=0;i<password.size();i++) seenCounter[password[i]-'a']++;
int poslcounter=1;
for(int i=1;i<password.size();i++){
    if(password[i]==password[i-1]){
        poslcounter++;
        if(poslcounter==3){
            seenCounter[password[i]-'a']--;
            password[i]=letterForChanging(password[i]);
            seenCounter[password[i]-'a']++;
            poslcounter=1;
        }
    }else poslcounter=1;
}
for(int i=1;i<password.size();i++){
    if(seenCounter[password[i]-'a']>password.size()/2){
        seenCounter[password[i]-'a']--;
        password[i]=letterForChanging(password[i]);
    }
}
cout<<password;
return 0;
}
