#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
long long n,a,b,c,k;
vector<pair<long long,long long> > points;
vector<pair<pair<long long,long long>,pair<long long, pair<long long,long long> > > >ots;
pair<long long,long long> sysNaOts[500001][2];
set<pair<pair<long long,long long>,long long > > srtots;
stack<pair<pair<long long,long long>,long long > >sss;
long long kymKoqOts[500001],iskaniT[500001],memo[500001];
map<pair<long long,long long>,long long>TellTheNumber;
void prep(){
cin>>n;
for(long long i=1;i<n+1;i++){
    cin>>a>>b>>c;
    ots.push_back(make_pair(make_pair(a,b),make_pair(i,make_pair(a,b))));
    ots.push_back(make_pair(make_pair(a+c,b),make_pair(-i,make_pair(a,b))));
    points.push_back(make_pair(a,b));
    sysNaOts[i][0]=make_pair(a,b);
    sysNaOts[i][1]=make_pair(a+c+1,b);
    points.push_back(make_pair(a+c+1,b));
}
    a=0;b=0;c=100007;
    ots.push_back(make_pair(make_pair(a,b),make_pair(n+1,make_pair(a,b))));
    ots.push_back(make_pair(make_pair(a+c-1,b),make_pair(-n-1,make_pair(a,b))));
cin>>k;
for(long long i=0;i<k;i++){
    cin>>a;
    a++;
    iskaniT[i]=a;
    points.push_back(make_pair(a,1000001));
}
sort(points.begin(),points.end());
for(long long i=0;i<points.size();i++){
    TellTheNumber[points[i]]=i;
}
sort(ots.begin(),ots.end());
for(long long i=0;i<ots.size();i++){
   // cout<<points[i].first<<" "<<points[i].second<<"\n";
    //cout<<ots[i].first.first<<" "<<ots[i].first.second<<" "<<ots[i].second.first<<"\n";
}
long long t=0;
for(long long i=0;i<=ots.size();i++){
        //printS();
    while(t<=points.size() and points[t].first<=ots[i].first.first){
            pair<pair<long long,long long>,long long>P=*(srtots.lower_bound(make_pair(make_pair((-1)*points[t].second,points[t].first),10000001)));
           // cout<<P.first.first<<" "<<P.first.second<<"\n";
            kymKoqOts[t]=P.second;
       // cout<<"The point : "<<points[t].first<<" "<<points[t].second<<" do "<<P.second<<"\n";
        t++;
    }
    if(ots[i].second.first>0){
        srtots.insert(make_pair(make_pair((-1)*ots[i].first.second,ots[i].first.first),ots[i].second.first));
    }else{
        srtots.erase(make_pair(make_pair((-1)*ots[i].second.second.second,ots[i].second.second.first),(-1)*ots[i].second.first));
    }
    //cout<<"Size do : "<<i<<" : "<<srtots.size()<<" , "<<t<<"Kraj na ots"<<"\n";
}
}
long long din(long long otsss){
    //cout<<otsss<<"\n";
if(otsss==(n+1)){
    return 0;
}else{
    if(memo[otsss]!=-1){
        return memo[otsss];
    }else{
        memo[otsss]=min(din(kymKoqOts[TellTheNumber[sysNaOts[otsss][0]]])+1,din(kymKoqOts[TellTheNumber[sysNaOts[otsss][1]]])+1);
        return memo[otsss];
    }
}
}
int main(){
    prep();
    ios::sync_with_stdio(false);
/*for(long long i=0;i<points.size();i++){
    cout<<points[i].first<<" "<<points[i].second<<" "<<kymKoqOts[i]<<" "<<"\n";
}*/
for(long long i=0;i<2*n;i++){
    memo[i]=-1;
}
for(long long i=0;i<k;i++){
    cout<<din(kymKoqOts[TellTheNumber[make_pair(iskaniT[i],1000001)]])<<" ";
}
return 0;
}
