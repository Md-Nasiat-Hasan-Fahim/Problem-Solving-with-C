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

int cnt;

int mp[11][11];
vector<vector<int>>vec;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
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

unordered_map<vector<vector<int>>,bool,custom_hash> ump;

int n,t,m;

void abc(int x)
{
    if(ump[vec]) return;
    if(x==n+1)
    {
        bool ans = true;
        for(int i=1;i<=t;i++) ans = (vec[i].size()!=0);
        cnt+=ans;
        ump[vec]=true;
        return;
    }
    for(int i=1;i<=t;i++)
    {
        bool ans = true;
        for(int j=0;j<vec[i].size();j++)
        {
            if(mp[x][vec[i][j]])
            {
                ans = false;
            }
        }
        if(ans)
        {
            vec[i].pb(x);
            abc(x+1);
            vec[i].pop_back();
        }
    }
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
        cin>>n>>t>>m;
        vec.assign(t+1,vector<int>());
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            mp[a][b]=mp[b][a]=1;
        }
        abc(1);
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
// if(ans)
//         {
//             cout<<"------------"<<endl;
//             for(int i=1;i<=t;i++)
//             {
//                 for(int j=0;j<vec[i].size();j++)
//                 {
//                     cout<<vec[i][j]<<" ";
//                 }
//                 cout<<endl;
//             }
//         }