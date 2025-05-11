#include <iostream>
using namespace std;

// const int height = 10;
// const int width = 5;

// int main() {
//     string topBottom(width + 2, '_');
//     string middle = "|" + string(width, ' ') + "|";

//     cout << topBottom << endl;
//     for (int i = 0; i < height; i++) {
//         cout << middle << endl;
//     }
//     cout << topBottom << endl;

//     return 0;
// }
//#include <iostream>
#include <string>
using namespace std;

int main() {
    int w = 20, h = 10;
    string border(w + 2, '#');
    string inner = "#" + string(w, ' ') + "#";

    cout << border << endl;
    for_each_n([](int){ cout << inner << endl; }, h);
    cout << border << endl;

    return 0;
}
