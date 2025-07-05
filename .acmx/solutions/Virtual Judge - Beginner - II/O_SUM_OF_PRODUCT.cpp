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
        int cnt = 0;
        int i;
        int  x = 500000004;
        for(i=1;i*i<n;i++)
        {
            cnt+=i*(n/i);
            cnt%=mod;
            int a = n/i;
            int b = (n/(i+1))+1;
            if(i==b) b++;
            if(b>a) continue;
            int sum = (a+b)*(a-b+1);
            //cout<<i<<" "<<b<<" "<<a<<" "<<cnt<<endl;
            sum%=mod;
            sum*=i;
            sum%=mod;
            sum*=x;
            sum%=mod;
            cnt+=sum;
            cnt%=mod;
        }
        if(i*i==n) cnt+=i*i;
        cnt%=mod;
        cout<<cnt<<endl;
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
