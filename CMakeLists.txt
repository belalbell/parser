cmake_minimum_required(VERSION 3.10)
project(Parser)

set(CMAKE_CXX_STANDARD 11)

add_executable(Parser main.cpp InputHandler.cpp InputHandler.h parsing.cpp parsing.h ImmediateLeftRecursion.h ImmediateLeftRecursion.cpp NotImmediateLeftRecursion.h NotImmediateLeftRecursion.cpp LeftFactoring.h LeftFactoring.cpp SymbolsNames.h SymbolsNames.cpp tableTracer.h tableTracer.cpp Save_Load.h Save_Load.cpp)