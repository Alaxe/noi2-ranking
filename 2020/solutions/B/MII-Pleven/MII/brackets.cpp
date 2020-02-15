#include <bits/stdc++.h>
using namespace std;

string s;

int main (){
int i;

    cin>>s;
    int d=s.size();
    for(i=0;i<d;i++){
        if(s[i]!='(' && s[i]!=')') cout<<s[i];
    }

    return 0;
}
