#include "source_file_a.hpp"

using namespace std;

namespace my_namespace_A {

template<class T> ostream& operator<<(ostream& os, const vector<T>& v) {os<<"{";for(T const& x:v){os<<x<<",";}os<<"}";return os;}
template ostream& operator<<(ostream& os, const vector<int>& v);

template<class T> my_class_A<T>::my_class_A() : v_(10) {}
template class my_class_A<int>;

}
