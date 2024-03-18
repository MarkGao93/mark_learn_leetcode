PROJECT(data_05_stack_and_queue)
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
# set(CMAKE_AUTOMOC ON)

# #SET(APP_SRCS calibration.cpp core_function.cpp ctrlTool.cpp keyBoard.cpp point.cpp)
SET(DATA_5_SRCS my_stack.cpp my_queue.cpp)
ADD_LIBRARY(data_05_stack_and_queue SHARED ${DATA_5_SRCS})
SET_TARGET_PROPERTIES(data_05_stack_and_queue PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# TARGET_LINK_LIBRARIES(data_01_array)


