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
        int n,a,b;
        cin>>n>>a>>b;
        vector<int>vec;
        int ara[n+1]={0};
        ara[a]=1;
        vec.pb(a);
        int m = (n/2)-1;
        int ct = m;
        ara[b]=1;
        //cout<<m<<" "<<vec.size()<<endl;
        for(int i=n;i>0&&m&&i>a;i--) if(!ara[i]) vec.pb(i),ara[i]=1,m--;
        //cout<<m<<endl;
        if(m)
        {
            cout<<"-1"<<endl;
            continue;
        }
        vec.pb(b);
        int cnt = 0;
        for(int i=1;i<b;i++) if(!ara[i]) cnt++;
        //cout<<cnt<<" "<<m<<endl;
        if(cnt<ct)
        {
            cout<<"-1"<<endl;
            continue;
        }
        for(int i=1;i<b;i++) if(!ara[i]) vec.pb(i);
        for(int i=0;i<vec.size();i++) cout<<vec[i]<<" ";
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
