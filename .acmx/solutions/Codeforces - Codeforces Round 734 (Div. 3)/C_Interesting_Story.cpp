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
        vector<string>vec;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            vec.pb(s);
        }
        int mx = 0;
        for(char c = 'a';c<='e';c++)
        {
            int tmx = 0;
            vector<int>pr;
            for(int i=0;i<n;i++)
            {
                int x = 0;
                for(int j=0;j<vec[i].size();j++)
                {
                    if(vec[i][j]==c) x++;
                }
                int y = vec[i].size()-x;
                pr.pb(x-y);
            }
            sort(all(pr));
            reverse(all(pr));
            int cnt = pr[0];
            if(cnt>0) tmx++;
            int i = 1;
            while(cnt+pr[i]>0&&i<n)
            {
                //cout<<i<<" "<<pr[i]<<" "<<cnt<<endl;
                cnt+=pr[i];
                i++;
                tmx++;
            }
            mx = max(tmx,mx);
        }
        cout<<mx<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
