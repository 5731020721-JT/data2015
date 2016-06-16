#include <iostream>
#include <vector>

using namespace std;

namespace CP { 
template <typename T> 
class vector {
protected:
  T *mData;
  int mSize;
  int mCap;

  void expand(int cap) {
    T *tmp;
    tmp = new T[cap]();
    for (int i = 0;i < mSize;i++) {
      tmp[i] = mData[i];
    }

    delete [] mData;
    mData = tmp;
    mCap = cap;
  }

  void ensureCapacity(int cap) {
    if (cap > mCap) {
      if (cap < mCap * 2) {
        expand(mCap * 2);
      } else {
        expand(cap);
      }
    }
  }

public:
  vector() : mSize(0) {
    mData = new T[1]();
  }

  void push_back(T x) {
    ensureCapacity(mSize+1);

    if (mSize == mCap) {
      expand(mCap * 2)
    }

    mData[mSize] = x;
    mSize++;
  }

  void insert(int pos, T value) {
    ensureCapacity(mSize+1);

    for (int i = mSize;i > pos;i--) {
      mData[i] = mData[i-1];
    }
    mData[pos] = value;
    shrink();
    mSize++;

  }

  void erase(int pos) {
    for (int i = pos;i < mSize-1;i++) {
      mData[i] = mData[i+1];
    }
    mSize--;
  }

  T& operator[](int pos) {
    return mData[pos];
  }

  int size() {
    return mSize;
  }

};
}


int main() {
  CP::vector<int> v;
  v.push_back(10);
  for (int i = 0;i < v.size();i++) { cout << i << ":" << v[i] << endl; } cout << endl;

  v.push_back(20);
  for (int i = 0;i < v.size();i++) { cout << i << ":" << v[i] << endl; } cout << endl;

  v.push_back(30);
  for (int i = 0;i < v.size();i++) { cout << i << ":" << v[i] << endl; } cout << endl;




}


