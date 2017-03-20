#include<iostream>
#include<string>
#include<vector>
using namespace std;
class NM{
public:
    int m;
    int n;
    NM(int M,int N){m=M;n=N;}
};
    vector<NM> endd;
    vector<vector<int> > v;
    NM start;
    vector<int>sums;
    int sum =0;
    int n,m;
void getend(NM nm)
{
    if((nm.n!=start.n)&&(nm.m!=start.m))sum+=v[nm.n][nm.m];
     if(((nm.n==0)||(nm.n==n-1))||((nm.n==0)||(nm.m==m-1)))
            {
                NM nm1;
                nm1.n=nm.n;
                nm1.m=nm.m;
                endd.push_back(nm1);
                sums.push_back(sum);
                sum=0;
            }
    if(v[nm.n-1][nm.m]>0)getend(new NM(nm.n-1,nm.m);
    if(v[nm.n+1][nm.m]>0)getend(new NM(nm.n+1,nm.m));
    if(v[nm.n][nm.m+1]>0)getend(new NM(nm.n-1,nm.m+1);
    if(v[nm.n-1][nm.m-1]>0)getend(new NM(nm.n-1,nm.m-1));
}

int main()
{
    cin>>n>>m;
    for(int br=0;br<n;br++)
    {
        string s;
        cin>>s;
        vector<int> vi;
        for(int br1=0;br1<s.length();br1++)
        {
            int i;
            i=(int)s[br1]-64;
            if(i==-29)
            {
                start.n=br;
                start.m=br1;
            }

            vi.push_back(i);
        }
        v.push_back(vi);
    }
    getend(start);
    sort(sums.begin(),sums.end());
    cout<<sums[0];
}
