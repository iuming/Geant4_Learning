cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(Ex01)

option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
    find_package(Geant4 REQUIRED ui_all vis_all)
else()
    find_package(Geant4 REQUIRED)
endif()

include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

add_executable(Ex01 Ex01.cpp ${sources} ${headers})
target_link_libraries(Ex01 ${Geant4_LIBRARIES})

# set(TUTORIAL_SCRIPTS
#   tutorial.in
#   tutorial.out
#   init_vis.mac
#   run1.mac
#   run2.mac
#   vis.mac
#   )

install(TARGETS Ex01 DESTINATION bin)