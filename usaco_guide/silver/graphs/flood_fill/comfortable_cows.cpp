#include <bits/stdc++.h>
using namespace std;

// li o editorial dessa

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int count_neighbors(vector<vector<bool>> &v, int x, int y) {
	int count_neighbors = 0;
	for (int i = 0; i < 4; i++) {
		if (v[x + dx[i]][y + dy[i]]) count_neighbors++;
	}
	return count_neighbors;
}

array<int, 2> find_empty(vector<vector<bool>> &v, int x, int y) {
	array<int, 2> empty_cell;
	for (int i = 0; i < 4; i++) {
		if (!v[x + dx[i]][y + dy[i]]) empty_cell = {x + dx[i], y + dy[i]};
	}
	return empty_cell;
}

void check_cell(int x, int y, vector<vector<bool>> &v, queue<array<int, 2>> &to_place) {
	if (count_neighbors(v, x, y) == 3) {
		array<int, 2> empty_cell = find_empty(v, x, y);
		if (!v[empty_cell[0]][empty_cell[1]]) { to_place.push(empty_cell); }
	}
}

int main() {
	int n;
	cin >> n;
	vector<vector<bool>> filled(2000, vector<bool>(2000));
	queue<array<int, 2>> to_place;
	int total_cows = 0;
	for (int cow_number = 1; cow_number <= n; cow_number++) {
		array<int, 2> new_cow;
		cin >> new_cow[0] >> new_cow[1];

		new_cow[0] += 500;
		new_cow[1] += 500;
		to_place.push(new_cow);

		while (!to_place.empty()) {
			array<int, 2> current_cow = to_place.front();
			to_place.pop();
			if (filled[current_cow[0]][current_cow[1]]) continue;
			total_cows++;
			filled[current_cow[0]][current_cow[1]] = true;

			check_cell(current_cow[0], current_cow[1], filled, to_place);
			for (int i = 0; i < 4; i++) {
				if (filled[current_cow[0] + dx[i]][current_cow[1] + dy[i]]) {
					check_cell(current_cow[0] + dx[i], current_cow[1] + dy[i], filled,
					           to_place);
				}
			}
		}

		cout << total_cows - cow_number << endl;
	}
}