#pragma once
class MyColor
{
public:
	MyColor();
	MyColor(int red, int green, int blue, int alpha);

	int r;
	int g;
	int b;
	int a = 256;

	// arithmetic operators
	MyColor operator+(const MyColor &rhs) const;  // returns an additive blend of the two colors
	MyColor operator-(const MyColor &rhs) const;  // returns a subtractive blend of the two colors
	MyColor operator*(const MyColor &rhs) const;  // returns a multiply blend of the two colors
	MyColor operator/(const MyColor &rhs) const;  // returns a divide blend of the two colors

	// compound arithmetic operator
	MyColor& operator+=(const MyColor &rhs);      // adds and assigns the sum of the two colors to the lhs
	MyColor& operator-=(const MyColor &rhs);      // subtracts and assigns the difference of the two colors to the lhs
	MyColor& operator*=(const MyColor &rhs);      // multiplies and assigns the product of the two colors to the lhs
	MyColor& operator/=(const MyColor &rhs);      // divides and assigns the quotient of the two colors to the lhs

	bool operator==(const MyColor &rhs) const;    // returns true if the two colors are identical
	bool operator!=(const MyColor &rhs) const;    // returns true if the two colors are NOT identical

	MyColor operator!() const;                    // returns a negative version of the color (think film negatives)
};