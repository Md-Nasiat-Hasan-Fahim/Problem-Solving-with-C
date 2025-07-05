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
        set<pair<int,int>>st1;
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
            st1.insert({vec[i],i});
        }
        priority_queue<pair<int,int>>pq;
        int mx = -1;
        string s="";
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            pq.push({a,i});s.pb('0');
        }
        int x = vec[pq.top().second];
        while(!pq.empty())
        {
            int y = st1.rbegin()->first;
            //cout<<(max(y,vec[pq.top().second])>x)<<endl;
            if(max(y,vec[pq.top().second])>mx||max(y,vec[pq.top().second])>x)
            {
                s[pq.top().second]='1';
                mx = max(mx,vec[pq.top().second]);
            }
            st1.erase({vec[pq.top().second],pq.top().second});
            pq.pop();
        }
        cout<<s<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
