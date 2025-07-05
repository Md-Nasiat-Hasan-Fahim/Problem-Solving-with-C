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

string s1,s2;
vector<int>vec;

bool abc(int x)
{
    int i,j;
    vector<int>a;
    for(int i=x;i<vec.size();i++) a.pb(vec[i]);
    sort(all(a));
    for(i=0,j=0;i<a.size()&&j<s2.size();i++)
    {
        if(s1[a[i]-1]==s2[j]) j++;
    }
    return j==s2.size();
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    //cin>>t;
    for(int z=1;z<=t;z++)
    {
        cin>>s1>>s2;
        for(int i=0;i<s1.size();i++)
        {
            int a;
            cin>>a;
            vec.pb(a);
        }
        int lo = 0, hi = 200000+5;
        while(hi-lo>1)
        {
            int mid = (hi+lo)/2;
            if(abc(mid)) lo = mid;
            else hi = mid-1;
        }
        if(abc(hi)) cout<<hi<<endl;
        else cout<<lo<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
