#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>
#include "Simple_window.h"
#include "Graph.h"

const double PI = 3.14159;

int main() {
	try {
		using namespace  Graph_lib;
		Graph_lib::Point tl{ 100, 100 }; // top left corner. Window position on screen
		Simple_window win{ tl, 600, 400, "Canvas" };


		Graph_lib::Open_polyline poly;
		int start_x = 300;
		int start_y = 200;
		int r = 100;

		for (double i = 0; i <= (PI * 2); i += 0.01) {
			int x = r * cos(i);
			int y = r * sin(i);

			std::cout << x << " " << y << "\n";
			poly.add(Point{ start_x + x, start_y - y });
		}

		poly.set_color(Color::yellow);
		poly.set_style(Line_style(Line_style::solid, 4));
		win.attach(poly);

		win.set_label("Canvas");
		win.wait_for_button(); // display to screen
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
}