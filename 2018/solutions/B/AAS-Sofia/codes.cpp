#include <vector>
#include <iostream>
#include <string>
#include <cmath>

typedef unsigned long long ull;

ull sum_digits(ull a)
{
	ull sum = 0;

	while (a != 0) {
		sum += a % 10;
		a /= 10;
	}

	return sum;
}


int count_digits(ull a)
{
	int count = 0;

	while (a != 0) {
		++count;
		a /= 10;
	}

	return count;
}

ull concat(ull a, ull b) {
	return a*std::pow(10, count_digits(b)) + b;
}

std::vector<ull> generate(std::vector<ull> prev, std::vector<ull> digits)
{
	int i, j, digits_size = digits.size(), prev_size = prev.size();
	std::vector<ull> next;
	for (i = 0; i < digits_size; ++i) {
		if (i % 2 == 0) {
			for (j = 0; j < prev_size; ++j) {
				next.push_back(concat(digits.at(i), prev.at(j)));
			}
		}
		else {
			for (j = prev_size - 1; j >= 0; --j) {
				next.push_back(concat(digits.at(i), prev.at(j)));
			}
		}
	}

	return next;
}


template <typename T>
T abs(T a)
{
	return a > 0 ? a : -a;
}

int main()
{
	int N, K, A, B, i;
	std::vector<ull> orig;
	std::vector<ull> curr;
	std::cin >> N >> K >> A >> B;
	ull max;

	int tmp;
	for (i = 0; i < N; ++i) {
		std::cin >> tmp;
		orig.push_back(tmp);
	}

	curr = orig;

	for (i = 1; i < K; ++i) {
		curr = generate(curr, orig);
	}

	int curr_size = curr.size();
	max = curr.at(A);
	int max_diff, last_sum, curr_sum;
	last_sum = sum_digits(curr.at(A-1)); // ugly fix
	for (i = A - 1; i <= B - 1; ++i) {
		curr_sum = sum_digits(curr.at(i));
		if (max < curr.at(i)) max = curr.at(i);

		if (max_diff < abs(curr_sum - last_sum)) max_diff = abs(curr_sum - last_sum);
		last_sum = curr_sum;
	}

	std::cout << max << " " << max_diff << std::endl;
	return 0;
}
