#include<iostream>
#include "recursive.h"
#include "hw4.h"
#include "hw7.h"

using namespace std;

bool ListEqual(list_t l1, list_t l2)
    // EFFECTS: reeturns true of l1 and l2 are equal, false otherwise
{
    // If either are empty, both must be empty for equality
    if (list_isEmpty(l1) || list_isEmpty(l2)) {
	return (list_isEmpty(l1) && list_isEmpty(l2));
    }

    if (list_first(l1) != list_first(l2)) {
	return false;
    } else {
	return ListEqual(list_rest(l1), list_rest(l2));
    }
}

bool notByFour(int i)
{
    return (i%4);
}

int main() {
  //   list_t original = list_make();
  //   list_t rotated = list_make();
  //   list_t testlist;

  //   const int largest = 7;
  //   const int steps = 4+largest;

  //   bool answer = true;

  //   for (int i = largest-1; i>=0; i--) {
  //     original = list_make(i, original);
  //     rotated = list_make((i+steps)%largest, rotated);
  //   }

  //   testlist = rotate(original, steps);
  //   bool results  = ListEqual(testlist, rotated);

  // list_print(rotated);
  // list_print(testlist);
  
  // for (int i = 0; i < 20; i++) {
  //   cout << fib_tail(i) << endl;
  // }

  /*list_t test_list = list_make();
  list_t test_list2 = list_make();

  for (int i = 1; i < 11; i++) {
    test_list = list_make(i, test_list);
    test_list2 = list_make(11-i, test_list2);
  }


  cout << sum(test_list) << endl;
  cout << product(test_list) << endl;
  list_print(test_list);
  cout << endl;
  list_print(test_list2);
  cout << endl;

  list_print(filter_odd(test_list));

  cout << endl;

  list_print(filter_even(test_list));

  cout << endl;

  list_print(append(test_list, test_list2));*/

  list_t new_list = list_make();
  list_t old_hash_test = list_make();
  old_hash_test = list_make(29, old_hash_test);
  old_hash_test = list_make(26, old_hash_test);
  old_hash_test = list_make(24, old_hash_test);
  old_hash_test = list_make(23, old_hash_test);
  old_hash_test = list_make(22, old_hash_test);
  old_hash_test = list_make(22, old_hash_test);

  list_t old_hash_test2 = list_make();
  old_hash_test2 = list_make(62, old_hash_test);
  old_hash_test2 = list_make(20, old_hash_test);
  old_hash_test2 = list_make(56, old_hash_test);
  old_hash_test2 = list_make(18, old_hash_test);
  old_hash_test2 = list_make(58, old_hash_test);
  old_hash_test2 = list_make(16, old_hash_test);

  string input_list;
  getline(cin, input_list);
  new_list = ReadListFromInput(input_list);

  hash_test1(new_list);

}