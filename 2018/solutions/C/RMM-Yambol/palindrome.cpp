# include <iostream>
# include <cstdio>
using namespace std;
string s;
int main()
{
cin>>s;

int i;
/*for(i=0;i<1300;i++)
    s+='9';

cout<<l<<endl;*/
int l=s.size();
for(i=0;i<l;i++)
    if(s[i]!='9')break;

if(i==l)
{
    s[0]='1';
    for(i=1;i<=l;i++)
        s[i]='0';
        l++;
}
else
{
    i=l-1;
    int c;
    s[i]=s[i]+1;

    while(i>=0&&c>0)
    {
         if(s[i]-'0'>9){s[i]='0';c=1;}
         else
            c=0;
         i--;
    }
}

/*cout<<"&&"<<endl;
for(i=0;i<l;i++)
    cout<<s[i];
cout<<endl;
cout<<"%%"<<endl;*/
if(l%2==0)
{
    int x,y;
    int a=0,b;
    x=l/2-1;
    y=l/2;
    while(y<l)
    {
        if(s[y]-'0'<s[x]-'0'){a=1;b=y;break;}
        if(s[y]-'0'==s[x]-'0'){y++;x--;continue;}
        a=2;break;
    }
    if(a==1)
    {
      //  cout<<b<<" "<<l<<endl;
        for(i=0;i<l/2;i++)
            cout<<s[i];

        for(i=l/2;i<b;i++)
            cout<<s[i];
          //    cout<<"**"<<endl;
        for(i=l-b-1;i>=0;i--)
            cout<<s[i];
            cout<<endl;
        return 0;
    }//cout<<l<<endl;
    if(a==0)
    {
        for(i=0;i<l;i++)
            cout<<s[i];
        cout<<endl;
        return 0;
    }
    if(a==2)
    {
        x=l/2-1;
        y=l/2;
        while(y<l)
        {
            if(s[x]-'0'<=s[y]-'0'){if(s[x]-'0'==s[y]-'0')s[y]=s[x]+1;b=x;break;}
            y++;
            x--;
        }
         s[b]=s[l-b-1];
        for(i=0;i<l/2;i++)
            cout<<s[i];
           // cout<<"%%"<<endl;
        x=l/2-1;
        while(x>=0)
        {cout<<s[x];x--;}
        cout<<endl;
        return 0;
    }
}
else
{
     int x,y;
    int a=0,b;
    x=l/2-1;
    y=l/2+1;
    while(y<l)
    {
        if(s[y]-'0'<s[x]-'0'){a=1;b=y;break;}
        if(s[y]-'0'==s[x]-'0'){y++;x--;continue;}
        a=2;break;
    }
   // cout<<a<<endl;
    if(a==1)
    {
      //  cout<<b<<" "<<l<<endl;
        for(i=0;i<=l/2;i++)
            cout<<s[i];

        for(i=l/2+1;i<b;i++)
            cout<<s[i];
          //    cout<<"**"<<endl;
        for(i=l-b-1;i>=0;i--)
            cout<<s[i];
            cout<<endl;
        return 0;
    }

     if(a==0)
    {
        for(i=0;i<l;i++)
            cout<<s[i];
        cout<<endl;
        return 0;
    }
     if(a==2&&s[l/2]!='9')
    {

        s[l/2]=s[l/2]+1;
        for(i=0;i<=l/2;i++)
            cout<<s[i];
        for(i=l/2-1;i>=0;i--)
            cout<<s[i];
            cout<<endl;
        return 0;
    }
    if(a==2)
    {

        x=l/2-1;
        y=l/2+1;
        while(y<l)
        {
            if(s[x]-'0'<s[y]-'0'){b=x;break;}
            y++;
            x--;
        }
        //67cout<<b<<endl;
        s[b]=s[l-b-1];
        for(i=0;i<=l/2;i++)
            cout<<s[i];

           // cout<<"%%"<<endl;
        x=l/2-1;
        while(x>=0)
        {cout<<s[x];x--;}
        cout<<endl;
        return 0;
    }
}

}
