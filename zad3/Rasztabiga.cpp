// Bartłomiej Rasztabiga 304117

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool contains(const string &arr, char element) {
    return std::find(arr.begin(), arr.end(), element) != arr.end();
}

int main() {
    int width;
    int height;
    cin >> width >> height;
    cin.ignore();
    int number_of_turns;
    cin >> number_of_turns;
    cin.ignore();
    int x_mid_index;
    int y_mid_index;
    cin >> x_mid_index >> y_mid_index;
    cin.ignore();

    int x_left_index = 0;
    int x_right_index = width;
    int y_down_index = 0;
    int y_up_index = height;

    while (number_of_turns != 0) {
        string bombDir;
        cin >> bombDir;
        cin.ignore();

        if (contains(bombDir, 'U')) {
            y_up_index = y_mid_index;
        } else if (contains(bombDir, 'D')) {
            y_down_index = y_mid_index;
        }

        if (contains(bombDir, 'L')) {
            x_right_index = x_mid_index;
        } else if (contains(bombDir, 'R')) {
            x_left_index = x_mid_index;
        }

        x_mid_index = x_left_index + (x_right_index - x_left_index) / 2;
        y_mid_index = y_down_index + (y_up_index - y_down_index) / 2;

        cout << x_mid_index << ' ' << y_mid_index << endl;
        number_of_turns--;
    }
}