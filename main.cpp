#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;
const auto IMAGE_WIDTH = 400;
const auto IMAGE_HEIGHT = 300;
const auto TEXT_LEFT = 20;
const auto TEXT_BASELINE = 20;
const auto TEXT_WIDTH = 50;
const auto BIN_HEIGHT = 30;
const auto BLOCK_WIDTH = 10;
const vector<string> COLORS {"black", "mediumblue", "green", "deepskyblue", "lime", "lightyellow", "moccasin", "orangered", "fuchsia", "orchid"};


vector <double>
    input_numbers(size_t count_){
    vector<double> result(count_);
    for (size_t i = 0; i < count_; i++) {
        cin >> result[i];
    }
    return result;
}
void find_minmax(const vector <double>& numbers,double& min_, double& max_){
    for (double x : numbers) {
        if (x < min_) {
            min_ = x;
        }
        else if (x > max_) {
            max_ = x;
        }
    }
}

void make_histogram(const vector <double>& numbers,vector <double>& bins, size_t& bin_count,double& min_, double& max_){
    double bin_size = (max_ - min_) / bin_count;
    size_t number_count = numbers.size();
    for (size_t i = 0; i < number_count; i++) {
        bool found = false;
        for (size_t j = 0; (j < bin_count - 1) && !found; j++) {
            auto lo = min_ + j * bin_size;
            auto hi = min_ + (j + 1) * bin_size;
            if ((lo <= numbers[i]) && (numbers[i] < hi)) {
                bins[j]++;
                found = true;
            }
        }
        if (!found) {
            bins[bin_count - 1]++;
        }
    }
}
void show_histogram_text (vector <double>& bins){
    size_t dlina = 0;
    size_t max_count = *max_element(begin(bins), end(bins));
    if (max_count > 76) {
        for (double x : bins) {
            x += dlina;
            dlina = x;
            if (x < 100) {
                cout << ' ';
                    if (x < 10) {
                        cout << ' ';
                }
        }
        cout << x << '|';
        size_t heigh =  x > 76 ? 76 : 76 * (static_cast<double>(x) / max_count);
        for (auto i = 0;i < heigh; i++) {
            cout << '*';
        }
        cout << endl;
        }
    }
    else {
        for (double x : bins) {
            x += dlina;
            dlina = x;
            if (x < 100) {
                cout << ' ';
                    if (x < 10) {
                        cout << ' ';
                    }
            }
            cout << x << '|';
            for (auto i = 0;i < x; i++) {
                cout << '*';
            }
            cout << endl;
        }
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
svg_text(double left, double baseline, string text) {
    cout << "<text x='" << left << "' y='" << baseline << "'" << ">" << text << "</text>";
}

void svg_rect(double x, double y, double width, double height, string stroke, string fill){
    cout << "<rect x='" << x << "' " <<  "y='" << y << "' " << "width='" << width << "' " <<  "height='" << height << "' ";
    cout << "stroke='" << stroke << "' " << "fill='" << fill << "'/>";
}

void
show_histogram_svg(vector<double>& bins) {
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top = 0;
    double dlina = 0;
    double max_count = *max_element(bins.begin(), bins.end());
    if (max_count > 76) {
        for (double x : bins) {
            x += dlina;
            dlina = x;
            if (x < 100) {
                cout << ' ';
                    if (x < 10) {
                        cout << ' ';
                }
        }
        const double bin_width = IMAGE_WIDTH * (static_cast<double>(x) / max_count);
        string color = COLORS[rand() % 10];
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(x));
        double heigh =  x > 76 ? 76 : 76 * (static_cast<double>(x) / max_count);
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, color, color);
        }
    }
    else{
        for (size_t x : bins) {
            x += dlina;
            dlina = x;
            if (x < 100) {
                cout << ' ';
                    if (x < 10) {
                        cout << ' ';
                    }
            }
            string color = COLORS[rand() % 10];
            svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(x));
            svg_rect(TEXT_WIDTH, top, x * 20 , BIN_HEIGHT, color, color);
            top += BIN_HEIGHT;
        }
    }
    svg_end();
}



int main(){
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;
    cerr << "Enter numbers: ";
    const auto numbers = input_numbers(number_count);
    size_t bin_count;
    cerr << "Enter bin count: ";
    cin >> bin_count;
    double min_ = numbers[0];
    double max_ = numbers[0];
    find_minmax(numbers,min_,max_);
    vector <double> bins(bin_count);
    make_histogram(numbers, bins, bin_count,min_,max_);
    show_histogram_svg(bins);

}
