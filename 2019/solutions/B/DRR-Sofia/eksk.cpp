#include<bits/stdc++.h>
#include<bits/stl_vector.h>
using namespace std;

vector<int> graph[200001];
vector<int> aPath;
vector<int> bPath;
int maxPath;

void APath();

void BPath()
{
    vector<int>::reverse_iterator current = bPath.rbegin();
    for(vector<int>::iterator j = graph[*current].begin(); j != graph[*current].end(); j++)
    {
        bool doIt = true;
        for(vector<int>::iterator s = bPath.begin(); s != bPath.end(); s++)
        {
            if(*s == *j)
            {
                // Already been here
                doIt = false;
            }
        }

        for(vector<int>::iterator s = aPath.begin(); s != aPath.end(); s++)
        {
            if(*s == *j)
            {
                // A has been here
                doIt = false;
            }
        }

        if(doIt)
        {
            bPath.push_back(*j);
            // Increase path length
            if(maxPath < bPath.size()) maxPath = bPath.size();
            APath();
            bPath.pop_back();
        }
    }
    return;
}

void APath()
{
    vector<int>::reverse_iterator current = aPath.rbegin();
    for(vector<int>::iterator j = graph[*current].begin(); j != graph[*current].end(); j++)
    {
        bool doIt = true;
        for(vector<int>::iterator s = aPath.begin(); s != aPath.end(); s++)
        {
            if(*s == *j)
            {
                // Already been here
                doIt = false;
            }
        }

        for(vector<int>::iterator s = bPath.begin(); s != bPath.end(); s++)
        {
            if(*s == *j)
            {
                // B has been here
                doIt = false;
            }
        }

        if(doIt)
        {
            aPath.push_back(*j);
            BPath();
            aPath.pop_back();
        }
    }
    return;
}

int main()
{
    int n = 0, u = 0, v = 0, a = 0, b = 0;
    cin >> n;
    for(int i = 0 ; i < n - 1; i++)
    {
        cin >> u;
        cin >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cin >> a;
    cin >> b;
    aPath.push_back(a);
    bPath.push_back(b);
    APath();
    cout << maxPath;
    return 0;
}
