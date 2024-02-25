PROJECT(skill_01_dichotomy)
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
# set(CMAKE_AUTOMOC ON)

# #SET(APP_SRCS calibration.cpp core_function.cpp ctrlTool.cpp keyBoard.cpp point.cpp)
SET(SKILL_1_SRCS dichotomy.cpp)
ADD_LIBRARY(skill_01_dichotomy SHARED ${SKILL_1_SRCS})
SET_TARGET_PROPERTIES(skill_01_dichotomy PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# TARGET_LINK_LIBRARIES(data_01_array)


