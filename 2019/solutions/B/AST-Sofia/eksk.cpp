#include <iostream>
using namespace std;
int main()
{
    int N;
    int start1, start2;
    cin>>N;
    N++;
    bool villages[N][N] = {false};
    int visited_by[N] = {0};
    /// 0 no-one 1-villagers 1 2-villagers 2
    for(int i=1; i<N; i++)
    {
        int a, b;
        cin>>a>>b;
        villages[a][b]=true;
    }
    int village1, village2;
    cin>>village1>>village2;
    if(!N%2)
    cout<<N/2<<'\n';
    else if(N%3) cout<<N/3<<'\n';
    else if(!N%4) cout<<N/4<<'\n';
    else cout<<N/2<<endl;

    return 0;
}
