#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <functional>
#include <stdexcept>

using namespace std;

/**
 * @brief Структура точки с целочисленными координатами и строковым полем.
 */
struct point {
    int x{};
    int y{};
    string s;

    /**
     * @brief Сравнение точек по правилу из задачи 9.
     *
     * Точка A меньше точки B, если:
     * - A.x < B.x
     * - или A.x == B.x и A.y < B.y
     *
     * @param other Другая точка.
     * @return true, если текущая точка меньше other.
     */
    bool operator<(const point& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

/**
 * @brief Считывает объект point из входного потока.
 *
 * Члены считываются в порядке: x, y, s.
 *
 * @param is Входной поток.
 * @param p Объект point.
 * @return Ссылка на входной поток.
 */
istream& operator>>(istream& is, point& p) {
    is >> p.x >> p.y >> p.s;
    return is;
}

/**
 * @brief Выводит объект point в выходной поток.
 *
 * Члены выводятся в порядке: x y s.
 *
 * @param os Выходной поток.
 * @param p Объект point.
 * @return Ссылка на выходной поток.
 */
ostream& operator<<(ostream& os, const point& p) {
    os << p.x << ' ' << p.y << ' ' << p.s;
    return os;
}

/**
 * @brief Складывает две точки.
 *
 * Координаты складываются, строковые поля конкатенируются.
 *
 * @param a Первая точка.
 * @param b Вторая точка.
 * @return Результат сложения.
 */
point operator+(const point& a, const point& b) {
    return {a.x + b.x, a.y + b.y, a.s + b.s};
}

/**
 * @brief Считывает все точки из файла в вектор.
 *
 * @param fileName Имя входного файла.
 * @return Вектор считанных точек.
 * @throw runtime_error Если файл не удалось открыть.
 */
vector<point> readPointsFromFile(const string& fileName) {
    ifstream fin(fileName);
    if (!fin) {
        throw runtime_error("Error: cannot open file \"" + fileName + "\".");
    }

    return vector<point>(
        istream_iterator<point>(fin),
        istream_iterator<point>()
    );
}

/**
 * @brief Выводит все точки из вектора в консоль.
 *
 * Каждая точка выводится на новой строке.
 *
 * @param points Вектор точек.
 */
void printPoints(const vector<point>& points) {
    if (points.empty()) {
        cout << "The file does not contain any points.\n";
        return;
    }

    cout << "Transformed points:\n";
    copy(points.begin(), points.end(), ostream_iterator<point>(cout, "\n"));
}

/**
 * @brief Преобразует все точки, прибавляя к каждой point(10, 20, "Z").
 *
 * Используются алгоритм transform, функциональный объект plus
 * и связыватель bind.
 *
 * @param points Исходный вектор точек.
 * @return Новый вектор преобразованных точек.
 */
vector<point> transformPoints(const vector<point>& points) {
    vector<point> result(points.size());
    const point addValue{10, 20, "Z"};

    transform(
        points.begin(),
        points.end(),
        result.begin(),
        bind(plus<point>(), placeholders::_1, addValue)
    );

    return result;
}

/**
 * @brief Точка входа в программу.
 *
 * Считывает имя файла, читает точки, преобразует их
 * и выводит результат на экран.
 *
 * @return Код завершения программы.
 */
int main() {
    try {
        string fileName;

        cout << "Enter file name: ";
        cin >> fileName;

        if (!cin || fileName.empty()) {
            throw runtime_error("Error: invalid file name.");
        }

        vector<point> points = readPointsFromFile(fileName);
        vector<point> transformedPoints = transformPoints(points);

        printPoints(transformedPoints);
    }
    catch (const exception& e) {
        cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}