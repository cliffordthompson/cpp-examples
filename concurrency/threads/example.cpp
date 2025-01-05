//***************************************************************************//
//*                                                                         *//
//*  Copyright (c) 2024 Clifford Thompson                                   *//
//*                                                                         *//
//*  All code in this file is released under Creative Commons Attribution   *//
//*  (CC-BY) license : https://creativecommons.org/licenses/by/4.0/.        *//
//*                                                                         *//
//***************************************************************************//

#include <iostream>
#include <thread>

void func1(void);
void func2(const int value);
void func3(const int& value);

class functor1 {
public:
  void operator()()
  {
    std::cout << "In functor1::operator()\n";
  }
};

int
main()
{
  std::cout << "|------------- Start -------------|\n";

  std::cout << "Starting threads\n";
  std::thread t1(func1);
  std::thread t2(func2, 99);

  int value = 69;
  std::cout << "Address of 'value': " << &value << "\n";
  std::thread t3(func3, std::ref(value));

  functor1 myFunctor;
  std::thread t4(std::ref(myFunctor));

  std::cout << "Joining threads\n";
  t1.join();
  t2.join();
  t3.join();
  t4.join();
  std::cout << "Joined threads\n";

  std::cout << "|-------------- End --------------|\n";
  return 0;
}

void
func1(void)
{
  std::cout << "In func1()\n";
}

void
func2(const int value)
{
  std::cout << "In func2(" << value << ")\n";
}

void
func3(const int& value)
{
  std::cout << "In func3(" << &value << ")\n";
}


