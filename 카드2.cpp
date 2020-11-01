#include <iostream>
#include <stack>
#include <string>
#include <queue>

using namespace std;

queue <int> q;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (q.size() > 1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front();
}