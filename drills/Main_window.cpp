#include "Drill12.cpp"
#include "Exercises12.cpp"
#include "Drill13.cpp"
#include "Drill14.cpp"
#include "Drill15.cpp"
#include "Drill16.cpp"
#include "Drill19.cpp"

class Main_window : Window
{
public:
	Main_window(Point xy, int w, int h, const string& title) :
		Window(xy, w, h, title),
		d12{ Point{ drill_pos_x, 5 + d_separ++ }, drill_x, drill_y, "Drill 12",
			[](Address, Address pw) {reference_to<Main_window>(pw).start_drill(12); } },
		d13{ Point{ drill_pos_x, 25 + d_separ++ }, drill_x, drill_y, "Drill 13",
			[](Address, Address pw) {reference_to<Main_window>(pw).start_drill(13); } },
		d14{ Point{ drill_pos_x, 45 + d_separ++ }, drill_x, drill_y, "Drill 14",
			[](Address, Address pw) {reference_to<Main_window>(pw).start_drill(14); } },
		d15{ Point{ drill_pos_x, 65 + d_separ++ }, drill_x, drill_y, "Drill 15",
			[](Address, Address pw) {reference_to<Main_window>(pw).start_drill(15); } },
		d16{ Point{ drill_pos_x, 85 + d_separ++ }, drill_x, drill_y, "Drill 16",
			[](Address, Address pw) {reference_to<Main_window>(pw).start_drill(16); } },
		d19{ Point{ drill_pos_x, 105 + d_separ++ }, drill_x, drill_y, "Drill 19",
			[](Address, Address pw) {reference_to<Main_window>(pw).start_drill(19); } },
		d20{ Point{ drill_pos_x, 125 + d_separ++ }, drill_x, drill_y, "Drill 20",
			[](Address, Address pw) {reference_to<Main_window>(pw).start_drill(20); } },
		d21{ Point{ drill_pos_x, 145 + d_separ++ }, drill_x, drill_y, "Drill 21",
			[](Address, Address pw) {reference_to<Main_window>(pw).start_drill(21); } },
		d27{ Point{ drill_pos_x, 165 + d_separ++ }, drill_x, drill_y, "Drill 27",
		[](Address, Address pw) {reference_to<Main_window>(pw).start_drill(27); } },
		ex12{ Point{80, 5}, 80, 20, "Exercise 12",
			[](Address, Address pw) {reference_to<Main_window>(pw).start_exercise(12); } },
		exit_btn{ Point{ x_max() - 75, 5}, 70, 20, "Exit",
			[](Address, Address pw) {reference_to<Main_window>(pw).exit(); } }
	{
		// Attaching buttons
		attach(d12);
		attach(d13);
		attach(d14);
		attach(d15);
		attach(d16);
		attach(d19);
		attach(d20);
		attach(d21);
		attach(d27);
		attach(ex12);
		attach(exit_btn);
	}

private:
	const int drill_x = 70;
	const int drill_y = 20;
	const int drill_pos_x = 5;
	int d_separ = 0;

	Button d12;
	Button d13;
	Button d14;
	Button d15;
	Button d16;
	Button d19;
	Button d20;
	Button d21;
	Button d27;
	Button ex12;
	Button exit_btn;

	void exit()
	{
		hide();
	}

	void start_exercise(int num)
	{
		switch (num)
		{
			case 12:
			{
				Exercise12 e12;
				e12.start();
				break;
			}
			default:
			{
				cout << "Not implemented yet." << endl;
				break;
			}
		}
	}

	void start_drill(int num)
	{
		switch (num)
		{
			case 12:
			{
				Drill12 d12;
				d12.start();
				break;
			}
			case 13:
			{
				Drill13 d13;
				d13.start();
				break;
			}
			case 14:
			{
				Drill14 d14;
				d14.start();
				break;
			}
			case 15:
			{
				Drill15 d15;
				d15.start();
				break;
			}
			case 16:
			{
				Drill16 d16;
				d16.start();
				break;
			}
			case 19:
			{
				Drill19 d19;
				d19.start();
				break;
			}
			default:
			{
				cout << "Not implemented yet."<< endl;
				break;
			}
		}
	}
};
