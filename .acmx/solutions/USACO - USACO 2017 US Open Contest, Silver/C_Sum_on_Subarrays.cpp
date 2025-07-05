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
        int n,k;
        cin>>n>>k;
        int cnt = 999;
        int c = ((n*(n+1))/2)-k;
        vector<int>vec;
        int a = n;
        for(int i=0;i<n;i++,a--)
        {
            if(c)
            {
                if(a<=c)
                {
                    c-=a;
                    vec.pb(-cnt);
                }
                else
                {
                    for(int j=0;j<a-c;j++)
                    {
                        i++;
                        vec.pb(5);
                    }
                    vec.pb(-4);
                    c=0;
                }
            }
            else vec.pb(1);
        }
        for(auto x:vec)
        cout<<x<<" ";
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
