#include "gtest/gtest.h"

#include <fstream>
#include <memory>

#include "drawing/ppm_writer.h"
#include "drawing/canvas.h"

TEST(PPM_WRITER_TEST, test_initialization)
{
    std::unique_ptr<raytracer::canvas> canvas = std::make_unique<raytracer::canvas>(10, 20);
    std::string output_file("outfile.ppm");
    raytracer::ppm_writer writer(output_file, std::move(canvas));

    std::fstream out("outfile.ppm");
    EXPECT_TRUE(out);
}

