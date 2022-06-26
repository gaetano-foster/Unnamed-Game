#ifndef __VECTOR2F_H__
#define __VECTOR2F_H__

struct Vector2f {
public:
	Vector2f();
	Vector2f(float x, float y);

public:
	float mag();
	Vector2f norm();
	float dot(const Vector2f& other);
	float cross(const Vector2f& other);

public:
	Vector2f  operator+(const Vector2f& other);
	Vector2f  operator-(const Vector2f& other);
	Vector2f  operator*(const float& other);
	Vector2f  operator/(const float& other);
	Vector2f& operator+=(const Vector2f& other);
	Vector2f& operator-=(const Vector2f& other);
	Vector2f& operator*=(const float& other);
	Vector2f& operator/=(const float& other);

public:
    float x = 0;
	float y = 0;
};
#endif // __VECTOR2F_H__