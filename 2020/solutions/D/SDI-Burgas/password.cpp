#include <iostream>

using namespace std;

char pass[500]={'a'};


int main(){
    char temp='a';
    int counta=1,n=0;
    bool isdone=false;

    cin.get(temp);
    while(temp!='\n'){pass[n]=temp; n++; cin.get(temp);}
    while(isdone!=true){
        isdone=true;
        for(int i=1; i<n; i++){
            if(pass[i]==pass[i-1])counta++;
            else counta=1;
            if(counta==3) {temp='a';
                for(char j='a'; j==pass[i]||j==pass[i]+1; j++)temp=j;
                pass[i]=temp;
                isdone=false;}}}

    for(int i=0; i<n; i++) cout<<pass[i];
    cout<<endl;
}
