#pragma once

// Size: 16
class Color {
public:
	float r;	// 0-4
	float g;	// 4-8
	float b;	// 8-12
	float a;	// 12-16
	
	static const Color BLACK;
	static const Color BLUE;
	static const Color CYAN;
	static const Color GREEN;
	static const Color GREY;
	static const Color NIL;
	static const Color ORANGE;
	static const Color PURPLE;
	static const Color RED;
	static const Color SHADE_DOWN;
	static const Color SHADE_NORTH_SOUTH;
	static const Color SHADE_UP;
	static const Color SHADE_WEST_EAST;
	static const Color WHITE;
	static const Color YELLOW;
	
	static Color fromHSB(float, float, float);
	
	int toABGR() const;
	int toARGB() const;
};