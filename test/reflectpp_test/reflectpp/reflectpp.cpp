#include <iostream>
#include <string>
#include <reflect.h>

#define _STRINGFY(expression) #expression
#define STRINGFY(expression) _STRINGFY(expression)  


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

void printHumanizedCode(const std::string& code)
{
    int tabs = 0;
    bool putendline = false;
    char oldchar = 0;

    for (auto ch : code)
    {
        // skipping spaces at the beginning of the line
        if (putendline && ch == ' ')
            continue;

        // keeping together {};
        if ((oldchar == '{' && ch == '}') || 
            (oldchar == '}' && ch == ';'))
        {
            if(oldchar == '{') 
                tabs--;
            std::cout << ch;
        }

        else
        {
            if (putendline) {
                std::cout << std::endl;
                const auto ntabs = ch != '}' ? tabs : tabs - 1;
                for (int i = 0; i < ntabs; i++)
                    std::cout << "    ";
            }

            // handling open braces
            if (ch == '{' || ch == '}' || ch == ';')
            {
                std::cout << ch;
                if(ch == '{' || ch == '}')
                    tabs += ch == '}' ? -1 : 1;
            }

            // default routine
            else
            {
                std::cout << ch;
            }
        }

        oldchar = ch;
        putendline = ch == '{' || ch == '}' || ch == ';';
    }

    std::cout << std::endl;
}

int main()
{
    // print of a macro expansion
    // helpful to know how the macro generates the class
    std::string macroExp = STRINGFY(REFL_CLASS_SERIALIZABLE(
        REFL_CLASS_NAME(BaseClass),
        REFL_MEMBER(std::vector<int>, integer_vector)
    ););

    macroExp += STRINGFY(REFL_CLASS_DERIVED_SERIALIZABLE(
        REFL_CLASS_NAME(DerivedClass),
        REFL_BASE_NAME(BaseClass),
        REFL_MEMBER(int, age)
    ););

    // humanizing code for a better readability
    std::cout << "Humanized Code:\n";
    printHumanizedCode(macroExp);
    std::cout << "\n\n\n";

    DerivedClass test;
    test.age = 30;
    test.integer_vector = {100, 20, 25};

    ExampleSerializer ser;
    test.serialize(ser);

    std::cout << "Example of serialized reflect class\n";
    std::cout << ser.result << std::endl;
    return 0;
}
