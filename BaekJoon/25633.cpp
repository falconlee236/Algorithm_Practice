#include <iostream>
using namespace std;
int N;
int arr[1001];
int dp[1001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];

	for (int i = 1; i <= N; i++) {
		for (int j = i; j > 0; j--) {
			if (dp[j - 1] >= arr[i]) dp[j] = max(dp[j], dp[j - 1] + arr[i]);
		}
		dp[1] = max(dp[1], arr[i]);
	}
	for (int i = N; i > 0; i--) {
		if (dp[i]) {
			cout << i;
			break;
		}
	}
}
