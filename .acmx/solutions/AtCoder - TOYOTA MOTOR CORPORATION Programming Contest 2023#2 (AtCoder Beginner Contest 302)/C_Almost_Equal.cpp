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
vector<int>ara = {1,2,3,4,5,6,7,8};
vector<string>st;
vector<int>vec;
int n,m;
bool ans;

void abc(int fg)
{
    if(vec.size()==n)
    {
        int i = 0;
        for(i=0;i<n-1;i++)
        {
            int x = vec[i]-1;
            int y = vec[i+1]-1;
            int diff = 0;
            for(int j=0;j<m;j++)
            {
                if(st[x][j]!=st[y][j]) diff++;
            }
            if(diff!=1) break;
        }
        if(i==n-1) ans = true;
    }
    for(int i=0;i<n;i++)
    {
        if(((1<<i)&fg)==0)
        {
            vec.pb(ara[i]);
            abc(((1<<i)+fg));
            vec.pop_back();
        }
    }
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    //cin>>t;
    for(int z=1;z<=t;z++)
    {
        ans=false;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            st.pb(s);
        }
        abc(0);
        if(ans) cout<<"Yes\n";
        else cout<<"No\n";
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
