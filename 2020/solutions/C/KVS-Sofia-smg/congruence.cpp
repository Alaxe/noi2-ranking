#include<bits/stdc++.h>
using namespace std;
bool b[30];
char z1[30];
char z2[30];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int br=0;
    string a;
    char x='A',y='Z';
    cin>>a;
    for(int i=0;i<a.size() and br<26;i++){
        if(!b[a[i]-'A']){
            b[a[i]-'A']=true;
            br++;
        }
    }
    for(int i=0;i<26;i++){
        if(b[i]){
            z1[i]=x;
            x++;
        }
    }
    for(int i=25;i>=0;i--){
        if(b[i]){
            z2[i]=y;
            y--;
        }
    }
    for(int i=0;i<a.size();i++){
        cout<<z1[a[i]-'A'];
    }
    cout<<endl;

    for(int i=0;i<a.size();i++){
        cout<<z2[a[i]-'A'];
    }
    cout<<endl;
    return 0;
}
