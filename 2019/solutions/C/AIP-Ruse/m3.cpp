#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<stack>
#include<string>

using namespace std;

int pul[10];

void nuli(int n)
{
    int n2 = n,br = 0;
    do
    {
        n2 /= 10;
        br++;
    }
    while(n2 != 0);

    cout<<n;
    for(int i = 0;i < 3 - br;i++)
    {
        cout<<"0";
    }
}
int main()
{
    int s,k,a,b,c,d,br = 1;
    cin>>s>>k>>a>>b>>c>>d;
    br += k / (d * 4);
    if(k % (d * 4) == 0)
    {
        cout<<d<<".000 "<<d<<".000 "<<d<<".000 "<<d<<".000 "<<endl;
        return 0;
    }
    if(k > s * 4 * d)
    {
        cout<<((k * 1000) / (s * 4)) / 1000<<".";
        nuli(((k * 1000) / (s * 4)) % 1000);
        cout<<" ";
        cout<<((k * 1000) / (s * 4)) / 1000<<".";
        nuli(((k * 1000) / (s * 4)) % 1000);
        cout<<" ";
        cout<<((k * 1000) / (s * 4)) / 1000<<".";
        nuli(((k * 1000) / (s * 4)) % 1000);
        cout<<" ";
        cout<<((k * 1000) / (s * 4)) / 1000<<".";
        nuli(((k * 1000) / (s * 4)) % 1000);
        cout<<" ";
        return 0;
    }
    k %= d * 4;
    if(br == 1)
    {
        swap(b,c);
    }
    if(br == 2)
    {
        swap(b,a);
    }
    if(br == 3)
    {
        swap(a,c);
        swap(a,b);
    }
    if(br == 4)
    {
        swap(a,b);
        swap(a,c);
    }

    if(br == 1||br == 3)
    {
        if(k <= a)
        {
            cout<<k<<".000 "<<d<<".000 "<<d<<".000 "<<d<<".000"<<endl;
            return 0;
        }
        pul[0] = a * 1000;
        if(k - a <= a)
        {
            cout<<pul[0]/1000<<".";
            nuli(pul[0] % 1000);
            cout<<" "<<k - a<<".000 "<<0<<".000 "<<0<<".000"<<endl;
            return 0;
        }
        pul[1] = a * 1000;
        if(k <= b * 2)
        {
            cout<<(k * 1000 / 2) / 1000<<".";
            nuli((k * 1000 / 2) % 1000);
            cout<<" "<<(k * 1000 / 2) / 1000<<".";
            nuli((k * 1000 / 2) % 1000);
            cout<<" "<<0<<".000 "<<0<<".000"<<endl;
            return 0;
        }
        pul[0] = b * 1000;
        pul[1] = b * 1000;
        if(k - 2 * b <= c)
        {
            cout<<pul[0]/1000<<".";
            nuli(pul[0] % 1000);
            cout<<" ";
            cout<<pul[1]/1000<<".";
            nuli(pul[1] % 1000);
            cout<<" ";
            cout<<(k - b * 2)<<".000 "<<0<<".000"<<endl;
            return 0;
        }
        pul[2] = c * 1000;
        if(k - 2 * b - c <= c)
        {
            cout<<pul[0]/1000<<".";
            nuli(pul[0] % 1000);
            cout<<" ";
            cout<<pul[1]/1000<<".";
            nuli(pul[1] % 1000);
            cout<<" ";
            cout<<pul[2]/1000<<".";
            nuli(pul[2] % 1000);
            cout<<" ";
            cout<<(k - b * 2 - c)<<".000"<<endl;
            return 0;
        }
        pul[3] = c * 1000;
        if(k <= 4 * b)
        {
            cout<<pul[0]/1000<<".";
            nuli(pul[0] % 1000);
            cout<<" ";
            cout<<pul[1]/1000<<".";
            nuli(pul[1] % 1000);
            cout<<" ";
            cout<<((k - b * 2) * 1000 / 2) / 1000<<".";
            nuli(((k - b * 2) * 1000 / 2) % 1000);
            cout<<" ";
            cout<<((k - b * 2) * 1000 / 2) / 1000<<".";
            nuli(((k - b * 2) * 1000 / 2) % 1000);
            return 0;
        }

        pul[2] = (k - b * 2) * 1000 / 2;
        pul[3] = (k - b * 2) * 1000 / 2;
        pul[0] = k * 1000 / 4;
        pul[1] = k * 1000 / 4;
        pul[2] = k * 1000 / 4;
        pul[3] = k * 1000 / 4;
        cout<<pul[0]/1000<<".";
        nuli(pul[0] % 1000);
        cout<<" ";
        cout<<pul[1]/1000<<".";
        nuli(pul[1] % 1000);
        cout<<" ";
        cout<<pul[2]/1000<<".";
        nuli(pul[2] % 1000);
        cout<<" ";
        cout<<pul[3]/1000<<".";
        nuli(pul[3] % 1000);
        cout<<endl;
    }



    if(br == 2||br == 4)
    {
        if(k <= a)
        {
            cout<<k<<".000 "<<0<<".000 "<<0<<".000 "<<0<<".000"<<endl;
            return 0;
        }
        pul[0] = a * 1000;
        if(k - a <= b)
        {
            cout<<pul[0]/1000<<".";
            nuli(pul[0] % 1000);
            cout<<" "<<k - a<<".000 "<<0<<".000 "<<0<<".000"<<endl;
            return 0;
        }
        pul[1] = b * 1000;
        if(k - a - b <= b)
        {
            cout<<pul[0]/1000<<".";
            nuli(pul[0] % 1000);
            cout<<" ";
            cout<<pul[1]/1000<<".";
            nuli(pul[1] % 1000);
            cout<<" "<<k - a - b<<".000 "<<0<<".000"<<endl;
            return 0;
        }
        pul[2] = b * 1000;
        cout<<k<<endl;
        if(k - a<= min(a,c) * 2)
        {
            cout<<pul[0]/1000<<".";
            nuli(pul[0] % 1000);
            cout<<" "<<((k - a) * 1000 / 2) / 1000<<".";
            nuli(((k - a) * 1000 / 2) % 1000);
            cout<<" "<<((k - a) * 1000 / 2) / 1000<<".";
            nuli(((k - a) * 1000 / 2) % 1000);
            cout<<" "<<0<<".000"<<endl;
            return 0;
        }
        pul[2] = min(a,c) * 1000;
        pul[1] = min(a,c) * 1000;
        if(br == 2)
        {
            if(k <= c * 3)
            {
                cout<<k / 3<<".";
                nuli((k * 1000 / 3) % 1000);
                cout<<" ";
                cout<<k / 3<<".";
                nuli((k * 1000 / 3) % 1000);
                cout<<" ";
                cout<<k / 3<<".";
                nuli((k * 1000 / 3) % 1000);
                cout<<" ";
                cout<<0<<".000"<<endl;
                return 0;
            }
            pul[0] = k * 1000 / 3;
            pul[1] = k * 1000 / 3;
            pul[2] = k * 1000 / 3;
            if(k - 3 * c <= c)
            {
                cout<<pul[0]/1000<<".";
                nuli(pul[0] % 1000);
                cout<<" ";
                cout<<pul[1]/1000<<".";
                nuli(pul[1] % 1000);
                cout<<" ";
                cout<<pul[2]/1000<<".";
                nuli(pul[2] % 1000);
                cout<<" ";
                cout<<(k - 3 * c)<<".000"<<endl;
                return 0;
            }
            pul[0] = k * 1000 / 4;
            pul[1] = k * 1000 / 4;
            pul[2] = k * 1000 / 4;
            pul[3] = k * 1000 / 4;
            cout<<pul[0]/1000<<".";
            nuli(pul[0] % 1000);
            cout<<" ";
            cout<<pul[1]/1000<<".";
            nuli(pul[1] % 1000);
            cout<<" ";
            cout<<pul[2]/1000<<".";
            nuli(pul[2] % 1000);
            cout<<" ";
            cout<<pul[3]/1000<<".";
            nuli(pul[3] % 1000);
            cout<<endl;
            }
        else
        {
            if(k <= c * 2)
            {
                cout<<k / 2<<".";
                nuli((k * 1000 / 2) % 1000);
                cout<<" ";
                cout<<k / 2<<".";
                nuli((k * 1000 / 2) % 1000);
                cout<<" ";
                cout<<k / 3<<".";
                nuli((k * 1000 / 2) % 1000);
                cout<<" ";
                cout<<0<<".000"<<endl;
                return 0;
            }
            pul[1] = k * 1000 / 3;
            pul[2] = k * 1000 / 3;
            if(k - a - 2 * c <= c)
            {
                cout<<pul[0]/1000<<".";
                nuli(pul[0] % 1000);
                cout<<" ";
                cout<<pul[1]/1000<<".";
                nuli(pul[1] % 1000);
                cout<<" ";
                cout<<pul[2]/1000<<".";
                nuli(pul[2] % 1000);
                cout<<" ";
                cout<<(k - a - 2 * c)<<".000"<<endl;
                return 0;
            }

            if(k - a <= c)
            {
                cout<<pul[0]/1000<<".";
                nuli(pul[0] % 1000);
                cout<<" ";
                cout<<(k - a) / 3<<".";
                nuli(((k - a) * 1000 / 3)  % 1000);
                cout<<" ";
                cout<<(k - a) / 3<<".";
                nuli(((k - a) * 1000 / 3)  % 1000);
                cout<<" ";
                cout<<(k - a) / 3<<".";
                nuli(((k - a) * 1000 / 3)  % 1000);
                cout<<endl;
                return 0;
            }
            pul[0] = k * 1000 / 4;
            pul[1] = k * 1000 / 4;
            pul[2] = k * 1000 / 4;
            pul[3] = k * 1000 / 4;
            cout<<pul[0]/1000<<".";
            nuli(pul[0] % 1000);
            cout<<" ";
            cout<<pul[1]/1000<<".";
            nuli(pul[1] % 1000);
            cout<<" ";
            cout<<pul[2]/1000<<".";
            nuli(pul[2] % 1000);
            cout<<" ";
            cout<<pul[3]/1000<<".";
            nuli(pul[3] % 1000);
            cout<<endl;
        }
    }
    return 0;
}
