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

/*
 * hash_test1 ()
 *  Let list = get line from console
 *  Let old_hash_test = getline from console
 *  Let hashed_list = Hash1 (list)
 *  Print hashed_list
 *  Print Difference between hashed_list and old_hash_test
 *  Print Collisions
 * */
void hash_test1 () {
  std::string list_string;
  std::getline(std::cin, list_string);
  list_t list = ReadListFromInput(list_string);
  std::string old_hash_test_string;
  std::getline(std::cin, old_hash_test_string);
  list_t old_hash_test = ReadListFromInput(old_hash_test_string);
  list_t hashed_list = Hash1(list);
  std::cout << "hash_output: ";
  list_print(hashed_list);
  std::cout << std::endl;
  std::cout << "final_diff_output: ";
  list_print(Difference(hashed_list, old_hash_test));
  Collisions(old_hash_test, hashed_list, "hash_test1");
}

/*
 * Hash1Helper (list, new_list, sum_of_list)
 *  If list is empty
 *    Return new_list
 *  Let input = first item of list
 *  Let input = fibonnaci(input) + sum_of_list
 *  new_list = input + new_list
 *  Return Hash1Helper(list without first item, new_list, sum_of_list)
 * */
list_t Hash1Helper (list_t list, list_t new_list, int sum_of_list) {
  if (list_isEmpty(list)) {
    return new_list;
  }
  int input = list_first(list);
  input = fib_tail(input) + sum_of_list;
  new_list = list_make(input, new_list);
  return Hash1Helper(list_rest(list), new_list, sum_of_list);
}

/*
 * Hash1 (list)
 *  Let new_list = Hash1Helper(reverse(list), new_list, sum(list))
 *  Return new_list
 * */

list_t Hash1 (list_t list) {
  list_t new_list = list_make();
  new_list = Hash1Helper(reverse(list), new_list, sum(list));
  return new_list;
}





//Hash 2 Test Code

/*
 * hash_test2 ()
 *  Let list = get line from console
 *  Let old_hash_test = getline from console
 *  Let hashed_list = Hash2 (list)
 *  Print hashed_list
 *  Print Difference between hashed_list and old_hash_test
 *  Print Collisions
 * */

void hash_test2 () {
  std::string list_string;
  std::getline(std::cin, list_string);
  list_t list = ReadListFromInput(list_string);
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

/*
 * odd_fn (list, new_list, product_of_odd)
 *  If list is empty
 *    Return new_list
 *  Let input = first item in list
 *  If input is even
 *    Let input = input + product_of_odd
 *  Let new_list = input + new_list
 *  Return odd_fn(list without first element, new_list, product of odd)
 * */
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

/*
 * even_fn (list, new_list, old_list, sum_of_list)
 *  If list is empty
 *    return new_list
 *  Let input = first element of list
 *  If input == the first element of old list
 *    Let input = input + sum_of_list
 *  Let new_list = input + new_list
 *  Return even_fn(list without first element, new_list, old_list without first element, sum_of_list)
 *
 * */
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


/*
 * Hash2 (list)
 *  Let old_list = list
 *  Let empty_list = empty list
 *  Let new_list = reverse(odd_fn(list, empty_list, product(filter_odd(list)))
 *  Let sum_of_list = SumWithoutPrimes(new_list, old_list)
 *  Let new_list = reverse(even_fn(new_list, empty_list, old_list, sum_of_list)))
 *  Return new_list
 * */
list_t Hash2 (list_t list) {
  list_t old_list = list;
  list_t empty_list = list_make();
  list_t new_list = reverse(odd_fn(list, empty_list, product(filter_odd(list))));
  int sum_of_list = SumWithoutPrimes(new_list, old_list);
  new_list = reverse(even_fn(new_list, empty_list, old_list, sum_of_list));
  return new_list;
}

/*
 * SumWOPrimesHelper(list, old_list, result)
 *  If list is empty
 *    Return result
 *  Let input = first item in list
 *  If input isn't prime and isn't the same as the first element of old list
 *    Let result = result + input
 *  Return SumWOPrimesHelper(list without first element, old_list without first element, result)
 *
 * */
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

/*
 * SumWithoutPrimes(list, old_list)
 *  Return SumWOPrimesHelper(list, old_list, 0)
 * */
int SumWithoutPrimes(list_t list, list_t old_list) {
  return SumWOPrimesHelper(list,old_list,0);
}


/*
 * IsPrime(n)
 *  If n == 0 or n == 1
 *    Return false
 *  If ((n-1)! mod n == (-1 % n) or (n-1)! mod n == (n-1) mod n
 *    Return true
 *  Return false
 * */
bool IsPrime(int n) {
  if (n <= 1) {
    return false;
  }
  if ((Factorial(n-1) % n == (-1 % n)) || (Factorial(n-1) % n == ((n-1) % n))) {
    return true;
  }
  return false;
}


/*
 * Factorial(n)
 *  If n == 0 or n == 1
 *    Return 1
 *  Else Return Factorial(n-1) * n
 * */
int Factorial(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }
  else {
    return Factorial(n - 1) * n;
  }
}





//Common Code

/* DifferenceHelper(list, list2, list new_list)
 *  If list is empty
 *    Return new_list
 *  Let input = |first element of list1 - first element of list 2|
 *  Let new_list = input + new_list
 *  Return DifferenceHelper(list1 without first element, list2 without first element, new_list)
 * */
list_t DifferenceHelper (list_t list1, list_t list2, list_t new_list) {
  if (list_isEmpty(list1)) {
      return new_list;
  }
  int input = abs(list_first(list1) - list_first(list2));
  new_list = list_make(input, new_list);
  return DifferenceHelper(list_rest(list1), list_rest(list2), new_list);
}


/*
 * Difference(list1, list2)
 *  Return DifferenceHelper(reverse(list1), reverse(list2), empty list)
 * */
list_t Difference (list_t list1, list_t list2) {
  return DifferenceHelper(reverse(list1),reverse(list2), list_make());
}


/*
 * ReadListFromInput(input_list)
 *  Let new_list = empty list
 *  For each char in input_list
 *    If char == '(' or ','
 *      ignore
 *    Else
 *      add to list
 *  Return reverse(new_list)
 *
 * */
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


/*
 * collisions_cnt (list, map, collisions)
 *  If list is empty
 *    return collisions
 *  Let input = first element of list
 *  If input is in map
 *    collisions++
 *  Else
 *    add input to map
 *  Return collisions_cnt(list without first element, map, collisions)
 *
 * */
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


/*
 * Collisions(old_hashed_list, new_hashed_list, test_name)
 *  Declare old_hash_map
 *  Declare new_hash_map
 *  Print line "collision cnt"
 *  Print line test_name
 *  Print line "new_code : " + collisions_cnt(new_hashed_list, new_hash_map, 0)
 *  Print line "old_code : " + collisions_cnt(old_hashed_list, old_hash_map, 0)
 * */
void Collisions(list_t old_hashed_list, list_t new_hashed_list, const std::string& test_name) {
  std::unordered_map<int, int> old_hash_map;
  std::unordered_map<int, int> new_hash_map;
  std::cout << std::endl << "collision cnt" << std::endl;
  std::cout << test_name << std::endl;
  std::cout << "new_code : " << collisions_cnt(new_hashed_list, new_hash_map, 0) << std::endl;
  std::cout << "old_code : " << collisions_cnt(old_hashed_list, old_hash_map, 0) << std::endl;
}

