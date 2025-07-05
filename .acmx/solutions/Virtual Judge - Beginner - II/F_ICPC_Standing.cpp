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
int k;

//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    FastIO;
    int t=1;
    //cin>>t;
    while(1)
    {
        int n;
        cin>>n>>k;
        if(n==0&&k==0) break;
        vector<int>vec;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            vec.pb(a);
        }
        sort(all(vec),[](int a, int b)
        {
            if(a%k<b%k) return true;
            else if(a%k>b%k) return false;
            else
            {
                if(abs(a%2)==0&&abs(b%2)==0)
                return a<b;
                else if(abs(a%2)==1&&abs(b%2)==1) return a>b;
                else
                {
                    return abs(a%2)==1;
                }
            }
        });
        cout<<n<<" "<<k<<endl;
        for(int i=0;i<n;i++)
        cout<<vec[i]<<endl;
    }
    cout<<"0 0\n";
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
