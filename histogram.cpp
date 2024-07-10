#include "histogram.h"
void find_minmax(const vector <double>& numbers,double& min_, double& max_){
    if (numbers.size() == 0) {
        min_ = min_;
        max_ = max_;
    }
    else {
        min_ = *min_element(numbers.begin(), numbers.end());
        max_ = *max_element(numbers.begin(), numbers.end());
    }
}
void
svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void
svg_end() {
    cout << "</svg>\n";
}

void
svg_text(double left, double baseline, string text,double font) {
    cout << "<text x='" << left << "' y='" << baseline << "' " << "font-size='" << font / 16 << "em'" << ">" << text << "</text>";
}

void svg_rect(double x, double y, double width, double height, string stroke, string fill){
    cout << "<rect x='" << x << "' " <<  "y='" << y << "' " << "width='" << width << "' " <<  "height='" << height << "' ";
    cout << "stroke='" << stroke << "' " << "fill='" << fill << "'/>";
}

void
show_histogram_svg(vector<double>& bins) {
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double font = 12;
    cerr << "Enter font: ";
    cin >> font;
    if (font < 8 or font > 32){
        cerr << "Error: select a value between 8 and 32 ";
        cin >> font;
    }
    double top = 0;
    double dlina = 0;
    double max_count = *max_element(bins.begin(), bins.end());
    if (max_count > 76) {
        for (double x : bins) {
            double Text_l = TEXT_LEFT;
            x += dlina;
            dlina = x;
            if (x < 100) {
                Text_l += 10;
                    if (x < 10) {
                        Text_l += 10;
                    }
            }
        string color = COLORS[rand() % 10];
        svg_text(Text_l, top + TEXT_BASELINE, to_string(x),font);
        double heigh =  x > 76 ? 76 : 76 * (static_cast<double>(x) / max_count);
        svg_rect(TEXT_WIDTH, top, x * 20, BIN_HEIGHT, color, color);
        }
    }
    else{
        for (size_t x : bins) {
            double Text_l = TEXT_LEFT;
            x += dlina;
            dlina = x;
            if (x < 100) {
                Text_l += 10;
                    if (x < 10) {
                        Text_l += 10;
                    }
            }
            string color = COLORS[rand() % 10];
            svg_text(Text_l, top + TEXT_BASELINE, to_string(x),font);
            svg_rect(TEXT_WIDTH, top, x * 20 , BIN_HEIGHT, color, color);
            top += BIN_HEIGHT;
        }
    }
    svg_end();
}

