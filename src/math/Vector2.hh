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

struct Vector2i {
public:
	Vector2i();
	Vector2i(int x, int y);

public:
	int mag();
	Vector2i norm();
	int dot(const Vector2i& other);
	int cross(const Vector2i& other);

public:
	Vector2i  operator+(const Vector2i& other);
	Vector2i  operator-(const Vector2i& other);
	Vector2i  operator*(const int& other);
	Vector2i  operator/(const int& other);
	Vector2i& operator+=(const Vector2i& other);
	Vector2i& operator-=(const Vector2i& other);
	Vector2i& operator*=(const int& other);
	Vector2i& operator/=(const int& other);

public:
    float x = 0;
	float y = 0;
};
#endif // __VECTOR2F_H__