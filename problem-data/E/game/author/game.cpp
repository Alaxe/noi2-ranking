// Task: game
// Author: Plamenka Hristova
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int k, m, lastmin, nom, sum=0, c, br=0;
    cin>>m>>k;
   do
    {
        cin>>c;
        br++;
        if(c%2==0) sum+=c;
        if(br==1)
        { nom=br;
          lastmin=c;
        }
        else
        {
          if(fabs(m-c)<= fabs(m-lastmin))
          {
            nom=br;
            lastmin=c;
          }
        }
    } while(sum<=k && br<200);

    cout<<nom<<' '<<sum<<endl;
}
