#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int mx=2e7+5;
int f[mx];

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	f[1]=0;
	for(int i=2;i<mx;i++){
		if(!f[i]){
			for(int j=i;j<mx;j+=i){
				f[j]++;
			}
		}
	}
	int t; cin>>t; while(t--){
		ll c,d,x; cin>>c>>d>>x;
		ll ans=0;
		for(int g=1;g*g<=x;g++){
			if(x%g==0){
				int gg=x/g;
				if((x+d*g)%(c*g)==0){
					ll p=(x+d*g)/(c*g);
                    cout<<p<<endl;
					ans+=(1LL<<f[p]);
				}if(gg!=g && (x+d*gg)%(c*gg)==0){
					ll p=(x+d*gg)/(c*gg);
					ans+=(1LL<<f[p]);
                    cout<<p<<endl;
				}
			}
		}cout<<ans<<endl;
	}
}