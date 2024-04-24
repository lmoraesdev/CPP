# include "Triangle.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Triangle triangle = Triangle(a, b, c);

	// Check if the point is inside the triangle
	return(triangle.containsPoint(point));
}
