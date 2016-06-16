#include <iostream>
#include <vector>
#include <queue>
#include <assert.h>

using namespace std;

namespace CP {
template <typename T>
class queue {
protected:
  vector<T> mVect;

public:
    // default constructor
    queue(){

    }

       //------------- capacity function -------------------
    bool empty(){
        return mVect.empty();
    }
    size_t size(){
        return mVect.size();
    }
    T& front(){
        return mVect[0];
    }
    T& back(){
        return *(--mVect.end());
    }

    //----------------- modifier -------------
    void push(const T& e){
        mVect.push_back(e);
    }
    void pop(){
        vector<T> temp = mVect;
        mVect.clear();
        for(auto i = temp.begin()+1 ; i< temp.end(); ++i){
            mVect.push_back(*i);
        }
    }


};
}

void test1(){
  CP::queue<int> q;
  assert(q.empty() == true);
  q.push(1);
  q.push(2);
  q.push(3);
  assert(q.size() == 3);
  assert(q.size() != 4);
  assert(q.front() == 1);
  assert(q.back() == 3);
  q.pop();
  assert(q.front() == 2);
  assert(q.size() == 2);
  assert(q.back() == 3);
  q.push(27);
  assert(q.back() == 27);
  assert(q.size() == 3);

  CP::queue<int> q1;
  q1 = q;
  assert(q1.size() == 3);
  assert(q1.front() == 2);
  assert(q1.back() == 27);
}

void test2(){

  CP::queue<vector<int>> q;
  vector<int> v1;
  vector<int> v2;
  for(int i = 1 ; i <= 10 ; i++){
    v1.push_back(i*10);
  }
  q.push(v1);
  q.push(v2);
  assert(q.size() == 2);
  assert(q.front()[0] == 10);
  assert(q.back().empty() == true);
}

void test3(){
  CP::queue<string> q;
  size_t n = 1e6;
  for(size_t i = 0 ; i < n ; i++){
    string a = "a";
    q.push(a);
  }

  assert(q.size() == n);
  assert(q.front() == "a");
  assert(q.back() == "a");

  for (size_t i = q.size(); i > 1 ; i --){
    q.pop();
  }
  assert(q.size() == 1);
  assert(q.front() == "a");
}

int main() {
  test1(); cout << "test1 OK " << endl;
  test2(); cout << "test2 OK " << endl;
  test3(); cout << "test3 OK " << endl;

}
