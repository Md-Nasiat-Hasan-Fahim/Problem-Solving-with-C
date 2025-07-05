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
    //cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n,q;
        cin>>n>>q;
        string s;cin>>s;
        int cnt = 0;
        for(int i=1;i<n-1;i++)
        {
            if(s[i]=='b'&&s[i-1]=='a'&&s[i+1]=='c') cnt++;
        }
        while(q--)
        {
            int pos;char c;
            cin>>pos>>c;
            if(c==s[pos-1])
            {
                cout<<cnt<<endl;
                continue;
            }
            if(s[pos-1]=='a'&&pos+1<n)
            {
                if(s[pos]=='b'&&s[pos+1]=='c') cnt--;
            }
            else if(pos-2>-1&&s[pos-1]=='b'&&pos<n)
            {
                if(s[pos-2]=='a'&&s[pos]=='c') cnt--;
            }
            else if(pos-3>-1&&s[pos-1]=='c')
            {
                if(s[pos-3]=='a'&&s[pos-2]=='b') cnt--;
            }
            s[pos-1]=c;
            if(s[pos-1]=='a'&&pos+1<n)
            {
                if(s[pos]=='b'&&s[pos+1]=='c') cnt++;
            }
            else if(pos-2>-1&&s[pos-1]=='b'&&pos<n)
            {
                if(s[pos-2]=='a'&&s[pos]=='c') cnt++;
            }
            else if(pos-3>-1&&s[pos-1]=='c')
            {
                if(s[pos-3]=='a'&&s[pos-2]=='b') cnt++;
            }
            cout<<cnt<<endl;
        }
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
