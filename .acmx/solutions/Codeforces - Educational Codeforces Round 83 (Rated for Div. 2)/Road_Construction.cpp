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
int par[60];

int find_par(int x)
{
    if(par[x]==x) return x;
    return par[x]=find_par(par[x]);
}

struct node
{
    int w;
    int a;
    int b;
};

//{{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}}
//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        cout<<"Case "<<z<<": ";
        for(int i=0;i<60;i++) par[i]=i;
        map<string,int>mp;
        int m;
        cin>>m;
        vector<node>vec;
        int mark = 1;
        for(int i=0;i<m;i++)
        {
            string s1,s2;
            int w;
            cin>>s1>>s2>>w;
            if(!mp[s1]) {mp[s1] = mark++;}
            if(!mp[s2]) {mp[s2] = mark++;}
            vec.pb({w,mp[s1],mp[s2]});
        }
        sort(all(vec),[](node a, node b)
        {
            return a.w<b.w;
        });
        int cnt = 0;
        int cost = 0;
        for(int i=0;i<vec.size();i++)
        {
            int u = vec[i].a;
            int v = vec[i].b;
            int w = vec[i].w;
            if(find_par(u)!=find_par(v))
            {
                //cout<<u<<" "<<v<<" "<<par[u]<<" "<<par[v]<<endl;
                cnt++;
                par[find_par(u)]=par[v];
                cost+=w;
            }
        }
        //cout<<cnt<<" "<<mark<<" "<<cost<<endl;
        if(cnt==mark-2) cout<<cost<<endl;
        else cout<<"Impossible\n";
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}