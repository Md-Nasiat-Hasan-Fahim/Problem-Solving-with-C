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
int cnt[300004];
signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int i=1;i<300004;i++)
    {
        cnt[i]=(i^cnt[i-1]);
    }
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n,r;
        cin>>n>>r;
        //cout<<cnt[n-1]<<" "<<cnt[1]<<endl;
        if(cnt[n-1]==r)
        {
            cout<<n<<endl;
        }
        else if((cnt[n-1]^r)==n)
        {
            cout<<n+2<<endl;
        }
        else cout<<n+1<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
