#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
long long w,h,n,y1=0,otg=0,a,k,p;
pair<long long,long long>to4ki[100001];
priority_queue<long long>dyljini;
int main(){
cin.tie(NULL);
ios::sync_with_stdio(false);
cin>>w>>h;
cin>>n;
for(long long i=0;i<n;i++){
cin>>to4ki[i].second>>to4ki[i].first;
}
k=n;
p=0;
for(long long i=0;i<n;i++){
if(i>=2 and to4ki[i].first==to4ki[p-1].first and to4ki[i].first==to4ki[p-2].first){
        //cout<<"tuk";
p=p-1;
k=k-1;
}

to4ki[p].first=to4ki[i].first;
to4ki[p].second=to4ki[i].second;
p++;
}
//cout<<"tuk";
sort(to4ki+0,to4ki+k);
for(long long i=0;i<k;i++){
        //cout<<i;
            dyljini.push(to4ki[i].second);
//cout<<dyljini.top()<<" "<<to4ki[i].first<<" "<<to4ki[i].second<<"\n";
    otg+=(to4ki[i].first-y1)*dyljini.top();
    //cout<<(to4ki[i].first-y1)<<" "<<dyljini.top()<<"\n";
    y1=to4ki[i].first;
    a=dyljini.top();
    dyljini.pop();
    while(dyljini.empty()==0 and a==dyljini.top()){
          //  cout<<"A:"<<a<<"\n";
        dyljini.pop();
        a=dyljini.top();
        dyljini.pop();
    }
    dyljini.push(a);
}
cout<<(w*h-otg);
return 0;
}
/*
15 10
23
6 0
6 2
7 2
11 2
11 4
12 4
12 3
13 3
13 5
11 5
11 6
8 6
8 4
9 4
9 5
10 5
10 3
6 3
6 7
12 7
12 8
9 8
9 10
*/
