#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>

using std::cout;
using std::copy_if;
using std::copy;
using std::count_if;
using std::remove_if;
using std::generate;
using std::accumulate;
using std::ostream_iterator;
using std::vector;

int main() {
	vector<int> vec = { 1, 2, 3, 4, 5, 4, 4, 6, 7, 8, 9, 10, 13, 12, 11 };

	cout << count_if(vec.begin(), vec.end(), [](int value) { return value == 4; }) << '\r\n';
	cout << count_if(vec.begin(), vec.end(), [](int value) { return value > 4; }) << '\r\n';
	remove_if(vec.begin(), vec.end(), [](int value) { return value < 8; });
	copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));

	cout << "\r\n"; // for pretty printing

	vector<int> vec2(vec.size() - 1);
	generate(vec2.begin(), vec2.end(), [i = 0, &vec]() mutable { return vec[i] - vec[++i]; });
	copy(vec2.begin(), vec2.end(), std::ostream_iterator<int>(cout, " "));
	cout << '\r\n' << accumulate(vec2.begin(), vec2.end(), 0) << '\r\n';
}