#include <tcframe/spec.hpp>
#include <limits.h>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    int T;
    std::vector<std::string> raw_lines;
    std::vector<int> output;
    void InputFormat() {
        LINE(T);
        RAW_LINES(raw_lines);
    }

    void OutputFormat() { LINES(output) % SIZE(T); }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(128);
    }

    void Constraints() { CONS(1 <= T && T <= 100); }

private:
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    int last_store_count = 0;
    void BeforeTestCase() {
        raw_lines.clear();
    }

    void GenerateData() {
        for (int i = 0; i < 2 * T; ++i) {
            if (i % 2 == 0) {
                // even lines contain only the number of stores
                last_store_count = rnd.nextInt(1, 21);
                raw_lines.push_back(std::to_string(last_store_count));
            } else {
                // odd lines contain the position of those stores
                std::string s;
                for (int i = 0; i < last_store_count; ++i) {
                    s += std::to_string(rnd.nextInt(0, 100));
                    if (i != last_store_count - 1) {
                        s += " ";
                    }
                }
                raw_lines.push_back(s);
            }
        }
    }

    void TestCases() {
        T = rnd.nextInt(1, 101);
        CASE(GenerateData());
        T = rnd.nextInt(1, 101);
        CASE(GenerateData());
        T = rnd.nextInt(1, 101);
        CASE(GenerateData());
        T = rnd.nextInt(1, 101);
        CASE(GenerateData());
        T = rnd.nextInt(1, 101);
        CASE(GenerateData());
        T = rnd.nextInt(1, 101);
        CASE(GenerateData());
        T = rnd.nextInt(1, 101);
        CASE(GenerateData());
        T = rnd.nextInt(1, 101);
        CASE(GenerateData());
        T = rnd.nextInt(1, 101);
        CASE(GenerateData());
        T = rnd.nextInt(1, 101);
        CASE(GenerateData());
    }
};
