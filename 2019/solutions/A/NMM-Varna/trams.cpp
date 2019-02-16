#include <iostream>
#include <queue>
#define maxn 50000
#include <algorithm>
using namespace std;
deque<int> dominos[maxn];
int main()
{
    int n, l;
    cin>>n>>l;
    int a, b;
    cin>>a>>b;
    int res = 0;
    bool found;
    dominos[res].push_back(a);
    dominos[res].push_back(b);
    res = 1;
    for(int i = 1; i < l; i++)
    {
        cin>>a>>b;
        found = false;
        for(int d = 0; d < res; d++)
        {
            if(dominos[d].front() == a)
            {
                found = true;
                dominos[d].push_front(b);
                break;
            }
            else if(dominos[d].back() == a)
            {
                found = true;
                dominos[d].push_back(b);
                break;
            }
            else if(dominos[d].front() == b)
            {
                found = true;
                dominos[d].push_front(a);
                break;
            }
            else if(dominos[d].back() == b)
            {
                found = true;
                dominos[d].push_back(a);
                break;
            }
        }
        if(!found)
        {
            dominos[res].push_back(a);
            dominos[res].push_back(b);
            res++;
        }
    }

    // Unconnected in the first try
    int realres = res;
    for(int d  = 0; d < res; d++)
    {
        for(int d1 = d+1; d1 < res; d1++)
        {
            if(dominos[d].front() != -1 && dominos[d1].front()!=-1)
            {
                if(dominos[d].front() == dominos[d1].front())
                {
                    for(a = 1; a < dominos[d].size(); a++)
                    {
                        dominos[d1].push_front(dominos[d][a]);
                    }
                    dominos[d].push_front(-1);
                    realres --;
                    break;
                }
                else if(dominos[d].back() == dominos[d1].front())
                {
                    for(a = dominos[d].size()-2; a >=0 ; a--)
                    {
                        dominos[d1].push_front(dominos[d][a]);
                    }
                    dominos[d].push_front(-1);
                    realres--;
                    break;
                }
                else if(dominos[d].front() == dominos[d1].back())
                {
                    for(a = 1; a < dominos[d].size(); a++)
                    {
                        dominos[d1].push_back(dominos[d][a]);
                    }
                    dominos[d].push_front(-1);
                    realres--;
                    break;
                }
                else if(dominos[d].back() == dominos[d1].back())
                {
                    for(a = dominos[d].size()-2; a >=0 ; a--)
                    {
                        dominos[d1].push_back(dominos[d][a]);
                    }
                    dominos[d].push_front(-1);
                    realres--;
                    break;
                }
            }

        }
    }

    // Loops handling

    for (int d = 0; d < res; d++)
    {
        if(dominos[d].front() == dominos[d].back())
        {
            found = false;
            int chislo = dominos[d].front();
            for (int d1 = 0; d1 < res; d1++)
            {
                if(d!= d1 && dominos[d].front()!=-1 && dominos[d1].front()!=-1 && !found)
                {
                    for(a = 0; a < dominos[d1].size() ; a++)
                    {
                        if(dominos[d1][a] == chislo)
                        {
                            found = true;
                            for(b = 1; b < dominos[d].size() ; b++)
                            {
                                dominos[d1].insert(dominos[d1].begin() + a, dominos[d][b]);
                            }
                            dominos[d].push_front(-1);
                            realres--;
                            break;
                        }
                    }
                }
            }
        }
    }

    cout<<realres<<endl;
    for (int d = 0; d < res; d++)
    {
        if(dominos[d].front()!=-1)
        {
            cout<<dominos[d].size()<< " ";
            while(true)
            {
                if(dominos[d].front())
                {
                    cout<<dominos[d].front()<< " ";
                    dominos[d].pop_front();
                }
                else
                    break;
            }
            cout<<endl;
        }

    }
    return 0;
}


/*

8 12
2 3
3 4
5 4
2 6
4 8
6 8
8 7
5 7
6 7
1 2
1 5
1 3

*/

/*

7 7
1 2
2 3
4 5
5 6
6 4
3 4
4 7


*/

