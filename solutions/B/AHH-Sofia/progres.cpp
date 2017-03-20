#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
vector<int> V[1001];
int A[1001];
int N;
ll mem[1001][1001];

int main()
{
    cin >> N;
    //N = 500;
    for(int i = 0; i < N; i++)
    {
        cin >> A[i];
        //A[i] = i+1;
        V[A[i]].push_back(i);
    }
    ll ans = 0;

    for(int i = 0; i < N-1; i++)
    {
        if(A[i] < A[N-1])
        {
            //cout << i << " " << N-1 << " " << 1 << endl;
            mem[i][N-1] = 1;
            ans++;
        }
    }
    for(int i = N-2; i >= 0; i--)
    {
        for(int j = N-2; j > i; j--)
        {
            if(A[i] >= A[j])continue;
            mem[i][j]=1;
            int next_num = 2*A[j] - A[i];
            if(next_num > 1000 || V[next_num].empty() || V[next_num].back() < j)
            {
                //cout<< i << " " << j << " " << mem[i][j] << endl;
                ans+=1;
                ans%=123456789012345;
                continue;
            }
            int l_b = distance(V[next_num].begin(),lower_bound(V[next_num].begin(),V[next_num].end(),j));
            for(int k = l_b; k < V[next_num].size(); k++)
            {
                mem[i][j]+=mem[j][V[next_num][k]];
                mem[i][j]%=ll(123456789012345);
            }
            //cout<< i << " " << j << " " << mem[i][j] << endl;
            ans+=mem[i][j];
            ans%=ll(123456789012345);
        }
    }
    cout << ans << endl;
}
