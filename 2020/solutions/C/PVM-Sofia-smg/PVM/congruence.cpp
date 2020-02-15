//headache
#include<bits/stdc++.h>
using namespace std;
string s;
long long zdr[26],br1=0;
pair<char,long long> p[1000000];
pair<long long,char> p23[1000000];
int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(false);
    cin>>s;
for (int q=0;q<s.size();q++) {
    p[q]=make_pair(s[q],q);
}
sort(p,p+s.size());
long long prom=1;
p23[0]=make_pair(p[0].second,'A');
for (int q=1;q<s.size();q++) {
    if (p[q].first==p[q-1].first) {
        p23[q]=make_pair(p[q].second,p23[q-1].second);
    }
    else {
         p23[q]=make_pair(p[q].second,'A'+prom);
         prom++;
    }
}
sort(p23,p23+s.size());
string fastog1;
for (int q=0;q<s.size();q++) {
        fastog1+=p23[q].second;
}
cout<<fastog1<<"\n";
for (int q=0;q<fastog1.size();q++) {
    if (zdr[fastog1[q]-'A']==0) {br1++;zdr[fastog1[q]-'A']=1;}
}
for (int q=0;q<fastog1.size();q++) {
    fastog1[q]=fastog1[q]+26-br1;
}
cout<<fastog1<<"\n";
return 0;
}
