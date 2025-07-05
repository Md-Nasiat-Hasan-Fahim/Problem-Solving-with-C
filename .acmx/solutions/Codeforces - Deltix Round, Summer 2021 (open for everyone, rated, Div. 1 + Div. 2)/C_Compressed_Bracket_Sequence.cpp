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

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    //cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n;
        cin>>n;
        vector<int>vec(n+1);
        for(int i=1;i<=n;i++) cin>>vec[i];
        int cnt = 0;
        int dp[n+1]={0};
        int total[n+1]={0};
        for(int i=2;i<=n;i+=2)
        {
            int op = vec[i];
            int tf = 0;
            int ts = 0;
            for(int j=i;j>0;j--)
            {
                if(j%2==0)
                {
                    ts+=vec[j];
                    continue;
                }
                tf+=vec[j];
                int mx = min(tf-ts+op,op);
                mx = max(0LL,mx);
                op-=mx;
                dp[i]+=mx;
                if(mx&&ts>=tf) dp[i]+=total[j-1];
                //cout<<i<<" "<<j<<" "<<mx<<endl;
                if(op==0)
                {
                    total[i]+=1;
                    if(tf==ts) total[i]+=total[j-1];
                }
                if(tf>ts||!op) break;
            }
            cnt+=dp[i];
            //cout<<"// "<<i<<" "<<cnt<<endl;
        }
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
