#include<iostream>
#include<cstring>
using namespace std;

int d2m[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int d2d(char a[5]){
    int res=0;
    int len=strlen(a);
    pair<int, int> date;
    if(len==3)date = {a[0]-'0', a[2]-'0'};
    if(len==5)date = {(a[0]-'0')*10+a[1]-'0', (a[3]-'0')*10+a[4]-'0'};
    if(a[1]=='/')date = {a[0]-'0', (a[2]-'0')*10+a[3]-'0'};
    if(a[2]=='/')date = {(a[0]-'0')*10+a[1]-'0', a[3]-'0'};
    for(int i=0;i<=date.second;i++){
        res+=d2m[i];
    }
    return res+date.first;
}

int main(){
    char input[5];
    int f, s, t, m;
    cin >> input;
    f=d2d(input);
    cin >> input;
    s=d2d(input);
    cin >> input;
    t=d2d(input);
    cin >> input;
    m=d2d(input);
    while(f>m)f-=23;
    while(f<m)f+=23;
    while(s>m)s-=28;
    while(s<m)s+=28;
    while(t>m)t-=33;
    while(t<m)t+=33;
    f-=23-f-m;
    s-=28-s-m;
    t-=33-t-m;
    for(int i=0;i<21251;i++){
        if(f==i%23 && s==i%28 && t==i%33){
            cout << 21252-i << endl;
            return 0;
        }
    }

    return 0;
}
