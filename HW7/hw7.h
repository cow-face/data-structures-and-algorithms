//
// Created by Caden Unnasch on 11/15/20.
//

#ifndef HW7_H
#define HW7_H

#include "hw4.h"
#include "recursive.h"
#include<unordered_map>

void hash_test1 (list_t);

list_t Hash1 (list_t list);

list_t Hash1Helper (list_t list, list_t new_list);

void hash_test2 (list_t list);

list_t odd_fn (list_t list, list_t new_list, int product_of_odd);

int ProductOfOdd(list_t list);

int ProductOfOddHelper(list_t list, int product_of_odd);

list_t even_fn (list_t list, list_t new_list, list_t old_list, int sum_of_list);

list_t Hash2 (list_t list);

list_t DifferenceHelper (list_t list1, list_t list2, list_t new_list);

list_t Difference (list_t list1, list_t list2);

list_t ReadListFromInput(std::string input_list);

bool IsPrime(int);

int Factorial(int n);

int SumWithoutPrimes(list_t list, list_t old_list);

static int SumWOPrimesHelper(list_t list, list_t old_list, int result);

int collisions_cnt(list_t list, std::unordered_map<int, int> map, int collisions);

void Collisions(list_t old_hashed_list, list_t new_hashed_list, std::string test_name);



#endif //HW7_H
