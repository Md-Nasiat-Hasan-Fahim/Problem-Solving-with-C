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
const int mod = LONG_LONG_MAX;

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
        int n,k;
        cin>>n>>k;
        vector<int>vec(n);
        for(int i=0;i<n;i++) cin>>vec[i];
        k++;
        int cnt = 0;
        int val = 0;
        for(int i=0;i<n-1&&cnt<k;i++)
        {
            int x = POW(10,vec[i]);
            int y = POW(10,vec[i+1]);
            y--;
            int xy = y/x;
            int yz = min(k-cnt,xy);
            //cout<<xy<<" "<<yz<<" "<<x<<" "<<y<<endl;
            cnt+=yz;
            val+=yz*x;
        }
        //cout<<cnt<<" "<<k<<endl;
        val+=max(0LL,k-cnt)*POW(10,vec[n-1]);
        cout<<val<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
