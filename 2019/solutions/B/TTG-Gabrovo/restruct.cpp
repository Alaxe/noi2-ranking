#include<iostream>
using namespace std;
int n,k;
int a[5000][5000];
int common[5000];
int tree[5000], used[5000];
int pos;
int br=1;
void Init()
{
    cin>>n>>k;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i][0];
        for(int j=1;j<=a[i][0];j++)
        {
            cin>>a[i][j];
            common[a[i][j]]++;
        }
    }

}


void Low()
{
    int br=n;

    for(int i=1;i<=n;i++)
    {
        if(br>common[i]){br=common[i];pos=i;}
    }

}

int Pay(int x)
{
    br++;
   for(int i=1;i<=n;i++)
   {
       if(tree[i]==x)return Pay(i);
   }

   return br;
}



int main()
{
    Init();
    Low();
    tree[pos]=a[pos][1];
    used[a[pos][1]]++;
     for(int i=1;i<=n;i++)
        {   if(i==pos)continue;
            for(int j=1;j<=a[i][0];j++)
            {
                if(a[i][j]==tree[pos]){
                    tree[i]=tree[pos];
                    used[a[i][j]]++;
                break;
                }

            }
            if(tree[i]==tree[pos])break;
        }

    while(true)
    {

        int t=0;
        for(int i=1;i<=n;i++)
            if(tree[i]==0)t++;
        if(t==1)break;


        for(int i=1;i<=n;i++)
        {
            if(tree[i]==0 && used[i]!=2){

                for(int j=1;j<=a[i][0];j++)
                {
                    if(used[a[i][j]]<2){
                        used[a[i][j]]++;
                        tree[i]=a[i][j];
                    }
                }
            }
        }
    }




    int red;

    for(int i=1;i<=n;i++)
        if(tree[i]==0){red=Pay(i);break;}



cout<<k*(red+n+1)<<endl;
    return 0;
}
