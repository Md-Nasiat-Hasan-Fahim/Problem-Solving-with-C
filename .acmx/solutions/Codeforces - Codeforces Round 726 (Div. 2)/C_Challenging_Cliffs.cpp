#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define check(x) cout << (#x) << " is " << (x) << endl;
const int mod = 1e9 + 7;

//{{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}}
//{{1,2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,-1},{-2,1},{1,-2}}

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

signed main()
{
    // freopen("","r+",stdin);
    // freopen("","w+",stdout);
    FastIO;
    int t = 1;
    cin >> t;
    for (int z = 1; z <= t; z++)
    {
        unordered_map<int, int, custom_hash> mp;
        multiset<int> st;
        int n;
        cin >> n;
        vector<int>vec(n);
        bool d = false;
        int c;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            st.insert(a);
            vec[i]=a;
            mp[a]++;
            if (mp[a] > 1)
            {
                d = true;
                c = a;
            }
        }
        int mn1, mn2;
        if (d)
        {
            mn1 = mn2 = c;
        }
        else
        {
            int p,q;
            sort(all(vec));
            int mn = INT_MAX;
            for(int i=0;i<n-1;i++)
            {
                if(abs(vec[i]-vec[i+1])<mn)
                {
                    p = vec[i];
                    q = vec[i+1];
                    mn = abs(vec[i]-vec[i+1]);
                }
            }
            mn1 = p;
            mn2 = q;
        }
        mp[mn1]--;
        mp[mn2]--;
        //cout << mn1 << " ";
        int cnt = 0;
        vec[cnt++] = mn1;
        while (st.size() > 1)
        {
            while(st.size()&&mp[*st.begin()]==0) st.erase(st.begin());
            if(!st.size()) break;
            int a = *st.begin();
            st.erase(st.begin());
            while(st.size()&&mp[*st.begin()]==0) st.erase(st.begin());
            int b = -1;
            if(st.size()){
            b = *st.begin();
            st.erase(st.begin());
            }
            while (mp[a] > 1 && mp[b] > 1)
            {
                vec[cnt++]=a;vec[cnt++]=b;
                //cout << a << " " << b << " ";
                mp[a]--;
                mp[b]--;
            }
            while (mp[a] > 0)
            {
                vec[cnt++]=a;
                //cout << a << " ";
                mp[a]--;
            }
            while (mp[b] > 0)
            {
                vec[cnt++]=b;
                //cout << b << " ";
                mp[b]--;
            }
        }
        if (st.size())
        {
            int a = *st.begin();
            st.erase(st.begin());
            while (mp[a] > 0)
            {
                vec[cnt++]=a;
                //cout << a << " ";
                mp[a]--;
            }
        }
        if(n>3&&vec[0]<vec[2]&&vec[0]>=vec[1]) swap(vec[1],vec[2]);
        if(n>3&&vec[n-3]<vec[n-1]&&vec[n-1]<=vec[n-2]) swap(vec[n-2],vec[n-3]);
        vec[cnt++] = mn2;
        for(int i=0;i<n;i++) cout<<vec[i]<<" ";
        cout<<endl;
    }
    // cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}