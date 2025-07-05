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
        int x = INT_MAX;
        int n;
        cin>>n;
        vector<int>vec;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            if(a>0) x = min(x,a);
            else vec.pb(a);
        }
        if(x==INT_MAX)
        {
            cout<<n<<endl;
            continue;
        }
        if(vec.size())
        {
            bool ans = true;
            sort(vec.rbegin(),vec.rend());
            for(int i=1;i<vec.size();i++)
            {
                if(x>vec[i-1]-vec[i])
                {
                    ans=false;break;
                }
            }
            if(ans) cout<<vec.size()+1<<endl;
            else cout<<vec.size()<<endl;
        }
        else cout<<"1"<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
