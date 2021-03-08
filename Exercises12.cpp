#include "week02-06/GUI/Simple_window.h"
#include "week02-06/GUI/Graph.h"

int main()
{
	using namespace Graph_lib;

	Simple_window win{ Point{100, 100}, 800, 600, "Exercises" };

	// Exercise 1.
	Graph_lib::Rectangle blue_rect{ Point{50, 50}, 100, 125 };
	blue_rect.set_color(Color::blue);
	win.attach(blue_rect);

	Graph_lib::Polygon red_poly_rect;
	red_poly_rect.add(Point{ 50, 200 });
	red_poly_rect.add(Point{ 50, 325 });
	red_poly_rect.add(Point{ 150, 325 });
	red_poly_rect.add(Point{ 150, 200 });
	red_poly_rect.set_color(Color::red);
	win.attach(red_poly_rect);

	// Exercise 2.
	Graph_lib::Rectangle text_rect{ Point{225, 50}, 100, 30 };
	text_rect.set_color(Color::black);
	win.attach(text_rect);

	Text howdy{ Point{250, 70}, "Howdy!" };
	howdy.set_color(Color::black);
	win.attach(howdy);

	// Exercise 3.
	Text initial1{ Point{225, 220}, "P" };
	initial1.set_color(Color::magenta);
	initial1.set_font(Font::times_bold);
	initial1.set_font_size(150);
	win.attach(initial1);

	Text initial2{ Point{310, 220}, "G" };
	initial2.set_color(Color::cyan);
	initial2.set_font(Font::times_bold);
	initial2.set_font_size(150);
	win.attach(initial2);

	// Exercise 4.
	Point tic_tac_start_pos{ 50, 375 };
	Point tic_tac_size{ 30, 30 };

	Vector_ref<Graph_lib::Rectangle> grid;

	int counter = 0;
	for (int y = 0; y < 3; y++)
		for (int x = 0; x < 3; x++)
		{
			Point rect_pos{ tic_tac_start_pos.x + tic_tac_size.x * x, tic_tac_start_pos.y + tic_tac_size.y * y };
			grid.push_back(new Graph_lib::Rectangle{ rect_pos, tic_tac_size.x, tic_tac_size.y });
			(counter % 2 == 0) ? grid[counter].set_fill_color(Color::white) : grid[counter].set_fill_color(Color::red);
			win.attach(grid[counter]);
			counter++;
		}

	// Exercise 5.
	// Different window
	double inch = 94;

	Simple_window ex5_win{ Point{120, 120}, 300, 300, "Exercise 3" };

	Graph_lib::Rectangle frame{ Point{10, 10}, int(3 * ex5_win.x_max() / 4) , int(2 * ex5_win.y_max() / 3) };
	frame.set_style(Line_style(Line_style::solid, inch / 4));
	frame.set_color(Color::red);
	ex5_win.attach(frame);

	// Exercise 6
	Simple_window unfitting_win{ Point{140, 140}, 1600, 1600, "Unfitting" };

	Circle unfitting_circle{ Point{300, 300}, 900 };
	unfitting_circle.set_color(Color::black);
	unfitting_win.attach(unfitting_circle);

	// Exercise 7
	Simple_window house_win{ Point(120, 120), 400, 400, "House" };

	Open_polyline house{ Point{100, 100} };
	house.set_color(Color::black);
	// House & Door
	house.add(Point{ 200, 100 });
	house.add(Point{ 200, 200 });
	house.add(Point{ 140, 200 });
	house.add(Point{ 140, 160 });
	house.add(Point{ 160, 160 });
	house.add(Point{ 160, 200 });
	house.add(Point{ 100, 200 });
	house.add(Point{ 100, 100 });
	house.add(Point{ 200, 100 });
	// Roof
	house.add(Point{ 100, 100 });
	house.add(Point{ 150, 40 });
	house.add(Point{ 200, 100 });
	// Chimney
	house.add(Point{ 175, 70 });
	house.add(Point{ 175, 50 });
	house.add(Point{ 195, 50 });
	house.add(Point{ 195, 93 });

	Closed_polyline window_shape{ Point{110, 130} };
	window_shape.set_color(Color::black);
	window_shape.add(Point{ 125, 130 });
	window_shape.add(Point{ 125, 145 });
	window_shape.add(Point{ 110, 145 });

	Vector_ref<Line> smoke;
	Point chimney_pos{ 175, 50 };

	for (int i = 0; i < 5; i++)
	{
		smoke.push_back(new Line{ Point{chimney_pos.x + i * 4, chimney_pos.y}, Point{chimney_pos.x + i * 4 + 5, chimney_pos.y - 15} });
		smoke[i].set_color(Color::black);
		house_win.attach(smoke[i]);
	}

	house_win.attach(house);
	house_win.attach(window_shape);

	// Exercise 8
	Simple_window olympic_win{ Point{160, 160}, 800, 500, "Olympic rings" };
	int olympic_width = 100;

	Circle blue{ Point{150, 150}, olympic_width };
	blue.set_style(Line_style(Line_style::solid, 8));
	blue.set_color(Color::blue);
	olympic_win.attach(blue);

	Circle black{ Point{275, 150}, olympic_width };
	black.set_style(Line_style(Line_style::solid, 8));
	black.set_color(Color::black);
	olympic_win.attach(black);

	Circle red{ Point{400, 150}, olympic_width };
	red.set_style(Line_style(Line_style::solid, 8));
	red.set_color(Color::red);
	olympic_win.attach(red);

	Circle yellow{ Point{200, 275}, olympic_width };
	yellow.set_style(Line_style(Line_style::solid, 8));
	yellow.set_color(Color::yellow);
	olympic_win.attach(yellow);

	Circle green{ Point{350, 275}, olympic_width };
	green.set_style(Line_style(Line_style::solid, 8));
	green.set_color(Color::green);
	olympic_win.attach(green);

	// Exercise 9
	Simple_window photo_win{ Point{120, 120}, 550, 400, "Lunar rat" };
	Image photo{ Point{25, 25}, "lunar_rat.jpg" };
	Text photo_label{ Point{25, 525}, "Lunar rat" };
	photo_label.set_color(Color::black);
	photo_win.attach(photo);
	photo_win.attach(photo_label);

	photo_win.wait_for_button();
	win.wait_for_button();
	olympic_win.wait_for_button();
	ex5_win.wait_for_button();
	house_win.wait_for_button();
	unfitting_win.wait_for_button();
}