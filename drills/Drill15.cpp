#include "Drill.h"

struct Person
{
	Person(string first = "", string last = "", int a = 0)
		:first_name{ first }, last_name{ last }, age{ a } {
		if (age < 0 || 150 < age) error("Age not in range!");
		if (valid_name()) error("Invalid character(s) in name!");
	};

	inline string get_full_name() const { return first_name + " " + last_name; }
	inline string get_first_name() const { return first_name; }
	inline string get_last_name() const { return last_name; }
	inline int get_age() const { return age; }

private:
	bool valid_name()
	{
		for (char ch : (first_name + last_name))
			for (char elem : invalid_chars)
				if (ch == elem) return true;
		return false;
	}

	string first_name, last_name;
	int age;
	string invalid_chars = ";:\"\'[]*&^%&$#@!";
};

inline istream& operator>>(istream& is, Person& p)
{
	string first, last, age;
	is >> first >> last >> age;
	p = Person{ first, last, stoi(age) };
	return is;
}

inline ostream& operator<<(ostream& os, Person& p)
{
	return os << p.get_first_name() << " " << p.get_last_name() << " " << p.get_age();
}

class Drill15 : Drill
{
public:
	void start() override
	{
		function_grapsh();
		class_drill();
	}

	void function_grapsh()
	{
		Simple_window win{ Point{100, 100}, 600, 600, "Function graphs" };

		// Setting up axes
		Axis ax{ Axis::x, Point{100, 300}, 400, 20, "1 = = 20 pixels" };
		Axis ay{ Axis::y, Point{300, 500}, 400, 20, "1 = = 20 pixels" };

		ax.set_color(Color::red);
		ay.set_color(Color::red);

		win.attach(ax);
		win.attach(ay);

		// Graphing
		Point origo{ win.x_max() / 2, win.y_max() / 2 };
		constexpr double min_range = -10.0;
		constexpr double max_range = 11.0;
		constexpr int length = 400;
		constexpr double scale = 20.0;

		// Functions
		// For some reason Functions work only when the first parameter is specifically a lamdba expression with a return value
		Function first{ [](double x) -> double { return 1.0; }, min_range, max_range, origo, length };
		first.set_color(Color::black);
		win.attach(first);

		Function second{ [](double x) -> double { return 1.0; }, min_range, max_range, origo, length, scale, scale };
		second.set_color(Color::black);
		win.attach(second);

		Function slope{ [](double x) -> double { return x / 2.0; }, min_range, max_range, origo, length, scale, scale };
		slope.set_color(Color::black);
		win.attach(slope);
		// slope label
		Text slope_label{ Point{100, 400 - 25}, "x/2" };
		slope_label.set_color(Color::black);
		win.attach(slope_label);

		Function square{ [](double x) -> double { return x * x; }, min_range, max_range, origo, length, scale, scale };
		square.set_color(Color::black);
		win.attach(square);

		Function cosine{ [](double x) -> double { return cos(x); }, min_range, max_range, origo, length, scale, scale };
		cosine.set_color(Color::blue);
		win.attach(cosine);

		Function sloping_cos{ [](double x) -> double {return cos(x) + x / 2.0; }, min_range, max_range, origo, length, scale, scale };
		sloping_cos.set_color(Color::black);
		win.attach(sloping_cos);

		win.wait_for_button();
	}

	void class_drill()
	{
		// Commented out because of the first/last name changes
		//cout << "Task 1" << endl;
		//Person goofy{ "Goofy", 63 };
		//cout << "Name: " << goofy.get_name() << "\nAge: " << goofy.get_age() << "\n\n";

		vector<Person> input_people;

		cout << "Input three people (first_name last_name age):" << endl;
		for (int i = 0; i < 3; i++)
		{
			Person input;
			cin >> input;
			input_people.push_back(input);
		}

		cout << "\nPeople input:" << endl;
		for (Person pers : input_people) cout << pers << endl;

		cin.get();
		cin.get();
	}
};
