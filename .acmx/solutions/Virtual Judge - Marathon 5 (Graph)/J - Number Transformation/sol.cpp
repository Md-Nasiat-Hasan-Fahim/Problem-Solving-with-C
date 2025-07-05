#include<bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
// #define int long long
#define all(x) x.begin(),x.end()
#define pb push_back
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define check(x) cout << (#x) << " is " << (x) << endl;
const int mod = 1e9+7;

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n,q;
        cin>>n>>q;
        vector<int>vec(n);
        for(int i=0;i<n;i++) cin>>vec[i];
        cout<<"Case "<<tttttttt<<":\n";
        while(q--)
        {
            int x;char c;
            cin>>c>>x;
            if(c=='c')
            {
                if(x-1<vec.size()) cout<<vec[x-1]<<endl,vec.erase(vec.begin()+(x-1));
                else cout<<"none\n";
            }
            else
            {
                vec.pb(x);
            }
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
