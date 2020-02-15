#include <iostream>
#include <iterator>
#include <map>
using namespace std;

map<int, int> A;
map<int, int> B;

int main()
{ int w,k,a,b,n,m;

cin>>w>>k>>n;
int stA[n];
for (int i=0;i<n;i++)
cin>>stA[i];

cin>>m;
int stB[m];
for (int i=0;i<m;i++)
cin>>stA[i];
int g=0;

while (g<n)
{
    if ((stA[g]==stA[g+1])&& (stA[g]==stA[g+k-2]))

    {
        if (A.count(stA[g])>0)
        {
            A[stA[g]]++;

        }
        else
          A.insert({stA[g], 1 });
    }
    g++;
}

g=0;
while (g<m)
{
    if ((stA[g]==stA[g+1])&& (stA[g]==stA[g+k-2]))
    {
        if (B.count(stB[g])>0)
        {
            B[stB[g]]++;

        }
        else
          B.insert({stB[g], 1 });
    }

    g++;
}

int answer=0;
for(map<int,int>::iterator it = A.begin(); it != A.end(); it++)
{
    if(B.count(it->first)>0)
       {
         answer=answer+B[it->second]*A[it->second];
       }
}
   cout<<answer<<endl;


    return 0;
}

