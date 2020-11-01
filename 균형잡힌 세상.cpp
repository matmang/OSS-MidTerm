#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	string str;

	while (true) {
		stack<char> st;
		bool emptyFlag = false;
		getline(cin, str, '\n');

		if (str == ".") break;

		for (int i = 0; i < (int)str.length(); i++) {
			if (str[i] == '[' || str[i] == '(') st.push(str[i]);
			else if (str[i] == ']' || str[i] == ')') {
				if (st.empty()) {
					emptyFlag = true;
					break;
				}
				else if (str[i] == ']') {
					if (st.top() == '[') st.pop();
					else break;
				}
				else if (str[i] == ')') {
					if (st.top() == '(') st.pop();
					else break;
				}
			}
			else
				continue;
		}
		if (st.empty() && (!emptyFlag))
			cout << "yes\n";
		else
			cout << "no\n";
	}
}