PROJECT(algo_03_dynamic_programming)
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
# set(CMAKE_AUTOMOC ON)

# #SET(APP_SRCS calibration.cpp core_function.cpp ctrlTool.cpp keyBoard.cpp point.cpp)
SET(ALGO_3_SRCS dynamic_programming.cpp)
ADD_LIBRARY(algo_03_dynamic_programming SHARED ${ALGO_3_SRCS})
SET_TARGET_PROPERTIES(algo_03_dynamic_programming PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# TARGET_LINK_LIBRARIES(data_01_array)


