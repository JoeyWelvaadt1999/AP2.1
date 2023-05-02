#pragma once

#include <iostream>

class Vector {
    public:
        int x;
        int y;
        Vector();
        Vector(int x, int y);
        
        friend Vector operator+(Vector lhs, const Vector rhs);

        Vector& operator+=(const Vector rhs);

        friend Vector operator*(Vector v, int m);
        friend Vector operator*(int m, Vector v);

        Vector& operator*=(const int m);

        friend std::ostream& operator<<(std::ostream& os , Vector v);
};