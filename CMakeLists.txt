cmake_minimum_required(VERSION 3.0.0)
project(TP1_C++ VERSION 0.1.0)

include(CTest)
enable_testing()
SET(sources main.cpp Magasin.cpp Client.cpp Produit.cpp)
add_executable(TP1_C++ ${sources})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
