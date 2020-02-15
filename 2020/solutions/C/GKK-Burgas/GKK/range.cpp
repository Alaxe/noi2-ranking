#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 100000;
int seq[N]; vector<int>ans;

int main()
{
    int n, m;
    cin>>n;
     for(int i = 0; i < n; i++)
        cin>>seq[i];
    sort(seq, seq + n);

    int min = seq[0];
    int max = seq[n-1];

    cin>>m; int ai, bi;
    for(int i = 0; i < m; i++)
    {
        cin>>ai>>bi;
        if(bi < min || max < ai) ans.push_back(0);
        else
        {
            if(ai < min && bi <= max) // 3456 for range 1-5
            {
                for(int j = 0; j < n; j++)
                {
                    if(bi < seq[j + 1] && bi > seq[j]){ ans.push_back(j+1); break;}
                        if(bi == seq[j]){ans.push_back(j+1); break;}
                }


            }

            else if(ai <= min && bi >= max) //3456 for range 1-7
            {
               ans.push_back(n);
            }


            else if(ai >= min && bi > max) //3456 for range 4-7
            {
                for(int j = 0; j < n; j++)
                {
                    if(ai <= seq[j + 1] && ai >= seq[j]){ ans.push_back(n-j-1); break;}
                }

            }

            else //if(ai >= min && bi <= max) //3456 for range 3-6
            {
                int x, y;
                for(int j = 0; j < n - 1; j++)
                {
                    if(ai == seq[j]) x = j; if(bi == seq[j]){ y = j; ans.push_back(y-x+1); break; }
                    if(ai < seq[j + 1] && ai > seq[j])  x = j + 1;
                    if(bi < seq[j + 1] && bi > seq[j]){ y = j; ans.push_back(y - x + 1); break;}
                }
            }

        }
    }
    for(int i = 0; i < ans.size(); i++) cout<<ans[i]<<endl;
}
