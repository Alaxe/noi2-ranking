#include<iostream>
#include<stack>

using namespace std;
stack<bool> st;
long long s,t,z;
int S_FLAG,T_FLAG,S_FLAG1,T_FLAG1,steps,stept;
long long mat[68][68];


long long dec_to_bin(int n)
{
    int br0=0;
    for(;n!=0;)
    {
        st.push(n%2);
        if(n%2==0)br0++;
        n/=2;
    }
    for(;!st.empty();)
    {
        //cout<<st.top();
        st.pop();
    }
    //cout<<"-"<<br0<<endl;
    return br0;
}

void sol2();
void sol1();

int main()
{
    cin>>s>>t>>z;
    long long check=1;
    for(int i=1;i<=s;i++)
    {
        if(check==s){S_FLAG=i;S_FLAG1=check;steps=i;break;}
        if(check>s){S_FLAG1=check;steps=i;break;}
        check*=2;

    }
    check=1;
    for(int i=1;i<=t;i++)
    {
        if(check==t){T_FLAG=i;T_FLAG1=check;stept=i;break;}
        if(check>t){T_FLAG1=check;stept=i;break;}
        check*=2;
        //cout<<i<<endl;

    }
    if(S_FLAG>0&&T_FLAG>0)
    {
        sol2();
    }
    else sol1();

}
void printmat()
{
    for(int i=1;i<=63;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }


}


void sol1()
{
    long long brz=0;
    //cout<<steps<<" "<<stept<<endl;
    mat[1][0]=1;
    for(int i=2;i<=64;i++)
    {
        mat[i][0]=1;
        for(int j=1;j<i;j++)
        {
            mat[i][j]=mat[i-1][j-1]+mat[i-1][j];
        }
    }
    long long left=T_FLAG1/2;
    long long right=T_FLAG1;
    long long mid=(left+right)/2;
    long long step=1;
    if(T_FLAG==0)
    for(;;)
    {
        //cout<<mid<<endl;
        if(t>mid)
            {
                brz+=mat[stept-step][z-step];
                mid=(mid+right)/2;
                left=mid;
                step-=1;
            }
        if(t<mid)
            {
                mid=(mid+left)/2;
                right=mid;
            }
        if(t==mid)
            {
                brz+=mat[1][z];
                break;
            }
    }
    long long brz1=brz;
    if(dec_to_bin(t)==z)brz+=1;
    //cout<<brz<<endl;
    brz1=brz;
    brz=0;
    left=S_FLAG1/2;
    right=S_FLAG1;
    mid=(left+right)/2;
    step=1;
    //cout<<step<<" "<<steps<<endl;
    if(S_FLAG==0)
    for(;;)
    {
        //out<<mid<<endl;
        if(s>mid)
            {
                brz+=mat[steps-step][z-step];
                 left=mid;
                 mid=(mid+right)/2;

                step++;
            }else
        if(s<mid)
            {
                right=mid;
                mid=(mid+left)/2;

            }else
        if(s==mid)
            {
                brz+=mat[1][z];
                break;
            }
    }
    for(int i=steps-1;i>=1;i--)
    {
        brz-=mat[i][z];
    }brz=-brz;
    if(dec_to_bin(s)==z)brz+=1;

    cout<<brz1-brz<<endl;

}











void sol2()
{
    //cout<<T_FLAG<<" "<<S_FLAG<<endl;
    mat[1][0]=1;
    for(int i=2;i<=T_FLAG;i++)
    {
        mat[i][0]=1;
        for(int j=1;j<i;j++)
        {
            mat[i][j]=mat[i-1][j-1]+mat[i-1][j];
        }
    }
    long long ans=0;
    for(int i=S_FLAG;i<=T_FLAG-1;i++)
    {
        ans+=mat[i][z];
    }
    if(z==T_FLAG-1)ans++;
    cout<<ans<<endl;
}


