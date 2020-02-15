#include<iostream>
#include<string>
using namespace std;
bool letter[26];
int minimum_Coding[26];
int maximum_Coding[26];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string word;
    cin>>word;
    for(int i=0;i<word.size();i++){
        letter[word[i]-'A']=1;
    }
    int nowNumber_minimum_Coding=0;
    int nowNumber_maximum_Coding=25;
    for(int i=0;i<26;i++){
        if(letter[i]==1){
            minimum_Coding[i]=nowNumber_minimum_Coding;
            nowNumber_minimum_Coding++;
        }
    }
    for(int i=25;i>=0;i--){
        if(letter[i]==1){
            maximum_Coding[i]=nowNumber_maximum_Coding;
            nowNumber_maximum_Coding--;
        }
    }
    for(int i=0;i<word.size();i++){
        cout<<char(minimum_Coding[word[i]-'A']+'A');
    }
    cout<<endl;
    for(int i=0;i<word.size();i++){
        cout<<char(maximum_Coding[word[i]-'A']+'A');
    }
    cout<<endl;
return 0;
}
