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
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        map<int,int>mp;
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            string s = "";
            while(a)
            {
                s+=to_string(a%k);
                a/=k;
            }
            //reverse(all(s));
            cout<<s<<endl;
            for(int i=0;i<s.size();i++)
            {
                mp[i]+=s[i]-'0';
            }
        }
        bool ans = true;
        for(auto x:mp)
        {
            if(x.second>1LL)
            {
                //cout<<i<<" "<<ara[i]<<endl;
                ans=false;
                break;
            }
        }
        if(ans) YES;
        else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
