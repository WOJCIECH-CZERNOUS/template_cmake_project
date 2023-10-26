#include "source_file_a.hpp"
#include "source_file_b.hpp"

using namespace std;
using namespace my_namespace_A;

namespace my_namespace_B {

template<class T> void out(T const& t) { cout << t << endl; }
template void out<my_class_A<int>>(my_class_A<int> const&);

}
