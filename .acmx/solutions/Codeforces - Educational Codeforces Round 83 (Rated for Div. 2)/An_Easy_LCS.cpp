#include<bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
//#define int long long
#define all(x) x.begin(),x.end()
#define pb push_back
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define check(x) cout << (#x) << " is " << (x) << endl;
const int mod = 1e9+7;

vector<vector<int>>dp;
string dp1[105][105];
string a,b;
vector<bool>vis;
int mx;


string abc(int i, int j)
{
    if(i==0||j==0)
    {
        return "";
    }
    if(dp1[i][j]!="-1") return dp1[i][j];
    if(a[i]==b[j])
    {
        string s1 = abc(i-1,j-1)+a[i];
        //cout<<s1<<endl;
        return dp1[i][j]=s1;
    }
    else
    {
        if(dp[i-1][j]>dp[i][j-1])
        return abc(i-1,j);
        else if(dp[i-1][j]<dp[i][j-1])
        return abc(i,j-1);
        else
        {
            string s1 = abc(i-1,j);
            string s2 = abc(i,j-1);
            if(s1>s2) return dp1[i][j] = s2;
            else return dp1[i][j]=s1;
        }
    }
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        cout<<"Case "<<z<<": ";
        cin>>a>>b;
        a="#"+a;
        b="#"+b;
        vis.assign(a.size()+2,false);
        dp.assign(a.size()+2,vector<int>(b.size()+2));
        for(int i=0;i<105;i++)
        {
            for(int j=0;j<105;j++)
            dp1[i][j]="-1";
        }
        for(int i=1;i<a.size();i++)
        {
            for(int j=1;j<b.size();j++)
            {
                if(a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
                else 
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        string st = abc(a.size()-1,b.size()-1);
        //reverse(all(st));
        //cout<<st.size()<<endl;
        if(st.size()) cout<<st<<endl;
        else cout<<":("<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
