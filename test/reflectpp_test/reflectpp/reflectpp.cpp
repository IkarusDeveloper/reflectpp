#include <iostream>
#include <string>
#include <reflect.h>

//#define _STRINGFY(expression) #expression
//#define STRINGY(expression) _STRINGFY(expression)  


REFL_CLASS_SERIALIZABLE(
    REFL_CLASS_NAME(BaseClass),
    REFL_MEMBER(std::vector<int>, integer_vector)
);

REFL_CLASS_DERIVED_SERIALIZABLE(
    REFL_CLASS_NAME(DerivedClass), 
    REFL_BASE_NAME(BaseClass), 
    REFL_MEMBER(int, age)
);

// example of serializer
struct ExampleSerializer {
    std::string result;

    template<class T>
    void put(const std::string_view name, const T& v){ result += name; result += "=" + std::to_string(v) + "\n"; }

    template<class T>
    void put(const std::string_view name, const std::vector<T>& values){
        result += name;
        result += "={";
        for(auto& value : values)
            result += std::to_string(value) + ",";
        result += "}";
        result += "\n";
    }
};

int main()
{
    DerivedClass test;
    test.age = 30;
    test.integer_vector = {100, 20, 25};

    ExampleSerializer ser;
    test.serialize(ser);
    std::cout << ser.result << std::endl;
    return 0;
}
