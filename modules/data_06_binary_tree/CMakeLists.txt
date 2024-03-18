PROJECT(data_06_binary_tree)
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
# set(CMAKE_AUTOMOC ON)

# #SET(APP_SRCS calibration.cpp core_function.cpp ctrlTool.cpp keyBoard.cpp point.cpp)
SET(DATA_6_SRCS binary_tree.cpp)
ADD_LIBRARY(data_06_binary_tree SHARED ${DATA_6_SRCS})
SET_TARGET_PROPERTIES(data_06_binary_tree PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# TARGET_LINK_LIBRARIES(data_01_array)


