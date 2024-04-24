#ifndef TRIANGLE_HPP
# define TRIANGLE_HPP

# include "Point.hpp"

class Triangle {
private:
	Point _a;
	Point _b;
	Point _c;
public:
	// Constructors & Destructors
	Triangle(void);
	Triangle(const Point &a, const Point &b, const Point &c);
	Triangle(const Triangle &other);
	~Triangle(void);

	// Assignment Operator overload
	Triangle	&operator=(const Triangle &other);

	// Getters
	Point	getA(void) const;
	Point	getB(void) const;
	Point	getC(void) const;

	// Methods
	bool	containsPoint(Point const &p) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
