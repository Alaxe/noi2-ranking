#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
vector<char> StringToChar(vector<string> str)
{
    int br=0;
    vector<char> cha;
    for(int i=0; i<str.size(); i++)
    {
        for(int j=0; j<str[i].size(); j++)
        {
            cha.push_back((str[i])[j]);
        }
    }
    return cha;
}
long long StringToInt(string s)
{
    int a=0;
    for(int i=0; i<s.size(); i++)
    {
        a=10*a+(s[i]-'0');
    }
    return a;
}
vector<string> generate(vector<string> prev, vector<char> digits)
{
    vector<string> next;
    for(int i = 0; i < digits.size(); i++)
    {
        if (i%2 == 0)
        {
            for(int j = 0; j < prev.size(); j++)
            {
                next.push_back(digits[i] + prev[j]);
            }
        }
        else
        {
            for(int j = prev.size() - 1; j >=0; j--)
            {
                next.push_back(digits[i] + prev[j]);
            }
        }
    }
    return next;
}
int main ()
{
    long long n,k,a,b,pp,summ=0;
    vector<string> prehod1,prehod2;
    char pr1,pr2;
    vector<string> p,last,kk;
    vector<char> d;
    vector<int> kki,dd;
    int sums1[1000],summinussum[1000];
    int maxi=0;
    int maxii=0;
    int br=0;
    string ss="";
    string z="87365";
    char ch;
    cin>>n>>k>>a>>b;
    for(int i=0; i<n; i++)
    {
        cin>>ch;
        d.push_back(ch);
        ss+=ch;
        p.push_back(ss);
        ss="";
    }
    prehod1=generate(p,d);
    prehod2=prehod1;
    prehod1.clear();
    for(int i=0; i<k-2; i++)
    {
        prehod1=generate(prehod2,StringToChar(prehod2));
        prehod2.clear();
        prehod2=prehod1;
        prehod1.clear();
    }
    /*for(int i=0; i<prehod2.size(); i++)
    {
        cout<<prehod2[i]<<" ";
    }*/
    //cout<<endl<<"-------"<<endl;
    for(int i=a; i<=b; i++)
    {
        kk.push_back(prehod2[i-1]);
        kki.push_back(StringToInt(prehod2[i-1]));
        pp=StringToInt(prehod2[i-1]);
        while(pp)
        {
            summ+=pp%10;
            pp/=10;
        }
        sums1[br]=summ;
        summ=0;
        br++;
        //cout<<sums1[br-1]<<endl;
        if(StringToInt(prehod2[i-1])>maxi) maxi=StringToInt(prehod2[i-1]);
    }
    /*for(int i=0; i<kk.size(); i++)
    {
        cout<<kk[i]<<" ";
    }
    cout<<endl<<"-------"<<endl;*/
    br=0;
    for(int i=0; i<b-a; i++)
    {
        summinussum[i]=abs(sums1[i]-sums1[i+1]);
        if(summinussum[i]>maxii) maxii=summinussum[i];
    }
    /*for(int i=0; i<kk.size(); i++)
    {
        cout<<kk[i]<<" ";
    }*/
    cout<<maxi<<" ";
    cout<<maxii<<endl;
    return 0;
}
