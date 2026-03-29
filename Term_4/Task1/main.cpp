#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>


using namespace std;

int main() {

    int K;
    string name1, name2;

    cin >> K >> name1 >> name2;

    ifstream fin(name1);
    if (!fin) {
        cerr << "Input file does not exist" << name1 << '\n';
        return 1;
    }

    ofstream fout(name2);
    if (!fout) {
        cerr << "Output file does not exist" << name2 << '\n';
        return 1;
    }

    istream_iterator<string> in_begin(fin);
    istream_iterator<string> in_end;
    ostream_iterator<string> out_it(fout, "\n");

    remove_copy_if(
        in_begin,
        in_end,
        out_it,
        [K](const string& word) {
            return word.length() > static_cast<size_t>(K);
        }
    );

    return 0;
}