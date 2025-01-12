//***************************************************************************//
//*                                                                         *//
//*  Copyright (c) 2024-2025 Clifford Thompson                              *//
//*                                                                         *//
//*  All code in this file is released under Creative Commons Attribution   *//
//*  (CC-BY) license : https://creativecommons.org/licenses/by/4.0/.        *//
//*                                                                         *//
//***************************************************************************//

#include <iostream>
#include <future>

int func1(void);
int func2(const int value);
int func3(const int& value);

int
main()
{
  std::cout << "|------------- Start -------------|\n";

  auto future1 = std::async(func1);
  auto future2 = std::async(func2, 45);

  int value = 46;
  std::cout << "Address of 'value': " << &value << "\n";
  auto future3 = std::async(func3, value);

  future1.wait();
  future2.wait();
  future3.wait();

  std::cout << "Value of future1: " << future1.get() << "\n";
  std::cout << "Value of future2: " << future2.get() << "\n";
  std::cout << "Value of future3: " << future3.get() << "\n";

  std::cout << "|-------------- End --------------|\n";
  return 0;
}

int
func1(void)
{
  std::cout << "In func1()\n";
  return 44;
}

int
func2(const int value)
{
  std::cout << "In func2(" << value << ")\n";
  return value;
}

int
func3(const int& value)
{
  std::cout << "In func3(" << &value << ")\n";
  return value;
}
