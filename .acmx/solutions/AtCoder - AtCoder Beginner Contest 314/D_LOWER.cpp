#include<bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
#define int long long
#define all(x) x.begin(),x.end()
#define pb push_back
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define check(x) cout << (#x) << " is " << (x) << endl;
const int mod = 1e9+7;

vector<int>hi,down;
int up[500005+1];
int lo[500005+1];
int dp[500005+1][2];

bool abc(int i, bool flag)
{
    if(dp[i][flag]!=-1) return dp[i][flag];
    if(flag==true)
    {
        auto x = lower_bound(all(down),i);
        if(x==down.end()) return dp[i][flag]=true;
        return dp[i][flag]=abc(*x,false);
    }
    else
    {
        auto x = lower_bound(all(hi),i);
        if(x==hi.end()) return dp[i][flag]=false;
        return dp[i][flag]=abc(*x,true);
    }
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    //cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        memset(dp,-1,sizeof(dp));
        int n;string s;
        cin>>n>>s;
        n++;s="#"+s;
        int q;
        cin>>q;
        int cup = 0, clow = 0;
        int cnt = 0;
        while(q--)
        {
            int t,x;
            char a;
            cin>>t>>x>>a;
            cnt++;
            if(t==1)
            {
                up[x]=cup;
                lo[x]=clow;
                s[x]=a;
            }
            else if(t==2)
            {
                clow++;
                down.pb(cnt);
            }
            else
            {
                cup++;
                hi.pb(cnt);
            }
        }
        for(int i=1;i<n;i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
            {
                if(lo[i]==0)
                {
                    if(down.size()==0) cout<<s[i];
                    else
                    {
                        if(abc(down[0],true)) cout<<s[i];
                        else cout<<(char)(s[i]-'A'+'a');
                    }
                }
                else
                {
                    if(down.size()<=lo[i]) cout<<s[i];
                    else
                    {
                        if(abc(down[lo[i]],true)) cout<<s[i];
                        else cout<<(char)(s[i]-'A'+'a');
                    }
                }
            }
            else
            {
                if(up[i]==0)
                {
                    if(hi.size()==0) cout<<s[i];
                    else
                    {
                        if(abc(hi[0],false)) cout<<(char)(s[i]-'a'+'A');
                        else cout<<s[i];
                    }
                }
                else
                {
                    if(hi.size()<=up[i]) cout<<s[i];
                    else
                    {
                        if(abc(hi[up[i]],false)) cout<<(char)(s[i]-'a'+'A');
                        else cout<<s[i];
                    }
                }
            }
        }
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
