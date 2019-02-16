#include<iostream>
#include<vector>
using namespace std;
unsigned int N, maxY = 0, counter = 0, minCounter = 0, cPosX;
unsigned int cPosY = 0;

int min_tries(unsigned int nX, vector<unsigned int[3]> p, vector<bool> v)
{
cPosX = nX;
while(cPosY!=0)
  {
    for(int j=0;j<N;j++)
    {
    if(cPosX == p[j][0] && cPosY == p[j][1])
        {
            if(!v[j])
                {
                    v[j]=true;
                    cPosX--;
                    break;
                }
            else
            {
            for(int k=0;k<p[j][2];k++)
                {
                if(cPosX == p[j][0]+k && cPosX>=1) cPosX++;
                }
            }
          counter++;
          break;
        }
    }
cPosY--;
  }
if(counter<minCounter)minCounter=counter;
for(unsigned i=0;i<N;i++)
{
    if(!v[i])
    {
        counter=0;
        cPosY=maxY;
        min_tries(nX,p,v);
    }
}
return minCounter;
}
int main()
{
vector<unsigned int[3]> planks;
vector<bool> visited;
vector<unsigned int> starting_position;
planks.reserve(100000);
starting_position.reserve(100000);
unsigned int T,x_input,y_input,d_input;

cin>>N;
for(unsigned int i=0;i<N;i++)
{
        cin>>x_input>>y_input>>d_input;
        planks[i][0]= x_input;
        planks[i][1]= y_input;
        planks[i][2]= d_input;
        if(y_input>maxY)maxY = y_input;
}
cin>>T;
for(unsigned int i=0;i<T;i++)
{
    cin>>x_input;
    starting_position.push_back(x_input);
}
for(unsigned int i=0;i<starting_position.size();i++)
{
    cPosY = maxY;
    for(unsigned int i=0;i<N;i++)
    {
        visited[i]=false;
    }
    minCounter = 999999;
    cout<<min_tries(starting_position[i],planks,visited)<<" ";
}

}
