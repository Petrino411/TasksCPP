#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <numeric>
#include <iterator>
#include <stdexcept>

using namespace std;

/**
 * @brief Проверяет, состоит ли слово только из заглавных английских букв.
 *
 * @param word Входная строка.
 * @return true, если слово корректно, иначе false.
 */
bool isValidWord(const string& word) {
    if (word.empty()) return false;

    for (char ch : word) {
        if (ch < 'A' || ch > 'Z') return false;
    }
    return true;
}

/**
 * @brief Считывает количество слов с клавиатуры.
 *
 * @return Количество слов.
 * @throw runtime_error при некорректном вводе.
 */
int inputCount() {
    int n;

    cout << "Enter number of words: ";
    if (!(cin >> n)) {
        throw runtime_error("Error: integer expected.");
    }

    if (n < 0) {
        throw runtime_error("Error: number cannot be negative.");
    }

    return n;
}

/**
 * @brief Считывает вектор слов, состоящих из заглавных английских букв.
 *
 * @param n Количество слов.
 * @return Вектор строк.
 * @throw runtime_error при некорректном вводе.
 */
vector<string> inputWords(int n) {
    vector<string> V;
    V.reserve(n);

    cout << "Enter " << n << " words ONLY uppercase:\n";

    for (int i = 0; i < n; ++i) {
        string word;

        if (!(cin >> word)) {
            throw runtime_error("Error reading word #" + to_string(i + 1));
        }

        if (!isValidWord(word)) {
            throw runtime_error("Invalid word: \"" + word + "\"");
        }

        V.push_back(word);
    }

    return V;
}

/**
 * @brief Формирует multimap, группируя слова по последней букве.
 *
 * Внутри каждой группы элементы располагаются в порядке,
 * обратном их расположению в исходном векторе.
 *
 * @param V Вектор слов.
 * @return multimap<char, string> с группировкой.
 */
multimap<char, string> buildMap(const vector<string>& V) {
    multimap<char, string> M;

    for (const string& word : V) {
        char key = word.back();
        M.insert(M.lower_bound(key), make_pair(key, word));
    }

    return M;
}

/**
 * @brief Обрабатывает группы и выводит результат.
 *
 * Для каждой группы (по последней букве) формируется строка,
 * содержащая все слова группы, кроме последнего (в исходном порядке),
 * разделённые пробелами.
 *
 * @param M multimap с сгруппированными словами.
 */
void processAndPrint(const multimap<char, string>& M) {
    cout << "\nResult:\n";

    for (auto it = M.begin(); it != M.end(); ) {
        char key = it->first;
        auto range = M.equal_range(key);

        string result;
        int count = distance(range.first, range.second);

        if (count > 1) {
            auto rbeginGroup = make_reverse_iterator(range.second);
            auto rendGroup = make_reverse_iterator(range.first);

            result = accumulate(
                rbeginGroup,
                prev(rendGroup),
                string(),
                [](const string& acc, const pair<const char, string>& elem) {
                    return acc + elem.second + " ";
                }
            );
        }

        cout << key << " -> " << result << '\n';

        it = range.second;
    }
}

/**
 * @brief Точка входа
 */
int main() {
    try {
        int n = inputCount();

        if (n == 0) {
            cout << "Empty input. Nothing to process.\n";
            return 0;
        }

        vector<string> V = inputWords(n);
        multimap<char, string> M = buildMap(V);

        processAndPrint(M);
    }
    catch (const exception& e) {
        cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}