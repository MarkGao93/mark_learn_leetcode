PROJECT(data_03_string)
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
# set(CMAKE_AUTOMOC ON)

# SET(APP_SRCS calibration.cpp core_function.cpp ctrlTool.cpp keyBoard.cpp point.cpp)
SET(DATA_3_SRCS data_string.cpp)
ADD_LIBRARY(data_03_string SHARED ${DATA_3_SRCS})
SET_TARGET_PROPERTIES(data_03_string PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# TARGET_LINK_LIBRARIES(data_03_string)


