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
        int n = s.size();
        int cta = 0, ctb = 0;
        for(int i=0;i<n-1;i++) if(s[i]=='a'&&s[i+1]=='b') cta++;
        for(int i=0;i<n-1;i++) if(s[i]=='b'&&s[i+1]=='a') ctb++;
        if(cta==ctb)
        {
            cout<<s<<endl;
        }
        else if(cta>ctb)
        {
            if(s[0]=='a') s[0]='b';
            else 
            for(int i=1;i<n-1;i++)
            {
                if(s[i]=='a'&&s[i-1]=='b'&&s[i+1]=='b')
                {
                    s[i]='b';
                    break;
                }
            }
            cout<<s<<endl;
        }
        else
        {
            if(s[0]=='b') s[0]='a';
            else 
            for(int i=1;i<n-1;i++)
            {
                if(s[i]=='b'&&s[i-1]=='a'&&s[i+1]=='a')
                {
                    s[i]='a';
                    break;
                }
            }
            cout<<s<<endl;
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
