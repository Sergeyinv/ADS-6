// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <cassert>

template<typename T, int size>
class TPQueue {
 private:
  T* arr;
  int nowSize;
  int cap;
  int head, tail;
 public:
 
  TPQueue() :cap(size), head(0), tail(0), nowSize(0) {
    arr = new T[cap + 1];
  }
  void push(const T& value) {
    assert(nowSize < cap);
    if (nowSize == 0) {
      arr[tail++] = value;
      nowSize++;
    } else {
      int i = tail - 1;
      bool f = 0;
      while (i >= head && value.prior > arr[i].prior) {
        f = 1;
        arr[i + 1] = arr[i];
        arr[i] = value;
        i--;
      }
      if (f == 0) {
        arr[tail] = value;
      }
      tail++;
      nowSize++;
    }
    if (tail > cap) {
      tail -= cap + 1;
    }
  }
  const T& pop() {
    assert(nowSize > 0);
    nowSize--;
    if (head > cap) {
      head -= cap + 1;
    }
    return arr[head++];
  }
  char get() {
    assert(nowSize > 0);
    return arr[head].ch;
  }
  bool isFull() const {
    return nowSize == cap;
  }
  bool isEmpty() const {
    return nowSize == 0;
  }
  ~TPQueue() {
    delete[] arr;
  }
};
struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
