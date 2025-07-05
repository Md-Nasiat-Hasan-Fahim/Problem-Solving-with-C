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
vector<int>vec;

int abc(int i, int x)
{
    if(i==16) return __builtin_popcountll(x);
    if(x-vec[i]>=0)
    return min({1+abc(i+1,x-vec[i]),abc(i+1,x),(int)__builtin_popcountll(x)});
    return min(abc(i+1,x),(int)__builtin_popcountll(x));
}

//{{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}}
//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    FastIO;
    int t=1;
    cin>>t;
    int cnt = 1;
    for(int i=1;i<16;i++)
    {
        cnt=i*cnt;
        vec.pb(cnt);
    }
    for(int z=1;z<=t;z++)
    {
        int n;
        cin>>n;
        cout<<abc(0,n)<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
