#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std; // Використовуємо стандартний простір імен

// Функція для знаходження медіани
double findMedian(vector<int>& numbers) {
    sort(numbers.begin(), numbers.end());
    if (numbers.size() % 2 == 0) {
        return (numbers[numbers.size() / 2 - 1] + numbers[numbers.size() / 2]) / 2.0;
    } else {
        return numbers[numbers.size() / 2];
    }
}

// Функція для знаходження найдовшої зростаючої послідовності
vector<int> findLongestIncreasingSubsequence(const vector<int>& numbers) {
    vector<int> longestSeq, currentSeq;
    for (size_t i = 0; i < numbers.size(); ++i) {
        if (i == 0 || numbers[i] > numbers[i - 1]) {
            currentSeq.push_back(numbers[i]);
        } else {
            if (currentSeq.size() > longestSeq.size()) {
                longestSeq = currentSeq;
            }
            currentSeq.clear();
            currentSeq.push_back(numbers[i]);
        }
    }
    if (currentSeq.size() > longestSeq.size()) {
        longestSeq = currentSeq;
    }
    return longestSeq;
}

// Функція для знаходження найдовшої спадної послідовності
vector<int> findLongestDecreasingSubsequence(const vector<int>& numbers) {
    vector<int> longestSeq, currentSeq;
    for (size_t i = 0; i < numbers.size(); ++i) {
        if (i == 0 || numbers[i] < numbers[i - 1]) {
            currentSeq.push_back(numbers[i]);
        } else {
            if (currentSeq.size() > longestSeq.size()) {
                longestSeq = currentSeq;
            }
            currentSeq.clear();
            currentSeq.push_back(numbers[i]);
        }
    }
    if (currentSeq.size() > longestSeq.size()) {
        longestSeq = currentSeq;
    }
    return longestSeq;
}

int main() {
    ifstream inputFile("/Users/vika/Desktop/TZ/numbers.txt"); // Вказуємо повний шлях до файлу
    vector<int> numbers;
    int number;

    if (!inputFile.is_open()) {
        cerr << "Unable to open file"; // Повідомлення про помилку, якщо файл не вдалося відкрити
        return 1;
    }

    while (inputFile >> number) {
        numbers.push_back(number);
    }
    inputFile.close();

    if (numbers.empty()) {
        cerr << "File is empty or contains no valid numbers";
        return 1;
    }

    double median = findMedian(numbers);
    int maxNumber = *max_element(numbers.begin(), numbers.end());
    int minNumber = *min_element(numbers.begin(), numbers.end());
    double average = accumulate(numbers.begin(), numbers.end(), 0.0) / numbers.size();
    vector<int> longestIncreasingSubseq = findLongestIncreasingSubsequence(numbers);
    vector<int> longestDecreasingSubseq = findLongestDecreasingSubsequence(numbers);

    cout << "Median: " << median << "\n";
    cout << "Maximum number: " << maxNumber << "\n";
    cout << "Minimum number: " << minNumber << "\n";
    cout << "Average: " << average << "\n";
    cout << "Longest increasing subsequence: ";
    for (size_t i = 0; i < longestIncreasingSubseq.size(); ++i) {
        cout << longestIncreasingSubseq[i] << " ";
    }
    cout << "\n";
    cout << "Longest decreasing subsequence: ";
    for (size_t i = 0; i < longestDecreasingSubseq.size(); ++i) {
        cout << longestDecreasingSubseq[i] << " ";
    }
    cout << "\n";

    return 0;
}
