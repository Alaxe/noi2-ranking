 #include<iostream>
 #include<string>
 using namespace std;
 string sbor(string s,string f)
 {
     int i,j,ds,df,k=0,p;
     string q="";
     ds=s.size()-1;
     df=f.size()-1;
     if(df<ds)swap(f,s);
     ds=s.size()-1;
     df=f.size()-1;

     while(ds<df)
     {
         s='0'+s;
         ds++;
     }
     //cout<<s<<endl;
     //cout<<f<<endl;
     for(i=df;i>=0;i--)
     {
         p=(s[i]-'0')+(f[i]-'0')+k;
         p=p%10;
         q=char(p+'0')+q;
         k=((s[i]-'0')+(f[i]-'0')+k)/10;
     }
     if(k>0)q=char(k+'0')+q;
     return q;
 }
 string umn1(string s,int k)
 {
     int ds,i,j=0,p;
     string q="";
     ds=s.size()-1;
     for(i=ds;i>=0;i--)
     {
         p=(s[i]-'0')*k+j;
         p%=10;
         //cout<<j<<endl;
         q=char(p+'0')+q;
         j=(((s[i]-'0')*k)+j)/10;
     }
     if(j>0)q=char(j+'0')+q;
     return q;
 }
 string umn2(string s,string f)
 {
     int i,j,ds=0,df,p,br=0;
     string q="",u="";
     ds=s.size()-1;
     df=f.size()-1;
     if(ds<df)swap(s,f);
     ds=s.size()-1;
     df=f.size()-1;
     for(i=df;i>=0;i--)
     {
         p=f[i]-'0';
         u=umn1(s,p);
         for(j=1;j<=br;j++)
         {
             u=u+'0';
         }
         //cout<<u<<endl;
         q=sbor(q,u);
         br++;
     }
     return q;
 }
 int srv(string s,string f)
 {
     int i,j,ds,df;
     ds=s.size()-1;
     df=f.size()-1;
     if(df<ds)return 1;
     else if(ds<df)return 0;
     else
     {
         for(i=0;i<=ds;i++)
         {
             if(s[i]-'0'>f[i]-'0')return 1;
             else if(s[i]-'0'<f[i]-'0')return 0;
         }
         return -1;
     }
 }
 int main()
 {
    long long n,i=1,j,p,d,br=0;
    string s="",f="",q="",k,l="1";
    cin>>n>>k;
    //q='1'+q;
    s='1'+s;
    for(i=1;i<n;i++)
    {

        s=s+'0';
        //cout<<s<<endl;
    }
   //cout<<s<<endl;
  // cout<<100+'0';
    while(1)
    {
        j=i;
        br=0;
        while(j>0)
        {
            q=char((j%10)+'0')+q;
            br++;
            j/=10;
        }
        //cout<<q<<endl;
        f=umn2(k,q);
        if(srv(s,f)==-1){cout<<f;return 0;}
        else if(srv(s,f)==0){cout<<f;return 0;}
        q.erase(0,br);
        i++;
    }
    return 0;
 }
