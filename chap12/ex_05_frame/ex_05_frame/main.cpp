#include <stdexcept>
#include <string>
#include <vector>
#include "Simple_window.h"
#include "Graph.h"

const std::string IMG_DIR = "../../../includes/graphics/images/";

int main() {
	using namespace  Graph_lib;
	Graph_lib::Point tl{ 100, 100 }; // top left corner. Window position on screen
	Simple_window win{ tl, 600, 400, "Canvas" };

	Graph_lib::Rectangle r{ Point{100, 100}, 100, 50 };
	r.set_color(Color::black);

	Graph_lib::Rectangle frame{ Point{76, 76}, 148, 98 };
	frame.set_color(Color::red);

	win.attach(r);
	win.attach(frame);
	win.set_label("Canvas");
	win.wait_for_button(); // display to screen
}