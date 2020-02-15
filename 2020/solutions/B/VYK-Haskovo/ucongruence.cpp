#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

const int MAXN = 1000005;

struct apiece
{
    int value,index,level;
};

long long N,U,x,br,y,w;
unsigned long long n=1;
apiece redica[MAXN];
int red[MAXN];
stack <int> s;
apiece add;

bool cmp(apiece A, apiece B)
{
    if(A.value!=B.value) return A.value < B.value;
    return A.index < B.index;
}

bool cmp2(apiece A, apiece B)
{
    return A.index < B.index;
}
int k;
bool flag = false;

void rec(int index, int baseK)
{
    for(int i=index;i<U;i++)
    {
        k=baseK;
        while(k!=0)
        {
            k--;rec(i+1,baseK-1);
            if(flag==true)
            {
                s.push(i);return;
            }
        }
        n++;
        if(n == w)
        {
            flag = true;
            s.push(i);
            return;
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N>>U;
    for(int i=0;i<N;i++)
    {
        cin >> x;
        add.level = 0;
        add.value = x;
        add.index = i;
        redica[i] = add;
    }
    sort(redica,redica + N, cmp);
    br=1;
    red[y] = br;y++;
    redica[0].level = br;
    for(int i=1;i<N;i++)
    {
        if(redica[i].value != redica[i-1].value)
        {
            br++;
            redica[i].level = br;
            red[y] = br;
            y++;
        }
        else
        {
            redica[i].level=br;
        }
    }
    int yDel = 1;
    for(int i=0;i<y;i++) {yDel *= i+1;}
    n = U;
    for(int i=1;i<y;i++)
    {
        n *= (U-i);
    }
    n/=yDel;
    w = (n+1)/2;
    n=0;
    k =y-1;
    rec(1,k);


    redica[0].value = s.top();
    for(int i=1;i<N;i++)
    {
        if(redica[i].level==redica[i-1].level)
        {
            redica[i].value = s.top();
        }
        else
        {
            s.pop();
            redica[i].value = s.top();
        }
    }


    sort(redica,redica + N, cmp2);

    for(int i=0;i<N-1;i++)
    {
        cout << redica[i].value << ' ';
    }

    cout << redica[N-1].value << '\n';


    return 0;
}







///rec bachka bez return
/*int rec(int index, int baseK)
{
    for(int i=index;i<U;i++)
    {
        k=baseK;
        while(k!=0)
        {
            k--;rec(i+1,baseK-1);
        }
        n++;
        if(n == w)
        {
            cout << i << '\n';
        }
    }
    return i;
}
*/



/*for(int i=1;i<=U;i++)
    {
        for(int j=i+1;j<=U;j++)
        {
            n++;
            if(n==w)
            {
                 for(int jj=0;jj<N;jj++)
                {
                        if(redica[jj].level == 1) redica[jj].value=i;
                        if(redica[jj].level == 2) redica[jj].value=j;
                }
                sort(redica,redica + N, cmp2);
                for(int x=0;x<N;x++) cout << redica[x].value << ' ';
                cout << '\n';
            }
        }
    }*/





/*
 for(int i=red[0];i<=U;i++)
    {
        for(int j=i + red[1] - 1;j<=U;j++)
        {
            n++;
            if ( n == 163) cout  << i << ' ' << j << '\n';
        }
    }
*/



//    for(int j=0;j<y;j++) cout << red[j]<< ' ';


    //sort(redica,redica + N, cmp2);


