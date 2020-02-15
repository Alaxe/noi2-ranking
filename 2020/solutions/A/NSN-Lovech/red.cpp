#include <bits/stdc++.h>

using namespace std;

bool checkTwo(vector<int>& a,int start,int end){
    for(int i=start;i<end;++i){
        if(a[i]!=a[i+1])
            return false;
    }
    return true;
}
bool checkOne(vector<int>& a,int start,int end){
    for(int i=start;i<end;++i){
        if(a[i]>= a[i+1])
            return false;
    }
    return true;
}
int main()
{
    int w,k,n,m;
    map<vector<int>,int> A,B;
    cin>>w>>k;
    cin>>n;
    vector<int> a(n);
    for(int i =0;i<n;++i){
        cin>>a[i];
    }
    cin>>m;
    vector<int> b(m);
    for(int i =0;i<m;++i){
        cin>>b[i];
    }
    vector<int>::const_iterator first_a = a.begin();
    vector<int>::const_iterator first_b = b.begin();
    for(int i =0;i<n-k;++i){
        if(w == 1){
            if(checkOne(a,i,i+k))
            {
                vector<int> temp(first_a+i,first_a+i+k);
                if(A.find(temp)!=A.end())
                {
                    A[temp]=0;
                }
                A[temp]++;
            }
        }
        else{
            if(checkTwo(a,i,i+k))
            {
                vector<int> temp(first_a+i,first_a+i+k);
                if(A.find(temp)!=A.end())
                {
                    A[temp]=0;
                }
                A[temp]++;
            }
        }
    }

    for(int i =0;i<m-k;++i){
        if(w == 1){
            if(checkOne(b,i,i+k))
            {
                vector<int> temp(first_b+i,first_b+i+k);
                if(B.find(temp)!=B.end())
                {
                    B[temp]=0;
                }
                B[temp]++;
            }
        }
        else{
            if(checkTwo(b,i,i+k))
            {
                vector<int> temp(first_b+i,first_b+i+k);
                if(B.find(temp)!=B.end())
                {
                    B[temp]=0;
                }
                B[temp]++;
            }
        }
    }
    int ans = 0;
    map<vector<int>, int>::iterator it_A = A.begin();
    map<vector<int>, int>::iterator it_B = B.begin();
    while(it_A != A.end())
    {
        if(B.find(it_A->first)!=B.end()){
        ans+=B[it_A->first]*it_A->second;
        }

        it_A++;
    }
    while(it_B != B.end())
    {
       if(A.find(it_B->first)!=A.end()){
        ans+=A[it_B->first]*it_B->second;
        }
        it_B++;
    }
    cout<<ans<<endl;
    return 0;
}
