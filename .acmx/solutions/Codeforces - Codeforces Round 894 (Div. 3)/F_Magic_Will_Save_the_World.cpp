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

int n;
int f,s;
int sum;
vector<int>vec;
int dp[4000000];

bool abc(int x)
{
    int cf = x*f;
    int cs = x*s;
    int mn = min(cf,cs);
    int mx = max(cs,cf);
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        for(int j=mn+1;j>-1;j--)
        {
            if(i==0)
            {
                if(j-vec[i]>-1) dp[j]=vec[0];
            }
            else
            {
                if(j-vec[i]>-1) dp[j]=max(vec[i]+dp[j-vec[i]],dp[j]);
            }
        }
    }
    return sum-dp[mn]<=mx;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        cin>>f>>s;
        cin>>n;
        vec.clear();
        sum=0;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            sum+=a;
            vec.pb(a);
        }
        int lo=1,hi=1000000/min(f,s);
        cout<<lo<<" "<<hi<<endl;
        while(hi-lo>1)
        {
            int mid = (hi+lo)/2;
            if(abc(mid)) hi = mid;
            else lo = mid+1;
        }
        if(abc(lo)) cout<<lo<<endl;
        else cout<<hi<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}