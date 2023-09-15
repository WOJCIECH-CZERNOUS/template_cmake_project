#include <map>

#include "source_dir_A/source_file_a.hpp"
#include "source_dir_B/source_file_b.hpp"

using namespace std;
using namespace my_namespace_A;
using namespace my_namespace_B;

using TestFunctionType = void (*)();

int main(int argc, char* argv[]) {

    map<string, TestFunctionType> test {
        { "test1", []() {
            my_class_A<int> a;
            out(a);
        } },
    };

    if (argc > 1)
    {
        string name = string(argv[1]);
        // Do *one* test, according to the choice communicated in the command line arg:
        test[name]();
    } else {
        // test["test20"]();
    }
    return 0;
} 
