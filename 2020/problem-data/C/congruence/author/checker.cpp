#include <cstdio>
#include <cstring>
using namespace std;
char in[15000001],t[26];
char sol[15000001];
int len,cnt=0,r1=0,r2=0;

void makeFirst()
{char m='A';
 for (int i=0;i<26;i++) t[i]=0;
 for (len=0;in[len];len++) if (!t[in[len]-'A'])
  {t[in[len]-'A']=1;
   cnt++;
   if (cnt==26)return;
  }
 for (int i=0;i<26;i++) if (t[i]) t[i]=m++;
 for (int i=0;i<len;i++) in[i]=t[in[i]-'A'];
}
void makeLast()
{for (int i=0;in[i];i++) in[i]+=(26-cnt);
}
int main(int c,char **s)
{FILE *f;
 {f=fopen(s[1],"r");//in-file
  if (!f){printf("???\n");fprintf(stderr,"In-file %s not found\n",s[1]);return 0;}
  fscanf(f,"%s",in);
  fclose(f);
 }
 {f=fopen(s[3],"r");//solution
  if (!f){printf("0\n");fprintf(stderr,"Solution not found\n");return 0;}
  makeFirst();
  fscanf(f,"%s",sol);
  if (!strcmp(in,sol)) r1=1;
  makeLast();
  fscanf(f,"%s",sol);
  if (!strcmp(in,sol)) r2=1;
  fclose(f);
 }
 printf("%0.1f\n",(r1+r2)/2.0);
 switch(r1+(r2<<1))
 {case 0:fprintf(stderr,"Incorrect answer\n");break;
  case 1:fprintf(stderr,"Incorrect second word\n");break;
  case 2:fprintf(stderr,"Incorrect first word\n");break;
  case 3:fprintf(stderr,"Correct\n");break;
 }
 return 0;
}
