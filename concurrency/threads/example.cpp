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

int
main()
{
  std::cout << "|------------- Start -------------|" << std::endl;

  std::cout << "Starting threads\n";
  std::thread t1(func1);
  std::thread t2(func2, 99);

  std::cout << "Joining threads\n";
  t1.join();
  t2.join();
  std::cout << "Joined threads\n";

  std::cout << "|-------------- End --------------|" << std::endl;
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
