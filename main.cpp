#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
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
    show_histogram_text(bins);

}
