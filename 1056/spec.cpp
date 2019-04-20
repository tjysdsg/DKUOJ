#include <tcframe/spec.hpp>
#include <limits.h>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N;
    std::vector<long long> A;
    std::vector<long long> B;
    double output;
    void InputFormat() {
        LINE(A % SIZE(N));
        LINE(B % SIZE(N));
    }
    void OutputFormat() { LINE(output); }
    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(128);
    }

    void Constraints() {
        CONS(1 <= N && N <= 1000);
        CONS(eachElementBetween(A, INT_MIN, INT_MAX));
        CONS(eachElementBetween(B, INT_MIN, INT_MAX));
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
        A.clear();
        B.clear();
    }
    void randomArray() {
        for (int i = 0; i < N; ++i) {
            A.push_back(rnd.nextInt(1000000));
            B.push_back(rnd.nextInt(1000000));
        }
    }

    void TestCases() {
        N = rnd.nextInt(1, 1000);
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
