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
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        string s;
        cin>>s;
        deque<char>dq;
        bool ans = true;
        for(int i=0;i<s.size();i++)
        {
            dq.pb(s[i]);
        }
        for(int i=s.size()-1;i>-1;i--)
        {
            if(dq[0]=='a'+i)
            {
                dq.pop_front();
            }
            else if(dq.back()=='a'+i)
            {
                dq.pop_back();
            }
            else
            {
                ans = false;
                break;
            }
        }
        if(ans) YES;
        else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
