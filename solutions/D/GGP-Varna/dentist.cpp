#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair <int, int> > patient;
void read()
{
    int arrive_time, duration;
    while (cin >> arrive_time >> duration)
    {
        pair <int, int> curr;
        curr.first = arrive_time;
        curr.second = duration;
        patient.push_back(curr);
    }
}
void solve()
{
    sort (patient.begin(), patient.end());
    int curr_time = 0, sz = patient.size();
    for (int i = 0; i < sz; i++)
        curr_time = max(curr_time, patient[i].first) + patient[i].second;
    cout << curr_time - patient[sz-1].first << endl;
}
int main()
{
    read();
    solve();
}
