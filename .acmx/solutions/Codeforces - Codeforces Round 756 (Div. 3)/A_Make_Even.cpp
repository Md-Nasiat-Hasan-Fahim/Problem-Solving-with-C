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
        bool ans = false;
        for(int i=0;i<s.size();i++)
        {
            if((s[i]-'0')%2==0) ans = true;
        }
        if(!ans) cout<<"-1"<<endl;
        else 
        {
            if((s[s.size()-1]-'0')%2==0) cout<<"0\n";
            else if((s[0]-'0')%2==0) cout<<"1"<<endl;
            else cout<<"2"<<endl;
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
