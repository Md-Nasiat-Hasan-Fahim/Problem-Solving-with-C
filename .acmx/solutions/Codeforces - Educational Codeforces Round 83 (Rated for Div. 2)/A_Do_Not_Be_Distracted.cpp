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
        string s;
        cin>>s;
        vector<int>vec[28];
        for(int i=0;i<s.size();i++)
        {
            vec[s[i]-'A'].pb(i);
        }
        bool ans = true;
        for(int i=0;i<28;i++)
        {
            if(vec[i].size()>1)
            for(int j=1;j<vec[i].size();j++)
            {
                if(vec[i][j]-vec[i][j-1]>1)
                {
                    ans=false;
                }
            }
        }
        if(ans) YES;
        else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
