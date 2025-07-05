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

int abc(string s,int i)
{
    //cout<<s<<endl;
    if(i==11)
    {
        return 10;
    }
    int x = 0, y = 0;
    int cnt;
    int xc = 0, yc = 0;
    for(int j=0;j<i;j++)
    {
        if(s[j]=='1')
        {
            if(j%2) y++;
            else x++;
        }
        if(j%2) yc++;
        else xc++;
    }
    xc=5-xc;
    yc=5-yc;
    if(x+xc<y||yc+y<x) return i;
    if(s[i]=='?')
    {
        s[i]='1';
        int q = abc(s,i+1);
        s[i]='0';
        int p = abc(s,i+1);
        cnt = min(p,q);
    }
    else cnt = abc(s,i+1);
    return cnt;
}

signed main()
{
    //freopen("","r+",stdin);
    //freopen("","w+",stdout);
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        string s;
        cin>>s;
        cout<<abc(s,0)<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
