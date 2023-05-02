#include "include/Vector.hpp"

Vector::Vector() {
    this->x = 0;
    this->y = 0;
}

Vector::Vector(int x, int y) {
    this->x = x;
    this->y = y;
}


Vector operator+(Vector lhs, const Vector rhs) {
    return Vector(lhs.x + rhs.x, lhs.y + rhs.y);
}

Vector& Vector::operator+=(const Vector rhs) {
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
}

Vector operator*(Vector v, int m) {
    return Vector(v.x * m, v.y * m);
}

Vector operator*(int m, Vector v) {
    return Vector(v.x * m, v.y * m);
}


Vector& Vector::operator*=(const int m) {
    this->x *= m;
    this->y *= m;
    return *this;
}

std::ostream &operator<<(std::ostream& os, Vector v) {
    os << "Your X is: " << std::to_string(v.x) << " and your Y is: " << std::to_string(v.y) << std::endl;
    return os;
}