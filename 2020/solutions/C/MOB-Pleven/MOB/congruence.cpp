#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int a[27];
int ans[27];
vector<char>ch;
char c;
int main()
{
    while(1)
    {
        scanf("%c",&c);
        if(c=='\n')break;
        ch.push_back(c);
        a[c-65]++;
    }
    int counter=1;
    for(int i=0;i<26;i++)
    {
        if(a[i]>0){ans[i]=counter;counter++;}
    }
    string s1="",s2="";
    for(int i=0;i<ch.size();i++)
    {
        s1+=ans[ch[i]-65]+64;
        s2+=(26-(counter-ans[ch[i]-65]))+65;
    }
    cout<<s1<<endl<<s2;
return 0;
}
/**
man4o hadji deanchu i jasenkata sa pichove
ama ministur denka e moqta pich
*/
