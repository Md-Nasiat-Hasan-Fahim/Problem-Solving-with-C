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
int n,m;

//{{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}}
//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
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

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    unordered_map<char,int,custom_hash>mp;
    mp['U']=-1;
    mp['R']=1;
    mp['D']=1;
    mp['L']=-1;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int stx,sty,desx,desy;char x,y;
        cin>>n>>m>>stx>>sty>>desx>>desy>>x>>y;
        vector<vector<int>>grid(n+2,vector<int>(m+2,-1));
         vector<vector<int>>vis(n+2,vector<int>(m+2,0));
        int cnt = 0;
        int tx=stx;
        int ty=sty;
        while(1)
        {
            //cout<<stx<<" "<<sty<<endl;
            if(grid[stx][sty]==-1)grid[stx][sty]=cnt;
            vis[stx][sty]++;
            bool ans = false;
            if(stx+mp[x]>n||stx+mp[x]<1)
            {
                if(x=='D') x='U';
                else x = 'D';
                ans = true;
            }
            if((sty+mp[y]>m||sty+mp[y]<1))
            {
                if(y=='R') y = 'L';
                else y = 'R';
                ans = true;
            }
            cnt+=ans;
            stx+=mp[x];
            sty+=mp[y];
            if(vis[tx][ty]==5) break;
        }
        cout<<grid[desx][desy]<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
