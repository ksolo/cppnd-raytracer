#include "gtest/gtest.h"

#include "data_structures/color.h"
#include "drawing/canvas.h"

#include <algorithm>

TEST(CANVAS_TEST, test_canvas_initialization)
{
    raytracer::canvas canvas_one(10, 20);
    EXPECT_EQ(canvas_one.width(), 10);
    EXPECT_EQ(canvas_one.height(), 20);

    raytracer::color black(0,0,0);

    auto pixels = canvas_one.pixels();
    std::for_each(pixels.begin(), pixels.end(),[&](auto& pixel) {
        EXPECT_TRUE((*pixel) == black);
    });
}

TEST(CANVAS_TEST, test_setting_pixels)
{
    raytracer::canvas canvas_one(10, 20);
    raytracer::color red(1.0, 0, 0);

    canvas_one.write_pixel(2, 3, red);

    EXPECT_TRUE(canvas_one.pixel_at(2, 3) == red);
}
