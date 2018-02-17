#include <iostream>
#include <string>
#include <set>
#include<windows.h>
using namespace std;

long long cnt = 0;

string s;
bool isPalindrome (){
    for(int i = 0; i < s.size()/2; i++){
        if(s[i] != s[s.size()-1-i])return false;
    }
    return true;
}

void removeLetter(int i){

    string olds = s;

    s = s.erase(i,1);
    if(s.size() > 0 && isPalindrome()){
        cnt = (cnt+1) % 1000000007;
        //cout<<s<<" is palindrome!"<<endl;

    }
    for(int j = i; j < s.size(); j++){
        removeLetter(j);
    }
    s = olds;
}

int main(){
    cin>>s;

    if(isPalindrome()){
        cnt++;
        //cout<<s<<" is palindrome!"<<endl;

    }

    for(int i = 0; i < s.size(); i++){
        removeLetter(i);
    }
    cout<<cnt<<endl;
    return 0;
}
/*

abcdefghijklmnopponmlkjihgfedcba
aaaaaaaaaaaaaaaa

*/
