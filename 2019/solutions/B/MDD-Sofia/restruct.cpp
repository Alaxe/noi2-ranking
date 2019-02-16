#include <iostream>

using namespace std;

//const int maxn = 5005;

//struct pers{
//    int timesWanted;
//    vector<int> acceptedPeople;
//};
//
//pair<pers, int> people[maxn];
//
//bool operator<(pers a, pers b){
//    if(a.timesWanted < b.timesWanted) return true;
//    return false;
//}
//
//bool operator>(pers a, pers b){
//    if(a.timesWanted > b.timesWanted) return true;
//    return false;
//}
//bool operator==(pers a, pers b){
//    if(a.timesWanted == b.timesWanted) return true;
//    return false;
//}
//
//int n;
//
//int findMax(pair<pers, int> a[]){
//    int maxx = -1;
//    int maxxIndex;
//    for(int i=0; i<n; i++){
//        if(maxx < a[i].first.timesWanted){
//            maxx = a[i].first.timesWanted;
//            maxxIndex = a[i].second;
//        }
//    }
//    return maxxIndex;
//}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);

    int n, k;
    cin >> n, k;

//    for(int i=0; i<n; i++){
//        people[i].second = i;
//    }

    for(int i=0; i<n; i++){
        int p;
        cin >> p;
        for(int j=0; j<p; j++){
            int q;
            cin >> q;
//            people[i].first.acceptedPeople.push_back(q);
//            people[q].first.timesWanted++;
        }
    }

//    int ind = findMax(people);
    cout << (2*n+1)*k << endl;


    return 0;
}

