
#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

#define MAXN 200200

int t, n, a[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		set<pair<int,int>> curr;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if (a[i])
				curr.insert({a[i], i + 1});
		}
		vector<pair<int,int>> ans;
		while (curr.size() >= 2) {
			auto i = *curr.begin(); curr.erase(curr.begin());
			auto j = *curr.rbegin(); curr.erase(curr.find(j));
			ans.push_back({i.second, j.second});
			i.first--; j.first--;
			if (i.first > 0) curr.insert(i);
			if (j.first > 0) curr.insert(j);
		}
		printf("%d\n", (int)ans.size());
	}
}