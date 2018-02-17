#include <bits/stdc++.h>
using namespace std;
struct point
{
    long long a,b;
};
point ch[10000];
bool cmp (point s , point e)
{
    if (s.a>e.a)return s.a<e.a;
    else return e.a>s.a;

}
int main()
{
   long long j,i=0,c,d,sum=0,br=0;
   while (1)
   {
      cin>>ch[i].a>>ch[i].b;
      if (cin.eof())break;
      i++;

   }
   sort (ch,ch+i,cmp);
   for (j=0;j<i-2;j++)
   {
       if (ch[j].a+ch[j].b>ch[j+1].a && br==0){sum+=ch[j].a+ch[j].b;br++;}
       if (ch[j].a+ch[j].b>ch[j+1].a && br!=0){sum+=ch[j+1].b;br++;}
   }
   if (ch[j].a+ch[j].b>ch[j+1].a)sum+=ch[j+1].b-ch[j+1].a;
   else sum=ch[j+1].b;
   cout<<sum<<endl;
}

