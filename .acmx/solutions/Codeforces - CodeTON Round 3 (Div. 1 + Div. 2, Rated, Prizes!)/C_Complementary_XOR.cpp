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
        int n;cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        int cnt = 0;int m = 0, nm = 0;
        for(int i=0;i<n;i++)
        {
            if(s1[i]!=s2[i]) nm++;
        }
        m = n-nm;
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++)
        {
            if(s1[i]==s2[i]&&cnt%2)
            {
                swap(m,nm);
                cnt++;
                vec.pb({i+1,i+1});

            }
            else if(s1[i]!=s2[i]&&cnt%2==0)
            {
                swap(m,nm);
                cnt++;
                vec.pb({i+1,i+1});
            }
        }
        if(nm==n)
        {
            YES;
            cout<<vec.size()+1<<endl;
            for(int i=0;i<vec.size();i++)
            {
                cout<<vec[0].first<<" "<<vec[0].second<<endl;
            }
            cout<<"1 1\n";
        }
        else if(m == n)
        {
            YES;
            cout<<vec.size()<<endl;
            for(int i=0;i<vec.size();i++)
            {
                cout<<vec[0].first<<" "<<vec[0].second<<endl;
            }
        }
        else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
