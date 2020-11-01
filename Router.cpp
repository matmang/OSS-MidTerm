#include <iostream>
#include <queue>


using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	queue<int> Q;
	int x = 0; cin >> x;
	while (x != -1) {
		if (x != 0) {
			if (Q.size() != N) {
				Q.push(x);
			}
		}
		else {
			Q.pop();
		}
		cin >> x;
	}
	if (Q.empty()) {
		cout << "empty\n";
	}
	else {
		while (!Q.empty()) {
			cout << Q.front() << '\n';
			Q.pop();
		}
	}
}