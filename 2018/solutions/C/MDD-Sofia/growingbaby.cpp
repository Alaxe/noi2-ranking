#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector< pair<int, bool> >  ans;
vector<int> ans2;

int main()
{
    int sum=1;
    int start, endd, in, out;
    bool lastWasOut=false;
    cin >> start >> endd >> in >> out;
    start +=in;
    int lastsize=0;
    ans.push_back(make_pair(start, lastWasOut));
    while(sum>0){
        int sizee = ans.size();
        sum=0;
        for(int i =lastsize; i<sizee; i++){
            if (ans[i].first<endd)sum++;
            else{
                continue;
            }
            if(ans[i].second){
                lastWasOut=false;
                ans.push_back(make_pair(ans[i].first+in, lastWasOut));
                ans[i].first=-1;
            }
            else{
                lastWasOut =false;
                ans.push_back(make_pair(ans[i].first+in, lastWasOut));
                lastWasOut=true;
                ans.push_back(make_pair(ans[i].first-out, lastWasOut));
                ans[i].first=-1;
            }
        }
        lastsize=sizee;
    }
    for(int i=0; i<ans.size(); i++){
        ans2.push_back(ans[i].first);
    }
    sort(ans2.begin(), ans2.end());
    int answer = upper_bound(ans2.begin(), ans2.end(), -1)-ans2.begin();
    cout << ans2.size()-answer << endl;
    return 0;
}
