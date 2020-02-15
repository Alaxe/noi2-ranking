#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct operations
{
   bool op=false;
   bool om=false;
   bool omp=false;
   bool od=false;
};

int P[200001];
int Br[200001];

int main()
{
   string s;
   cin >> s;

   vector<pair<int, int> > bracks;
   vector<operations> pbracks;
   int ss=s.size();
   priority_queue<int> q;
   for(int i=0; i<ss; i++)
    {
       if(s[i]=='(')
        q.push(i);
       if(s[i]==')')
        {
           int j=q.top();
           q.pop();
           bracks.push_back(make_pair(j, i));
           operations o;
           pbracks.push_back(o);
           Br[i]=j;
        }
    }

   int bs=bracks.size();
   for(int i=0; i<bracks.size(); i++)
    {
       bool p=false, m=false, mp=false, d=false;
       for(int j=bracks[i].second-1; j>bracks[i].first; j--)
        {
           if(s[j]=='/')
            {
               d=true;
               pbracks[j].od=true;
            }
           else if(s[j]=='*')
            {
               mp=true;
               pbracks[j].omp=true;
            }
           else if(s[j]=='+')
            {
               p=true;
               pbracks[j].op=true;
            }
           else if(s[j]=='-')
            {
               m=true;
               pbracks[j].om=true;
            }
           else if(s[j]==')' && !P[j])
            {
               if(pbracks[j].om)
                m=true;
               if(pbracks[j].od)
                d=true;
               if(pbracks[j].omp)
                mp=true;
               if(pbracks[j].op)
                p=true;
               j=Br[j];
            }
        }
       if(bracks[i].first-1>=0 && s[bracks[i].first-1]=='/')
        {
           P[bracks[i].first]=false;
           P[bracks[i].second]=false;
        }
       else if(bracks[i].first-1>=0 && s[bracks[i].first-1]=='*')
        {
           if(p || d || m)
            {
               P[bracks[i].first]=false;
               P[bracks[i].second]=false;
            }
           else
            {
               P[bracks[i].first]=true;
               P[bracks[i].second]=true;
            }
        }
       else if(bracks[i].first-1>=0 && s[bracks[i].first-1]=='+')
        {
           if(bracks[i].second+1<ss && (s[bracks[i].second+1]=='*' || s[bracks[i].second+1]=='/'))
            {
               P[bracks[i].first]=false;
               P[bracks[i].second]=false;
            }
           else
            {
               P[bracks[i].first]=true;
               P[bracks[i].second]=true;
            }
        }
       else if(bracks[i].first-1>=0 && s[bracks[i].first-1]=='-')
        {
           if(bracks[i].second<ss && (s[bracks[i].second+1]=='*' || s[bracks[i].second+1]=='/' || p || m))
            {
               P[bracks[i].first]=false;
               P[bracks[i].second]=false;
            }
           else
            {
               P[bracks[i].first]=true;
               P[bracks[i].second]=true;
            }
        }
       else if(bracks[i].first-1>=0 && s[bracks[i].first-1]=='(')
        {
           if((p||m) && (bracks[i].second+1<ss && (s[bracks[i].second+1]=='*' || s[bracks[i].second+1]=='/')))
            {
               P[bracks[i].first]=false;
               P[bracks[i].second]=false;
            }
           else
            {
               P[bracks[i].first]=true;
               P[bracks[i].second]=true;
            }
        }
      else if(bracks[i].first-1<0)
       {
           if(p||m && (bracks[i].second+1<ss && (s[bracks[i].second+1]=='*' || s[bracks[i].second+1]=='/')))
            {
               P[bracks[i].first]=false;
               P[bracks[i].second]=false;
            }
           else
            {
               P[bracks[i].first]=true;
               P[bracks[i].second]=true;
            }
       }
    }

   for(int i=0; i<ss; i++)
    {
       if(!P[i])
        cout << s[i];
    }


   return 0;
}
/*
((&+&)*&)/&
&+(&*(&-&)-(&-))
*/
