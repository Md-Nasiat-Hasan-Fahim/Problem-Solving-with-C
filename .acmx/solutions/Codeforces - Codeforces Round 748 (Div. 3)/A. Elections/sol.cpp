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
        int a,b,c;
        cin>>a>>b>>c;
        int mx = max({a,b,c});
        int pq = (a==b)&&(b==c);
        if(pq) cout<<a+1<<" "<<a+1<<" "<<a+1<<endl;
        else if(a==b||b==c||a==c) cout<<mx+1-a<<" "<<mx+1-b<<" "<<mx+1-c<<endl;
        else cout<<mx+1-a-(a==mx)<<" "<<mx+1-b-(b==mx)<<" "<<mx+1-c-(c==mx)<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
