#include <iostream>
#include <queue>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		int N=0, M=0;
		int count=0;
		queue <pair<int, int>> q; 
		priority_queue<int> pq;

		cin >> N >> M;


		for (int j = 0; j < N; j++)
		{
			int val;
			cin >> val;

			q.push({ j,val }); 
			pq.push(val); 
		}

		while (!q.empty())
		{
			int currentIndex = q.front().first;
			int currentVal = q.front().second;
			q.pop();

			if (pq.top() == currentVal)
			{
				pq.pop();
				count++;

				if (currentIndex == M) 
				{
					cout << count << endl;
					break;
				}
			}
			else
			{
				q.push({ currentIndex,currentVal });
			}
		}

	}
	return 0;
}