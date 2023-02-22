// clang++ -std=c++2b copy_bench.cpp -o copy_bench
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

vector<int> seedArray(int arrsize, int numsize = 100) {
    vector<int> seeded;
    for (int i = 0; i < arrsize; i++) {
        seeded.push_back(rand() % numsize);
    }
    return seeded;
}

void runMeasurement(vector<int> a) {
    auto t1 = chrono::high_resolution_clock::now();
    vector<int> copy1 = a;
    auto t2 = chrono::high_resolution_clock::now();
    cout << "\tvector:\t" << chrono::duration_cast<chrono::microseconds>(t2 - t1).count() << "\tmicroseconds, " << copy1.size() << endl;

    auto t3 = chrono::high_resolution_clock::now();
    vector<int> copy2(a);
    auto t4 = chrono::high_resolution_clock::now();
    cout << "\tcopy:\t" << chrono::duration_cast<chrono::microseconds>(t4 - t3).count() << "\tmicroseconds, " << copy2.size() << endl;

    auto t5 = chrono::high_resolution_clock::now();
    vector<int> copy3;
    for (const auto& i : a) {
        copy3.push_back(i);
    }
    auto t6 = chrono::high_resolution_clock::now();
    cout << "\trange-for:\t" << chrono::duration_cast<chrono::microseconds>(t6 - t5).count() << "\tmicroseconds, " << copy3.size() << endl;

    auto t7 = chrono::high_resolution_clock::now();
    vector<int> copy4;
    for (size_t i = 0; i < a.size(); i++) {
        copy4.push_back(a[i]);
    }
    auto t8 = chrono::high_resolution_clock::now();
    cout << "\tfor:\t" << chrono::duration_cast<chrono::microseconds>(t8 - t7).count() << "\tmicroseconds, " << copy4.size() << endl;

    auto t9 = chrono::high_resolution_clock::now();
    vector<int> copy5;
    for (auto it = a.begin(); it != a.end(); ++it) {
        copy5.push_back(*it);
    }
    auto t10 = chrono::high_resolution_clock::now();
    cout << "\titerator:\t" << chrono::duration_cast<chrono::microseconds>(t10 - t9).count() << "\tmicroseconds, " << copy5.size() << endl;
}

void mainFunction() {
    srand(time(NULL));
    vector<int> sizes = {10, 100, 1000, 1000000, 10000000};
    for (auto size : sizes) {
        cout << "Running Measure for size: " << size << endl;
        vector<int> a = seedArray(size);
        runMeasurement(a);
    }
}

int main() {
    mainFunction();
    return 0;
}
