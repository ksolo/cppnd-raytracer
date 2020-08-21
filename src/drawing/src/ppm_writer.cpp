#include "drawing/ppm_writer.h"

namespace raytracer
{
    ppm_writer::ppm_writer(std::string &output, std::unique_ptr<raytracer::drawable> &&canvas)
    {
       _canvas = std::move(canvas);
       _outfile = std::ofstream(output);
    }

    ppm_writer::~ppm_writer()
    {
        _outfile.close();
    }

    void ppm_writer::generate_image()
    {
        _outfile << "P3" << std::endl;
        _outfile << _canvas->width() << " " << _canvas->height() << std::endl;
        _outfile << "255" << std::endl;

        int pixel_count = 0;
        for (auto color : _canvas->pixels())
        {
            _outfile << color->red() << " " << color->green() << " " << color-> blue();
            if (++pixel_count % 5 == 0)
            {
                _outfile << std::endl;
                continue;
            }
            if (color == *_canvas->pixels().end())
            {
                _outfile << std::endl;
                return;
            }
            _outfile << " ";
        }
    }
}
