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

int chk(int n, int m)
{
    if(n==0||m==0) return 0;
    if((n==1&&m==2)||(n==2&&m==1)||(n==3&&m==1)||(n==1&&m==3)) return 1;
    if(n==1&&m==1) return 1;
    int cnt = INT_MAX;
    if(m>1) cnt=min(chk(n,m%2)+(m/2)*n,cnt);
    if(n>1) cnt=min(cnt,chk(n%2,m)+(n/2)*m);
    if(m>2) cnt =min(chk(n,m%3)+(m/3)*n,cnt);
    if(n>2) cnt=min(cnt,chk(n%3,m)+(n/3)*m);
    return cnt;
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
        int n,m;
        cin>>n>>m;
        cout<<chk(n,m)<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
