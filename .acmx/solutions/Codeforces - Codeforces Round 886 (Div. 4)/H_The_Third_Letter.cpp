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
const int mod = 1e11+10;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct PairHash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &v) const
    {
        return std::hash<T1>()(v.first) ^ hash<T2>()(v.second) << 1;    
        //return std::hash<T1>{}(v.first) ^ hash<T2>{}(v.second) << 1;    //same as above
    }
};

vector<vector<int>>graph;
vector<int>vis;
unordered_map<int,int,custom_hash>mp,doo;
unordered_map<pair<int,int>,int,PairHash>dis,stat;
int cnt;
bool ans;
int st;

void dfs(int x,int p, int d)
{
    vis[x]=1;
    //cout<<x<<" "<<d<<endl;
    mp[x]=d;
    for(auto c:graph[x])
    {
        if(c==p) continue;
        int y = d + dis[{x,c}];
        if(vis[c])
        {
            //cout<<c<<" "<<mp[c]<<" "<<y<<endl;
            if(vis[c]==st)
            {
                ans |= (mp[c]!=y);
            }
            continue;
        }
        //cout<<x<<" "<<c<<endl;
        dfs(c,x,y);
    }
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n,m;
        cin>>n>>m;
        mp.clear();
        graph.assign(n+1,vector<int>());
        vis.assign(n+1,0LL);
        dis.clear();
        cnt=0;
        ans = false;
        st=0;
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            graph[a].pb(b);
            graph[b].pb(a);
            if(dis.count({min(a,b),max(a,b)})) ans|=(dis[{min(a,b),max(a,b)}]!=c);
            dis[{min(a,b),max(a,b)}]=c;
        }
        //cout<<graph[2].size()<<endl;
        for(int i=1;i<=n;i++)
        {
            cnt+=mod;
            st++;
            if(!vis[i]) dfs(i,i,cnt);
        }
        if(ans) NO;
        else YES;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
