#include<iostream>
#include<vector>
#include<algorithm>
#define MOD 1e15+7
using namespace std;
vector<long long>arr,sarr;
bool used[65];
long long orig[1000005];
long long fact[1000005];
bool used2[65];
long long combis[65][65];
long long combi(long long n,long long k){
    /*long long cnt=1;//=fact[u]/fact[arr.size()]/fact[u-arr.size()];
    for(long long i=0;i<k;i++){
        cnt=cnt*(n-i);
        cnt/=(i+1);
    }*/
    return combis[n][k];
}
long long ans[65];
long long assigned[65];
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long n,u;
    cin>>n>>u;
    combis[0][0]=1;
    for(int i=1;i<=u;i++){
        combis[i][0]=1;
        for(int j=1;j<=i;j++){
            combis[i][j]=combis[i-1][j]+combis[i-1][j-1];
        }
    }
    /*for(int i=0;i<=u;i++){
        for(int j=0;j<=i;j++){
            cout<<combis[i][j]<<" ";
        }
        cout<<endl;
    }*/
    for(long long i=0;i<=u;i++){
        assigned[i]=-1;
    }
    for(long long i=0;i<n;i++){
        long long a;
        cin>>a;
        orig[i]=a;
        if(!used[a]){
            used[a]=1;
            arr.push_back(a);
            sarr.push_back(a);
        }
    }
    sort(sarr.begin(),sarr.end());
    for(long long i=0;i<sarr.size();i++){
        for(long long j=0;j<arr.size();j++){
            if(arr[j]==sarr[i]){
                arr[j]=i+1;
            }
        }
        for(long long j=0;j<n;j++){
            if(orig[j]==sarr[i]){
                orig[j]=i+1;
            }
        }
    }
    //cout<<endl;
    //cout<<fact[u];
    long long cnt=combi(u,arr.size());//=fact[u]/fact[arr.size()]/fact[u-arr.size()];
    //cout<<cnt<<endl;
    cnt=(cnt+1)/2;
    //cin>>cnt;
    assigned[0]=0;
    assigned[arr.size()+1]=u+1;
    for(long long i=0;i<arr.size();i++){
        long long curr=arr[i];
        long long last=0;
        long long ccnt=1;
        long long ub,lb;
        for(long long j=1;j<=arr.size()+1;j++){
            if(assigned[j]!=-1){
                if(curr>=last && curr<=j){
                    ub=j;
                    lb=last;
                }else{
                    ccnt=ccnt*combi(assigned[j]-assigned[last]-1,j-last-1);
                }
                last=j;
            }
        }
        //cout<<"kur"<<endl;
        for(long long j=assigned[lb]+(curr-lb);j<=assigned[ub]-(ub-curr);j++){
            //cout<<j<<endl;
            long long cccnt=combi(j-assigned[lb]-1,curr-lb-1)*combi(assigned[ub]-j-1,ub-curr-1);
            //cout<<cccnt<<endl;
            if(ccnt*cccnt<cnt){
                cnt-=(ccnt*cccnt);
            }else{
                //cout<<"penis"<<endl;
                //cout<<curr<<endl;
                assigned[curr]=j;
                break;
            }
        }
        //cout<<"kur"<<endl;
    }
    for(long long i=0;i<n;i++){
        cout<<assigned[orig[i]]<<" ";
    }
    cout<<endl;
    return 0;
}
