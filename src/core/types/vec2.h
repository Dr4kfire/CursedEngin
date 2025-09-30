#pragma once


struct vec2
{
    int y;
    int x;

    vec2(int y = 0, int x = 0) : y(y), x(x) {}
};


// Arithmetic operators
inline vec2 operator+(const vec2& a, const vec2& b) 
{
    return vec2(a.x + b.x, a.y + b.y);
}
inline vec2 operator-(const vec2& a, const vec2& b) 
{
    return vec2(a.x - b.x, a.y - b.y);
}
inline vec2 operator*(const vec2& a, const int b) 
{
    return vec2(a.x * b, a.y * b);
}
inline vec2 operator/(const vec2& a, const int b) 
{
    return vec2(a.x / b, a.y / b);
}

// Comparison operators
inline bool operator==(const vec2& a, const vec2& b) 
{
    return (a.x == b.x) && (a.y == b.y);
}
inline bool operator!=(const vec2& a, const vec2& b) 
{
    return !(a == b);
}

// Relational operators
inline bool operator<(const vec2& a, const vec2& b) 
{
    return (a.x < b.x) && (a.y < b.y);
}
inline bool operator<=(const vec2& a, const vec2& b) 
{
    return (a.x <= b.x) && (a.y <= b.y);
}
inline bool operator>(const vec2& a, const vec2& b) 
{
    return (a.x > b.x) && (a.y > b.y);
}
inline bool operator>=(const vec2& a, const vec2& b) 
{
    return (a.x >= b.x) && (a.y >= b.y);
}

// Assignment operators
inline vec2& operator+=(vec2& a, const vec2& b) 
{
    a.x += b.x;
    a.y += b.y;
    return a;
}
inline vec2& operator-=(vec2& a, const vec2& b) 
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}
inline vec2& operator*=(vec2& a, const int b) 
{
    a.x *= b;
    a.y *= b;
    return a;
}
inline vec2& operator/=(vec2& a, const int b) 
{
    a.x /= b;
    a.y /= b;
    return a;
}
