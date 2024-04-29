#include "V2D.h"

V2D::V2D()
{
	x = 0;
	y = 0;
	mag = 0.0;
}

V2D::V2D(int vect_x, int vect_y)
{
	this->x = vect_x;
	this->y = vect_y;
	this->mag = 0.0;
}

V2D& V2D::Add(const V2D& vector)
{
	this->x += vector.x;
	this->y += vector.y;
	this->mag = 0.0;

	return *this;
}

V2D& V2D::Sub(const V2D& vector)
{
	this->x -= vector.x;
	this->y -= vector.y;
	this->mag = 0.0;

	return *this;
}

V2D& V2D::Div(const V2D& vector)
{
	this->x /= vector.x;
	this->y /= vector.y;
	this->mag = 0.0;

	return *this;
}

V2D& V2D::Mul(const V2D& vector)
{
	this->x /= vector.x;
	this->y /= vector.y;
	this->mag = 0.0;

	return *this;
}

V2D& V2D::operator+=(const V2D& vector)
{
	return this->Add(vector);
}

V2D& V2D::operator-=(const V2D& vector)
{
	return this->Sub(vector);
}

V2D& V2D::operator/=(const V2D& vector)
{
	return this->Div(vector);
}

V2D& V2D::operator*=(const V2D& vector)
{
	return this->Mul(vector);
}
