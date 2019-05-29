#include "pch.h"
#include "Rectangle.h"

Rectangle::Rectangle()
{
	width = 100;
	height = 100;


}

int Rectangle::returnArea()
{
	return width * height;
}




Rectangle::~Rectangle()
{
	
}
