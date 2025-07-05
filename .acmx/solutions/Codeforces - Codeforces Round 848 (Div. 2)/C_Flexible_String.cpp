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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int cpt(int x)
{
    return (x*(x+1))/2;
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
        unordered_map<char,bool,custom_hash>mp;
        int n,k;
        cin>>n>>k;
        string s1,s2;
        cin>>s1>>s2;
        queue<int>q;
        q.push(0);
        for(int i=0;i<n;i++) if(s1[i]!=s2[i]) q.push(i);
        int mx = 0LL;
        int ct = 0;
        while(!q.empty())
        {
            int l = 0;
            int r1 = q.front();
            q.pop();
            set<int>st;
            mp.clear();
            int cnt = 0;
            int r;
            for(r=0;r<n;r++)
            {
                if(r>=r1){
                if(s1[r]!=s2[r])
                {
                    if(mp[s1[r]]) continue;
                    else if(st.size()<k)
                    {
                        st.insert(s1[r]);
                        mp[s1[r]]=true;
                    }
                    else
                    {
                        cnt+=cpt(r-l);
                        l = r+1;
                    }
                }
                }
                else
                {
                    if(s1[r]!=s2[r])
                    {
                        cnt+=cpt(r-l);
                        l = r+1;
                    }
                }
            }
            //cout<<cnt<<" "<<s1[r1]<<endl;
            if(r!=l) cnt+=cpt(r-l);
            //cout<<cpt(4)<<" "<<s1[r1]<<endl;
            mx = max(mx,cnt);
        }
        cout<<mx<<endl;
    }
    //cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
