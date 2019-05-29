#pragma once
#include <ostream>

class Rectangle
{
	int width{}, height{};
public:
	Rectangle();
	Rectangle(int width, int height) : width(width), height(height) {  }

	int returnArea();



	~Rectangle();
};
