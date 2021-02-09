#设置cmake最低版本为2.6，若最小版本为2.6以下，则出现严重错误，整个过程中止
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

#项目名称为"Ex01",之后可以用${PROJECT_NAME}替代
project(Ex01)

#如果用户没有定义"WITH_GEANT$_UIVIS"，那么默认的值为ON，如果用户在命令行改变该值，则按照用户定义为准
option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
    #寻找Geant4配置文件，找到后，将头文件目录设置到${GEANT4_INCLUDE_DIR}中，链接库设置到${GEANT4_LIBS}中。后面的ui_all和vis_all为组件。
    find_package(Geant4 REQUIRED ui_all vis_all)
else()
    find_package(Geant4 REQUIRED)
endif()

#导入头文件目录
include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)

#文件操作命令，GLOB表示将后面的文件组成的列表保存到变量中
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

#添加可执行文件，程序名，后面为程序的头文件和源文件
add_executable(Ex01 Ex01.cpp ${sources} ${headers})
#将目标文件与库文件进行链接
target_link_libraries(Ex01 ${Geant4_LIBRARIES})

#将后面的文件用变量代替值替换
# set(Ex01_SCRIPTS
#   tutorial.in
#   tutorial.out
#   init_vis.mac
#   run1.mac
#   run2.mac
#   vis.mac
#   )
#
#对list中每个变量执行一组命令
# foreach(_script ${Ex01_SCRIPTS})
#   #将文件复制到构建目录相应文件夹
#   configure_file(
#     ${PROJECT_SOURCE_DIR}/${_script}
#     ${PROJECT_BINARY_DIR}/${_script}
#     COPYONLY
#     )
# endforeach()

将可执行文件安装到bin中
install(TARGETS Ex01 DESTINATION bin)