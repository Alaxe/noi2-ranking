#include<iostream>
#define MAXN 100005
#define MAXA 10005
using namespace std;

struct node
{
    int a, pos;
};
node m[MAXN];

int n;

int checktillend(int b)
{
    if(b==n-1) return 1;
    for(int i=b+1; i<n; i++)
    {
        if(m[i].a<m[i-1].a)
        {
            return 0;
        }
    }
    return 1;
}

int tryy()
{

    int a;
    for(int i=1; i<n; i++)
    {
        if(m[i].a<m[i-1].a)
        {
            a=checktillend(i);
            if(a==1)
            {
                cout<<m[i-1].a - m[i].a<<endl;
                return 1;
            }
            return 0;
        }
    }
    cout<<0<<endl;
    return 1;
}


int v[MAXN];
void rec()
{

    int l=0, me, highers = 0;
    int ans=0;
    int higher=0;
    int lower = 0;
    //int sumtillnow = m[0].a;
    for(int i=1; i<n; i++)
    {
        //sumtillnow +=m[i].a;
        if(m[i].a+v[i]>m[i-1].a) continue;
        me = m[i-1].a + v[i-1] - m[i].a;

        for(int j=i-1; j>=0; j--)
        {
            if(m[j].a>m[i].a)
            {
            	higher = v[j];
            	lower = m[j].a+v[j]-m[i].a;


                l=l+(lower-higher - v[j]);
            }
            else break;
        }
        ans=min(l,me);
        if(l<me)
        {
            for(int j=i-1; j>=0; j--)
            {
                if(m[j].a>m[i].a)
                {
                    v[j]=v[j]+(m[j].a-m[i].a);
                    //m[j].a=m[i].a;
                }
            }
        }
        else
        {
            v[i]=me;
            //m[i].a=m[i-1].a;
        }
    }
}

int main()
{

    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>m[i].a;
        m[i].pos=i;

    }
    bool a = tryy();
    if(a)
    {
        return 0;
    }

    rec();

    bool t = checktillend(1);
    if(t==1)
	{
	cout<<m[1].a-m[0].a<<endl;;
		return 0;
	}
    int ans=0;
    for(int i=1;i<=n;i++)
	{
	ans+=v[i];
	}
	cout<<ans<<endl;
}

/**
5
2 6 4 3 2




*/
