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
