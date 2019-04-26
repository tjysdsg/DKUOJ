#include <tcframe/spec.hpp>
#include <iostream>
#include <limits.h>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N;
    std::vector<long long> A;
    int output;
    void InputFormat() { LINE(A % SIZE(N)); }
    void OutputFormat() { LINE(output); }
    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(128);
    }

    void Constraints() {
        CONS(1 <= N && N <= 1000);
        CONS(eachElementBetween(A, INT_MIN, INT_MAX));
    }

private:
    bool eachElementBetween(const std::vector<long long>& v, long lo, long hi) {
        for (long long i : v) {
            if (i < lo || i > hi) {
                return false;
            }
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void BeforeTestCase() {
        N = rnd.nextInt(1, 1000);
        A.clear();
    }

    void randomArray() {
        std::cout << N << std::endl;
        for (int i = 0; i < N; ++i) {
            A.push_back(rnd.nextInt(INT_MIN, INT_MAX));
        }
    }

    void TestCases() {
        CASE(randomArray());
        CASE(randomArray());
        CASE(randomArray());
        CASE(randomArray());
        CASE(randomArray());
        CASE(randomArray());
        CASE(randomArray());
        CASE(randomArray());
        CASE(randomArray());
        CASE(randomArray());
    }
};
