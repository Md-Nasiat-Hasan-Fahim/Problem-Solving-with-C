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

const int mx = 200000+5;
vector<int>graph[mx];
bool ans;
set<pair<int,int>>st;

void reset(int n)
{
    for(int i=0;i<n+2;i++)
    {
        graph[i].clear();
    }
    ans=true;
    st.clear();
}

int dfs(int x, int f)
{
    if(!ans) return -1;
    int ct = 0;
    for(auto c:graph[x])
    {
        if(c==f) continue;
        int y = dfs(c,x);
        ct+=y;
    }
    if(ct<2) return ct+1;
    if(ct!=2)
    {
        ans = false;
        return -1;
    }
    if(x!=f)
    st.insert({min(x,f),max(x,f)});
    return 0;
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
        int n;
        cin>>n;
        reset(n);
        queue<pair<int,int>>q;
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            graph[a].pb(b);
            graph[b].pb(a);
            q.push({min(a,b),max(a,b)});
        }
        int cnt = dfs(1,1);
        if(cnt!=0) ans = false;
        if(ans)
        {
            cout<<st.size()<<endl;
            int i=0;
            while(!st.empty()&&!q.empty())
            {
                i++;
                auto it = st.find(q.front());
                if(it!=st.end())
                {
                    cout<<i<<" ";
                    st.erase(it);
                }
                q.pop();
            }
            cout<<endl;
        }
        else
        {
            cout<<"-1\n";
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
