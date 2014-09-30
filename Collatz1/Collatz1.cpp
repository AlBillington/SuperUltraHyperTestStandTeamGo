// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <utility>  // make_pair, pair

// ------------
// collatz_read 
// ------------

std::pair<int, int> collatz_read(std::istream& r)
{
	int i;
	r >> i;
	
	if (!r)
		return std::make_pair(0, 0);

	int j;
	r >> j;
	
	return std::make_pair(i, j);
}

// --------------------
// collatz_cycle_length
// --------------------

int collatz_cycle_length(int n)
{
	int iterationCount = 1;

	while (n > 1)
	{
		if (!(n % 2))
		{
			n = (n / 2);
			++iterationCount;
		}
		else
		{
			n = n + (n >> 1) + 1;
			iterationCount += 2;
		}
	}

	return iterationCount;
}

// ------------
// collatz_eval
// ------------

int collatz_eval(int i, int j)
{
	int maxLength = 0;
	int temp = 0;

	if (i > j)
		std::swap(i, j);

	temp = j / 2 + 1;

	if (i < temp)
		i = temp;

	for (int n = i; n <= j; n++)
	{
		if ((temp = collatz_cycle_length(n)) > maxLength)
			maxLength = temp;
	}

	return maxLength;
}

// -------------
// collatz_print
// -------------

void collatz_print(std::ostream& w, int i, int j, int v)
{
	w << i << " " << j << " " << v << std::endl;
}

// -------------
// collatz_solve
// -------------

void collatz_solve(std::istream& r, std::ostream& w)
{
	while (true)
	{
		const std::pair<int, int> p = collatz_read(r);

		if (p == std::make_pair(0, 0))
			return;

		const int i = p.first;
		const int j = p.second;
		const int v = collatz_eval(i, j);

		collatz_print(w, i, j, v);
	}
}

int main()
{
	using namespace std;

	collatz_solve(cin, cout);

	return 0;
}