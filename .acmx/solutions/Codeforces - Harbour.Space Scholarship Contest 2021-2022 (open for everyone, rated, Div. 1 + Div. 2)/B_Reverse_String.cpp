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

string s,t;
bool ans;

void abc(int i, int j, bool l)
{
    if(ans) return;
    if(j==t.size()-1)
    {
        ans = (s[i]==t[j]);
        return;
    }
    if(i-1>-1&&s[i-1]==t[j+1]) abc(i-1,j+1, true);
    if(!l&&i+1<s.size()&&s[i+1]==t[j+1]) abc(i+1,j+1,l);
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int tc=1;
    cin>>tc;
    for(int z=1;z<=tc;z++)
    {
        ans = false;
        cin>>s>>t;
        for(int i=0;i<s.size()&&!ans;i++)
        {
            if(s[i]==t[0]) abc(i,0,false);
        }
        if(ans) YES;
        else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
