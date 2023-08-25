#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int n, k;
vii jams;
vi cs;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n >> k;

	jams = vii(n);
	for (auto&& [m, v] : jams) {
		cin >> m >> v;
	}

	sort(jams.begin(), jams.end());

	cs = vi(k);
	for (auto&& c : cs) {
		cin >> c;
	}

	sort(cs.begin(), cs.end());

	auto ans = ll{ 0 };
	auto idx = int{ 0 };
	auto q = priority_queue<int>{};
	for (auto i = 0; i < k; ++i) {
		while (idx < n && jams[idx].first <= cs[i]) {
			q.push(jams[idx].second);
			++idx;
		}

		if (!q.empty()) {
			ans += q.top();
			q.pop();
		}
	}

	cout << ans;

	return 0;
}