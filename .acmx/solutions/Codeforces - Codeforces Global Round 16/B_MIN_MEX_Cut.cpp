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
        string s;
        cin>>s;
        bool one = false, zero = false;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1') one = true;
            if(s[i]=='0') zero = true;
        }
        if(one&&zero)
        {
            int cnt = 0;
            for(int i=1;i<s.size();i++)
            {
                if(s[i]!=s[i-1]&&s[i]=='0') cnt++; 
            }
            if(s[0]=='0') cnt++;
            cout<<min(2LL,cnt)<<endl;
        }
        else if(one) cout<<"0"<<endl;
        else if(zero) cout<<"1"<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
