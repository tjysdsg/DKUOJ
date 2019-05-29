#include <tcframe/spec.hpp>
#include <limits.h>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    int M;
    std::vector<std::string> A;
    std::vector<int> output;
    char eof_mark = '#';
    void InputFormat() {
        RAW_LINES(A) % SIZE(M);
        LINE(eof_mark);
    }

    void OutputFormat() { LINES(output) % SIZE(M); }
    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(128);
    }

    void Constraints() {
        CONS(1 <= M && M <= 255);
        CONS(vectorConstraints(A));
    }

private:
    bool vectorConstraints(const std::vector<std::string>& v) {
//        for (std::string s : v) {
//            for (int i = s.length() - 1; i >= 0; --i) {
//                if (i == s.length() - 1 || i == 0) {
//                    if (!std::isalpha(s[i])) return false;
//                } else {
//                    if (!(std::isalpha(s[i])) && !(s[i] == ' ')) return false;
//                }
//            }
//        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    std::vector<char> curr_str;
    void BeforeTestCase() {
        A.clear();
        curr_str.clear();
    }
    void randomArray() {
        for (int m = 0; m < M; ++m) {
            int N = rnd.nextInt(1, 255);
            char letters[] =
                "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
            int index = rnd.nextInt(2 * 26);
            curr_str.push_back(letters[index]);
            for (int i = 1; i < N - 1; ++i) {
                int index = rnd.nextInt(2 * 26 + 1);
                curr_str.push_back(letters[index]);
            }
            index = rnd.nextInt(2 * 26);
            std::string str(curr_str.begin(), curr_str.end());
            A.push_back(str);
        }
    }

    void TestCases() {
        M = rnd.nextInt(1, 255);
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
