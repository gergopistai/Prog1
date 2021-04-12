#include "Drill.h"

struct Drill12 : Drill
{
	void start() override
	{
		using namespace Graph_lib;

		Simple_window win{ Point {100, 100}, 600, 400, "My window" };

		// 12.7.3
		// Axis
		Axis xa{ Axis::x, Point{20, 320}, 280, 10, "x axis" };
		xa.set_color(Color::magenta);
		win.attach(xa);

		Axis ya{ Axis::y, Point{20, 320}, 280, 10, "y axis" };
		ya.set_color(Color::cyan);
		win.attach(ya);

		// 12.7.4
		// Function
		Function sine{ sin, 0, 100, Point{20, 150}, 30, 50, 50 };
		sine.set_color(Color::black);
		win.attach(sine);

		// 12.7.5
		// Polygons
		Graph_lib::Polygon poly;

		poly.add(Point{ 300, 200 });
		poly.add(Point{ 350, 100 });
		poly.add(Point{ 700, 200 });

		poly.set_color(Color::red);
		poly.set_style(Line_style(Line_style::dash, 4));

		win.attach(poly);

		// 12.7.6
		// Rectangle
		Graph_lib::Rectangle rect{ Point{200, 200}, 100, 50 };

		rect.set_color(Color::black);
		rect.set_fill_color(Color::yellow);
		rect.set_style(Line_style::dashdotdot);

		win.attach(rect);

		Closed_polyline poly_rect;

		poly_rect.add(Point{ 100, 50 });
		poly_rect.add(Point{ 200, 50 });
		poly_rect.add(Point{ 200, 100 });
		poly_rect.add(Point{ 100, 100 });
		poly_rect.add(Point{ 50, 75 });
		poly_rect.add(Point{ 5, 7 });

		poly_rect.set_color(Color::black);
		poly_rect.set_fill_color(Color::green);
		poly_rect.set_style(Line_style(Line_style::dash, 2));

		win.attach(poly_rect);

		// 12.7.8
		// Text
		Text txt{ Point{150, 150}, "Hello graphical world!" };

		txt.set_color(Color::black);
		txt.set_font(Font::times_bold);
		txt.set_font_size(200);

		win.attach(txt);

		// 12.7.9
		// Image
		Image img{ Point{380, 150}, "lunar_rat.jpg" };
		win.attach(img);

		// 12.7.10
		// Much more
		Circle cir{ Point{100, 200}, 50 };
		cir.set_color(Color::black);
		win.attach(cir);

		Graph_lib::Ellipse ell{ Point(100, 200), 75, 25 };
		ell.set_color(Color::red);
		win.attach(ell);

		Mark mar{ Point{100, 200}, 'x' };
		mar.set_color(Color::black);
		win.attach(mar);

		ostringstream oss;
		oss << "screen size: " << x_max() << "*" << y_max()
			<< "; window size: " << win.x_max() << "*" << win.y_max();

		Text sizes{ Point{100, 20}, oss.str() };
		sizes.set_color(Color::black);
		win.attach(sizes);

		win.wait_for_button();
	}
};