CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

PROJECT(MarkLearnLeetCode C CXX)

# SET(CMAKE_BUILD_TYPE "Debug") 

# set(CMAKE_PREFIX_PATH "/home/siac/Qt5.10.0/5.10.0/gcc_64/")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTOUIC ON)

#FILE(GLOB SRC_FILES "./*.cxx")
#FILE(GLOB HEAD_FILES "./*.h")
#FILE(GLOB UI_FILES "./*.ui")

#QT5_WRAP_UI(WRAP_FILES "mainwindow.ui")
#source_group("ui" FILES ${UI_FILES} ${WRAP_FILES})

# SET(CMAKE_CXX_FLAGS "-std=c++0x -O0 -Wall -Wno-unused -g2 -ggdb -fPIC -lrt -lm -Wl,-Map,pangu.map")
# set(CMAKE_EXE_LINKER_FLAGS "-Xlinker --section-start=calram=0x700000 -Xlinker --section-start=mesram=0x800000")
# SET(CMAKE_CXX_FLAGS "-std=c++11 -Wall")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

INCLUDE_DIRECTORIES(
	# ${PROJECT_SOURCE_DIR}/thirdparty/linuxcan/include
	# ${PROJECT_SOURCE_DIR}/thirdparty/lcm-1.3.1/include
	# ${PROJECT_SOURCE_DIR}/thirdparty/opencv/include
	# ${PROJECT_SOURCE_DIR}/thirdparty/toolbox/include
	# ${PROJECT_SOURCE_DIR}/thirdparty/qcustomplot/include
	# ${PROJECT_SOURCE_DIR}/thirdparty/v2x/include
	${PROJECT_SOURCE_DIR}/common/include
	${PROJECT_SOURCE_DIR}/execute
	${PROJECT_SOURCE_DIR}/modules/algo_01_backtracking
	${PROJECT_SOURCE_DIR}/modules/algo_02_greedy
	${PROJECT_SOURCE_DIR}/modules/algo_03_dynamic_programming
	${PROJECT_SOURCE_DIR}/modules/data_01_array
	${PROJECT_SOURCE_DIR}/modules/data_02_hash_table
	${PROJECT_SOURCE_DIR}/modules/data_03_string
	${PROJECT_SOURCE_DIR}/modules/data_04_linked_list
	${PROJECT_SOURCE_DIR}/modules/data_05_stack_and_queue
	${PROJECT_SOURCE_DIR}/modules/data_06_binary_tree
	${PROJECT_SOURCE_DIR}/modules/skill_01_dichotomy
	${PROJECT_SOURCE_DIR}/modules/skill_02_double_pointer
)

LINK_DIRECTORIES(
	${PROJECT_BINARY_DIR}/lib 
	# ${PROJECT_SOURCE_DIR}/thirdparty/linuxcan/canlib
#                  ${PROJECT_SOURCE_DIR}/thirdparty/lcm-1.3.1/lib
#                  ${PROJECT_SOURCE_DIR}/thirdparty/opencv/lib
#                  ${PROJECT_SOURCE_DIR}/thirdparty/toolbox/lib
                # /usr/local/lib
# 	    	 ${PROJECT_SOURCE_DIR}/thirdparty/qcustomplot/lib
#                  ${PROJECT_SOURCE_DIR}/thirdparty/v2x/lib
                 ${PROJECT_SOURCE_DIR}/common/lib)

ADD_SUBDIRECTORY(modules)
ADD_SUBDIRECTORY(execute)
