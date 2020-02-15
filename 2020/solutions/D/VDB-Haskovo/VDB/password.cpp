#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
char s[5005];
char l[26];
struct povtoreniq
{
    int Beg, End;
};
povtoreniq p[1000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    for(int i=0; i<26; i++)
        l[i]='a'+i;

    int n = strlen(s), j=0;
    for(int i=0; i<n; i++)
    {
        p[j].Beg=i;
        while(s[i]==s[i+1]) i++;
        if(i-p[j].Beg+1<3) continue;
        p[j].End=i+1;
        j++;
    }
    int r=0;
    for(int i=0; i<j; i++)
    {
        for(int k=p[i].Beg+2; k<p[i].End; k+=3)
        {
            if(s[k]==l[r]) r++;
            if(r>25) r=0;
            s[k]=l[r++];
        }
    }
    cout << s << endl;
    return 0;
}

