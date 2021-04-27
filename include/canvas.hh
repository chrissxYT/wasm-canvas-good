#include <string>

class canvas {
private:
        const std::string id;

public:
        canvas(const std::string id) noexcept;
        int width() const noexcept;
        int height() const noexcept;
        void set_scale(const double x, const double y) noexcept;
        void set_fill_style(const std::string fill_style) noexcept;
        void fill_rect(double x, double y, double w, double h) noexcept;
        void draw_chart(std::function<int(int)>, int width, int height,
                        std::string fill_style) noexcept;
};
