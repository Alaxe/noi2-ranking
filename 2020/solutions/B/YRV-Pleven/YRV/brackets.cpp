#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iomanip>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<list>
using namespace std;
long long fl[200005],d,i,a[200005],flp,l;
stack < pair<char,long long> > st;
pair <char,long long> p;
string s;
bool znak(char &c1){
   if(c1=='+' || c1=='-' || c1=='*' || c1=='/')return true;
   return false;
}
void add1(char &c1){
        p.first=c1;
        p.second=i;
        st.push(p);
}
int main(){
cin>>s;
s="+"+s+"+";
d=s.size();
fl[0]=-1;
fl[d-1]=-1;
for(i=0;i<d-1;i++){
    if(znak(s[i])) add1(s[i]);
    if(s[i]=='('){
        if(st.top().first=='+' || st.top().first=='(')a[i]=1;
        add1(s[i]);
    }
    if(s[i]==')'){
        if(s[i+1]=='+' || s[i+1]=='-' || s[i+1]==')')a[i]=1;
        flp=1;
        while(st.top().first!='('){
            if(st.top().first=='+' || st.top().first=='-')flp=0;
            st.pop();
        }
        l=st.top().second;//na koq poz e lqvata skoba
        st.pop();
        //cout<<l<<" "<<i<<" "<<a[l]<<" "<<a[i]<<endl;
        if(flp==1 || (a[l]==1 && a[i]==1)){fl[l]=-1; fl[i]=-1;}
    }
}
for(i=1;i<d-1;i++)if(fl[i]==0)printf("%c",s[i]);
cout<<endl;
return 0;
}
/*
&+(&-&)

(&+&*(&/&*&)/&-&)+(&*&-(&-(&*&/&)))-(&+(&*&+&)/&)

&+7*(7-7)-(7-(7+7*(7*7)/7))+(7+(7*7-7)/7)
*/
