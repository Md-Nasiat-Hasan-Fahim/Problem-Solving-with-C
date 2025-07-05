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

void dij(int s,int b, vector<vector<pair<int,int>>> &vec, vector<int> &dis)
{
    dis[s]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
    vector<int>vis(dis.size());
    pq.push({0,s});
    if(s==b) return;
    while(!pq.empty())
    {
        auto [fw,fa] = pq.top();
        vis[fa]=1;
        if(fa==b) return;
        pq.pop();
        for(auto [ca,cw]:vec[fa])
        {
            if(!vis[ca]&&dis[ca]>fw+cw)
            {
                dis[ca] = fw+cw;
                pq.push({dis[ca],ca});
            }
        }
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
        unordered_map<string,int>mp;
        int n;
        cin>>n;
        vector<vector<pair<int,int>>> vec(n+1,vector<pair<int,int>>());
        for(int i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            mp[s]=i;
            int m;
            cin>>m;
            for(int j=0;j<m;j++)
            {
                int b,w;
                cin>>b>>w;
                vec[i].pb({b,w});
            }
        }
        int q;
        cin>>q;
        vector<int>dis;
        while(q--)
        {
            string s1,s2;
            cin>>s1>>s2;
            int a = mp[s1];
            int b = mp[s2];
            dis.assign(n+1,200005);
            dij(a,b,vec,dis);
            cout<<dis[b]<<endl;
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
