#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

class SafeCounter {
    int count = 0;
    std::mutex mtx;

public:
    void Increment() {
        std::lock_guard<std::mutex> lock(mtx);
        ++count;
    }

    int GetCount() {
        std::lock_guard<std::mutex> lock(mtx);
        return count;
    }
};

int main() {
    SafeCounter counter;
    std::vector<std::thread> threads;

    for (int i = 0; i < 10; ++i) {
        threads.emplace_back([&counter]() {
            for (int j = 0; j < 1000; ++j) {
                counter.Increment();
            }
            });
    }

    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "Кінцевий рахунок: " << counter.GetCount() << std::endl;
    return 0;
}
