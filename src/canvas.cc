#include <canvas.hh>
#include <emscripten.h>

canvas::canvas(std::string id) noexcept {
        this->id = id;
}

int canvas::width() const noexcept {
        return EM_ASM_INT({ return document.getElementById($0).width; },
                          id.c_str());
}

int canvas::height() const noexcept {
        return EM_ASM_INT({ return document.getElementById($0).height; },
                          id.c_str());
}

void canvas::set_scale(double x, double y) noexcept {
        EM_ASM({
                document.getElementById($0).getContext('2d')
                        .setTransform($1, 0, 0, $2, 0, 0);
        }, id.c_str(), x, y);
}

void canvas::set_fill_style(std::string fill_style) noexcept {
        EM_ASM({
                document.getElementById($0).getContext('2d')
                        .fillStyle = $1;
        }, id.c_str(), fill_style.c_str());
}

void canvas::fill_rect(double x, double y, double w, double h) noexcept {
        EM_ASM({
                document.getElementById($0).getContext('2d')
                        .fillRect($1, $2, $3, $4);
        }, id.c_str(), x, y, w, h);
}

void canvas::draw_chart(std::function<int(int)> f, int w, int h,
                        std::string fill_style) noexcept {
        set_scale((double)w / (double)width(), (double)h / (double)height());
        set_fill_style(fill_style);
        for(int x = 0; x < w; x++) {
                int y = f(x);
                fill_rect(x, y, 1, y);
        }
}
