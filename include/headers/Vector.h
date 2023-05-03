#pragma once

#include <iostream>

struct Vectorc
{
	Vectorc()
	:x(0.0f), y(0.0f)
	{}

	Vectorc(float p_x, float p_y)
	:x(p_x), y(p_y)
	{}

	void print()
	{
		std::cout << x << ", " << y << std::endl;
	}
	
	float x, y;
};