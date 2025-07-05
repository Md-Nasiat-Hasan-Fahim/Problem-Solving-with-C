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

int nc2(int n, int c)
{
    if(n==1) return 1;
    int x = n-c;
    x = ((n*(n+1))-(x*(x+1)))/2;
    return x;
}

signed main()
{
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n,m;
        cin>>n>>m;
        vector<int>cnt(n+m+1,0LL);
        vector<int>mark(n+m+1,-1);
        vector<int>vec(n+1);
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            vec[i+1]=a;
            mark[a]=0;
        }
        for(int i=1;i<=m;i++)
        {
            int p,v;
            cin>>p>>v;
            cnt[vec[p]]+=i-mark[vec[p]];
            mark[vec[p]]=-1;
            mark[v]=i;
            vec[p]=v;
        }
        int ans = 0;
        for(int i=1;i<n+m+1;i++)
        {
            if(mark[i]!=-1)
            cnt[i]+=m-mark[i]+1;
            if(cnt[i])
            ans+=nc2(m,cnt[i]);
        }
        cout<<ans<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
