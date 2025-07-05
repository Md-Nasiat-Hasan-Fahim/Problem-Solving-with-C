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
vector<pair<int,int>>vec;

int abc(int x, int y)
{
    vector<int>cnt(4,0);
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i].first>x&&vec[i].second>y) cnt[0]++;
        else if(vec[i].first>x&&vec[i].second<y) cnt[3]++;
        else if(vec[i].first<x&&vec[i].second<y) cnt[2]++;
        else cnt[1]++;
    }
    return *max_element(all(cnt));
}

signed main()
{
    freopen("balancing.in","r+",stdin);
    freopen("balancing.out","w+",stdout);
    FastIO;
    int t=1;
    //cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n,b;
        cin>>n>>b;
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            vec.pb({a,b});
        }
        int mn = INT_MAX;
        for(int i=0;i<vec.size();i++)
        {
            int x = vec[i].first;
            int y = vec[i].second;
            for(int j=0;j<vec.size();j++)
            {
                mn = min(mn,abc(x+1,vec[j].second+1));
                mn = min(mn,abc(x+1,vec[j].second-1));
                mn = min(mn,abc(x-1,vec[j].second+1));
                mn = min(mn,abc(x-1,vec[j].second-1));
                mn = min(mn,abc(vec[j].first+1,y+1));
                mn = min(mn,abc(vec[j].first-1,y+1));
                mn = min(mn,abc(vec[j].first+1,y-1));
                mn = min(mn,abc(vec[j].first-1,y-1));
            }
        }
        cout<<mn<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
