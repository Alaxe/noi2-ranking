#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define pb push_back

vi data;
int n;
void read()
{
    cin>>n;
    data = vi(n, 0);
    for(int i=0; i<n; i++)
        cin>>data[i];
}

void solve()
{
    int moves = 0;
    //cout<<"solving\n";
    for(int i=1; i<n; i++)
    {
        if(data[i-1]<=data[i])
            continue;

        if(i==1)
        {
            moves+= data[i-1] - data[i];
            data[i-1] = data[i];
            continue;
        }

        if(data[i-2]<=data[i])
        {
            moves += data[i-1] - data[i];
            data[i-1] = data[i];
        }else
        {
            moves += data[i-1] - data[i];
            data[i] = data[i-1];
        }
    }
    cout<<moves<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    read();
    solve();

    return 0;
}
