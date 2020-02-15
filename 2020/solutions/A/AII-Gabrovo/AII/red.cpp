# include<iostream>
# include<map>
using namespace std;

string s;
map<int,int> m;
map<string,int> m2;
int a[100001],b[100001];
int N,M;
int w,k;
long long ans=0;

string div(int x)
{
    string t="";
    while(x>0)
    {
        int c=x%10;
        x/=10;
        t = char(c+'0') + t;
    }
    t = t + '/';
    return t;
}

int main()
{
    cin>>w>>k;
    cin>>N;
    for(int i=0; i<N; i++) cin>>a[i];
    cin>>M;
    for(int i=0; i<M; i++) cin>>b[i];

    if(w==2)
    {
        int p=0,q=0;
        while(p<N)
        {
            while(q<N && a[q]==a[p] && q-p+1<k) q++;
            if(q-p+1==k && a[q]==a[p]) {m[a[p]]++; p++;}
            else p=q;
        }

        p=0,q=0;
        while(p<M)
        {
            while(q<M && b[q]==b[p] && q-p+1<k) q++;
            if(q-p+1==k && b[q]==b[p]) {ans=ans+m[b[p]]; p++;}
            else p=q;
        }
        cout<<ans<<endl;
    }
    if(w==1)
    {
        int p=0,q=1;
        while(p<N)
        {

            s=div(a[p]);
            while(q<N && a[p]<a[q] && q-p+1<k) {s=s+div(a[q]); q++;}
            if(q-p+1==k && a[p]<a[q]) {s=s+div(a[q]); m2[s]++; p++;}
            else {p=q; q++;}
        }

        p=0,q=1;
        while(p<M)
        {

            s=div(b[p]);
            while(q<M && b[p]<b[q] && q-p+1<k) {s=s+div(b[q]); q++;}
            if(q-p+1==k && b[p]<b[q]) {s=s+div(b[q]); ans+=m2[s]; p++;}
            else {p=q; q++;}
        }
        cout<<ans<<endl;
    }

}

/*
2 3
11
3 4 4 4 4 5 6 6 6 6 7
16
3 6 6 6 4 4 4 5 6 6 6 7 7 6 6 6

1 2
6
2 1 3 4 3 6
6
3 6 1 3 6 7

1 2
6
2 11 111 4 3 6
6
1 1111 2 4 3 6


1 2
20
2 4 10 14 4 3 3 7 14 5 5 1 12 1 11 10 2 12 6 6
20
9 2 3 7 7 6 11 8 5 2 6 11 3 9 7 2 4 10 9 8

*/
