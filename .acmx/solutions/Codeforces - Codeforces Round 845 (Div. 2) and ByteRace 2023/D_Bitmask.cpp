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
   // cin>>t;
    for(int z=1;z<=t;z++)
    {
        string s;int n;
        cin>>s>>n;
        reverse(all(s));
        int x = 0LL;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                x = (x|(1LL<<i));
            }
        }
        bool p = false;
        //reverse(all(s));
        for(int i=62LL;i>-1;i--)
        {
            int y = (1LL<<i);
            //cout<<i<<" "<<y<<" "<<(n&y)<<endl; 
            int z = (n&y);
            //cout<<z<<endl;
            if((n&y)&&(i>s.size()-1))
            {
                p = true;
                continue;
            }
            if(s[i]!='?')
            {
                if(s[i]=='0'&&(n&y)) p = true;
                continue;
            }
            if(p)
            {
                if((x|y)<=n) x = (x|y);
                continue;
            }
            if(z)
            {
                //YES;
                if((x|y)<=n) x = (x|y);
                else p = true;
            }
        }
        if(x<=n) cout<<x<<endl;
        else cout<<"-1"<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
