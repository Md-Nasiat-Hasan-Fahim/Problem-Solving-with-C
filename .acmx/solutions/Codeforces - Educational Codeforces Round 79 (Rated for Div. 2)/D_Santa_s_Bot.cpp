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
const int mod = 998244353;

long long POW(long long n, long long r)
{
    if(r==0) return 1;
    long long res = POW(n,r/2);
    res = res*res;
    res%=mod;
    if(res<0) res+=mod;
    if(r%2) res*=n;
    res%=mod;
    if(res<0) res+=mod;
    return res;
}

int mul(int &cnt, int x)
{
    cnt*=x;
    cnt%=mod;
    if(cnt<0) cnt+=mod;
    return cnt;
}

vector<int>vec[1000006];

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    //cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int m;
            cin>>m;
            for(int j=0;j<m;j++)
            {
                int a;
                cin>>a;
                vec[a].pb(m);
            }
        }
        int nn = POW(n*n%mod,mod-2);
        int fin = 0;
        for(int i=1;i<1000006;i++)
        {
            for(int j=0;j<vec[i].size();j++)
            {
                int x = POW(vec[i][j],mod-2);
                int cnt = vec[i].size();
                mul(cnt,x);
                mul(cnt,nn);
                fin+=cnt;
                fin%=mod;
                if(fin<0) fin+=mod;
            }
        }
        cout<<fin<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
