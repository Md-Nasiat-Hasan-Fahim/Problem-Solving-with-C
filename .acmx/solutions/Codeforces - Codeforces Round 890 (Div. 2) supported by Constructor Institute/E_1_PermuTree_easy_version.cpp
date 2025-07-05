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

vector<int>vis,op,vec;
int n;

void dfs(int x,int cnt)
{
    if(vis[x]) return;
    vis[x]=true;op.pb(x);
    cnt+=vec[x];
    dfs(cnt%n,cnt);
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
        int k;
        cin>>n>>k;
        vec.assign(n+1,0);vis.assign(n+1,0);
        for(int i=0;i<n;i++) cin>>vec[i];
        dfs(0,0);
        int sz = op.size();
        int x = k/sz;
        int y = k%sz;
        int cnt = 0;
        //cout<<x<<" "<<y<<" "<<sz<<endl;
        for(int i=0;i<op.size();i++)
        {
            cnt+=(x+(i<y))*vec[op[i]];
        }
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
