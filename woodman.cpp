#include <bits/stdc++.h>

using namespace std;

void solve() {
	string str;
	cin >> str;
	stringstream s(str);
	char ch;
	s >> ch;
	vector<int> a;
	while (true) {
		int num;
		s >> num >> ch;
		a.push_back(num);
		if (ch == '>') break;
	}
	int n = a.size();
	int dp[n][n];
	for(int i = 0; i < n; ++i)
		dp[i][i] = 0;
	for(int l = 2; l <= n; ++l) {
		for(int i = 0; i < n; ++i) {
			int j = i + l - 1;
			dp[i][j] = INT_MAX;
			for(int k = i; k < j; ++k) {
				dp[i][j] = min(dp[i][j], a[i] + a[j] + dp[i][k] + dp[k+1][j]);
			}
		}
	}
	cout << dp[0][n - 1] << "\n";
}

int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		solve();
	}
}