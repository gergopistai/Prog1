#include "../Drill.h"

struct Lines_window : Window
{
	Lines_window(Point xy, int w, int h, const string& title) :
		Window(xy, w, h, title),
		next_button{ Point{x_max() - 150, 0 }, 70, 20, "Next point",
			[](Address, Address pw) { reference_to<Lines_window>(pw).next(); } },
		quit_button{ Point{ x_max() - 70, 0 }, 70, 20, "Quit",
			[](Address, Address pw) { reference_to<Lines_window>(pw).quit(); } },
		next_x{ Point{ x_max() - 310, 0 }, 50, 20, "next x:" },
		next_y{ Point{x_max() - 210, 0}, 50, 20, "next_y:" },
		xy_out{ Point{100, 0}, 100, 20, "current (x,y):" },
		color_menu{ Point{x_max() - 70,30}, 70, 20, Menu::vertical, "color"},
		menu_button{ Point{x_max() - 80, 30}, 80, 20, "color menu",
			[](Address, Address pw) { reference_to<Lines_window>(pw).menu_pressed(); } },
		style_menu{ Point{x_max() - 70, 30 * 2}, 70, 20, Menu::vertical, "style"},
		style_button{Point{x_max() - 80, 30 * 2}, 80, 20, "style menu",
			[](Address, Address pw) { reference_to<Lines_window>(pw).style_menu_pressed(); } }
	{
		// IO Boxes
		attach(next_x);
		attach(next_y);
		attach(xy_out);
		// Top Right Buttons
		attach(next_button);
		attach(quit_button);
		xy_out.put("no point");
		// Color Menu
		color_menu.attach(new Button{ Point{0, 0}, 0, 0, "red", cb_red });
		color_menu.attach(new Button{ Point{0, 0}, 0, 0, "blue", cb_blue });
		color_menu.attach(new Button{ Point{0, 0}, 0, 0, "black", cb_black });
		attach(color_menu);
		color_menu.hide();
		attach(menu_button);
		// Style Menu
		style_menu.attach(new Button{ Point{0, 0}, 0, 0, "solid", cb_solid });
		style_menu.attach(new Button{ Point{0, 0}, 0, 0, "dash", cb_dash });
		style_menu.attach(new Button{ Point{0, 0}, 0, 0, "dot", cb_dot });
		style_menu.attach(new Button{ Point{0, 0}, 0, 0, "dashdot", cb_dashdot });
		style_menu.attach(new Button{ Point{0, 0}, 0, 0, "dashdotdot", cb_dashdotdot });
		attach(style_menu);
		style_menu.hide();
		attach(style_button);
		// Lines
		attach(lines);
	}

private:
	Open_polyline lines;

	// IO Boxes
	In_box next_x;
	In_box next_y;
	Out_box xy_out;

	// Top Right Buttons
	Button next_button;
	void next()
	{
		int x = next_x.get_int();
		int y = next_y.get_int();
		lines.add(Point{ x, y });

		ostringstream ss;
		ss << '(' << x << ',' << y << ')';
		xy_out.put(ss.str());

		redraw();
	}

	Button quit_button;
	void quit() { hide(); }

	// Color Menu
	Menu color_menu;
	Button menu_button;
	void menu_pressed() { menu_button.hide(); color_menu.show(); hide_style_menu(); style_button.hide(); }

	void change(Color c) { lines.set_color(c); }
	void hide_menu() { color_menu.hide(); menu_button.show(); style_button.show(); }

	void red_pressed() { change(Color::red); hide_menu(); }
	static void cb_red(Address, Address pw) { reference_to<Lines_window>(pw).red_pressed(); }

	void blue_pressed() { change(Color::blue); hide_menu(); }
	static void cb_blue(Address, Address pw) { reference_to<Lines_window>(pw).blue_pressed(); }

	void black_pressed() { change(Color::black); hide_menu(); }
	static void cb_black(Address, Address pw) { reference_to<Lines_window>(pw).black_pressed(); }

	// Line Style Menu
	Menu style_menu;
	Button style_button;
	void style_menu_pressed() { hide_menu(); style_button.hide(); style_menu.show(); }

	void change_style(Line_style style) { lines.set_style(style); }
	void hide_style_menu() { style_menu.hide(); style_button.show(); }

	void solid_pressed() { change_style(Line_style::solid); hide_style_menu(); }
	static void cb_solid(Address, Address pw) { reference_to<Lines_window>(pw).solid_pressed(); }

	void dash_pressed() { change_style(Line_style::dash); hide_style_menu(); }
	static void cb_dash(Address, Address pw) { reference_to<Lines_window>(pw).dash_pressed(); }

	void dot_pressed() { change_style(Line_style::dot); hide_style_menu(); }
	static void cb_dot(Address, Address pw) { reference_to<Lines_window>(pw).dot_pressed(); }

	void dashdot_pressed() { change_style(Line_style::dashdot); hide_style_menu(); }
	static void cb_dashdot(Address, Address pw) { reference_to<Lines_window>(pw).dashdot_pressed(); }

	void dashdotdot_pressed() { change_style(Line_style::dashdotdot); hide_style_menu(); }
	static void cb_dashdotdot(Address, Address pw) { reference_to<Lines_window>(pw).dashdotdot_pressed(); }

};

class Drill16 : Drill
{
public:
	void start() override
	{
		Lines_window lw{ Point{100, 100}, 640, 480, "Drill 16" };
		gui_main();
	}
};