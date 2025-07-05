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

int abc(int x, int r)
{
    int cnt = 0;
    if(r>x) cnt++,swap(x,r);
    int xy = (x/r)*r;
    int m = xy/r;
    bool flag = m%2;
    m+=flag;
    return (m*3)/2+!flag+cnt;
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
        int x=100, r=45;
        int cnt = 2;
        while(r)
        {
            cnt-=2;
            if(r>x)
            {
                cnt++;
                int t = r-x;
                x = r;
                r = t;
            }
            cnt+=abc(x,r);
            cout<<x<<" "<<r<<" "<<cnt<<endl;
            int t = r;
            r = x%r;
            x = t;
        }
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
