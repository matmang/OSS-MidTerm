#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	cin.ignore();
	while (n--) {
		string line;
		getline(cin, line);
		int len = line.length();
		bool flag = true;
		for (int i = 0; i < len / 2; i++) {
			if (toupper(line[i]) != toupper(line[len - i - 1])) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
}