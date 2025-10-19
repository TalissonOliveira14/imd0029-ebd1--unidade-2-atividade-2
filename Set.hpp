#ifndef Set_hpp
#define Set_hpp

#include <string>

class Set {
private:
    int quantity;
    int capacity;
    std::string *array;
    const int CAPACITY_DEFAULT = 17;
    
    void resize();

public:
    Set();
    Set(int);
    ~Set();
    bool add(std::string s);
    void clear();
    bool contains(std::string s);
    bool isEmpty();
    bool remove(std::string s);
    int size();
};

#endif