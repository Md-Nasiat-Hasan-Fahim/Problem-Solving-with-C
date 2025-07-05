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

void abc(string &s)
{
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1') s[i]='l';
        else if(s[i]=='0') s[i]='o';
    }
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
        int n;
        cin>>n;

        string s1,s2;
        cin>>s1>>s2;
        abc(s1);abc(s2);
        if(s1==s2) cout<<"Yes\n";
        else cout<<"No\n";
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
