//
// Created by Caden Unnasch on 11/15/20.
//

#ifndef HW7_H
#define HW7_H

#include "hw4.h"
#include "recursive.h"

void hash_test1 (list_t);

list_t Hash1 (list_t list);

list_t Hash1Helper (list_t list, list_t new_list);

void hash_test2 (list_t list);

list_t Hash2OddHelper (list_t, list_t, int);

list_t Hash2EvenHelper (list_t, list_t, int);

list_t Hash2 (list_t list);

list_t DifferenceHelper (list_t list1, list_t list2, list_t new_list);

list_t Difference (list_t list1, list_t list2);

list_t ReadListFromInput(std::string input_list);

#endif //HW7_H
