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

struct node{
    int tm,a,b;
};

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    //cin>>t;
    for(int z=1;z<=t;z++)
    {
        vector<node>time;
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        vector<int>vec[n+1];queue<int>q;set<int>st;vector<int>tem;
        for(int i=0;i<m;i++)
        {
            int tm,a,b;
            cin>>tm>>a>>b;
            time.pb({tm,a,b});
        }
        sort(all(time),[](node &a, node &b){
            return a.tm<b.tm;
        });
        for(int i=0;i<time.size();i++)
        {
            node x = time[i];
            vec[x.a].pb(x.b);
            vec[x.b].pb(x.a);
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                q.push(i+1);
                st.insert(i+1);
                tem.pb(i+1);
            }
        }
        int cnt = 0;
        int k = INT_MAX;
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            int p = INT_MIN;
            bool ans = true;
            int pos[n+1]={0};
            for(int i=0;i<vec[x].size();i++)
            {
                pos[vec[x][i]]=i+1;
            }
            for(int j=0;j<tem.size();j++)
            {
                if(tem[j]==x) continue;
                if(pos[tem[j]]==0) ans = false;
                else p = max(p,pos[tem[j]]);
            }
            for(int i=0;i<vec[x].size();i++)
            {
                if(pos[vec[x][i]]<p) ans = false;
            }
            if(ans)
            {
                k = min(k,p);
                cnt++;
            }
        }
        cout<<cnt<<" "<<k<<" Infinity\n";
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
