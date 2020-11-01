#include <iostream>
#include <queue>
#include <string>


using namespace std;

queue <int> q;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N; cin >> N;
	while (N--) {
		string command; cin >> command;
		if (command == "push") {
			int X; cin >> X;
			q.push(X);
		}
		else {
			if (command == "pop") {
				if (q.empty()) cout << "-1";
				else {
					cout << q.front();
					q.pop();
				}
			}
			if (command == "size") {
				cout << q.size();
			}
			if (command == "empty") {
				cout << q.empty();
			}
			if (command == "front") {
				if (q.empty()) cout << "-1";
				else {
					cout << q.front();
				}

			}
			if (command == "back") {
				if (q.empty()) cout << "-1";
				else {
					cout << q.back();
				}
			}
			cout << '\n';
		}
	}
}