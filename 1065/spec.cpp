#include <tcframe/spec.hpp>
#include <iostream>
#include <string>
#include <limits.h>

using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N;
    std::vector<long long> A;
    std::string input;
    int output;
    void InputFormat() { LINE(input); }
    void OutputFormat() { LINE(output); }
    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(128);
    }

    void Constraints() {
        CONS(1 <= N && N <= 1000);
        CONS(eachElementBetween(A, (long)('a'), (long)('c')));
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

    void generate_random_input() {
        std::cout << N << std::endl;
        for (int i = 0; i < N; ++i) {
            A.push_back(rnd.nextInt((int)'a', (int)'c'));
        }
        // convert vector to string
        for (int i = 0; i < N; ++i) {
            input += (char)A[i];
        }
    }

    void TestCases() {
        CASE(generate_random_input());
        CASE(generate_random_input());
        CASE(generate_random_input());
        CASE(generate_random_input());
        CASE(generate_random_input());
        CASE(generate_random_input());
        CASE(generate_random_input());
        CASE(generate_random_input());
        CASE(generate_random_input());
        CASE(generate_random_input());
    }
};
