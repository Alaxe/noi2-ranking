#include<iostream>
#include<string>
using namespace std;
string sb,se,sda;
string sl,sr,sm;
string ans2,ans1;
string plusy(string edno,string dve){
    int sz1,sz2,i;
    sz1=edno.size();
    sz2=dve.size();
    if(sz1<sz2){
        for(i=0;i<sz1;i++){
//            cout<<dve[i]+0<<' '<<edno[i]+0<<' ';
            dve[i]+=edno[i];
//            cout<<dve[i]+0<<' '<<' ';
            while(dve[i]>=10){
                dve[i+1]++;
                dve[i]-=10;
            }
//            cout<<dve[i]+0<<endl;
        }
        return dve;
    }
    else if(sz1>sz2){
        for(i=0;i<sz2;i++){
            edno[i]+=dve[i];
            while(edno[i]>=10){
                edno[i+1]++;
                edno[i]-=10;
            }
        }
        return edno;
    }
    else if(sz1==sz2){
        for(i=0;i<sz1-1;i++){
            edno[i]+=dve[i];
            while(edno[i]>=10){
                edno[i+1]++;
                edno[i]-=10;
            }
        }
        edno[sz1-1]+=dve[sz1-1];
        if(edno[sz1-1]>10){
            edno+='0';edno[sz1]-=48;
            edno[sz1]++;
            edno[sz1-1]-=10;
        }
        return edno;
    }
}
string multy(string s1,string s2){
    string s3=s1;
    int sz1,sz2,sz3;
    sz2=s2.size();sz3=s3.size();sz1=sz2+sz3;
    s1="";
    while(s1.size()<sz1){s1+='0';s1[s1.size()-1]-=48;}
    int i,j,k;
    for(k=0;k<sz2;k++){
        for(j=0;j<sz3;j++){
            s1[k+j]+=s2[k]*s3[j];
            if(s1[k+j]>10){
                s1[k+j+1]+=s1[k+j]/10;
                s1[k+j]%=10;
            }
        }
    }
    for(i=0;i<sz1;i++){
        if(s1[i]>=10){
            s1[i+1]+=s1[i]/10;
            s1[i]%=10;
        }
    }
    return s1;
}
string divy(string s){
    int i,sz=s.size();
    for(i=sz-1;i>=0;i--){
        if(i>0)s[i-1]+=10*(s[i]%2);
        s[i]/=2;
    }
    return s;
};
bool l=false;
string minusy(string s,string s1){
    int i,sz=s.size();
    for(i=0;i<sz;i++){
        s1[i]+=10;
        s1[i]-=s[i];
        if(i==s1.size()-1&&s1[i]<10){
            l=true;
            return s1;
        }
        if(s1[i]<10)s1[i+1]--;
        s1[i]%=10;
    }
    return s1;
}
bool check(string edno,string dve){
    edno=minusy(edno,dve);
    int i,sz=edno.size();
    for(i=1;i<sz;i++){
        if(edno[i]>0)return true;
    }
    if(edno[0]>1)return true;
    return false;
}
string bs(string left,string right,string target){
    string mid,kvadrat;
//    for(int i=0;i<mid.size();i++)cout<<mid[i]+0;
//        cout<<"    ";
    while(check(left,right)){
        l=false;
        mid=plusy(left,right);
        mid=divy(mid);
//        for(int i=0;i<left.size();i++)cout<<left[i]+0;
//        cout<<"    ";
//        for(int i=0;i<mid.size();i++)cout<<mid[i]+0;
//        cout<<"    ";
//        for(int i=0;i<right.size();i++)cout<<right[i]+0;
//        cout<<endl;
        kvadrat=plusy(mid,multy(mid,mid));
        kvadrat=minusy(kvadrat,target);
        if(l==true)right=mid;
        else left=mid;
    }
    return left;
}
int main()
{
    int i,sz;
    cin>>sb>>se;
    sz=sb.size();
    for(i=0;i<sz;i++)
        sb[i]-='0';
    for(i=0;i<sz/2;i++)
        swap(sb[i],sb[sz-1-i]);
    sz=se.size();
    for(i=0;i<sz;i++)
        se[i]-='0';
    for(i=0;i<sz/2;i++)
        swap(se[i],se[sz-i-1]);
    sz=sb.size()/2;
    for(i=0;i<sz;i++){
        sl+='0';
        sl[i]-=48;
        sr+='9';
        sr[i]-=48;
    }
    if(sz==0)sl+='0';
    sl[sl.size()-1]=1;
    sr+='9';
    sr[sr.size()-1]-='0';
//    sb=plusy(sb,se);
//    for(i=0;i<sb.size();i++)
//        cout<<sb[i]+0;
//    cout<<endl;
    if(sz==0){
        ans1+='0';ans1[0]-=48;
        if(sb[0]>=2)ans1[0]++;
        if(sb[0]>=6)ans1[0]++;
    }
    else
    ans1=bs(sl,sr,sb);
//    for(i=0;i<ans1.size();i++)cout<<ans1[i]+0;
//    cout<<endl;
    
    ///preobrazuvane na sl i sr
    sl="";sr="";
    sz=sb.size()/2;
    for(i=0;i<sz;i++){
        sl+='0';
        sl[i]-=48;
        sr+='9';
        sr[i]-=48;
    }
    if(sz==0)sl+='0';
    sl[sl.size()-1]=1;
    sr+='9';
    sr[sr.size()-1]-='0';
    if(sz==0){
        ans2+='0';ans2[0]-=48;
        if(se[0]>=2)ans2[0]++;
        if(se[0]>=6)ans2[0]++;
    }
    else
    ans2=bs(sl,sr,se);
    if(sb.size()>1||sb[0]>=2)ans1[0]--; 
//    cout<<ans1[0]+0<<' '<<ans2[0]+0<<endl;
    ans2=minusy(ans1,ans2);
    sz=ans2.size();
    for(i=ans2.size();i>=0;i--){
        if(ans2[i]==0)
        sz--;
        else break;
    }
    for(i=sz;i>=0;i--)cout<<ans2[i]+0;
    cout<<endl;
    return 0;
}
/**
4000 9999
**/