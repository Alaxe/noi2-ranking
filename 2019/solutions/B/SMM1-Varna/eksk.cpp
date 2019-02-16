#include<bits/stdc++.h>
using namespace std;
vector <int> G[200000];
bool used[200000];
int maxdist=0;
int selo1br=0;
int selo2br=0;

int dig(vector <int> G[], int selo1, int selo2)
{
used[selo1]=true;
used[selo2]=true;
maxdist++;

for(int i=0; i<G[selo1].size(); i++)
    {
        if(!used[G[selo1][i]])
            {
              for(int j=0;j<G[selo2].size();j++)

                if(!used[G[selo2][j]])
                {
                   // dig(G, G[selo1][i],G[selo1][i]);
                    used[G[selo1][i]]=true;
                    used[G[selo2][j]]=true;
                    maxdist++;
                }

            }

    }
}


int main()
{
 cin.tie(0);
 cout.tie(0);
 int selo1;
 int selo2;

 int n;
 cin>>n;    int max_ending_here=0;
 for(int i=1;i<n-1;i++)
 {
  int b,d;
  cin>>b>>d;
  G[b].push_back(d);
  G[d].push_back(b);
 }
 cin>>selo1>>selo2;
 dig(G,selo1,selo2);
 cout<<maxdist+1<<endl;
}
