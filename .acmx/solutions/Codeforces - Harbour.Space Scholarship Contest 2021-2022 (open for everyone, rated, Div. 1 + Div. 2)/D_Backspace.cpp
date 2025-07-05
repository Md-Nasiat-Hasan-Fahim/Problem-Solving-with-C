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
    int tc=1;
    cin>>tc;
    for(int z=1;z<=tc;z++)
    {
        string s,t;
        cin>>s>>t;
        int ex = INT_MAX, ox = INT_MAX;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==t[0]&&(i%2))
            {
                ox = i;
                break;
            }
        }
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==t[0]&&(i%2==0))
            {
                ex = i;
                break;
            }
        }
        int i,j=0;
        int last = -1;
        for(i=ex;i<s.size()&&j<t.size();i++)
        {
            if(s[i]==t[j])
            {
                if((i-last)%2)
                {
                    if(j==t.size()-1)
                    {
                        if((s.size()-1-i)%2) continue;
                        else
                        {
                            j++;
                            last = i;
                        }
                    }
                    else{
                        j++;
                        last = i;
                    }
                }
            }
        }
        last = -2;
        bool ans = (j==t.size());
        j=0;
        for(i=ox;i<s.size()&&j<t.size();i++)
        {
            if(s[i]==t[j])
            {
                if((i-last)%2)
                {
                    if(j==t.size()-1)
                    {
                        if((s.size()-1-i)%2) continue;
                        else
                        {
                            j++;
                            last = i;
                        }
                    }
                    else{
                        j++;
                        last = i;
                    }
                }
            }
        }
        ans|=(j==t.size());
        if(ans) YES;
        else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
