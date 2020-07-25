#include "gtest/gtest.h"
#include "data_structures/tuple.h"

TEST(TUPLE_TEST, constructor_requires_x_y_z_w_parameters)
{
    raytracer::tuple tuple(1.0, 2.0, 3.0, 4.0);
    EXPECT_EQ(tuple.x(), 1.0) << "tuple x was not set properly during initialization";
    EXPECT_EQ(tuple.y(), 2.0) << "tuple y was not set properly during initialization";
    EXPECT_EQ(tuple.z(), 3.0) << "tuple z was not set properly during initialization";
    EXPECT_EQ(tuple.w(), 4.0) << "tuple w was not set properly during initialization";
}

