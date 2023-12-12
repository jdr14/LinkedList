//
//  main.cpp
//  LinkedList
//
//  Created by Joseph Rodgers on 12/12/23.
//

#include <iostream>
#include "SingleLinkedList.hpp"

int main(int argc, const char * argv[]) {
    // Test constructors of 2 different types
    LinkedList<int> list;
    LinkedList<std::string> strList;
    
    // Test add
    list.display();
    list.add(1);
    list.display();
    list.add(2);
    list.display();
    list.add(3);
    list.display();
    
    // Test deletes
    list.del(1);
    list.display();
    list.del(2);
    list.display();
    list.del(3);
    list.display();
    
    // Test add again with strings
    strList.display();
    strList.add("hello");
    strList.display();
    strList.add("world");
    strList.display();
    strList.add("cpp");
    strList.display();
    
    // Test search with strings
    if (strList.search("hello") == 0)
        std::cout << "hello found!" <<std::endl;
    if (strList.search("world") == 1)
        std::cout << "world found!" <<std::endl;
    if (strList.search("cpp") == 2)
        std::cout << "cpp found!" <<std::endl;
    if (strList.search("this shouldn't exist") == -1)
        std::cout << "non-existent text NOT found" << std::endl;
    
    // Test deletes reversed
    strList.del("cpp");
    strList.display();
    strList.del("world");
    strList.display();
    strList.del("hello");
    strList.display();
    
    if (list.isEmpty()) // This should be empty at this point
        std::cout << "List is empty" << std::endl;
    
    return 0;
}
