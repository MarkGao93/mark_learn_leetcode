#ADD_EXECUTABLE(pangu main.cpp aegis.cpp ${PROJECT_SOURCE_DIR}/modules/app/calibration.cpp)
project(main)
FILE(GLOB SRC_FILES "./*.cxx")
FILE(GLOB HEAD_FILES "./*.h")
# FILE(GLOB UI_FILES "./*.ui")

# QT5_WRAP_UI(WRAP_FILES "/execute/mainwindow.ui")
# source_group("ui" FILES ${UI_FILES} ${WRAP_FILES})

ADD_EXECUTABLE(marklearnleetcode main.cpp)
TARGET_LINK_LIBRARIES(
    marklearnleetcode 
    data_01_array
    skill_01_dichotomy
    data_02_hash_table
    data_03_string
    data_04_linked_list
    data_05_stack_and_queue
    data_06_binary_tree
    algo_03_dynamic_programming
    # dbc 
    # can 
    # rte 
    # eth 
    # xcp 
    # lcm_wrapper 
    # serial 
    # app 
    # map 
    # signal
)
