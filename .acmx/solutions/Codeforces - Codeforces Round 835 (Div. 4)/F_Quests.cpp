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

int n,c,d;
vector<int>vec;

bool abc(int x)
{
    int cnt = 0;
    for(int i=0;i<min(n,x+1);i++)
    {
        cnt+=vec[i]+(vec[i]*((d-1-i)/(x+1)));
    }
    return cnt>=c;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        cin>>n>>c>>d;
        vec.resize(n);
        for(int i=0;i<n;i++) cin>>vec[i];
        sort(all(vec));
        reverse(all(vec));
        if((abc(0)==false))
        {
            cout<<"Impossible\n";
            continue;
        }
        int lo = 0, hi = 1;
        int j = 0;
        while(abc(hi)&&j++<62) hi*=2;
        if(j==63){
            cout<<"Infinity\n";
            continue;
        }
        while(hi-lo>1)
        {
            int mid = (hi+lo)/2;
            if(abc(mid)) lo = mid;
            else hi = mid-1;
        }
        if(abc(hi)) cout<<hi<<endl;
        else cout<<lo<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
