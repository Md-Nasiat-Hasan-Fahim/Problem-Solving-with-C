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
vector<int>prime;
vector<int>add;

void abc(int i, int x,int mark, int n)
{
    if(i==n)
    {
        if((mark^1)==1) add.pb(-x);
        else add.pb(x);
        return;
    }
    abc(i+1,x*prime[i],!mark,n);
    abc(i+1,x,mark,n);
}

int solve(int n)
{
    int cnt = 0;
    for(int i=0;i<add.size();i++)
    {
        if(add[i]<0)
        {
            int x = -add[i];
            cnt+=(n/x);
        }
        else cnt-=(n/add[i]);
    }
    return cnt;
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
        cout<<"Case #"<<z<<": ";
        prime.clear();
        add.clear();
        int a,b,n;
        cin>>a>>b>>n;
        int m = n;
        for(int i=2;i*i<=n;i++)
        {
            if(m==1) break;
            if(m%i==0)
            {
                prime.pb(i);
                while(m%i==0)
                {
                    m/=i;
                }
            }
        }
        if(m>1) prime.pb(m);
        abc(0,1,0,prime.size());
        cout<<solve(b)-solve(a-1)<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
