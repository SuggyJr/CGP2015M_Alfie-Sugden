#ifndef V2D_H
#define V2D_H

class V2D
{
public:
	V2D();
	V2D(int vect_x, int vect_y);

	V2D& Add(const V2D& vector);
	V2D& Sub(const V2D& vector);
	V2D& Div(const V2D& vector);
	V2D& Mul(const V2D& vector);
	V2D& operator+=(const V2D& vector);
	V2D& operator-=(const V2D& vector);
	V2D& operator/=(const V2D& vector);
	V2D& operator*=(const V2D& vector);
	
	int x;
	int y;
	float mag;

};

#endif // !V2D_H