#include "gtest/gtest.h"
#include "data_structures/color.h"

TEST(COLOR_TEST, initialize_color_components)
{
    raytracer::color color(0.5, 0.4, 0.7);
    EXPECT_EQ(color.red(), 0.5) << "red component was not set correctly";
    EXPECT_EQ(color.green(), 0.4) << "green component was not set correctly";
    EXPECT_EQ(color.blue(), 0.7) << "blue component was not set correctly";
}
