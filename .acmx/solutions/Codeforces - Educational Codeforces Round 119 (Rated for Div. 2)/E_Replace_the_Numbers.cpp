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

int par[500005];

int dsu(int r)
{
    if(par[r]==r) return r;
    return par[r] = dsu(par[r]);
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
        for(int i=0;i<500005;i++) par[i]=i;
        int q;
        cin>>q;
        vector<int>vec(500005,-1),val(500005,-1);
        vector<int>ans;
        int j = 0;
        while(q--)
        {
            int a;
            cin>>a;
            if(a==1)
            {
                int b;
                cin>>b;
                if(vec[b]==-1)
                {
                    vec[b]=j;
                    par[j]=dsu(j);
                    val[j]=b;
                    ans.pb(j);
                    j++;
                }
                else
                {
                    ans.pb(vec[b]);
                    par[j]=dsu(vec[b]);
                    j++;
                }
            }
            else
            {
                int x,y;
                cin>>x>>y;
                if(vec[x]!=-1&&x!=y)
                {
                    if(vec[y]==-1)
                    {
                        vec[y]=vec[x];
                        vec[x]=-1;
                        par[vec[y]]=dsu(vec[y]);
                        val[vec[y]]=y;
                    }
                    else
                    {
                        par[vec[x]]=dsu(vec[y]);
                        vec[x]=-1;
                    }
                }
            }
        }
        for(int i=0;i<ans.size();i++)
        {
            int p = dsu(par[i]);
            cout<<val[p]<<" ";
        }
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
