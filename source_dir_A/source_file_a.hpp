#include <iostream>
#include <vector>

namespace my_namespace_A {

template<class T> std::ostream& operator<<(std::ostream& os, std::vector<T> const& v); // declared for "os << a.v_;" below...

template <class T> class my_class_A {
public:
    my_class_A();
    friend std::ostream& operator<<(std::ostream& os, my_class_A const& a) { os << a.v_; return os; }
private:
    std::vector<T> v_;
};

}
