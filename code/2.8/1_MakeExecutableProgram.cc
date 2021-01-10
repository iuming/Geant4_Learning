/***************************************************************************************************
 * File: 1_MakeExecutableProgram
 * Author: 刘铭
 * Describes:
 * Create: Jan 10 2021, 13:19
 * Last Modify:
 * Modifications: 0
 * ************************************************************************************************/

/**************************************************************
 * Geant4中用户示例的代码examples位于主Geant4源程序包的子目录中。该目录将安装到安装前缀下的share/Geant4-G4VERSION/examples（此处G4VERSION是Geant4版本号）子目录。在以下部分中，将快速概述如何使用CMake构建具体示例“ ExampleB1”，它是Geant4发行版的一部分。
 * ***********************************************************/

/*************************************************************
 * 使用CMake构建应用程序
 * Geant4安装名为的文件，Geant4Config.cmake位于
 *      +- CMAKE_INSTALL_PREFIX
 *          +- lib/
 *              +- Geant4-G4VERSION/
 *                  +- Geant4Config.cmake
 * 设计用于CMakefind_package命令。因此，使用CMake构建Geant4应用程序需要CMakeLists.txt使用此命令和其他CMake命令编写 脚本来定位Geant4并描述客户端应用程序的构建。尽管需要花费一些精力来编写脚本，但CMake提供了一个非常友好而强大的工具，尤其是在多个平台上工作时。因此，这是我们推荐的构建Geant4应用程序的方法。
 * **********************************************************/

/**************************************************************
 * 我们将使用Basic Example B1（您可以在Geant4源目录下的examples/basic/B1）中演示如何使用CMake构建Geant4应用程序。您将找到通篇使用的最新命令的最新CMake文档的链接，因此请遵循这些以获取更多信息。应用程序源和脚本按以下目录结构排列：
 *  +- B1/
 *      +- CMakeLists.txt
 *      +- exampleB1.cc
 *      +- include/
 *      |  ... headers.hh ...
 *      +- src/
 *          ... sources.cc ...
 * 在这里，exampleB1.cc包含main()用于应用程序，分别包含 include/和src/包含实现类标头和源。除了使用CMakeLists.txt文件在应用程序根目录中的位置之外，使用CMake进行构建时，源文件的这种排列不是强制性的。
 * 文本文件CMakeLists.txt是CMake脚本，其中包含描述如何构建exampleB1应用程序的命令。
 * ***********************************************************/

cmake_minimum_required(VERSION 3.8...3.18)
if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()
project(B1)
/***************************************************************
 * 基本配置
 * 该cmake_minimum_required命令和if块仅确保我们使用的是适当版本的CMake，并且已正确设置了它。
 * 该project 命令设置项目的名称，并启用和配置C和C ++编译器。
 * ************************************************************/

option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()
/**************************************************************
 * 查找和配置Geant4
 * 上面提到的find_package命令用于定位和配置Geant4（稍后将在运行CMake时看到如何指定位置），提供了该 REQUIRED参数，以便CMake在找不到Geant4时将失败并显示错误。
 * 该option命令指定一个布尔变量，默认为ON，可以在通过-D 命令行参数运行CMake时设置，也可以在CMake GUI界面中进行切换。
 * 我们将调用包装在选项值find_package的条件块中。这使我们可以通过exampleB1的 “ component”参数来配置Geant4 UI和可视化驱动程序的使用。提供了可用组件的概述在CMake中将Geant4Config.cmake与find_package一起使用ui_all vis_allfind_package完整列表位于已安装Geant4Config.cmake文件的顶部。
 * ***********************************************************/

include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)
/****************************************************************
 * 配置项目以使用Geant4和B1标头
 * 为了自动配置头路径，并强制设置针对Geant4进行编译所需的编译器标志和编译器定义，我们使用以下include命令加载Geant4提供的CMake脚本。Geant4_USE_FILE当Geant4位于时，将名为CMake的变量设置为该模块的路径find_package。我们使用include_directories 命令将B1头目录添加到编译器的头搜索路径。CMake变量 PROJECT_SOURCE_DIR指向项目的顶级目录，并由先前对project命令的调用来设置。
 * *************************************************************/

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/【星号】.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/【星号】.hh)
/****************************************************************
 * 列出构建应用程序的源
 * 使用file命令的全局功能来准备B1源文件和头文件的列表。
 * 但是请注意，此处仅出于方便使用CMake globbing 。仅当运行CMake时才会发生glob扩展，因此，如果以后添加或删除文件，则生成的构建脚本将不会知道已进行更改。Kitware强烈建议您明确列出源，因为CMake会自动使构建依赖于 CMakeLists.txt 文件。这意味着，如果您在中显式列出了源CMakeLists.txt，则在重建时将自动选择您所做的任何更改。当您在项目中使用源代码受版本控制且有多个贡献者时，这是最有用的。
 * *************************************************************/

