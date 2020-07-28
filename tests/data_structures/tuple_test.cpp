#include "gtest/gtest.h"
#include "data_structures/tuple.h"
#include <cmath>

TEST(TUPLE_TEST, tuple_with_w_of_1_is_point)
{
    raytracer::tuple tuple(4.3, -4.2, 3.1, 1.0);
    EXPECT_EQ(tuple.x(), 4.3) << "tuple x was not set properly during initialization";
    EXPECT_EQ(tuple.y(), -4.2) << "tuple y was not set properly during initialization";
    EXPECT_EQ(tuple.z(), 3.1) << "tuple z was not set properly during initialization";
    EXPECT_EQ(tuple.w(), 1.0) << "tuple w was not set properly during initialization";
    EXPECT_TRUE(tuple.is_point());
}

TEST(TUPLE_TEST, tuple_with_w_of_0_is_vector)
{
    raytracer::tuple tuple(4.3, -4.2, 3.1, 0.0);
    EXPECT_EQ(tuple.x(), 4.3) << "tuple x was not set properly during initialization";
    EXPECT_EQ(tuple.y(), -4.2) << "tuple y was not set properly during initialization";
    EXPECT_EQ(tuple.z(), 3.1) << "tuple z was not set properly during initialization";
    EXPECT_EQ(tuple.w(), 0.0) << "tuple w was not set properly during initialization";
    EXPECT_TRUE(tuple.is_vector());
}

TEST(TUPLE_TEST, create_point_with_factory_function)
{
    raytracer::tuple point = raytracer::tuple::point(4, -4, 3);
    raytracer::tuple other_point(4, -4, 3, 1);
    EXPECT_TRUE(point == other_point);
}

TEST(TUPLE_TEST, create_vector_with_factory_function)
{
    raytracer::tuple vector = raytracer::tuple::vector(4, -4, 3);
    raytracer::tuple other_vector(4, -4, 3, 0);
    EXPECT_TRUE(vector == other_vector);
}

TEST(TUPLE_TEST, adding_two_tuples)
{
    raytracer::tuple tuple_one(3, -2, 5, 1);
    raytracer::tuple tuple_two(-2, 3, 1, 0);

    raytracer::tuple result = tuple_one + tuple_two;

    EXPECT_EQ(result.x(), 1) << "x values were not added correctly";
    EXPECT_EQ(result.y(), 1) << "y values were not added correctly";
    EXPECT_EQ(result.z(), 6) << "z values were not added correctly";
    EXPECT_EQ(result.w(), 1) << "w values were not added correctly";
}

TEST(TUPLE_TEST, subtraciting_two_points)
{
    raytracer::tuple point_one = raytracer::tuple::point(3, 2, 1);
    raytracer::tuple point_two = raytracer::tuple::point(5, 6, 7);

    raytracer::tuple result = point_one - point_two;

    EXPECT_EQ(result.x(), -2) << "x values were not subtracted correctly";
    EXPECT_EQ(result.y(), -4) << "y values were not subtracted correctly";
    EXPECT_EQ(result.z(), -6) << "z values were not subtracted correctly";
    EXPECT_EQ(result.w(), 0) << "w values were not subtracted correctly";
}

TEST(TUPLE_TEST, negating_a_tuple)
{
    raytracer::tuple point = raytracer::tuple::point(3, 2, 1);

    raytracer::tuple result = -point;

    EXPECT_EQ(result.x(), -3) << "x values were not negated correctly";
    EXPECT_EQ(result.y(), -2) << "y values were not negated correctly";
    EXPECT_EQ(result.z(), -1) << "z values were not negated correctly";
    EXPECT_EQ(result.w(), -1) << "w values were not negated correctly";
}

TEST(TUPLE_TEST, multiplying_tuple_by_scalar)
{
    raytracer::tuple point = raytracer::tuple::point(3, 2, 1);

    raytracer::tuple result = point * 3.5;

    EXPECT_EQ(result.x(), 10.5) << "x values were not scaled correctly";
    EXPECT_EQ(result.y(), 7.0) << "y values were not scaled correctly";
    EXPECT_EQ(result.z(), 3.5) << "z values were not scaled correctly";
    EXPECT_EQ(result.w(), 3.5) << "w values were not scaled correctly";
}

TEST(TUPLE_TEST, divide_tuple_by_scalar)
{
    raytracer::tuple point = raytracer::tuple::point(3, 2, 1);

    raytracer::tuple result = point / 2;

    EXPECT_EQ(result.x(), 1.5) << "x values were not divided correctly";
    EXPECT_EQ(result.y(), 1.0) << "y values were not divided correctly";
    EXPECT_EQ(result.z(), 0.5) << "z values were not divided correctly";
    EXPECT_EQ(result.w(), 0.5) << "w values were not divided correctly";
}

TEST(TUPLE_TEST, magnitude_of_vector_1_0_0)
{
    raytracer::tuple vector = raytracer::tuple::vector(1, 0, 0);
    double magnitude = vector.magnitude();
    EXPECT_EQ(magnitude, 1);
}

TEST(TUPLE_TEST, magnitude_of_vector_0_1_0)
{
    raytracer::tuple vector = raytracer::tuple::vector(0, 1, 0);
    double magnitude = vector.magnitude();
    EXPECT_EQ(magnitude, 1);
}

TEST(TUPLE_TEST, magnitude_of_vector_0_0_1)
{
    raytracer::tuple vector = raytracer::tuple::vector(0, 0, 1);
    double magnitude = vector.magnitude();
    EXPECT_EQ(magnitude, 1);
}

TEST(TUPLE_TEST, magnitude_of_vector_1_2_3)
{
    raytracer::tuple vector = raytracer::tuple::vector(1, 2, 3);
    double magnitude = vector.magnitude();
    EXPECT_EQ(magnitude, std::sqrt(14.0));
}

TEST(TUPLE_TEST, magnitude_of_negative_vector_1_2_3)
{
    raytracer::tuple vector = raytracer::tuple::vector(-1, -2, -3);
    double magnitude = vector.magnitude();
    EXPECT_EQ(magnitude, std::sqrt(14.0));
}
