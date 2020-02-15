#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
stack <pair<int, int> > st; ///+1  -2   *3   /4 (5
struct skobi
{
    int idx1;
    int idx2;
    int op;
    int dali;
}sk[100000];
int bez[200000];
int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(false);
    string s;
    cin>>s;
    int j=0;
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]=='(')
        {
            st.push(make_pair(i, 0));
        }
        if (s[i]=='+' || s[i]=='-')
        {
            if (st.empty()==0){
            int t=st.top().first;
            st.pop();
            st.push(make_pair(t, 1));}
        }
        if (s[i]==')')
        {
            sk[j].idx1=st.top().first;
            sk[j].idx2=i;
            sk[j].op=st.top().second;
            j++;
            st.pop();
        }
    }
    int g=0;
    for (int i=0; i<j; i++)
    {
        if (sk[i].op==0) {sk[i].dali=-1; bez[g]=sk[i].idx1; bez[g+1]=sk[i].idx2; g+=2;continue;}
        if (sk[i].idx1==0)
        {
            if (sk[i].idx2==s.size()-1) {sk[i].dali=-1; bez[g]=sk[i].idx1; bez[g+1]=sk[i].idx2; g+=2;}
            else
            {
               // if (s[sk[i].idx2+1]=='*') sk[i].dali=1;
                if (s[sk[i].idx2+1]=='+') {sk[i].dali=-1; bez[g]=sk[i].idx1; bez[g+1]=sk[i].idx2; g+=2;}
            }
        }
        else
        {
           // if (s[sk[i].idx1-1]=='*') {sk[i].dali=1;}
            if (s[sk[i].idx1-1]=='+' || s[sk[i].idx1-1]=='(')
            {
                if (sk[i].idx2==s.size()-1) {sk[i].dali=-1; bez[g]=sk[i].idx1; bez[g+1]=sk[i].idx2; g+=2;}
                else
                {
                   // if (s[sk[i].idx2+1]=='*') sk[i].dali=1;
                    if (s[sk[i].idx2+1]=='+' || s[sk[i].idx2+1]=='(') {sk[i].dali=-1; bez[g]=sk[i].idx1; bez[g+1]=sk[i].idx2; g+=2;}
                }
            }
        }
    }
    sort(bez, bez+g);
    g=0;
    for (int i=0; i<s.size(); i++)
    {
        if (bez[g]==i) {g++; continue;}
        else cout<<s[i];
    }
    cout<<endl;
}
