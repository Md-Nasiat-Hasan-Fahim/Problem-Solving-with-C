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
        vector<int>vec(n);
        priority_queue<int>pq;
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
            pq.push(vec[i]);
        }
        int cnt = 0;
        int i;
        int mn = -1;
        for(int i=n-1;i>-1;i--)
        {
            if(vec[i]>mn)
            {
                cnt++;
                mn = vec[i];
            }
        }
        cout<<cnt-1<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
