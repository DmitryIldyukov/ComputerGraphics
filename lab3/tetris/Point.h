#pragma once

template <typename T>
struct Point {
	T x;
	T y;
	Point(T x, T y)
		: x(x)
		, y(y)
	{}
};

using PointF = Point<float>;
using PointI = Point<int>;