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
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int cnt = 0;
        int tp = (k-2)/2;
        cnt = (tp*(tp+1));
        //cout<<cnt<<endl;
        cnt+=k-1;
        if(k%2==0)cnt+=tp+1;
        int edge = (n*(n-1))/2;
        if(((n<=cnt&&m<=edge&&m>=n-1)||(k-2>0&&m==edge))) YES;
        else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}