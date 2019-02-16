#include <bits/stdc++.h>
using namespace std;
string mult_1(string s,int d) {
    string s1;
    int c=0;
    for (int i=s.size()-1 ; i>=0 ; i--) {
        s1+=((((s[i]-'0')*d+c)%10)+'0');
        c=((s[i]-'0')*d+c)/10;
    }
    if (c!=0) {s1+=(c+'0');}
    string ss1;
    for (int i=s1.size()-1 ; i>=0 ; i--) {
        ss1+=s1[i];
    }
        return ss1;
}
string add_big(string s,string s1) {
    string ss1;
    if (s.size()>s1.size()) while (s1.size()<s.size()) s1+='0';
    else while (s1.size()>s.size()) s+='0';
    int c=0;
    int i;
    for (i=s.size()-1 ; i>=0 ; i--) {
        ss1+=((((s[i]-'0')+(s1[i]-'0'))+c)%10)+'0';
        c=(s[i]-'0'+s1[i]-'0')/10;
    }
    string ss2;
    for (int i=s1.size()-1 ; i>=0 ; i--) {
        ss2+=ss1[i];
    }
        return ss2;
}
string mult_big(string s, string s1) {
    string f[s.size()];
    for (int i=s.size()-1 ; i>=0 ; i--) {
        f[i]=mult_1(s1,s[i]-'0');
        for (int j=0 ; j<i ; j++) f[i]='0'+f[i];
    }
    string ss1="";
    for (int i=0 ; i<s.size() ; i++) {
        ss1=add_big(ss1,f[i]);
    }
        return ss1;
}
bool div(string s,int d) {
    int ost=0;
    for (int i=0 ; i<s.size() ; i++) {
        int d1=(s[i]-'0')+ost*10;
        while (d1<d && i<s.size()) {
            i++;
            d1=d1*10+(s[i]-'0');
        }
        ost=d1%d;
    }
    if (ost) return 0;
    else return 1;
}
int main() {
	int a,b,n[16384];
	cin>>a>>b;
	for (int i=1 ; i<=a ; i++) {
        cin>>n[i];
	}
	string rr,r="1";
	bool h=1;
    while (h!=0) {
        rr=r;
        for (int i=2 ; i<=b ; i++) {
            rr=mult_big(rr,r);
        }
        int i;
        for (i=1 ; i<=a ; i++) {
            if (div(rr,n[i])==0) break;
        }
        if (i==a) {
            cout<<r<<endl;
                return 0;
        }
        if (r[r.size()-1]=='9') {
            int i=r.size()-1;
            while (r[i]=='9') {
                r[i]='0';
                i--;
            }
            if (i>-1) r[i]+=1;
            else r='1'+r;

        }
        else {r[r.size()-1]+=1;}
    }
		return 0;
}
