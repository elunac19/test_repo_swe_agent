#include "gtest/gtest.h" // GoogleTest header
#include "medium_area_calculator.cpp"

// Test Fixture for Shape tests (optional, but good practice for grouping)
class ShapeTest : public ::testing::Test {
protected:

};

// Test Case 1: Test Rectangle Area Calculation
TEST_F(ShapeTest, RectangleAreaCalculation) {
    Rectangle rect1(4, 5);
    EXPECT_DOUBLE_EQ(rect1.area(), 20.0); // 4 * 5 = 20

    Rectangle rect2(10, 0);
    EXPECT_DOUBLE_EQ(rect2.area(), 0.0); // 10 * 0 = 0

    Rectangle rect3(2.5, 3.0);
    EXPECT_DOUBLE_EQ(rect3.area(), 7.5); // 2.5 * 3.0 = 7.5
}

// Test Case 2: Test Circle Area Calculation
TEST_F(ShapeTest, CircleAreaCalculation) {
    Circle circ1(3);
    // Using M_PI from <cmath> for the expected value if your class uses it.
    // If your class uses a specific 3.14159, adjust the expected value.
    #ifndef M_PI
    #define M_PI_LOCAL 3.14159265358979323846
    #else
    #define M_PI_LOCAL M_PI
    #endif
    EXPECT_NEAR(circ1.area(), M_PI_LOCAL * 3 * 3, 0.0001);

    Circle circ2(1);
    EXPECT_NEAR(circ2.area(), M_PI_LOCAL * 1 * 1, 0.0001);

    Circle circ3(0);
    EXPECT_DOUBLE_EQ(circ3.area(), 0.0); // Pi * 0 * 0 = 0
}

// Test Case 3: Test Polymorphic Area Calculation
TEST_F(ShapeTest, PolymorphicAreaCalculation) {
    Shape* shape_rect = new Rectangle(7, 3);
    EXPECT_DOUBLE_EQ(shape_rect->area(), 21.0); // 7 * 3 = 21

    Shape* shape_circ = new Circle(5);
    #ifndef M_PI
    #define M_PI_LOCAL_POLY 3.14159265358979323846
    #else
    #define M_PI_LOCAL_POLY M_PI
    #endif
    EXPECT_NEAR(shape_circ->area(), M_PI_LOCAL_POLY * 5 * 5, 0.0001);

    // Clean up dynamically allocated memory
    // This also implicitly tests that the virtual destructor works correctly
    // and doesn't cause issues (like trying to call a non-virtual destructor
    // on a derived class through a base pointer).
    delete shape_rect;
    delete shape_circ;
}
