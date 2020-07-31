#include "gtest/gtest.h"
#include "data_structures/color.h"

TEST(COLOR_TEST, initialize_color_components)
{
    raytracer::color color(0.5, 0.4, 0.7);
    EXPECT_EQ(color.red(), 0.5) << "red component was not set correctly";
    EXPECT_EQ(color.green(), 0.4) << "green component was not set correctly";
    EXPECT_EQ(color.blue(), 0.7) << "blue component was not set correctly";
}

TEST(COLOR_TEST, adding_colors)
{
    raytracer::color color_one(0.9, 0.6, 0.75);
    raytracer::color color_two(0.7, 0.1, 0.25);

    raytracer::color result = color_one + color_two;
    raytracer::color expected_color(1.6, 0.7, 1.0);
    EXPECT_TRUE(result == expected_color) << "colors were not added";
}

TEST(COLOR_TEST, subtracting_colors)
{
    raytracer::color color_one(0.9, 0.6, 0.75);
    raytracer::color color_two(0.7, 0.1, 0.25);

    raytracer::color result = color_one - color_two;
    raytracer::color expected_color(0.2, 0.5, 0.5);
    EXPECT_TRUE(result == expected_color) << "colors were not subtracted";
}

TEST(COLOR_TEST, multiplying_by_scalar)
{
    raytracer::color clr(0.9, 0.6, 0.75);

    raytracer::color result = clr * 2.0;
    raytracer::color expected_color(1.8, 1.2, 1.5);
    EXPECT_TRUE(result == expected_color) << "colors were not scaled";
}

TEST(COLOR_TEST, multiplying_by_other_color)
{
    raytracer::color color_one(1.0, 0.2, 0.4);
    raytracer::color color_two(0.9, 1.0, 0.1);

    raytracer::color result = color_one * color_two;
    raytracer::color expected_color(0.9, 0.2, 0.04);
    EXPECT_TRUE(result == expected_color) << "colors were not multiplied";
}
