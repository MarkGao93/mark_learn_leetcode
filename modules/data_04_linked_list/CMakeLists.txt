PROJECT(data_04_linked_list)
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
# set(CMAKE_AUTOMOC ON)

# #SET(APP_SRCS calibration.cpp core_function.cpp ctrlTool.cpp keyBoard.cpp point.cpp)
SET(DATA_4_SRCS linked_list.cpp)
ADD_LIBRARY(data_04_linked_list SHARED ${DATA_4_SRCS})
SET_TARGET_PROPERTIES(data_04_linked_list PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# TARGET_LINK_LIBRARIES(data_01_array)


