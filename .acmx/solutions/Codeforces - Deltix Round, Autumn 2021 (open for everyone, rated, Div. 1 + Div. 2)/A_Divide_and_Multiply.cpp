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
        vector<unsigned long long>vec(n);
        for(int i=0;i<n;i++) cin>>vec[i];
        sort(all(vec));
        unsigned long long cnt = 0;
        for(int i=0;i<n;i++)
        {
            auto ab = vec;
            unsigned long long mx = 0;
            for(int j=0;j<n;j++)
            {
                if(j==i) continue;
                while(ab[j]%2==0)
                {
                    ab[j]/=2;
                    ab[i]*=2;
                }
                mx+=ab[j];
            }
            mx+=ab[i];
            cnt=max(cnt,mx);
        }
        cout<<cnt<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
