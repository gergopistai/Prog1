#include "../Drill.h"

struct Drill13 : Drill
{
	void start()
	{
		using namespace Graph_lib;
		Simple_window win{ Point{100, 100}, 1000, 800, "Drill 13" };

		Point start_pos{ 0, 0 };
		int rect_size = 100;
		int grid_dimension = 8;
		Vector_ref<Graph_lib::Rectangle> grid;

		for (int y = 0; y < grid_dimension; y++)
			for (int x = 0; x < grid_dimension; x++)
			{
				Point pos = start_pos + Point{ rect_size, rect_size } * Point{ x, y };
				grid.push_back(new Graph_lib::Rectangle{ pos, rect_size, rect_size });
			}

		for (int i = 0; i < grid.size(); i++)
		{
			if (i % 9 == 0) grid[i].set_fill_color(Color::red);
			else grid[i].set_fill_color(Color::black);
			win.attach(grid[i]);
		}

		Image img1{ Point{300, 0}, "image.jpg" };
		win.attach(img1);

		Image img2{ start_pos + Point{rect_size, rect_size} * Point{5, 0}, "image.jpg" };
		win.attach(img2);

		Image img3{ start_pos + Point{rect_size, rect_size} * Point{0, 3}, "image.jpg" };
		win.attach(img3);

		Image img_mark{ start_pos, "image_mark.jpg" };
		win.attach(img_mark);

		int mark_index = 0;
		while (win.wait_for_button())
		{
			mark_index = mark_index + 1 == grid.size() ? 0 : mark_index + 1;

			Point init_pos = img_mark.get_pos();
			Point target_pos = grid[mark_index].get_pos();
			Point difference = Point{ 0, 0 };

			if (target_pos.x != init_pos.x)
			{
				difference.x = target_pos.x > init_pos.x ? target_pos.x - init_pos.x : -(init_pos.x - target_pos.x);
			}
			if (target_pos.y != init_pos.y)
			{
				difference.y = target_pos.y > init_pos.y ? target_pos.y - init_pos.y : -(init_pos.y - target_pos.y);
			}

			img_mark.move(difference.x, difference.y);
		}
	}
};