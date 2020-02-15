#include <iostream>
#include <bits/stdc++.h>
using namespace std;
    int a[26];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string s;
    cin>>s;
    int br=1;
    for(int i=0;i<s.size();i++){
        a[s[i]-'a']++;
        if(a[s[i]-'a']>s.size()/2){
            //cout<<a[s[i]-'a']<<" "<<i<<" "<<s[i]<<endl;
            for(int j=0;j<26;j++){
                if(a[j]<=s.size()/2-1){
                    s[i]=j+'a';
                    a[j]++;
                    a[s[i]-'a']--;
                    break;
                }
            }
        }
    }
    for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1]){
            br++;
            if(br>2){
               // cout<<1;
               //cout<<br<<endl;
               for(int j=0;j<s.size();j++){
                    if(a[j]<=s.size()/2-1){
                       // cout<<a[j]<<endl;
                        if(s.size()-i-1<=1){
                            s[i]=j+'a';
                            //cout<<1;
                        }else{
                            if(j+'a'==s[i+1] && s[i+1]==s[i+2]){
                                continue;
                            }else{
                                s[i]=j+'a';
                                //cout<<s[i]<<endl;
                                break;
                                //cout<<1;
                        }
                    }
                }
            }
        }
        }else{
            br=1;
        }
    }
    cout<<s<<endl;
    return 0;
}
