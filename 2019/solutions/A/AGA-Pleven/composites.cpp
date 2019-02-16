#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long n,k=3,f,br=1,ofem,x;
vector <int> v,m;
int main () {
    cin>>n;
    f=n;
    while (f>9)
    {
        f=f/10;
        br++;
    }
    br=br+1;
    v.push_back(k);
        int i=0;
        while (i<100001)
        {
            i++;
            k=k+2;
            bool fl=false;
            for (int i=2;i<=sqrt(k);i++)
            {
                if (k%i==0) {fl=true; break;}
            }
            if (fl==false) v.push_back(k);
        }

    ofem=9;
    while (br>0)
    {
        br--;
        ofem=ofem*10+9;
    }
    ofem=ofem/10;
    if (n%2==0) x=n;
    else
    x=n+1;

    while (x<ofem)
    {
        bool fl=false;
        for (int i=0;i<n;i++)
        {
            m.push_back(v[i]*v[i]+x);
            //cout<<m[i]<<" ";
            for (int j=0;j<=v.size();j++)
            {
                if (m[i]<v[i]) break;
                if (m[i]==v[j]) {fl=true; break;}
            }
            if (fl==true) break;

        }
        m.clear();
        if (fl==true) x=x+2;
            else
            {
                cout<<x<<endl; return 0;
            }


    }
    cout<<0<<endl;



return 0;
}
