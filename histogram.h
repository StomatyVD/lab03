#pragma once
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
void find_minmax(const vector <double>& numbers,double& min_, double& max_);

void svg_begin(double width, double height);

void svg_end();

void svg_text(double left, double baseline, string text);

void svg_rect(double x, double y, double width, double height, string stroke, string fill);

void show_histogram_svg(vector<double>& bins);



