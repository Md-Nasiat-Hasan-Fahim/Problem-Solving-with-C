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
        int i=0;
        int cnt = 0;
        for(;i<n-1;i++)
        {
            if(s[i]==s[i+1]||(s[i]=='('&&s[i+1]==')'))
            {cnt++;i++;}
            else
            {
                if(s[i]=='(')
                {
                    int j = i+1;
                    for(;j<n;j++)
                    {
                        if(s[j]=='(') break;
                    }
                    if(j<n&&s[j]=='('){cnt++; i=j;}
                    else break;
                }
                else
                {
                    int j = i+1;
                    for(;j<n;j++)
                    {
                        if(s[j]==')')
                        break;
                    }
                    if(j<n&&s[j]==')'){cnt++; i=j;}
                    else break;
                }
            }
        }
        cout<<cnt<<" "<<n-i<<endl;
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
