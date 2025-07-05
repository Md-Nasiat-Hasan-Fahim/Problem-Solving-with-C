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

string ans;

void abc(string &s)
{
    if(s<ans) ans = s;
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
        ans.clear();
        int n,k;string s;
        cin>>n>>k;
        cin>>s;
        for(int i=0;i<k;i++) ans.pb('z');
        for(int i=n-1;i>-1;i--)
        {
            string tem = ans;
            int x = i+1;
            for(int j=0;j<k;j++)
            {
                tem[j]=s[j%x];
            }
            abc(tem);
        }
        cout<<ans<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
