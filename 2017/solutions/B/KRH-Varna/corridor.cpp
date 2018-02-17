#include<iostream>
#include<vector>
#include<string>
using namespace std;
string addit(string s1, string s2)
{
    string sans="";
    ///and im havin a GOOD time, avin a GOOD TIME AND I DONT WANNA STOP AT ALLLLLL
    bool oneover=0;
    char i,sum;
    if(s1.size()<s2.size()) swap(s1,s2);
    if(s2[0]=='0') return s1;
    for(i=0;i<s2.size();i++)
    {//cout<<"q";
        sum=(s1[s1.size()-i-1]-'0')+(s2[s2.size()-i-1]-'0')+oneover;
        oneover=sum/10;
        sum%=10;
        sans.insert(sans.begin(),sum+'0');
    }
    for(;i<s1.size();i++)
    {//cout<<"w";
        sum=(s1[s1.size()-i-1]-'0')+oneover;
        oneover=sum/10;
        sum%=10;
        sans.insert(sans.begin(),sum+'0');
    }
    if(oneover) {sans.insert(sans.begin(),'1');/*cout<<"e";*/}
    return sans;
}
string mult(string s1, string s2)
{
    string sans="0",stmp;
    ///im-burn-in-through-the-skyyy, yeah, 200 DEGREES ITS WHY THEY CALL ME MR FARENHEEEEEEEEEIT
    char i,y,y_jr,sum,oneover,n;
    if(s1.size()<s2.size()) swap(s1,s2);
    for(y=s2.size()-1;y>=0;y--)
    {//cout<<"t";
        n=s2[y]-'0';
        if(n==0) continue;
        stmp="";
        oneover=0;
        for(i=s1.size()-1;i>=0;i--)
        {//cout<<"y";
            sum=(s1[i]-'0')*n+oneover;
            oneover=sum/10;
            sum%=10;
            stmp.insert(stmp.begin(),sum+'0');
        }
        if(oneover) stmp.insert(stmp.begin(),oneover+'0');
        for(y_jr=y+1;y_jr<s2.size();y_jr++) stmp+="0";
        sans=addit(sans,stmp);
    }
    return sans;
}
struct line
{
    long long x1;
    long long x2;
    long long y1;
    long long y2;
};
int main()
{
    long long w,h,x,y,xprev,yprev,h1,l;
    int n,i;
    cin>>w>>h>>n;
    long long maxy;
    vector<line> v;
    line dummy;
    dummy.x1=0;
    dummy.y1=0;
    dummy.x2=0;
    dummy.y2=0;
    v.push_back(dummy);
    cin>>xprev>>yprev;
    maxy=yprev;
    for(i=1;i<n;i++)
    {
        cin>>x>>y;
        if(y>maxy) {dummy.x1=xprev;dummy.y1=v[v.size()-1].y2;dummy.x2=x;dummy.y2=y;v.push_back(dummy);maxy=y;}
        xprev=x;
        yprev=y;
    }
   /**for(i=0;i<v.size();i++)
   {
       cout<<v[i].x1<<" "<<v[i].y1<<" "<<v[i].x2<<" "<<v[i].y2<<endl;
   }*/
   string sh,sl,area,sans="0";
   ///there's a dead pigeon right outside the window i'm sitting at, it's great
   for(i=1;i<v.size();i++)
   {
      h1=w-v[i].x1;
      l=v[i].y2-v[i].y1;
      //cout<<h1<<" "<<l<<" ";
      sh="";
      sl="";
      while(h1)
      {
          sh.insert(sh.begin(),char('0'+h1%10));
          h1/=10;
      }
      while(l)
      {
          sl.insert(sl.begin(),char('0'+l%10));
          l/=10;
      }
      area=mult(sl,sh);
      //cout<<sh<<" "<<sl<<" "<<area<<"ffff"<<endl;
      sans=addit(sans,area);
   }
   cout<<sans<<endl;
   return 0;
}
