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

vector<vector<int>>graph;

void bfs(int s, vector<int> &level)
{
    level[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for(auto c:graph[p])
        {
            if(level[c]!=-1) continue;
            level[c]=1+level[p];
            q.push(c);
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
        int n,l,cs;
        cin>>n>>l>>cs;
        graph.assign(n+1,vector<int>(0));
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            graph[a].pb(b);
            graph[b].pb(a);
        }
        vector<int>level1(n+1,-1);
        bfs(1,level1);
        int b;
        int mx = 0;
        for(int i=1;i<=n;i++)
        {
            if(level1[i]>mx)
            {
                b = i;
                mx = level1[i];
            }
        }
        vector<int>level2(n+1,-1);
        bfs(b,level2);
        int c;
        mx = 0;
        for(int i=1;i<=n;i++)
        {
            if(level2[i]>mx)
            {
                c=i;
                mx=level2[i];
            }
        }
        mx = level1[b]*l;
        for(int i=1;i<=n;i++)
        {
            if(graph[i].size()==1)
            {
                mx = max(mx,level2[i]*l-level1[i]*cs);
            }
        }
        cout<<mx<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
