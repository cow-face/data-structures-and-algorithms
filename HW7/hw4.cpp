/**
PSEUDOCODE:

SumHelper (list, result)
  If list is empty 
    Return result
  Return SumHelper(list - first element, first element of list + result)


Sum (list)
  Return SumHelper(list,0)

ProductHelper (list, result)
  If list is empty
    Return result
  Return ProductHelper(list - first element, first element of list * result)

Product (list)
  Return ProductHelper(list,1)

ReverseHelper (list, new_list)
  If list is empty
    Return new_list
  Set new_list = first element of list + new_list
  Return ReverseHelper(list - first element, new_list)

Reverse (list)
  Initialize new_list
  Return ReverseHelper(list, new_list)

FilterOddHelper (list, new_list)
  If list is empty
    Return new_list
  If (first element of list is odd)
    new_list = first element of list + new_list
  Return Reverse(FilterOddHelper(list - first element, new_list))

FilterOdd (list)
  Initialize new_list
  Return FilterOddHelper(list, new_list)

FilterEvenHelper (list, new_list)
  If list is empty
    Return new_list
  If (first element of list is even)
    new_list = first element of list + new_list
  Return Reverse(FilterEvenHelper(list - first element, new_list))

FilterEven (list)
  Initialize new_list
  Return FilterEvenHelper(list, new_list)

Filter(list, fn(int), new_list)
  If list is empty
    Return new_list
  If (fn(first element of list))
    new_list = first element of list + new_list
  Return Reverse(FilterOddHelper(list - first element, new_list))

Filter (list, fn(int))
  Initialize new_list
  Return FilterHelper(list, fn, new_list)

AppendHelper (first, second)
  If first is empty
    Return second
  second = first element of first + second
  Return AppendHelper(first - first element, second)

Append (first, second)
  If second is empty 
    Return first
  Initialize new_list
  Return AppendHelper(Reverse(first), second)

ChopHelper (list,n) 
  If list is empty
    Return list
  If n == 0 
    Return list
  list = list - first element
  Return ChopHelper(list, n-1)

Chop(list, n) 
  Return reverse(ChopHelper(reverse(list),n))


Rotate (list, n) 
  If n <= 0 
    Return list;
  
  Initialize new_list
  new_list = first element of list + new_list
  list = append(list_rest(list),new_list)
  Return Rotate(list, n - 1);

Fib (n)
  If n == 0
    Return 0
  If n == 1
    Return 1
  Return Fib(n-1) + Fib(n-2)

FibTailHelper (n, temp, result)
  If n == 0
    Return temp
  Return FibTailHelper(n-1, temp + result)

FibTail (n)
  Return FibTailHelper(n, 0, 1)




**/
#include "recursive.h"
#include "hw4.h"

int accumulate(list_t l, int (*fn)(int, int), int base)
{
  if (list_isEmpty(l)) {
    return base;
  } else {
    return accumulate(list_rest(l), fn, fn(base, list_first(l)));
  }
}

static int SumHelper(list_t list, int result) {
  if (list_isEmpty(list)) {
    return result;
  }
  return SumHelper(list_rest(list),list_first(list)+result);
}

int sum(list_t list) {
  return SumHelper(list,0);
}

static int ProductHelper(list_t list, int result) {
  if (list_isEmpty(list)) {
    return result;
  }
  return ProductHelper(list_rest(list),list_first(list)*result);
}

int product(list_t list) {
  return ProductHelper(list, 1);
}

static list_t ReverseHelper(list_t list, list_t new_list) {
  if(list_isEmpty(list)) {
    return new_list;
  }
  new_list = list_make(list_first(list), new_list);
  return ReverseHelper(list_rest(list), new_list);
}

list_t reverse(list_t list) {
  list_t new_list = list_make();
  return ReverseHelper(list,new_list);
}

static list_t FilterOddHelper(list_t list,list_t new_list) {
  if(list_isEmpty(list)) {
    return new_list;
  }
  if((list_first(list) % 2)) {
    new_list = list_make(list_first(list), new_list);
  }
  return FilterOddHelper(list_rest(list),new_list);
}

list_t filter_odd(list_t list) {
  list_t new_list = list_make();
  return reverse(FilterOddHelper(list,new_list));
}

static list_t FilterEvenHelper(list_t list,list_t new_list) {
  if (list_isEmpty(list)) {
    return new_list;
  }
  if(!(list_first(list) % 2)) {
    new_list = list_make(list_first(list), new_list);
  }
  return FilterEvenHelper(list_rest(list),new_list);
}

list_t filter_even(list_t list) {
  list_t new_list = list_make();
  return reverse(FilterEvenHelper(list,new_list));
}

static list_t FilterHelper(list_t list, bool (*fn)(int), list_t new_list) {
  if (list_isEmpty(list)) {
    return new_list;
  }
  if(fn(list_first(list))) {
    new_list = list_make(list_first(list), new_list);
  }
  return FilterHelper(list_rest(list), fn, new_list);
}

list_t filter(list_t list, bool (*fn)(int)) {
  list_t new_list = list_make();
  return reverse(FilterHelper(list, fn, new_list));
}

static list_t AppendHelper(list_t first, list_t second) {
  if (list_isEmpty(first)) {
    return second;
  }
  second = list_make(list_first(first), second);
  return AppendHelper(list_rest(first), second);
}

list_t append(list_t first, list_t second) {
  if (list_isEmpty(second)) {
    return first;
  }
  list_t new_list = list_make();
  return AppendHelper(reverse(first), second);
}

list_t ChopHelper(list_t list, unsigned int n) {
  if (list_isEmpty(list)){
    return list;
  }
  if (n == 0) {
    return list;
  }
  list = list_rest(list);
  return ChopHelper(list, n-1);
}

list_t chop(list_t list, unsigned int n) {
  return reverse(ChopHelper(reverse(list),n));
}


list_t rotate(list_t list, unsigned int n) {
  if (n <= 0) {
    return list;
  }
  list_t new_list = list_make();
  new_list = list_make(list_first(list), new_list);
  list = append(list_rest(list),new_list);
  return rotate(list, n-1);
}

int fib(int n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  return fib(n-1) + fib (n-2);
}

static int FibTailHelper(int n,int temp, int result) {
  if (n == 0) {
    return temp;
  }
  if (n == 1) {
    return result;
  }
  return FibTailHelper(n-1,result, temp + result);
}

int fib_tail(int n) {
  return FibTailHelper(n,0,1);
}
