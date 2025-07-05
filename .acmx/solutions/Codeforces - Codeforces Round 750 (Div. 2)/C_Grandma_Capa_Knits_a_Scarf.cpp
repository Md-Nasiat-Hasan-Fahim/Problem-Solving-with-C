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

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int cnt = INT_MAX;
        for(char c = 'a';c<='z';c++)
        {
            vector<int>del;
            string a="";
            for(int i=0;i<n;i++)
            {
                if(s[i]==c)
                {
                    del.pb(i);
                }
                else a.pb(s[i]);
            }
            string b = a;
            reverse(all(b));
            int tcnt = INT_MAX;
            if(a==b)
            {
                //cout<<a<<" "<<b<<endl;
                int tct = 0;
                for(int i=0,j = del.size()-1;i<n/2;i++)
                {
                    
                }
                tcnt = del.size() - 2*tct;
                cout<<c<<" "<<del.size()<<" "<<tct<<" "<<tcnt<<endl;
            }
            cnt = min(cnt,tcnt);
        }
        if(cnt!=INT_MAX)cout<<max(cnt,0LL)<<endl;
        else cout<<"-1"<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
