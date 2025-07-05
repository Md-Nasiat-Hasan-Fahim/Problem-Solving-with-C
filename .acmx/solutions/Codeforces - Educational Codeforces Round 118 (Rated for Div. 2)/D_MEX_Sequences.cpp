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
const int mod = 998244353;

long long POW(long long n, long long r)
{
    if(r==0) return 1;
    long long res = POW(n,r/2);
    res = res*res;
    res%=mod;
    if(res<0) res+=mod;
    if(r%2) res*=n;
    res%=mod;
    if(res<0) res+=mod;
    return res;
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
        int n;
        cin>>n;
        vector<int>ct(500005,0);
        int cnt = 0;
        ct[0]=1;
        ct[1]=0;
        int zero = 0, one = 0;
        int cpt = 1;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            if(a==0)
            {
                zero++;
                ct[a]*=2;
                ct[a]%=mod;
            }
            else if(a==1)
            {
                one++;
                ct[a] = (ct[a] + ct[a])%mod;
                int xp = (ct[a-1] - 1)%mod;
                if(xp<0) xp+=mod;
                ct[a] = (ct[a] + xp)%mod;
                cnt+=ct[a];
                cnt%=mod;
            }
            else if(a==2)
            {
                ct[a] = (ct[a] + ct[a])%mod;
                ct[a] = (ct[a] + ct[a-1])%mod;
                ct[a] = (ct[a] + ct[a-2]-1)%mod;
                cnt+=ct[a];
                cnt%=mod;
            }
            else
            {
                ct[a] = (ct[a] + ct[a])%mod;
                ct[a] = (ct[a] + ct[a-1])%mod;
                ct[a] = (ct[a] + ct[a-2])%mod;
                cnt+=ct[a];
                cnt%=mod;
            }
            cout<<cnt<<endl;
        }
        //cout<<cnt<<endl;
        cnt+=POW(2,one)-1;
        cnt%=mod;
        cnt+=POW(2,zero)-1;
        cnt%=mod;
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
