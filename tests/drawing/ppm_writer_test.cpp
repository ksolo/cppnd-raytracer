#include "gtest/gtest.h"

#include <filesystem>
#include <fstream>
#include <memory>

#include "drawing/ppm_writer.h"
#include "drawing/canvas.h"

TEST(PPM_WRITER_TEST, test_initialization)
{
    std::unique_ptr<raytracer::canvas> canvas = std::make_unique<raytracer::canvas>(10, 20);
    std::string output_file("outfile.ppm");
    raytracer::ppm_writer writer(output_file, std::move(canvas));

    std::fstream out(output_file);
    EXPECT_TRUE(out);

    std::filesystem::path path(output_file);
    std::filesystem::remove(path);
}

TEST(PPM_WRITER_TEST, test_header_output)
{
    std::unique_ptr<raytracer::canvas> canvas = std::make_unique<raytracer::canvas>(10, 20);
    std::string output_file("outfile.ppm");
    raytracer::ppm_writer writer(output_file, std::move(canvas));

    std::filesystem::path path(output_file);
    std::filesystem::remove(path);
}

