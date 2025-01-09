#include "Shape.h"
#include <stdexcept>

using namespace std;

Shape::Shape(){
	color = "red";
}

Shape::Shape(string c){
	set_color(c);
}

std::string Shape::get_color() const{
	return color;
}

void Shape::set_color(string c){
	if(c == "red" || c == "green" || c == "blue"){
		color = c;
	}else{
		throw invalid_argument("Color no valido, solo rd, green y blue " + c);
	}
}
