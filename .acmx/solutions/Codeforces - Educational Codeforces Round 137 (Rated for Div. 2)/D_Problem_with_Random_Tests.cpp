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

//{{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}}
//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

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
        string s,ans;
        cin>>n>>s;
        reverse(all(s));
        while(s.size()&&s.back()=='0') s.pop_back();
        reverse(all(s));
        if(!s.size())
        {
            cout<<"0\n";
            continue;
        }
        ans = s;
        vector<int>one,zero;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0') zero.pb(i);
            else one.pb(i);
        }
        if(!one.size()||!zero.size())
        {
            cout<<ans<<endl;
            continue;
        }
        for(int i=0;i<one.size();i++)
        {
            if(one[i]>zero[0]) break;
            string tem = s;
            int y = one[i]-zero[0];
            for(int j = i;j<one.size();j++)
            {
                tem[one[j]-y]='1';
            }
            if(tem>ans)
            {
                ans = tem;
            }
        }
        cout<<ans<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
