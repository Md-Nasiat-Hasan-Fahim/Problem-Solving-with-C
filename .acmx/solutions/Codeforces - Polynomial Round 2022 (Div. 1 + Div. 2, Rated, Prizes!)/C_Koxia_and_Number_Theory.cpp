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

//{{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}}
//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

bool equal(vector<int>&ara)
{
    for(int i=0;i<4;i++)
    {
        for(int j=i+1;j<4;j++)
        {
            if(ara[i]==ara[j]) return true;
        }
    }
    return false;
}

bool gc(vector<int>&ara, int x)

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=100;
    //cin>>t;
    for(int z=1;z<=t;z++)
    {
        mt19937 rand(chrono::steady_clock::now().time_since_epoch().count());
        vector<int>ara(4);
        int o = 0, e = 0;
        for(int i=0;i<4;i++)
        {
            ara[i]=rand()%500;
            if(ara[i]%2==0) e++;
            else o++;
        }
        bool ans = true;
        if(equal(ara)||o==2&&e==2) ans = false;
        else
        {
            for(int i=1;i<1e4;i++)
            {
                
            }
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
