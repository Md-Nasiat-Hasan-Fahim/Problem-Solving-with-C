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

bool pqr(int x)
{
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0) return true;
    }
    return false;
}


signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int Master0fTheSEA=1;
    cin>>Master0fTheSEA;
    for(int tttttttt=1;tttttttt<=Master0fTheSEA;tttttttt++)
    {
        int n;string s;
        cin>>n>>s;
        int ara[10]={0};
        for(int i=0;i<n;i++) ara[s[i]-'0']++;
        bool abc = false;
        for(int i=1;i<=9;i++)
        {
            if(ara[i]&&(i==1||i==4||i==6||i==8||i==9))
            {
                abc = true;
                cout<<"1\n"<<i<<endl;
                break;
            }
        }
        if(abc) continue;
        for(int i=1;i<=9;i++)
        {
            if(ara[i]>1)
            {
                cout<<"2\n"<<i<<i<<endl;
                abc = true;
                break;
            }
        }
        if(abc) continue;
        cout<<"2\n";
        string str = "";
        for(int j=0;j<n;j++)
        {
            int i = s[j]-'0';
            if((i==1||i==4||i==6||i==8||i==9)) continue;
            str.pb(s[j]);
        }
        int y = -1;
        for(int i=0;i<str.size()-1;i++)
        {
            for(int j=i+1;j<str.size();j++)
            {
                int x = (str[i]-'0')*10+(str[j]-'0');
                if(pqr(x))
                {
                    y = x;
                    break;
                }
            }
            if(y!=-1) break;
        }
        cout<<y<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}