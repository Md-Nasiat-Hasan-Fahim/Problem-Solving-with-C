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

int abc(int x, vector<int> &vec)
{
    int cnt = 0;
    for(int i=0;i<vec.size();i++)
    {
        int y = sqrtl(1LL*vec[i]+x);
        if(y*y==(1LL*vec[i]+x)) cnt++;
    }
    return cnt;
}


signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int ttt=1;
    cin>>ttt;
    vector<int>vec;
    for(int i=1;i*i<=mod;i++)
    {
        vec.pb(i*i);
    }
    for(int z=1;z<=ttt;z++)
    {
        int n;
        cin>>n;
        vector<int>in(n);
        for(int i=0;i<n;i++) cin>>in[i];
        int cnt =max(1,abc(0,in));
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int x = abs(in[i]-in[j]);
                int y = -1;
                for(int k=0;k<vec.size();k++)
                {
                    auto it = lower_bound(all(vec),vec[k]+x);
                    if(*it==1LL*vec[k]+x)
                    {
                        y = vec[k];
                    }
                }
                if(y!=-1) cnt = max(cnt,abc(labs(y-min(in[i],in[j])),in));
            }
        }
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
