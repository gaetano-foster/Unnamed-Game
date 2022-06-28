#include "Vector2.hh"
#include "cmath"

Vector2i::Vector2i() 
    : x(0)
    , y(0) { }

Vector2i::Vector2i(int _x, int _y) 
    : x(_x)
    , y(_y) { }

int Vector2i::mag() {
    return sqrt(x * x + y * y) > 0 ? sqrt(x * x + y * y) : 1;	                         
}

Vector2i Vector2i::norm() {
    return Vector2i(x/mag(), y/mag());	     
}

int Vector2i::dot(const Vector2i& other) {
    return this->x * other.x + this->y * other.y;             
}

int Vector2i::cross(const Vector2i& other) {
    return this->x * other.y - this->y * other.x;             
}

Vector2i  Vector2i::operator+ (const Vector2i& other) {return Vector2i(this->x + other.x, this->y + other.y); }
Vector2i  Vector2i::operator- (const Vector2i& other) {return Vector2i(this->x - other.x, this->y - other.y); }
Vector2i  Vector2i::operator* (const int& other)           {return Vector2i(this->x * other, this->y * other);	 }
Vector2i  Vector2i::operator/ (const int& other)           {return Vector2i(this->x / other, this->y / other);	 }
Vector2i& Vector2i::operator+=(const Vector2i& other) {this->x += other.x; this->y += other.y; return *this;     }
Vector2i& Vector2i::operator-=(const Vector2i& other) {this->x -= other.x; this->y -= other.y; return *this;     }
Vector2i& Vector2i::operator*=(const int& other)           {this->x *= other; this->y *= other; return *this;	     }
Vector2i& Vector2i::operator/=(const int& other)           {this->x /= other; this->y /= other; return *this;	     }