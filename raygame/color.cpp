#include "color.h"

MyColor::MyColor() {
	r = 0; g = 0; b = 0;
}
MyColor::MyColor(int red, int green, int blue, int alpha) {
	r = red; b = blue, g = green; a = alpha;
}

MyColor MyColor::operator+(const MyColor &rhs) const {
	MyColor temp(r+rhs.r,g+rhs.g,b+rhs.b,a+rhs.a);
	return temp;
}
MyColor MyColor::operator-(const MyColor &rhs) const {
	MyColor temp(r - rhs.r, g - rhs.g, b - rhs.b, a - rhs.a);
	return temp;
}
MyColor MyColor::operator*(const MyColor &rhs) const {
	MyColor temp(r * rhs.r, g * rhs.g, b * rhs.b, a * rhs.a);
	return temp;
}
MyColor MyColor::operator/(const MyColor &rhs) const {
	MyColor temp(r / rhs.r, g / rhs.g, b / rhs.b, a / rhs.a);
	return temp;
}

MyColor& MyColor::operator+=(const MyColor &rhs) {
	MyColor temp(r + rhs.r, g + rhs.g, b + rhs.b, a + rhs.a);
	r += rhs.r;
	g += rhs.g;
	b += rhs.b;
	a += rhs.a;
	return temp;
}
MyColor& MyColor::operator-=(const MyColor &rhs) {
	MyColor temp(r - rhs.r, g - rhs.g, b - rhs.b, a - rhs.a);
	r -= rhs.r;
	g -= rhs.g;
	b -= rhs.b;
	a -= rhs.a;
	return temp;
}
MyColor& MyColor::operator*=(const MyColor &rhs) {
	MyColor temp(r * rhs.r, g * rhs.g, b * rhs.b, a * rhs.a);
	r *= rhs.r;
	g *= rhs.g;
	b *= rhs.b;
	a *= rhs.a;
	return temp;
}
MyColor& MyColor::operator/=(const MyColor &rhs) {
	MyColor temp(r / rhs.r, g / rhs.g, b / rhs.b, a / rhs.a);
	r /= rhs.r;
	g /= rhs.g;
	b /= rhs.b;
	a /= rhs.a;
	return temp;
}

bool MyColor::operator==(const MyColor &rhs) const {
	return r == rhs.r&&g == rhs.g&&b == rhs.b&&a == rhs.a;
}
bool MyColor::operator!=(const MyColor &rhs) const {
	return r != rhs.r&&g != rhs.g&&b != rhs.b&&a != rhs.a;
}