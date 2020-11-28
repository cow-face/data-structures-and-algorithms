//
// Created by Caden Unnasch on 11/15/20.
//

//Standard Includes
#include<iostream>
#include<sstream>

//Header File Includes
#include "hw4.h"
#include "recursive.h"
#include "hw7.h"

void hash_test1 (list_t list);
list_t Hash1 (list_t list);
list_t Hash1Helper (list_t list, list_t new_list);

//Hash 1 Test Code
void hash_test1 (list_t list) {
    std::string old_hash_test_string;
    std::getline(std::cin, old_hash_test_string);
    list_t old_hash_test = ReadListFromInput(old_hash_test_string);
    std::cout << "hash_output: ";
    list_print(Hash1(list));
    std::cout << std::endl;
    std::cout << "final_diff_output: ";
    list_print(Difference(Hash1(list), old_hash_test));
}

list_t Hash1Helper (list_t list, list_t new_list, int sum_of_list) {
    if (list_isEmpty(list)) {
        return new_list;
    }
    int input = list_first(list);
    input = fib_tail(input) + sum_of_list;
    new_list = list_make(input, new_list);
    return Hash1Helper(list_rest(list), new_list, sum_of_list);
}

list_t Hash1 (list_t list) {
    list_t new_list = list_make();
    new_list = Hash1Helper(reverse(list), new_list, sum(list));
    return new_list;
}





//Hash 2 Test Code
void hash_test2 (list_t list) {
    std::string old_hash_test_string;
    std::getline(std::cin, old_hash_test_string);
    list_t old_hash_test = ReadListFromInput(old_hash_test_string);
    std::cout << "hash_output: ";
    list_print(Hash1(list));
    std::cout << std::endl;
    std::cout << "final_diff_output: ";
    list_print(Difference(Hash1(list), old_hash_test));
}

list_t Hash2OddHelper (list_t list, list_t new_list, int product_of_odd) {
    if (list_isEmpty(list)) {
        return new_list;
    }
    int input = list_first(list);
    if (input % 2 == 1) {
        input = input + product_of_odd;
    }
    new_list = list_make(input, new_list);
    return Hash1Helper(list_rest(list), new_list, product_of_odd);
}

list_t Hash2EvenHelper (list_t list, list_t new_list, int sum_of_list) {
    if (list_isEmpty(list)) {
        return new_list;
    }
    int input = list_first(list);
    input = fib_tail(input) + sum_of_list;
    new_list = list_make(input, new_list);
    return Hash1Helper(list_rest(list), new_list, sum_of_list);
}


list_t Hash2 (list_t list) {
    list_t new_list = list_make();
    new_list = Hash2OddHelper(list, new_list, product(filter_odd(list)));
    return new_list;
}





//Common Code
list_t DifferenceHelper (list_t list1, list_t list2, list_t new_list) {
    if (list_isEmpty(list1)) {
        return new_list;
    }
    int input = list_first(list1) - list_first(list2);
    new_list = list_make(input, new_list);
    return DifferenceHelper(list_rest(list1), list_rest(list2), new_list);
}

list_t Difference (list_t list1, list_t list2) {
    return DifferenceHelper(reverse(list1),reverse(list2), list_make());
}

list_t ReadListFromInput(std::string input_list) {
    std::stringstream input_stream(input_list);
    if (input_stream.peek() == '(' || input_stream.peek() == ',') {
        input_stream.ignore();
    }
    list_t new_list = list_make();
    for (int i; input_stream >> i;) {
        new_list = (list_make(i, new_list));
        if (input_stream.peek() == '(' || input_stream.peek() == ',') {
            input_stream.ignore();
        }
    }
    return(reverse(new_list));
}
