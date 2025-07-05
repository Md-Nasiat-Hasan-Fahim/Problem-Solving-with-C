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
        bool zero = false, one = false, two = false;
        vector<int>vec;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            vec.push_back(a);
            if(a==0) zero = true;
            else if(a==1) one = true;
            else if(a==2) two = true;
        }
        if((one&&zero)||(one&&two)) NO;
        else
        {
            if(!one) YES;
            else 
            {
                sort(all(vec));
                bool  ans = true;
                for(int i=0;i<n;i++)
                {
                    if(binary_search(all(vec),vec[i]-1))
                    {
                        ans=false;
                        break;
                    }
                }
                if(ans) YES;
                else NO;
            }
        }
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC <<   "ms\n";
    return 0;
}
