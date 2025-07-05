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

int n,m;
vector<vector<int>>vec;

bool abc(int l)
{
    vector<vector<int>>cum(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(vec[i][j]>=l) cum[i][j]++;
            cum[i][j]+=cum[i-1][j]+cum[i][j-1]-cum[i-1][j-1];
            if(i-l>=0&&j-l>=0)
            {
                int x = cum[i][j]-cum[i-l][j]-cum[i][j-l]+cum[i-l][j-l];
                if(x==l*l) return true;
            }
        }
    }
    return false;
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
        cin>>n>>m;
        vec.assign(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++) cin>>vec[i][j];
        }
        int lo = 1, hi = 1;
        while(abc(hi)) hi *=2;
        while(hi-lo>1)
        {
            int mid = (hi+lo)/2;
            if(abc(mid)) lo = mid;
            else hi = mid-1;
        }
        if(abc(hi)) cout<<hi<<endl;
        else cout<<lo<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
