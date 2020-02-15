#include<bits/stdc++.h>
using namespace std;
int a[26];
int n;
string s;
bool isOk(){
    char p = s[0];
    int b = 1;
    for(int i = 1; i < n; i++){
        if(s[i] == p)b++;
        if(p != s[i]){
            p = s[i];
            b = 1;
        }
        if(b >= 3){
            return false;
        }
    }
    for(int i = 0; i < 26; i++){
        a[i] = 0;
        //cout << a[i] << endl;
    }
    for(int i = 0; i < n; i++){
        a[s[i] - 'a']++;
        //cout << s[i] << endl;
        //cout << a[s[i] - 'a'] << " " << n / 2;
        //cout << " " << (char)a[i] + 'a' << endl;
        if(a[s[i] - 'a'] > n / 2)return false;
    }
    return true;
}
int main(){

ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
getline(cin, s);
n = s.size();
char p = '0';
int b = 0;
while(!isOk()){
for(int i = 0; i < n; i++){
    if(s[i] == p)b++;
    if(p != s[i]){
        p = s[i];
        b = 1;
    }
    //cout << b << " " << s[i] << " "  << i << endl;
    if(b >= 3){
        s[i]++;
        p = s[i];
        b = 1;
    }
}
for(int i = 0; i < 26; i++){
        a[i] = 0;
}
for(int i = 0; i < n; i++){
    a[s[i] - 'a']++;
    //cout << a[s[i] - 'a'] << endl;
}
for(int i = 0; i < 26; i++){
    if(a[s[i] - 'a'] > n / 2){
        //cout << a[s[i] - 'a'] << " " << n / 2 << endl;
        for(int j = 0; j < n; j++){
            //cout << j << endl;
            //cout << s[j] << " " << s[i];
            if(s[j] == s[i]){
                //cout << s[j];
                s[j]++;
                //cout << endl << s[j] << endl;
                a[s[j] - 'a']++;
                a[s[j] - 'a' - 1]--;
                if(s[j] > 'z')s[j] = 'a';
            }
        }
    }
}
}
cout << s << endl;

return 0;
}
