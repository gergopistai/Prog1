#include "Drill.h"

class Drill20 : Drill
{
	template <typename T>
	void increase_by(T& cont, int amount)
	{
		for (auto& t : cont) t += amount;
	}

	template <typename Iter1, typename Iter2>
	Iter2 copy(Iter1 f1, Iter1 e1, Iter2 f2)
	{
		for (Iter1 p = f1; p != e1; p++) *f2++ = *p;
		return f2;
	}

public:
	void start() override
	{
		std::array<int, 10> arr { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		list<int> li = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		cout << "array: ";
		for (int i : arr) cout << i << ", ";
		cout << "\nvector: ";
		for (int i : vec) cout << i << ", ";
		cout << "\nlist: ";
		for (int i : li) cout << i << ", ";

		std::array<int, 10> arr2 = arr;
		vector<int> vec2 = vec;
		list<int> li2 = li;

		cout << "\n\narray2: ";
		for (int i : arr2) cout << i << ", ";
		cout << "\nvector2: ";
		for (int i : vec2) cout << i << ", ";
		cout << "\nlist2: ";
		for (int i : li2) cout << i << ", ";

		increase_by(arr, 2);
		increase_by(vec, 3);
		increase_by(li, 5);

		cout << "\n\narray: ";
		for (int i : arr) cout << i << ", ";
		cout << "\nvector: ";
		for (int i : vec) cout << i << ", ";
		cout << "\nlist: ";
		for (int i : li) cout << i << ", ";

		copy(arr.begin(), arr.end(), vec.begin());
		copy(li.begin(), li.end(), arr.begin());

		cout << "\n\narray: ";
		for (int i : arr) cout << i << ", ";
		cout << "\nvector: ";
		for (int i : vec) cout << i << ", ";
		cout << "\nlist: ";
		for (int i : li) cout << i << ", ";

		cout << "\n";
		vector<int>::iterator veci = std::find(vec.begin(), vec.end(), 3);
		if (veci != vec.end()) cout << "\n" << distance(vec.begin(), veci);

		list<int>::iterator lii = std::find(li.begin(), li.end(), 27);
		if (lii != li.end()) cout << "\n" << distance(li.begin(), lii);
	}
};