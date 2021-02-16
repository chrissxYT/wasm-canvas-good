#include <canvas.hh>
#include <emscripten.h>

EMSCRIPTEN_KEEPALIVE
extern "C" void sine_chart(char *c, int w, int h, char *fill_style) {
        canvas(c).draw_chart(sin<int>, w, h, fill_style);
}
