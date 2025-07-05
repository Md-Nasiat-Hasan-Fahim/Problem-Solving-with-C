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

//{{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}}
//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

signed main()
{
    FastIO;
    int t=1;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        //cout<<"Case "<<z<<": ";
        int n,k;
        cin>>n>>k;
        vector<int>vec(n);
        priority_queue<int>pq;
        for(int i=0;i<n;i++) {cin>>vec[i];pq.push(vec[i]);}
        int sum = accumulate(all(vec),0LL);
        if(sum==k)
        {
            cout<<"NO\n";
            continue;
        }
        int cnt = 0;
        YES;
        while(!pq.empty())
        {
            int x = pq.top();
            pq.pop();
            if(x+cnt==k)
            {
                cout<<pq.top()<<" ";
                cnt+=pq.top();
                pq.pop();
                pq.push(x);
            }
            else
            {
                cout<<x<<" ";
                cnt+=x;
            }
        }
        cout<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
