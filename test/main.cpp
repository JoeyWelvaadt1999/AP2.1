#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "include/catch2.hpp"

#include "../src/include/Vector.hpp"

TEST_CASE("Initializing Vectors", "[Vector]") {
    SECTION("Constructor without parameters") {
        Vector v = Vector();
        REQUIRE(v.x == 0);
        REQUIRE(v.y == 0);
    }
    SECTION("Constructor with parameters") {
        Vector v = Vector(3,6);
        REQUIRE(v.x == 3);
        REQUIRE(v.y == 6);
    }
}

TEST_CASE("Adding with vectors", "[Vector]") {
    Vector v1(2, 3);
    Vector v2 (3, 5);
    Vector v3 = Vector();

    Vector v4 = v1 + v2;
    Vector v5 = v2 + v3;

    REQUIRE(v4.x == 5);
    REQUIRE(v4.y == 8);

    REQUIRE(v5.x == 3);
    REQUIRE(v5.y == 5);
    
}

TEST_CASE("Adding to an existing vector", "[Vector]") {
    Vector v1(1, 7);
    Vector v2(2, 11);

    v1 += v2;
    REQUIRE(v1.x == 3);
    REQUIRE(v1.y == 18);
}

TEST_CASE("Multiplying with vectors", "[Vector]") {
    Vector v1 = Vector();
    Vector v2(2, 2);
    int m = 5;

    Vector v3 = m * v1;
    Vector v4 = v1 * m;
    
    Vector v5 = v2 * m;

    REQUIRE(v3.x == 0);
    REQUIRE(v3.y == 0);
    REQUIRE(v4.x == 0);
    REQUIRE(v4.y == 0);

    REQUIRE(v5.x == 10);
    REQUIRE(v5.y == 10);
}

TEST_CASE("Multiplying with an existing vector", "[Vector]") {
    Vector v1(2,8);
    int m = 9;

    v1 *= 9;

    REQUIRE(v1.x == 18);
    REQUIRE(v1.y == 72);
}

TEST_CASE("Vector output stream operator", "[Vector]") {
    Vector v(2, 3);
    std::stringstream ss;
    ss << v;
    REQUIRE(ss.str() == "Your X is: 2 and your Y is: 3\n");
}
