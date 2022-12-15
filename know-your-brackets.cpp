#include <bits/stdc++.h>

using namespace std;

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	map<int,int> cnt;
	int mx = 0;
	cnt[0] = 1;
	for(int i = 0; i < n; ++i) {
		int j = i;
		int sm = 0;
		while (j < n) {
			sm += (s[j] == '(' ? 1 : -1);
			if (sm == 0) {
				if (mx < j - i + 1) {
					mx = j - i + 1;
					// cout << mx << "\n";
					cnt[mx] = 1;
				} else if (mx == j - i + 1) cnt[mx]++;
			}
			if (sm < 0) break;
			++j;
		}
	}
	cout << mx << " " << cnt[mx] << "\n";
}

int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		solve();
	}
}