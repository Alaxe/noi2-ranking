#include<iostream>
using namespace std;
char password[5000];
int main(){
    bool safe=true;
    int counter=0;
    cin>>password;
    int br=0;
    int letters=0;
    char arr[26]={0};
    while(password[br]!='\0'){
    char temp=password[br];
        arr[temp]++;
        letters++;
        br++;
    }
    for(int i='a';i<='z';i++){
        if(arr[i]>letters/2){
            for(int j=0;j<letters;j++){
                if(password[j]==i){
                    password[j]=counter%26+'a';
                    counter++;
                }
            }
        }
    }
    br=0;
    while(password[br+2]!='\0'){
        if((password[br]==password[br+1])&&(password[br+1]==password[br+2])){
            if(password[br+2]==(char)counter%26+'a'){counter++;}
            password[br+2]=(char)counter%26+'a';
            counter++;
        }
        br++;
    }
    cout<<password<<endl;
}
