#include<iostream>
#include<vector>
#include<math.h>
#include<utility>

using namespace std;
vector<int> elems;

long getProgressions(int curInd, int d){
vector<int> progressions;
int el = elems[curInd];
for(int i = curInd+1; i<elems.size(); i++){
    if(el+d == elems[i]){
        progressions.push_back(i);
    }
}
if(progressions.size() == 0) return 0;
long counts = 0;
for(int i = 0; i<progressions.size(); i++){
    counts+=getProgressions(progressions[i], d);

}

return counts+progressions.size();
}

int main(){
int n;
cin>>n;

int m = 0;
for(int i = 0; i<n; i++){
    int a;
    cin>>a;
    if(a > m) m = a;
    elems.push_back(a);
}
long seq = 0;
for(int d = 1; d < m; d++){
    for(int i = 0; i<elems.size(); i++)
    seq += getProgressions(i, d);
}
cout<<seq<<endl;
return 0;

}
