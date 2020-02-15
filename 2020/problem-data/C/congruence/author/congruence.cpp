#include<cstdio>
using namespace std;
char in[15000001],t[26];
int main()
{char m='A';
 int len,cnt=0;
 scanf("%s",in);
 for (int i=0;i<26;i++) t[i]=0;
 for (len=0;in[len];len++) if (!t[in[len]-'A'])
  {t[in[len]-'A']=1;
   cnt++;
   if (cnt==26){printf("%s\n%s\n",in,in);return 0;}
  }
 for (int i=0;i<26;i++) if (t[i]) t[i]=m++;
 for (int i=0;i<len;i++)in[i]=t[in[i]-'A'];
 printf("%s\n",in);
 for (int i=0;in[i];i++) in[i]+=26-cnt;
 printf("%s\n",in);
 return 0;
}
