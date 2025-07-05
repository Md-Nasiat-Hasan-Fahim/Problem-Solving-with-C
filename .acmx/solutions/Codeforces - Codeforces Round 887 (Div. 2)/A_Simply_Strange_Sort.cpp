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
    int ttt=1;
    cin>>ttt;
    for(int z=1;z<=ttt;z++)
    {
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++) cin>>vec[i];
        int cnt = 0;
        while(1)
        {
            bool fg = false;
            for(int i=0;i<n-1;i++)
            {
                if(vec[i]>vec[i+1]) fg = true;
            }
            if(!fg) break;
            cnt++;
            if(cnt%2)
            {
                for(int i=0;i<n-1;i+=2)
                {
                    if(vec[i]>vec[i+1])swap(vec[i],vec[i+1]);
                }
            }
            else
            {
                for(int i=1;i<n-1;i+=2)
                {
                    if(vec[i]>vec[i+1]) swap(vec[i],vec[i+1]);
                }
            }
        }
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
