#include <bits/stdc++.h>
using namespace std;
char d[200000];
stack <long long> st;
long long l;
bool NeSeBroi[200000];
void fix(long long s, long long e){
    bool imap, imau, imam;
    int p, z;
    if(s>0){
        if(d[s-1]=='(' or d[s-1]=='0'){
            p=0;
        }
        if(d[s-1]=='+'){
            p=1;
        }
        if(d[s-1]=='-'){
            p=3;
        }
        if(d[s-1]=='*' or d[s-1]=='/'){
            p=2;
        }
    }else{
        p=0;
    }
    if(e<l-1){
        if(d[e+1]==')' or d[e+1]=='0'){
            z=0;
        }
        if(d[e+1]=='+' or d[e+1]=='-'){
            z=1;
        }
        if(d[e+1]=='*' or d[e+1]=='/'){
            z=2;
        }
    }else{
        z=0;
    }
    imap=false;
    imau=false;
    imam=false;
    for(long long i=s+1;i<e;i++){
        if(d[i]=='+' and !NeSeBroi[i]){
            imap=true;
        }
        if(d[i]=='-' and !NeSeBroi[i]){
            imam=true;
        }
        if(d[i]=='*' and !NeSeBroi[i]){
            imau=true;
        }
        if(d[i]=='/' and !NeSeBroi[i]){
            imau=true;
        }
        if(imap and imau and imam){
            break;
        }
    }
    if(imau and imap){
        if(p==0 and z==1 or p==1 and z==0 or p==0 and z==0 or p==1 and z==1){
            d[s]='0';
            d[e]='0';
            return;
        }
    }
    if(imau and !imap){
        if(p==0 and z==1 or p==1 and z==0 or p==0 and z==0 or p==1 and z==1 or p==0 and z==2 or p==1 and z==2 or p==2 and z==0
           or p==2 and z==1 or p==2 and z==2){
            d[s]='0';
            d[e]='0';
            return;
        }
    }
    if(!imau and imap){
        if(p==0 and z==1 or p==1 and z==0 or p==0 and z==0 or p==1 and z==1){
            d[s]='0';
            d[e]='0';
            return;
        }
    }
    if(imam and p==3){
        return;
    }
    if(imam){
        imap=true;
        if(imau and imap){
            if(p==0 and z==1 or p==1 and z==0 or p==0 and z==0 or p==1 and z==1){
                d[s]='0';
                d[e]='0';
                return;
            }
        }
        if(imau and !imap){
            if(p==0 and z==1 or p==1 and z==0 or p==0 and z==0 or p==1 and z==1 or p==0 and z==2 or p==1 and z==2 or p==2 and z==0
               or p==2 and z==1 or p==2 and z==2){
                d[s]='0';
                d[e]='0';
                return;
            }
        }
        if(!imau and imap){
            if(p==0 and z==1 or p==1 and z==0 or p==0 and z==0 or p==1 and z==1){
                d[s]='0';
                d[e]='0';
                return;
            }
        }
    }
    if(imau and imap){
        if(z==0 or z==1){
            d[s]='0';
            d[e]='0';
            return;
        }
    }
    if(imau and !imap){
        return;
    }
    if(!imau and imap){
        return;
    }
}
int main(){
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
cin>>d;
l=strlen(d);
for(long long i=0;i<l;i++){
    if(d[i]=='('){
        st.push(i);
    }
    if(d[i]==')'){
        fix(st.top(), i);
        if(d[i]!='0'){
            for(long long j=st.top();j<=i;j++){
                NeSeBroi[j]=true;
            }
        }
        st.pop();
    }
}
for(long long i=0;i<l;i++){
    if(d[i]!='0'){
        cout<<d[i];
    }
}
return 0;
}
