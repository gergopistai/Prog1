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
		Button* d12 = new Button{ Point{ 5, 5 }, 70, 20, "Drill 12",
			[](Address, Address pw) {reference_to<Main_window>(pw).start_drill(12); } };
		attach(*d12);

		Button* d13 = new Button{ Point{ 5, 25 + 1}, 70, 20, "Drill 13",
			[](Address, Address pw) {reference_to<Main_window>(pw).start_drill(13); } };
		attach(*d13);

		Button* d14 = new Button{ Point{ 5, 45 + 2}, 70, 20, "Drill 14",
			[](Address, Address pw) {reference_to<Main_window>(pw).start_drill(14); } };
		attach(*d14);

		Button* d15 = new Button{ Point{ 5, 65 + 3}, 70, 20, "Drill 15",
			[](Address, Address pw) {reference_to<Main_window>(pw).start_drill(15); } };
		attach(*d15);

		Button* d16 = new Button{ Point{ 5, 85 + 4}, 70, 20, "Drill 16",
			[](Address, Address pw) {reference_to<Main_window>(pw).start_drill(16); } };
		attach(*d16);

		Button* d19 = new Button{ Point{ 5, 105 + 5}, 70, 20, "Drill 19",
			[](Address, Address pw) {reference_to<Main_window>(pw).start_drill(19); } };
		attach(*d19);

		Button* d20 = new Button{ Point{ 5, 125 + 6}, 70, 20, "Drill 20",
			[](Address, Address pw) {reference_to<Main_window>(pw).start_drill(20); } };
		attach(*d20);

		Button* d21 = new Button{ Point{ 5, 145 + 7}, 70, 20, "Drill 21",
			[](Address, Address pw) {reference_to<Main_window>(pw).start_drill(21); } };
		attach(*d21);

		Button* d27 = new Button{ Point{ 5, 165 + 8}, 70, 20, "Drill 27",
			[](Address, Address pw) {reference_to<Main_window>(pw).start_drill(27); } };
		attach(*d27);
		// Exercises
		Button* ex12 = new Button{ Point{80, 5}, 80, 20, "Exercise 12",
			[](Address, Address pw) {reference_to<Main_window>(pw).start_exercise(); } };
		attach(*ex12);
		// Other buttons
		Button* exit = new Button{ Point{ x_max() - 75, 5}, 70, 20, "Exit",
			[](Address, Address pw) {reference_to<Main_window>(pw).exit(); } };
		attach(*exit);
	}

	void exit()
	{
		hide();
	}

	void start_exercise()
	{
		Exercise12 e12;
		e12.start();
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

			}
		}
	}
};
