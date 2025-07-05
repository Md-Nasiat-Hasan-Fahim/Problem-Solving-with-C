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

int cost(vector<pair<int,int>> &a, vector<pair<int,int>> &b)
{
    int cnt = 0;
    int i = 0, j = 0, k = 0;
    vector<int>vec;
    while(i<a.size()&&j<b.size())
    {
        int x = 2*k+1;
        int y = labs(x-b[j].first);
        cnt+=y;
        vec.pb(a[i].second);vec.pb(b[i].second);
        i++;j++;k++;
    }
    while(i<a.size()) vec.pb(a[i++].second);
    while(j<b.size()) vec.pb(b[j++].second);
    for(int i=1;i<vec.size();i++) if(vec[i]%2==vec[i-1]%2) return LONG_LONG_MAX;
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
        int n;
        cin>>n;
        vector<pair<int,int>> pe,po;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            if(a%2) po.pb({i,a});
            else pe.pb({i,a});
        }
        int cnt = min(cost(po,pe),cost(pe,po));
        if(cnt==LONG_LONG_MAX) cout<<"-1"<<endl;
        else cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
