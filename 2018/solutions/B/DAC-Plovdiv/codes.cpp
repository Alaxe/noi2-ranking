#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
#define MAXN 128

string ans="";
int arr[MAXN]={}, s[MAXN]={}, maxs=-1, maxs2=-2;
int n;
vector<int> maxii;

void rec(long long k, long long a, long long b){
    if(k==1){
        int maxi=-1;


        for(int i=a-1; i<=b-1; i++)
            maxi=max(maxi, arr[i]);

        ans+=((char) maxi + '0');

        return;
    }
    else{

        //cout<<k<<" "<<a<<" "<<b<<endl;
        long long pn=1;
        for(int i=0; i<k-1; i++)
            pn*=n;

        long long ai, bi;
        if(a%pn==0) ai=a/pn-1;
        else ai=a/pn;
        if(b%pn==0) bi=b/pn-1;
        else bi=b/pn;
        //cout<<ai<<" "<<bi<<endl;
        int maxi=-1;

        for(int i=ai; i<=bi; i++){
            if(arr[i]==maxi)
                maxii.push_back(i);

            if(arr[i]>maxi){
                maxi=arr[i];
                if(maxii.empty()==0) maxii.clear();
                maxii.push_back(i);
            }
        }
        //cout<<maxi<<endl;
        ans+=((char) maxi + '0');

        maxi=-1;
        bool flag=false;

        for(int i=0;i<maxii.size();i++)
            if(maxii[i]!=ai&&maxii[i]!=bi) {flag=true; break;}

        if(flag==true){
            for(int i=0;i<n;i++)
                maxi=max(maxi, arr[i]);
            for(int i=0;i<k-1;i++)
                ans+=((char) maxi + '0');
                //cout<<"*"<<endl;
        }
        else{
            flag=false;

            if(maxii[0]==ai&&maxii[0]==bi&&ai%2==0){

                pn=1;
                for(int i=1; pn<a; i++)
                    pn*=n;

                if(pn!=1) pn/=n;
                int a1=a/pn;
                int b1=b/pn;
//cout<<"*"<<endl;
                rec(k-1, a-a1*pn==0 ? a : a-a1*pn, b-b1*pn==0 ? b : b-b1*pn);
                return;
            }

            if(maxii[0]==ai&&maxii[0]==bi&&ai%2==1){

                pn=1;
                for(int i=1; pn<a; i++)
                    pn*=n;

                if(pn!=1) pn/=n;
                int a1=a/pn;
                int b1=b/pn;
//cout<<pn<<endl;
                rec(k-1, pn+1 - (b-b1*pn==0 ? b : b-b1*pn), pn+1 - (a-a1*pn==0 ? a : a-a1*pn));
                return;
            }

            string ansc=ans;
            if(maxii[0]==ai && ai%2==0){
                flag=true;

                pn=1;
                for(int i=1; pn<a; i++)
                    pn*=n;

                if(pn!=1) pn/=n;

                int a1=a/pn;
//cout<<"*"<<endl;
                rec(k-1, a-a1*pn==0 ? a : a-a1*pn, pn*n);
            }
            if(maxii[0]==ai && ai%2==1){
                flag=true;

                pn=1;
                for(int i=0; pn<a; i++)
                    pn*=n;

                if(pn!=1) pn/=n;
                int a1=a/pn;
//cout<<"*"<<endl;
                rec(k-1, 1, pn + 1 - (a-a1*pn==0 ? a : a-a1*pn));
            }
            string ansa;
            if(flag==true) ansa=ans;
            else ansa="";
            ans=ansc;

            flag=false;
            if(maxii[0]==bi && bi%2==0){
                flag=true;

                pn=1;
                for(int i=0; pn<b; i++)
                    pn*=n;
//cout<<"*"<<endl;
                if(pn!=1) pn/=n;
                int b1=b/pn;
                rec(k-1, 1, b-b1*pn==0 ? b : b-b1*pn);
            }
            if(maxii[0]==bi && bi%2==1){
                flag=true;

                pn=1;
                for(int i=0; pn<b; i++)
                    pn*=n;
//cout<<"*"<<endl;
                if(pn!=1) pn/=n;
                int b1=b/pn;

                rec(k-1, pn+1 - (b-b1*pn==0 ? b : b-b1*pn), pn*n);
            }

            string ansb;
            if(flag==true) ansb=ans;
            else ansb="";

            ans=max(ansa, ansb);

        }
    }

    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long k, a, b;
    cin>>n>>k>>a>>b;
    int minres=10000000, maxsi;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(i>0){
            s[i-1]=max(arr[i]-arr[i-1], arr[i-1]-arr[i]);
            if(s[i-1]>maxs){
                maxs2=maxs;
                maxs=s[i-1];
                maxsi=i-1;
            }
        }
    }
    int f=-1;
    for(int i=1;i<n-1;i++)
        if(s[i-1]==maxs){
            minres=min(minres, i-1-f);
            f=i-1;
        }
    long long pn=1;
    for(int i=0; i<=k; i++){
        if(pn>=b){
            for(int j=0; j<k-i; j++)
                ans+=((char) arr[0] + '0');

            rec(i, a, b);
            break;
        }
        pn*=n;
    }

    cout<<ans<<" ";

    if(b-a>=minres) cout<<maxs<<"\n";
    else{

    }
    return 0;
}
