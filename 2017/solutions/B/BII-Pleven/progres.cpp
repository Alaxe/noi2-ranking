#include<cstdio>
#include<vector>
using namespace std;
bool fl[1000];
vector<int> prog;
int main ()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(!fl[a[j]-a[i]] && a[j]-a[i]>0)
            {
                prog.push_back(a[j]-a[i]);
                fl[a[j]-a[i]]=true;
            }
        }
    }
    int br=0;
    for(int i=0; i<prog.size(); i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                if(a[k]-a[j]==prog[i])
                {
                    br++;
                }
            }
        }
        if(n<500)
            for(int j=0; j<n; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                    for(int l=k+1; l<n; l++)
                    {
                        if(a[k]-a[j]==prog[i] && a[l]-a[k]==prog[i])
                        {
                            br++;
                        }
                    }
                }
            }
        if(n<180)
            for(int j=0; j<n; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                    for(int l=k+1; l<n; l++)
                    {
                        for(int m=l+1; m<n; m++)
                            if(a[k]-a[j]==prog[i] && a[l]-a[k]==prog[i] && a[m]-a[l]==prog[i])
                            {
                                br++;
                            }
                    }
                }
            }
        if(n<31){
            for(int j=0; j<n; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                    for(int l=k+1; l<n; l++)
                    {
                        for(int m=l+1; m<n; m++)
                            for(int o=m+1; o<n; o++)
                                if(a[k]-a[j]==prog[i] && a[l]-a[k]==prog[i] && a[m]-a[l]==prog[i] && a[o]-a[m]==prog[i])
                                {
                                    br++;
                                }
                    }
                }
            }
        }
    }
    printf("%d\n",br%123456789012345);
    return 0;
}
