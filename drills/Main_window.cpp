#include "Drill12.cpp"
#include "Exercises12.cpp"
#include "Drill13.cpp"
#include "Drill14.cpp"
#include "Drill15.cpp"
#include "Drill16.cpp"

class Main_window : Window
{
public:
	Main_window(Point xy, int w, int h, const string& title) :
		Window(xy, w, h, title)
	{
		// Drills
		constexpr int drill_x = 70;
		constexpr int drill_y = 20;
		constexpr int drill_pos_x = 5;
		int d_separ = 0;

		Button* d12 = new Button{ Point{ drill_pos_x, 5 + d_separ++ }, drill_x, drill_y, "Drill 12",
			[](Address, Address pw) {reference_to<Main_window>(pw).start_drill(12); } };
		attach(*d12);

		Button* d13 = new Button{ Point{ drill_pos_x, 25 + d_separ++ }, drill_x, drill_y, "Drill 13",
			[](Address, Address pw) {reference_to<Main_window>(pw).start_drill(13); } };
		attach(*d13);

		Button* d14 = new Button{ Point{ drill_pos_x, 45 + d_separ++ }, drill_x, drill_y, "Drill 14",
			[](Address, Address pw) {reference_to<Main_window>(pw).start_drill(14); } };
		attach(*d14);

		Button* d15 = new Button{ Point{ drill_pos_x, 65 + d_separ++ }, drill_x, drill_y, "Drill 15",
			[](Address, Address pw) {reference_to<Main_window>(pw).start_drill(15); } };
		attach(*d15);

		Button* d16 = new Button{ Point{ drill_pos_x, 85 + d_separ++ }, drill_x, drill_y, "Drill 16",
			[](Address, Address pw) {reference_to<Main_window>(pw).start_drill(16); } };
		attach(*d16);

		Button* d19 = new Button{ Point{ drill_pos_x, 105 + d_separ++ }, drill_x, drill_y, "Drill 19",
			[](Address, Address pw) {reference_to<Main_window>(pw).start_drill(19); } };
		attach(*d19);

		Button* d20 = new Button{ Point{ drill_pos_x, 125 + d_separ++ }, drill_x, drill_y, "Drill 20",
			[](Address, Address pw) {reference_to<Main_window>(pw).start_drill(20); } };
		attach(*d20);

		Button* d21 = new Button{ Point{ drill_pos_x, 145 + d_separ++ }, drill_x, drill_y, "Drill 21",
			[](Address, Address pw) {reference_to<Main_window>(pw).start_drill(21); } };
		attach(*d21);

		Button* d27 = new Button{ Point{ drill_pos_x, 165 + d_separ++ }, drill_x, drill_y, "Drill 27",
			[](Address, Address pw) {reference_to<Main_window>(pw).start_drill(27); } };
		attach(*d27);

		// Exercises
		Button* ex12 = new Button{ Point{80, 5}, 80, 20, "Exercise 12",
			[](Address, Address pw) {reference_to<Main_window>(pw).start_exercise(12); } };
		attach(*ex12);

		// Other buttons
		Button* exit = new Button{ Point{ x_max() - 75, 5}, 70, 20, "Exit",
			[](Address, Address pw) {reference_to<Main_window>(pw).exit(); } };
		attach(*exit);
	}

private:
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
			}
			default:
			{
				cout << "Not implemented yet." << endl;
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
			default:
			{
				cout << "Not implemented yet."<< endl;
				break;
			}
		}
	}
};
