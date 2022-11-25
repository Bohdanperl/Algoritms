include "Algo.h"
#include <array>
#include <iostream>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <utility>

void algo_generate(int *begin, int *end) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 100);
  while (begin <= end) {
    *begin = dist6(rng);
    begin++;
  }
}

void *algo_find(int *begin, int *end, int val) {

  while (begin != end) {
    if (*begin == val) {
      return begin;
    }
    begin++;
  }
  return end;
}

void copy(int *src_begin, int *src_end, int *dest_begin) {

  while (src_begin != src_end) {
    *dest_begin++ = *src_begin++;
  }
}

void shuffle1(int *begin, int *end) {

  int leught{end - begin};
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(0, leught);

  if (begin == end) {
    return;
  }

  for (int i{}; i < leught; i++) {

    std::swap(begin[i], begin[dist6(rng)]);
  }
}

bool isNegative(int val) { return val <= 0; }

bool all_of(int *begin, int *end, bool (*foo)(int)) { // all {-10,-5,-45, 34}
  while (begin != end) {
    if (!foo(*begin)) {
      return false;
    }
    begin++;
  }
  return true;
}

bool any_of(int *begin, int *end, bool (*foo)(int)) { //{23,32,45,-56}
  while (begin != end) {
    if (foo(*begin)) {
      return true;
    }
    begin++;
  }
  return false;
}

int Power(int val) { return {val * 2}; }

void transform(int *begin, int *end, int *dest, int (*func)(int)) { // {5,4,6}

  while (begin != end) {
    *dest++ = func(*begin++);
  }
}

void copy_if(int *begin, int *end, int *dest, bool (*func)(int)) { // {5,4,6}

  while (begin != end) {
    if (func(*begin)) {
      *dest++ = *begin;
    }
    begin++;
  }
}

void sort_arr(int *begin, int *end) { //{2,5,1,23,10}
  if (begin == end) {
    return;
  }
  for (auto it{begin}; begin != end; it++) {

    for (auto it2{begin}; begin != end; it2++) {
      if (*it > *it2) {
        std::swap(*it, *it2);
      }
    }
  }
}

void sort_arr1(int *begin, int *end) {
  if (begin == end) {
    return;
  }
  for (int *temp{begin}; temp != end; temp++) {
    std::cout << *temp << std::endl;
    for (int *temp1{temp}; temp1 < end; temp1++) {
      if (*temp > *temp1) {
        std::swap(*temp, *temp1);
      }
    }
  }
}

void marger(int *begin, int *end, int *begin_second, int *end_second,
            int *dest) {

  while (begin != end + 1) {
    *dest++ = *begin++;
  }

  while (begin_second != end_second + 1) {
    *dest++ = *begin_second++;
  }
}

int *min_elem(int *begin, int *end) {
  int *temp_min{begin++};
  while (begin != end) {

    if (*begin < *temp_min) {
      temp_min = begin;
    }
    begin++;
  }
  return temp_min;
}

int *max_elem(int *begin, int *end) {
  int *temp_max{begin++};
  while (begin != end) {

    if (*begin > *temp_max) {
      temp_max = begin;
    }
    begin++;
  }
  return temp_max;
}

std::pair<int *, int *> min_max(int *begin, int *end) {
  int *temp_max{begin++};
  int *temp_min{begin++};
  while (begin != end) {

    if (*begin > *temp_max) {
      temp_max = begin;
    } else if (*begin < *temp_min) {
      temp_min = begin;
    }
    begin++;
  }
  return std::make_pair(temp_max, temp_min);
}

void merget_sort(int *begin_first_array, int *end_first_array,
                 int *begin_second_array, int *end_second_array,
                 int *begin_dest) {
  /*
  //auto leught_arr3{ (end_first_array - begin_first_array) + (end_second_array
  - begin_second_array) }; for (int it{}; it != leught_arr3; it++) { if
  (*begin_first_array > *begin_second_array) { if (begin_second_array !=
  end_second_array) { *begin_dest++ = *begin_second_array++;
                  }
      }
          else {
                  if (begin_first_array != end_first_array) {
                          *begin_dest++ = *begin_first_array++;
                  }
          }
  }*/
  while (begin_first_array != end_first_array) {

    if (begin_second_array == end_second_array) { // if second empty
      return copy(begin_first_array, end_first_array, begin_dest);
    }
    if (*begin_first_array > *begin_second_array) {
      *begin_dest++ = *begin_second_array++;
      continue;
    }
    if (*begin_first_array < *begin_second_array) {
      *begin_dest++ = *begin_first_array++;
    }
  }
  copy(begin_second_array, end_second_array, begin_dest); // if first empty
}

bool equal(int *begin_first_array, int *end_first_array,
           int *begin_second_array, int *end_second_array) {
  auto size_1{end_first_array - begin_first_array};
  auto size_2{end_second_array - begin_second_array};
  if (size_1 != size_2) {
    return false;
  }
  for (; begin_first_array != end_first_array;
       begin_first_array++, begin_second_array++) {
    if (*begin_first_array != *begin_second_array) {
      return false;
    }
  }

  return true;
}

int acumulate(int *begin, int *end) {
  int sum{};
  for (; begin != end; begin++) {
    sum += *begin;
  }
  return sum;
}

int mult(int elem_1, int elem_2) { return elem_1 * elem_2; }

int acumulate(int *begin, int *end, int init, int (*sum_func)(int, int)) {

  for (; begin != end; begin++) {
    init = sum_func(*begin, init);
  }
  return init;
}
