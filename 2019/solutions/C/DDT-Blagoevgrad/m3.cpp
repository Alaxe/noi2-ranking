#include<iostream>
#include<vector>
using namespace std;

void round(long double number)
{
   int n=number*10000;
   if(n%10>=5)
    {
       n/=10;
       n++;
    }
   else
    n/=10;
    vector<int> v;
    v.push_back(n%10);
    n/=10;
    v.push_back(n%10);
    n/=10;
    v.push_back(n%10);
    n/=10;
    v.push_back(11);
    while(n>0)
    {
       v.push_back(n%10);
       n/=10;
    }
    for(int i=v.size()-1; i>=0; i--)
    {
       if(v[i]!=11)
        cout << v[i];
       else
        cout << ".";
    }
}

int main()
{
   long long S, K;
   int a, b, c, d;
   cin >> S >> K >> a >> b >> c >> d;
   long long sw=4*d;
   long double ls=K%sw;
   long long bs=K/sw;

   if(bs%4==0)
    {
       if(ls<=a)
        {
           cout << ls << ".000" << " 0.000" << " 0.000" << " 0.000";
        }
       else
        {
           if(ls-a<=a)
            {
                cout << a << ".000" ;
                round(ls-a);
                cout << " " << "0.000 " << "0.000";
            }
           else
            {
               if(ls<=2*c)
                {
                   round(ls/2);
                   cout << " ";
                   round(ls/2);
                   cout << " " << "0.000 " << "0.000";
                }
               else
                {
                   if(ls-2*c<=b)
                    {
                       cout << c << ".000 " << c << ".000 ";
                       round(ls-2*c);
                       cout << " 0.000";
                    }
                   else
                    {
                       if(ls-2*c-b<=b)
                        {
                           cout << c << ".000 " << c << ".000 " << b << ".000 ";
                           round(ls-2*c-b);
                        }
                       else
                        {
                           if(ls-2*c<=2*c)
                           {
                              cout << c << ".000 " << c << ".000 ";
                              round((ls-2*c)/2);
                              cout << " ";
                              round((ls-2*c)/2);
                           }
                           else
                            {
                                round(ls/4);
                                round(ls/4);
                                round(ls/4);
                                round(ls/4);
                            }
                        }
                    }
                }
            }
        }
    }
   else if(bs%3==0)
    {
        if(ls<=c)
        {
           round(ls);
           cout << " 0.000 0.000 0.0000";
        }
       else
        {
           if(ls-c<=a)
            {
               round(c);
               cout << " ";
               round(ls-c);
               cout << " 0.000 0.000";
            }
           else
            {
               if(ls-c-a<=a)
                {
                   round(c);
                   cout << " ";
                   round(a);
                   cout << " ";
                   round(ls-c-a);
                   cout << " 0.000";
                }
               else
                {
                   if(ls-c<=2*b)
                    {
                       round(c);
                       cout << " ";
                       round((ls-c)/2);
                       cout << " ";
                       round((ls-c)/2);
                       cout << " 0.000";
                    }
                   else
                    {
                       if(ls-c-2*b<=b)
                        {
                           round(c);
                           cout << " ";
                           round(b);
                           cout << " ";
                           round(b);
                           cout << " ";
                           round(ls-c-2*b);
                        }
                       else
                        {
                           if(ls-c<=3*b)
                            {
                               round(c);
                               cout << " ";
                               round((ls-c)/3);
                               cout << " ";
                               round((ls-c)/3);
                               cout << " ";
                               round((ls-c)/3);
                            }
                           else
                            {
                               round(ls/4);
                               cout << " ";
                               round(ls/4);
                               cout << " ";
                               round(ls/4);
                               cout << " ";
                               round(ls/4);
                            }
                        }
                    }
                }
            }
        }
    }

   else if(bs%2==0)
    {
                if(ls<=b)
        {
           round(ls);
           cout << " 0.000 0.000 0.000";
        }
       else
        {
           if(ls-b<=b)
            {
               round(b);
               cout << " ";
               round(ls-b);
               cout << " 0.000 0.000";
            }
           else
            {
               if(ls<=2*c)
                {
                   round(ls/2);
                   cout << " ";
                   round(ls/2);
                   cout << " 0.000 0.000";
                }
               else
                {
                   if(ls-2*c<a)
                    {
                       round(c);
                       cout << " ";
                       round(c);
                       cout << " ";
                       round(ls-2*c);
                       cout << " 0.000";
                    }
                   else
                    {
                       if(ls-2*c-a<=a)
                        {
                           round(c);
                           cout << " ";
                           round(c);
                           cout << " ";
                           round(a);
                           cout << " ";
                           round(ls-2*c-a);
                        }
                       else
                        {
                           if(ls-2*c<=2*c)
                            {
                               round(c);
                               cout << " ";
                               round(c);
                               cout << " ";
                               round((ls-2*c)/2);
                               cout << " ";
                               round((ls-2*c)/2);
                            }
                           else
                            {
                               round(ls/4);
                               cout << " ";
                               round(ls/4);
                               cout << " ";
                               round(ls/4);
                               cout << " ";
                               round(ls/4);
                            }
                        }
                    }
                }
            }
        }
    }
   else
    {
       if(ls<=b)
        {
           round(ls);
           cout << " 0.000 0.000 0.000";
        }
       else
        {
           if(ls-b<=a)
            {
               round(b);
               cout << " ";
               round(ls-b);
               cout << " 0.000 0.000";
            }
           else
            {
               if(ls-b-a<=a)
                {
                   round(b);
                   cout << " ";
                   round(a);
                   cout << " ";
                   round(ls-b-a);
                   cout << " 0.000";
                }
               else
                {
                   if(ls-b<=2*b)
                    {
                       round(b);
                       cout << " ";
                       round((ls-b)/2);
                       cout << " ";
                       round((ls-b)/2);
                       cout << " 0.000";
                    }
                   else
                    {
                        if(ls<=3*c)
                         {
                            round(ls/3);
                            cout << " ";
                            round(ls/3);
                            cout << " ";
                            round(ls/3);
                            cout << " 0.000";
                         }
                        else
                         {
                            if(ls-3*c<=c)
                             {
                                round(c);
                                cout << " ";
                                round(c);
                                cout << " ";
                                round(c);
                                cout << " ";
                                round(ls-3*c);
                             }
                            else
                             {
                                round(ls/4);
                                cout << " ";
                                round(ls/4);
                                cout << " ";
                                round(ls/4);
                                cout << " ";
                                round(ls/4);
                             }
                         }
                    }
                }
            }
        }
    }

   cout << endl;
   return 0;
}
