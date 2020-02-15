#include <bits/stdc++.h>
using namespace std;
int n, a[202], weight=0, otg=0, c1, c2;
double w1, w2;
deque <int> ind;
vector <int> u;
bool used[202];
bool s(int x, int y){
    return x>y;
}
int main(){
cin.tie(0);
cout.tie(0);
ios_base::sync_with_stdio(false);
cin>>n>>w1>>w2;
for(int i=0;i<n;i++){
    cin>>a[i];
}
sort(a, a+n, s);
for(int i=0;i<n;i++){
    if(weight+a[i]<=w1 and !used[i]){
        ind.push_back(i);
        weight=weight+a[i];
        used[i]=true;
    }
    if(weight==w1){
        otg=w1;
        while(!u.empty()){
            u.pop_back();
        }
        while(!ind.empty()){
            u.push_back(ind.back());
            ind.pop_back();
        }
        for(int j=0;j<u.size();j++){
            ind.push_front(u[j]);
        }
        break;
    }
    if(i==n-1){
        if(weight>otg){
            otg=weight;
            while(!u.empty()){
                u.pop_back();
            }
            while(!ind.empty()){
                u.push_back(ind.back());
                ind.pop_back();
            }
            for(int j=0;j<u.size();j++){
                ind.push_front(u[j]);
            }
        }
        if(!ind.empty()){
            weight=weight-a[ind.front()];
            i=ind.front();
            used[ind.front()]=false;
            ind.pop_front();
        }else{
            break;
        }
    }
}
c1=c1+otg;
weight=0;
otg=0;
fill(used, used+n, 0);
for(int j=0;j<u.size();j++){
    used[u[j]]=true;
}
while(!ind.empty()){
    ind.pop_back();
}
for(int i=0;i<n;i++){
    if(weight+a[i]<=w2 and !used[i]){
        ind.push_back(i);
        weight=weight+a[i];
        used[i]=true;
    }
    if(weight==w2){
        otg=w2;
        while(!u.empty()){
            u.pop_back();
        }
        while(!ind.empty()){
            u.push_back(ind.back());
            ind.pop_back();
        }
        for(int j=0;j<u.size();j++){
            ind.push_front(u[j]);
        }
        break;
    }
    if(i==n-1){
        if(weight>otg){
            otg=weight;
            while(!u.empty()){
                u.pop_back();
            }
            while(!ind.empty()){
                u.push_back(ind.back());
                ind.pop_back();
            }
            for(int j=0;j<u.size();j++){
                ind.push_front(u[j]);
            }
        }
        if(!ind.empty()){
            weight=weight-a[ind.front()];
            i=ind.front();
            used[ind.front()]=false;
            ind.pop_front();
        }else{
            break;
        }
    }
}
c1=c1+otg;
weight=0;
otg=0;
fill(used, used+n, 0);
while(!ind.empty()){
    ind.pop_back();
}
for(int i=0;i<n;i++){
    if(weight+a[i]<=w2 and !used[i]){
        ind.push_back(i);
        weight=weight+a[i];
        used[i]=true;
    }
    if(weight==w2){
        otg=w2;
        while(!u.empty()){
            u.pop_back();
        }
        while(!ind.empty()){
            u.push_back(ind.back());
            ind.pop_back();
        }
        for(int j=0;j<u.size();j++){
            ind.push_front(u[j]);
        }
        break;
    }
    if(i==n-1){
        if(weight>otg){
            otg=weight;
            while(!u.empty()){
                u.pop_back();
            }
            while(!ind.empty()){
                u.push_back(ind.back());
                ind.pop_back();
            }
            for(int j=0;j<u.size();j++){
                ind.push_front(u[j]);
            }
        }
        if(!ind.empty()){
            weight=weight-a[ind.front()];
            i=ind.front();
            used[ind.front()]=false;
            ind.pop_front();
        }else{
            break;
        }
    }
}
c2=c2+otg;
weight=0;
otg=0;
fill(used, used+n, 0);
for(int j=0;j<u.size();j++){
    used[u[j]]=true;
}
while(!ind.empty()){
    ind.pop_back();
}
for(int i=0;i<n;i++){
    if(weight+a[i]<=w1 and !used[i]){
        ind.push_back(i);
        weight=weight+a[i];
        used[i]=true;
    }
    if(weight==w1){
        otg=w1;
        while(!u.empty()){
            u.pop_back();
        }
        while(!ind.empty()){
            u.push_back(ind.back());
            ind.pop_back();
        }
        for(int j=0;j<u.size();j++){
            ind.push_front(u[j]);
        }
        break;
    }
    if(i==n-1){
        if(weight>otg){
            otg=weight;
            while(!u.empty()){
                u.pop_back();
            }
            while(!ind.empty()){
                u.push_back(ind.back());
                ind.pop_back();
            }
            for(int j=0;j<u.size();j++){
                ind.push_front(u[j]);
            }
        }
        if(!ind.empty()){
            weight=weight-a[ind.front()];
            i=ind.front();
            used[ind.front()]=false;
            ind.pop_front();
        }else{
            break;
        }
    }
}
c2=c2+otg;
cout<<max(c1, c2);
return 0;
}


