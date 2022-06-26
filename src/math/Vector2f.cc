#include "Vector2f.hh"
#include "cmath"

Vector2f::Vector2f() 
    : x(0)
    , y(0) { }

Vector2f::Vector2f(float _x, float _y) 
    : x(_x)
    , y(_y) { }

float Vector2f::mag() {
    return sqrt(x * x + y * y);	                         
}

Vector2f Vector2f::norm() {
    return Vector2f(x/mag(), y/mag());	     
}

float Vector2f::dot(const Vector2f& other) {
    return this->x * other.x + this->y * other.y;             
}

float Vector2f::cross(const Vector2f& other) {
    return this->x * other.y - this->y * other.x;             
}

Vector2f  Vector2f::operator+ (const Vector2f& other) {return Vector2f(this->x + other.x, this->y + other.y); }
Vector2f  Vector2f::operator- (const Vector2f& other) {return Vector2f(this->x - other.x, this->y - other.y); }
Vector2f  Vector2f::operator* (const float& other)           {return Vector2f(this->x * other, this->y * other);	 }
Vector2f  Vector2f::operator/ (const float& other)           {return Vector2f(this->x / other, this->y / other);	 }
Vector2f& Vector2f::operator+=(const Vector2f& other) {this->x += other.x; this->y += other.y; return *this;     }
Vector2f& Vector2f::operator-=(const Vector2f& other) {this->x -= other.x; this->y -= other.y; return *this;     }
Vector2f& Vector2f::operator*=(const float& other)           {this->x *= other; this->y *= other; return *this;	     }
Vector2f& Vector2f::operator/=(const float& other)           {this->x /= other; this->y /= other; return *this;	     }