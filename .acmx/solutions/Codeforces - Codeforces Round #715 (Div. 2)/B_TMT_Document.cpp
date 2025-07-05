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

//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    FastIO;
    int t=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ct = 0, cm = 0, cnt = 0;
        int lim = n-(n/3);
        bool ans = true;
        if(lim%2==0) lim/=2;
        else ans=false;
        bool mark = false;
        if(ans)
        for(int i=0;i<n;i++)
        {
            if(s[i]=='T')
            {
                if(ct+1>lim||mark)
                {
                    mark=true;
                    if(!cm)
                    {
                        ans=false;
                        break;
                    }
                    else
                    {
                        ct--;
                        cm--;
                        //cout<<ct<<" "<<cm<<endl;
                    }
                }
                else ct++;
            }
            else
            {
                if(cm+1>ct)
                {
                    ans = false;
                    break;
                }
                else
                {
                    cm++;
                }
            }
        }
        //cout<<ans<<" "<<ct<<" "<<cm<<endl;
        if(ans&&!ct&&!cm) YES;
        else NO;
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
