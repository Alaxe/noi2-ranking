#include <bits/stdc++.h>
using namespace std;

struct BigNum
{
    void operator= (const BigNum &other)
    {
        data = other.data;
    }

    void operator= (int other)
    {
        data = "";
        while (other>0)
        {
            data+=char(other%10 + '0');
            other/=10;
        }
        reverse(data.begin(), data.end());
    }

    bool operator< (const BigNum &other)
    {
        if (data.size() < other.data.size())
            return true;
        else if (data.size() > other.data.size())
            return false;

        for (int i=0;i<data.size();i++)
        {
            if (data[i]<other.data[i])
                return true;
            else if (data[i]>other.data[i])
                return false;
        }
        return false;
    }
    bool operator== (const BigNum &other)
    {
        if (data.size() < other.data.size())
            return false;
        else if (data.size() > other.data.size())
            return false;

        for (int i=0;i<data.size();i++)
        {
            if (data[i]<other.data[i])
                return false;
            else if (data[i]>other.data[i])
                return false;
        }
        return true;
    }

    bool operator> (const BigNum &other)
    {
        return !(*this == other || *this < other);
    }

    BigNum operator+ (const BigNum &other)
    {
        BigNum result;
        result.data = "";

        int thisIndex = data.size()-1;
        int otherIndex = other.data.size()-1;
        bool extra = false;

        while (thisIndex >= 0 || otherIndex >= 0)
        {
            int currNumber = 0;
            currNumber += thisIndex>=0 ? int(data[thisIndex] - '0'):0;
            currNumber += otherIndex>=0 ? int(other.data[otherIndex] - '0'):0;
            currNumber += extra;

            extra = currNumber / 10;
            result.data += char('0' + currNumber % 10);
            thisIndex--;
            otherIndex--;
        }
        if (extra == true)
            result.data+= '1';

        reverse(result.data.begin(), result.data.end());
        return result;
    }
    BigNum operator+ (int other)
    {
        BigNum kek;
        kek = other;
        //cout<<"operator+: "<<kek.data<<endl;
        return (*this) + kek;
    }

    BigNum operator* (int other)
    {
        BigNum result;
        result.data = "";

        int extra = 0;
        for (int i=data.size()-1;i>=0;i--)
        {
            int currNumber = 0;
            currNumber += int(data[i]-'0') * other + extra;

            extra = currNumber/10;
            result.data+=char(currNumber%10+'0');
        }

        if (extra>0)
            result.data+=char(extra+'0');

        reverse(result.data.begin(), result.data.end());

        while (result.data.size() > 0 && result.data[0] == '0')
            result.data.erase(0, 1);

        if (result.data.size() == 0)
            result.data+='0';

        return result;
    }

    BigNum operator* (const BigNum &other)
    {
        BigNum result;
        result.data = "";


        for (int i=0;i<other.data.size();i++)
        {
            result.data+='0';
            result = result + (*this * int(other.data[i]-'0'));
        }

        while (result.data.size() > 0 && result.data[0] == '0')
            result.data.erase(0, 1);

        if (result.data.size() == 0)
            result.data+='0';

        return result;
    }
    BigNum operator- (const BigNum &other)
    {
        BigNum result;
        result.data = "";

        bool extra = false;

        for (int i=0;i<other.data.size();i++)
        {
            int currNumber = int(data[data.size()-i-1]-'0') - extra;
            currNumber-=int(other.data[other.data.size()-i-1]-'0');
            if (currNumber<0)
            {
                currNumber += 10;
                extra = true;
            }
            else
                extra = false;
            result.data += char(currNumber + '0');
        }

        for (int i=data.size() - other.data.size()-1;i>=0;i--)
        {
            int currNumber = int (data[i]-'0') - extra;
            if (currNumber < 0)
            {
                currNumber += 10;
                extra = true;
            }
            else
                extra = false;
            result.data += char(currNumber+'0');
        }

        reverse(result.data.begin(), result.data.end());

        while (result.data.size() > 0 && result.data[0] == '0')
            result.data.erase(0, 1);

        if (result.data.size() == 0)
            result.data+='0';

        return result;
    }

    BigNum div2()
    {
        BigNum result;
        result.data="";
        int extra = 0;

        for (int i=0;i<data.size();i++)
        {
            int currNumber = int(data[i]-'0') + extra*10;
            result.data+= char(currNumber/2 + '0');
            extra = currNumber%2;
        }

        while (result.data.size() > 0 && result.data[0] == '0')
        {
            result.data.erase(0, 1);
        }
        if (result.data.size() == 0)
            result.data+='0';

        return result;
    }


    string data;
};

int main()
{

    BigNum M, N;

    cin>>M.data>>N.data;
    //M.data = "1";
    //M.data = "999999999999999999999999999999999999999999999999999999999999999999999999998";
    //N.data = "999999999999999999999999999999999999999999999999999999999999999999999999999";

    //cout<<(N-M).data<<endl;

    BigNum l, r;
    l.data = "0";
    r = (M.div2()+1);

    while (l+1<r)
    {
        //cout<<l.data<<' '<<r.data<<endl;
        BigNum m = l + r;


        m = m.div2();

        if (m.data.size() + (m+1).data.size()-1>M.data.size())
        {
            r = m;
            continue;
        }
        else if (m.data.size() + (m+1).data.size() + 1 < M.data.size())
        {
            l = m;
            continue;
        }

        BigNum kek;
        kek = m;
        kek = kek + 1;

        //cout<<kek.data<<endl;
        kek = kek * m;

        //cout<<kek.data<<endl;

        //char c;
        //cin.get(c);
        //cin.get(c);



        if (kek<M || kek == M)
            l = m;
        else
            r = m;
    }

    BigNum first = l;
    first = first + 1;

    //cout<<first.data<<endl;


    r = (N.div2()+1);

    while (l+1<r)
    {
        //cout<<l.data<<' '<<r.data<<endl;
        BigNum m = l + r;


        m = m.div2();

        if (m.data.size() + (m+1).data.size()-1>N.data.size())
        {
            r = m;
            continue;
        }
        else if (m.data.size() + (m+1).data.size() + 1 < N.data.size())
        {
            l = m;
            continue;
        }

        BigNum kek;
        kek = m;
        kek = kek + 1;

        //cout<<kek.data<<endl;
        kek = kek * m;

        //cout<<kek.data<<endl;

        //char c;
        //cin.get(c);
        //cin.get(c);



        if (kek<N || kek == N)
            l = m;
        else
            r = m;
    }

    BigNum last = l;
    last = last + 1;

    //cout<<last.data<<endl;

    cout<<(last-first).data<<endl;


    return 0;
}

