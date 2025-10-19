#include <iostream>
#include <cassert>
#include "Set.hpp"

void testInsert() {
    Set s;
    assert( s.size() == 0 );
    
    assert( s.contains("teste" ) == false );
    assert( s.contains("set" ) == false );
    
    assert( s.add("teste") == true );
    assert( s.size() == 1 );
    assert( s.contains("teste" ) == true );
    assert( s.add("teste") == false );
    
    assert( s.add("set") == true );
    assert( s.size() == 2 );
    assert( s.contains("set" ) == true );
    assert( s.add("set") == false );
    
    assert( s.contains("teste" ) == true );
    
    Set smallSet(2);
    assert(smallSet.add("a") == true);
    assert(smallSet.add("b") == true);
    assert(smallSet.add("c") == true);
    assert(smallSet.size() == 3);
    assert(smallSet.contains("a") == true);
    assert(smallSet.contains("b") == true);
    assert(smallSet.contains("c") == true);
}

void testRemove(){
    Set s;
    assert( s.size() == 0);
    
    assert( s.contains("teste1") == false );
    assert( s.contains("teste2") == false );
    assert( s.contains("teste3") == false );
    
    assert( s.add("teste1") == true );
    assert( s.size() == 1 );
    
    assert( s.add("teste2") == true );
    assert( s.size() == 2 );
    
    assert( s.add("teste3") == true );
    assert( s.size() == 3 );
    
    assert( s.contains("teste2") == true );
    assert( s.size() == 3 );
    assert( s.remove("teste2") == true );
    assert( s.size() == 2 );
    assert( s.contains("teste2") == false );
    assert( s.remove("teste2") == false );
    
    assert( s.contains("teste3") == true );
    assert( s.size() == 2 );
    assert( s.remove("teste3") == true );
    assert( s.size() == 1 );
    assert( s.contains("teste3") == false );
    assert( s.remove("teste3") == false );
    
    assert( s.contains("teste1") == true );
    assert( s.size() == 1 );
    assert( s.remove("teste1") == true );
    assert( s.size() == 0 );
    assert( s.contains("teste1") == false );
    assert( s.remove("teste3") == false );
}

void testClear() {
    Set s;
    s.add("a");
    s.add("b");
    s.add("c");
    assert(s.size() == 3);
    
    s.clear();
    assert(s.size() == 0);
    assert(s.isEmpty() == true);
    assert(s.contains("a") == false);
    assert(s.contains("b") == false);
    assert(s.contains("c") == false);
}

void testEdgeCases() {
    Set s;
    
    assert(s.add("") == true);
    assert(s.contains("") == true);
    assert(s.add("") == false);
    assert(s.remove("") == true);
    assert(s.contains("") == false);
    
    assert(s.remove("inexistente") == false);
    assert(s.contains("qualquer") == false);
}

int main(int argc, const char * argv[]) {
    std::cout << "Begin - Test_Insert.\n";
    testInsert();
    std::cout << "End - Test_Insert.\n";
    
    std::cout << "Begin - Test_Remove.\n";
    testRemove();
    std::cout << "End - Test_Remove.\n";
    
    std::cout << "Begin - Test_Clear.\n";
    testClear();
    std::cout << "End - Test_Clear.\n";
    
    std::cout << "Begin - Test_Edge_Cases.\n";
    testEdgeCases();
    std::cout << "End - Test_Edge_Cases.\n";
    
    std::cout << "\nAll tests passed successfully!\n";
    
    return 0;
}
