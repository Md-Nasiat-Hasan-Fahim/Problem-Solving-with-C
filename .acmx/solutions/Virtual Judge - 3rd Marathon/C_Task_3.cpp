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
        int n;
        cin>>n;
        vector<string>vec;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            vec.pb(s);
        }
        bool ans = true;
        for(int i=n-1;i>-1;i--)
        {
            int flag = -1;
            for(int j=0;j<=i;j++)
            {
                int k = 0;
                for(;k<=i;k++)
                {
                    if(vec[j].find(vec[k])==string::npos) {break;}
                }
                //if(j==2) cout<<k<<endl;
                if(k==i+1)
                {
                    flag = j;
                    break;
                }
            }
            if(flag==-1)
            {
                //cout<<i<<endl;
                ans = false;
                break;
            }
            swap(vec[flag],vec[i]);
        }
        if(ans)
        {
            YES;
            for(int i=0;i<n;i++) cout<<vec[i]<<endl;
        }
        else NO;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
