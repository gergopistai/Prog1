#include "Drill.h"

template<typename T>
struct S
{ 
	S<T>(T pval) : val{ pval } { }

	T get();
	T get() const
	{
		return val;
	};

	S& operator=(const T& s)
	{
		val = s;
		return *this;
	}

private:
	T val;
};

template<typename T>
T S<T>::get() { return val; }

template<typename T>
void read_val(T& v)
{
	cin >> v;
}

class Drill19 : Drill
{
public:
	void start() override
	{
		S<int> num{ 7 };
		S<char> ch{ 'a' };
		S<double> dbl{ 0.05 };
		S<string> str{ "string" };
		S<vector<int>> vec{ {0, 1, 2, 3}};

		cout << num.get() << endl << ch.get() << endl << dbl.get() << endl << str.get() << endl;
		for (int i = 0; i < vec.get().size(); i++)
			cout << vec.get()[i];

		int i_num;
		read_val(i_num);

		char i_ch;
		read_val(i_ch);

		double i_dbl;
		read_val(i_dbl);

		string i_str;
		read_val(i_str);
	}
};