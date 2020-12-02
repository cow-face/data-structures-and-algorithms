//
// Created by Caden Unnasch on 11/15/20.
//

//Standard Includes
#include<iostream>
#include<sstream>
#include<unordered_map>

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
    list_t hashed_list = Hash1(list);
    std::cout << "hash_output: ";
    list_print(hashed_list);
    std::cout << std::endl;
    std::cout << "final_diff_output: ";
    list_print(Difference(Hash1(list), old_hash_test));
    Collisions(old_hash_test, hashed_list, "hash_test1");
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
    list_t hashed_list = Hash2(list);
    std::cout << "hash_output: ";
    list_print(hashed_list);
    std::cout << std::endl;
    std::cout << "final_diff_output: ";
    list_print(Difference(hashed_list, old_hash_test));
    Collisions(old_hash_test, hashed_list, "hash_test2");
}

list_t odd_fn (list_t list, list_t new_list, int product_of_odd) {
    if (list_isEmpty(list)) {
        return new_list;
    }
    int input = list_first(list);
    if (input % 2 == 1) {
        input = input + product_of_odd;
    }
    new_list = list_make(input, new_list);
    return odd_fn(list_rest(list), new_list, product_of_odd);
}

list_t even_fn (list_t list, list_t new_list, list_t old_list, int sum_of_list) {
    if (list_isEmpty(list)) {
        return new_list;
    }
    int input = list_first(list);
    if (input == list_first(old_list)) {
      input += sum_of_list;
    }
    new_list = list_make(input, new_list);
    return even_fn(list_rest(list), new_list, list_rest(old_list), sum_of_list);
}



list_t Hash2 (list_t list) {
    list_t old_list = list;
    list_t empty_list = list_make();
    list_t new_list = reverse(odd_fn(list, empty_list, product(filter_odd(list))));
    int sum_of_list = SumWithoutPrimes(new_list, old_list);
    new_list = reverse(even_fn(new_list, empty_list, old_list, sum_of_list));
    return new_list;
}

static int SumWOPrimesHelper(list_t list, list_t old_list, int result) {
  if (list_isEmpty(list)) {
    return result;
  }
  int input = list_first(list);
  if (!IsPrime(input) && input != list_first(old_list)) {
    result += input;
  }
  return SumWOPrimesHelper(list_rest(list), list_rest(old_list), result);
}

int SumWithoutPrimes(list_t list, list_t old_list) {
  return SumWOPrimesHelper(list,old_list,0);
}

bool IsPrime(int n) {
  if (n == 0 || n == 1) {
    return false;
  }
  if ((Factorial(n-1) % n == (-1 % n)) || (Factorial(n-1) % n == ((n-1) % n))) {
    return true;
  }
  return false;
}

int Factorial(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }
  else {
    return Factorial(n - 1) * n;
  }
}





//Common Code
list_t DifferenceHelper (list_t list1, list_t list2, list_t new_list) {
    if (list_isEmpty(list1)) {
        return new_list;
    }
    int input = abs(list_first(list1) - list_first(list2));
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

int collisions_cnt(list_t list, std::unordered_map<int, int> map, int collisions) {
  if (list_isEmpty(list)) {
    return collisions;
  }
  int input = list_first(list);
  if (map.count(input) == 1 ){
    collisions++;
  }
  else {
    map[input] = 1;
  }
  return collisions_cnt(list_rest(list), map, collisions);
}


void Collisions(list_t old_hashed_list, list_t new_hashed_list, std::string test_name) {
  std::unordered_map<int, int> old_hash_map;
  std::unordered_map<int, int> new_hash_map;
  std::cout << std::endl << "collision cnt" << std::endl;
  std::cout << test_name << std::endl;
  std::cout << "new_code : " << collisions_cnt(new_hashed_list, new_hash_map, 0) << std::endl;
  std::cout << "old_code : " << collisions_cnt(old_hashed_list, old_hash_map, 0) << std::endl;
}

