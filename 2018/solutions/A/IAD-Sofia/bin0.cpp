#include <iostream>
using namespace std;
long long facp[21] = {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000,20922789888000,355687428096000,6402373705728000,121645100408832000,2432902008176640000};
string mol(string x, int w)
{
    string rr = "";
    int p = 0;
    for(int i = 0; i < x.size(); i ++)
    {
        int res = ((x[i]-'0')*w+p)%10;
        p = ((x[i]-'0')*w+p)/10;
        rr += res+'0';
    }
    if(p > 0) rr += p+'0';
    return rr;
}
string sum(string a, string b)
{
    string rr = "";
    int p = 0;
    for(int i = 0; i < max(a.size(),b.size()); i ++)
    {
        int res;
        if(i >= a.size()) res = ((b[i]-'0')+p);
        else if(i >= b.size()) res = ((a[i]-'0')+p);
        else res = ((a[i]-'0')+(b[i]-'0')+p);
        p = res/10;
        res %= 10;
        rr += res+'0';
    }
    if(p > 0) rr += p+'0';
    return rr;
}
string ml(string a, string b)
{
    string res = "";
    string nuli = "";
    for(int i = 0; i < a.size(); i ++)
    {
        res = sum(res, nuli+mol(b,int(a[i]-'0')));
        nuli += "0";
    }
    return res;
}
int les(string a, string b)
{
    if(a.size() < b.size()) return 1;
    if(a.size() > b.size()) return 0;

}
string sub(string a, string b)
{

}
string div(string a, string b)
{

}
string rev(string a)
{
    string res = "";
    for(int i = a.size()-1; i >= 0; i --) res += a[i];
    return res;
}
string tostr(int w)
{
    string res = "";
    while(w != 0)
    {
        res += (w%10)+'0';
        w /= 10;
    }
    return res;
}
long long fact(int w)
{
    //if(w < 21) return facp[w];
    long long res = 1;
    for(int i = 2; i <= w; i ++)
    {
        res *= i;
    }
    return res;
}
long long btp(int f, int k) // f nad k
{
    if(k > f) return 0;
    long long res = 1;
    for(int i = k+1; i <= f; i ++)
    {
        res *= i;
    }
    return res/fact(k);
}
long long low = 1, ans = 0, high = 1;
int ll,l, af, bf;
int main()
{
    //for(int i = 0; i < 21; i ++) cout << fact(i) << ",";
    long long a, b, s, ss, sss;
    cin >> a >> b >> s;
    ss = s;
    sss = s;
    while(low < a)
    {
        low *= 2;
        l ++;
        ll ++;
    }
    high = low;
    while(high < b)
    {
        ans += btp(l, s);
        high *= 2;
        l ++;
    }
    // trqbva da dobavq ot [a,low) i mahna ot (b,high]
                                               int crr;
    if(low != a)
    {
        int tmp3 = low/2, tmp4 = low;
        crr = ll-1;
        if((tmp3+tmp4)/2 == a) ans += btp(crr-1, ss);
        while((tmp3+tmp4)/2 != a)
        {
            if((tmp3+tmp4)/2 > a)
            {
                crr --;
                ans += btp(crr, ss);
                //cout << tmp3 << " " << tmp4 << " pribavqm vsichko nadolu(crr = "<<crr<<"), a to e:" << btp(crr, ss) << endl;
                ss --;
                tmp4 = (tmp3+tmp4)/2;
            }
            else if((tmp3+tmp4)/2 < a)
            {
                crr --;
                tmp3 = (tmp3+tmp4)/2;
            }
        }
        int hm = 0;
        while(a != 0 && (low/2+low)/2 != a)
        {
            if(a%2 == 0) hm ++;
            a /= 2;
        }
        if(hm == sss) ans ++;
    }
    if(high != b)
    {
        long tmp1 = high/2;
        long tmp2 = high;
        crr = l-1;
        if((tmp2+tmp1)/2 == b) ans -= btp(crr-1, s);
        while((tmp2+tmp1)/2 != b)
        {
            //cout << tmp1 << " " << tmp2 << endl;
            if((tmp2+tmp1)/2 > b)
            {
                crr --;
                ans -= btp(crr, s);
                //cout << tmp1 << " " << tmp2 << " vadq vsichko nadolu(crr = "<<crr<<"), a to e:" << btp(crr, s) << endl;
                s --;
                tmp2 = (tmp2+tmp1)/2;
            }
            else if((tmp2+tmp1)/2 < b)
            {
                crr --;
                tmp1 = (tmp2+tmp1)/2;
            }
            //cout << tmp1 << " " << tmp2 << endl;
        }
        /*int hm = 0;
        while(b != 0)
        {
            if(b%2 == 0) hm ++;
            b /= 2;
        }
        //if(hm == sss) ans ++;*/
    }
    cout << ans << endl;
}
