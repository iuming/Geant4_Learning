#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 3.8...3.18)  # cmake最低版本
if(${CMAKE_VERSION} VERSION_LESS 3.12)  # 如果CMake版本小于3.12，则
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}) # 将CMake策略版本设置为指定版本
endif()
project(B1) # 项目名称为B1

#----------------------------------------------------------------------------
# Find Geant4 package, activating all available UI and Vis drivers by default
# You can set WITH_GEANT4_UIVIS to OFF via the command line or ccmake/cmake-gui
# to build a batch mode only executable
# 查找Geant4程序包，默认情况下激活所有可用的UI和Vis驱动程序您可以通过命令行或ccmake / cmake-gui将WITH_GEANT4_UIVIS设置为OFF来构建仅批处理模式的可执行文件
option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON) 
if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()

#----------------------------------------------------------------------------
# Setup Geant4 include directories and compile definitions
# Setup include directory for this project
#
include(${Geant4_USE_FILE}) # 导入Geant4头文件
include_directories(${PROJECT_SOURCE_DIR}/include)  # 导入该实例自定义头文件

#----------------------------------------------------------------------------
# Locate sources and headers for this project
# NB: headers are included so they will show up in IDEs
# 找到该项目的源文件和头文件
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

#----------------------------------------------------------------------------
# Add the executable, and link it to the Geant4 libraries
# 定义可执行文件
add_executable(exampleB1 exampleB1.cc ${sources} ${headers})
target_link_libraries(exampleB1 ${Geant4_LIBRARIES})  # 链接到Geant4可执行库

#----------------------------------------------------------------------------
# Copy all scripts to the build directory, i.e. the directory in which we
# build B1. This is so that we can run the executable directly because it
# relies on these scripts being in the current working directory.
# 将所有脚本复制到构建目录，即我们构建B1的目录。 这样我们可以直接运行可执行文件，因为它依赖于当前工作目录中的这些脚本。
set(EXAMPLEB1_SCRIPTS
  exampleB1.in
  exampleB1.out
  init_vis.mac
  run1.mac
  run2.mac
  vis.mac
  )

foreach(_script ${EXAMPLEB1_SCRIPTS})
  configure_file(
    ${PROJECT_SOURCE_DIR}/${_script}
    ${PROJECT_BINARY_DIR}/${_script}
    COPYONLY
    )
endforeach()

#----------------------------------------------------------------------------
# For internal Geant4 use - but has no effect if you build this
# example standalone
#
add_custom_target(B1 DEPENDS exampleB1)

#----------------------------------------------------------------------------
# Install the executable to 'bin' directory under CMAKE_INSTALL_PREFIX
# 将可执行文件安装到CMAKE_INSTALL_PREFIX下的'bin'目录
install(TARGETS exampleB1 DESTINATION bin)
