#include <bits/stdc++.h>
#define left ahjalghjeqw
#define right qouoqhgajghakj

using namespace std;

string a,b,left,right,middle,down,up;

string get_max() {
    string ans;
    for(int i=1;i<=51;i++) ans.push_back('9');
    return ans;
}

string add(string a, string b) {
    string c,d;
    int p=0,t,i;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    while(a.size()<b.size()) a.push_back('0');
    while(a.size()>b.size()) b.push_back('0');
    for(i=0;i<(int)(a.size());i++) {
        t=p+(a[i]-'0')+(b[i]-'0');
        p=t/10;
        t%=10;
        c.push_back(t+'0');
    }
    if(p>0) c.push_back(p+'0');
    reverse(c.begin(),c.end());
    for(i=0;i<(int)(c.size());i++) if(c[i]!='0') break;
    for(;i<(int)(c.size());i++) d.push_back(c[i]);
    if(d.size()==0) d="0";
    return d;
}

string multiply(string a, string b) {
    vector < int > v;
    string c,d;
    long long curr=0;
    int i,j;
    v.assign(a.size()+b.size(),0);
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    for(i=0;i<(int)(a.size());i++) for(j=0;j<(int)(b.size());j++) v[i+j]+=((int)(a[i]-'0')*(int)(b[j]-'0'));
    curr=0;
    for(i=0;i<(int)(v.size());i++) {
        curr+=v[i];
        c.push_back(curr%10+'0');
        curr/=10;
    }
    reverse(c.begin(),c.end());
    for(i=0;i<(int)(c.size());i++) if(c[i]!='0') break;
    for(;i<(int)(c.size());i++) d.push_back(c[i]);
    if(d.size()==0) d="0";
    return d;
}

string subtract(string a, string b) {
    string c,d;
    int i,j;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    while(a.size()<b.size()) a.push_back('0');
    while(a.size()>b.size()) b.push_back('0');
    for(i=0;i<(int)(a.size());i++) {
        if(a[i]>=b[i]) {
            c.push_back(a[i]-b[i]+'0');
        }
        else {
            for(j=i+1;j<(int)(a.size());j++) {
                if(a[j]>'0') {
                    a[j]--;
                    break;
                }
                else {
                    a[j]='9';
                }
            }
            c.push_back(a[i]+10-b[i]+'0');
        }
    }
    reverse(c.begin(),c.end());
    for(i=0;i<(int)(c.size());i++) if(c[i]!='0') break;
    for(;i<(int)(c.size());i++) d.push_back(c[i]);
    if(d.size()==0) d="0";
    return d;
}

string div2(string a) {
    string b,c;
    int i,curr=0;
    for(i=0;i<(int)(a.size());i++) {
        curr*=10;
        curr+=(a[i]-'0');
        b.push_back(curr/2+'0');
        curr%=2;
    }
    for(i=0;i<(int)(b.size());i++) if(b[i]!='0') break;
    for(;i<(int)(b.size());i++) c.push_back(b[i]);
    if(c.size()==0) c="0";
    return c;
}

bool cmp(string a, string b) {
    if(a.size()<b.size()) return true;
    if(a.size()>b.size()) return false;
    int i;
    for(i=0;i<(int)(a.size());i++) {
        if(a[i]<b[i]) return true;
        if(a[i]>b[i]) return false;
    }
    return true;
}

int main() {
    cin>>a>>b;
    
    left="0";
    right=get_max();
    while(add(left,"1")!=right) {
        middle=add(left,right);
        middle=div2(middle);
        if(cmp(a,multiply(middle,add(middle,"1")))) right=middle;
        else left=middle;
    }
    down=right;
    
    left="0";
    right=get_max();
    while(add(left,"1")!=right) {
        middle=add(left,right);
        middle=div2(middle);
        if(cmp(multiply(middle,add(middle,"1")),b)) left=middle;
        else right=middle;
    }
    up=left;

    if(cmp(down,up)) cout<<add(subtract(up,down),"1")<<endl;
    else cout<<"0"<<endl;
    
    //fprintf(stderr, "Time: %d ms\n", (int)(clock()*1000.0/CLOCKS_PER_SEC));

    return 0;
}
