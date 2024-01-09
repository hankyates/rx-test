cmake_policy(SET CMP0048 NEW)
project (rx-test VERSION 1.0.0)
cmake_minimum_required(VERSION 3.20)

set(TARGET rx)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(MODULE_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(RXCPP_DIR ${CMAKE_CURRENT_LIST_DIR}/RxCpp)
set(DAISY_DIR ${CMAKE_CURRENT_LIST_DIR}/libDaisy)

add_subdirectory(
  ${RXCPP_DIR}
  ${DAISY_DIR}
)

include_directories(${RXCPP_DIR}/Rx/v2/src)

add_executable(${TARGET} ${MODULE_DIR}/main.cpp)
