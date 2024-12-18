cmake_minimum_required(VERSION 3.23)
project(L2Pb24DSA)

set(CMAKE_CXX_STANDARD 20)

add_executable(L2Pb24DSA App.cpp SortedIteratedList.cpp SortedIteratedList.h ListIterator.cpp ListIterator.h ExtendedTest.cpp ExtendedTest.h ShortTest.cpp ShortTest.h)