add_executable(exampleB1 exampleB1.cc ${sources} ${headers})
target_link_libraries(exampleB1 ${Geant4_LIBRARIES})
/****************************************************************
 * 定义并链接可执行文件
 * 该add_executable命令定义应用程序的构建，并输出以其第一个参数命名的可执行文件，其后为源。请注意，我们将标题添加到源列表中，以便它们将出现在Xcode之类的IDE中。
 * 添加可执行文件后，我们使用target_link_libraries命令将其与Geant4库链接。该 Geant4_LIBRARIES变量是在放置find_packageGeant4时设置的，并且是链接使用Geant4所需的所有库的列表。
 * *************************************************************/

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
/***************************************************************
 * 将所有运行时脚本复制到构建目录
 * 因为我们要支持源代码之外的版本，以免将CMake生成的文件与实际源代码混合在一起，所以我们将B1应用程序使用的所有脚本复制到生成目录中。我们foreach用来遍历我们构造的脚本列表，并configure_file执行实际的复制。
 * 在这里，CMake变量PROJECT_BINARY_DIR是通过对project 命令的更早调用来设置的，并指向我们运行CMake来配置构建的目录。
 * ************************************************************/

install(TARGETS exampleB1 DESTINATION bin)
/****************************************************************
 * 如果需要，安装可执行文件
 * 使用install命令创建安装目标，该安装目标会将可执行文件安装到的bin目录下CMAKE_INSTALL_PREFIX。
 * 如果您不希望您的应用程序是可安装的，即您只想在构建时在本地使用它，则可以将其省略。
 * *************************************************************/

/****************************************************************************************
 * 此命令序列是用Geant4编译和链接应用程序所需的最基本命令，并且可以轻松扩展到涉及更多的用例，例如特定于平台的配置或使用其他第三方软件包（通过find_package）。
 * 有了CMake脚本，使用它来构建应用程序是一个两步过程。首先运行CMake生成生成脚本以描述生成。默认情况下，它们将是Unix平台上的Makefile和Windows上的Visual Studio解决方案，但是您可以根据需要为其他工具（例如Xcode和Eclipse）生成脚本 。其次，构建脚本由选定的构建工具运行，以编译和链接应用程序。
 * CMake的一个关键概念是，我们生成构建脚本并在源所在的目录（即所谓的source directory）中的单独目录（即所谓的build目录）中运行构建。这与我们在构建Geant4本身时使用的技术完全相同。尽管开始时这似乎很尴尬，但它是一种非常有用的技术。它可以防止CMake生成的文件与应用程序的文件混合在一起，并允许您针对单个源进行多个构建，而无需清理，重新配置和重新构建。
 * 我们将说明使用Makefile在Linux / macOS上以及使用Visual Studio在Windows上的配置和构建过程。示例脚本和Geant4的Geant4Config.cmake脚本都是原始的CMake，因此您应该可以使用其他Generator（例如Xcode和Eclipse）而不会出现问题。
 * *************************************************************************************/

/***************************************************************************************
 * 在Unix上使用Makefile在CMake上构建ExampleB1
 * 源目录是/home/you/B1，换句话说就是保存CMakeLists.txt文件的目录。
 * 我们的第一步是创建一个构建目录，在其中构建示例。我们将在B1源目录旁边创建该目录，如下所示：
 *  $ cd $HOME
 *  $ mkdir B1-build
 * 现在，我们转到该生成目录，并运行CMake生成生成B1应用程序所需的Makefile。我们通过CMake两个参数:
 *  $ cd $HOME/B1-build
 *  $ cmake -DGeant4_DIR=/home/you/geant4-install/lib64/Geant4-G4VERSION $HOME/B1
 * 在这里，第一个参数将CMake指向我们的Geant4安装。具体来说，它是保存Geant4Config.cmake Geant4所安装文件的目录，以帮助CMake查找和使用Geant4。您当然应该根据实际Geant4安装的位置调整此变量的值。这提供了将CMake指向要使用的Geant4安装的最具体方法。您也可以使用CMAKE_PREFIX_PATH变量，例如：
 *  $ cd $HOME/B1-build
 *  $ cmake -DCMAKE_PREFIX_PATH=/home/you/geant4-install $HOME/B1
 * 这对于系统集成商最有用，因为它可以通过环境或命令行进行扩展，并带有指向其他必需软件包的安装前缀的路径。
 * 有了Makefile，我们现在可以通过简单地运行make来构建：
 *  $ make -jN
 * CMake生成的Makefile支持并行构建，因此N可以将其设置为计算机上的内核数（例如，在双核处理器上，可以将N设置为2）。
 * CMake Unix Makefile非常简洁，但是您可以通过添加VERBOSEmake参数使它们更加冗长：
 *  $ make VERBOSE=1
 * 您现在可以就地运行该应用程序：
 *  $ ./exampleB1
 * 请注意，显示的确切输出将取决于Geant4和应用程序的配置方式。超出范围的其他输出和行为 将取决于Geant4安装支持的UI和可视化驱动程序。如果您回想起在命令中的用法，这将导致在应用程序中激活所有可用的UI和可视化驱动程序。如果您不需要任何UI或可视化，则可以使用以下参数在构建目录中重新运行CMake：Registering graphics systems...ui_all vis_allfind_package
 *  $ cmake -DWITH_GEANT4_UIVIS=OFF .
 * 这会将option我们设置为false，并导致 find_package不为该应用程序激活任何UI或可视化。您可以轻松地调整此模式，以为您的应用程序提供选项，例如其他组件或功能。
 * 配置构建后，您可以在其源目录中编辑该应用程序的代码。您只需要make在相应的构建目录中重新运行即可拾取并编译更改。但是，请注意，由于使用CMake globbing来创建源文件列表，因此，如果添加或删除文件，则必须记住重新运行CMake来获取更改。这是Kitware建议明确列出来源的另一个原因。
 * ************************************************************************************/