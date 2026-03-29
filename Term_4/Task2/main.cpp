#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector V = {1, 2, 3, 4, 5, 6, 7};

    int pos = 1;

    for (auto it = V.begin(); it != V.end(); ) {
        if (pos % 2 == 1) {
            it = V.erase(it);
        } else {
            ++it;
        }

        ++pos;

        if (it == V.end()) break;
    }

    for (int x : V) {
        cout << x << " ";
    }

    return 0;
}