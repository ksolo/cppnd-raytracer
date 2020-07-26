#include "gtest/gtest.h"
#include "data_structures/tuple.h"

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
