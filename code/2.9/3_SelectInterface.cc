/*****************************************************************************************
 * FileName: 3_SelectInterface
 * Author: 刘铭
 * Describes: 
 * Create: Jan 11 2021, 12:47
 * Last Modify:
 * Modifications: 0
 * **************************************************************************************/

/*****************************************************
 * 如何在应用程序中选择接口
 * 要在程序中选择一个接口（G4UIxxx位置 ），有两种方法。xxx = terminal,Xm, Win32, Qt, GAG, GainServer
 * **************************************************/

/********************************************************************
1、直接添加头文件：
#include "G4Uixxx.hh"
G4UIsession* session = new G4UIxxx;
session-> SessionStart();
delete session;
 * [注意]
 * 对于使用tcsh会话， G4UIterminal实例化为：
 *      G4UIsession* session = new G4UIterminal(new G4UItcsh);

 * 如果用户想停用由“ Ctr-C”引发的默认信号处理程序（软中止），则可以在G4UIterminal构造函数的第二个参数中设置false标志，例如
 *      G4UIsession* session = new G4UIterminal(new G4UItcsh, false).
 * ******************************************************************/

/**********************************************************************
 * 2、使用G4UIExecutive 这是选择会话类型的更方便的方法，可以根据以下描述的规则在运行时选择会话：
 * #include "G4UIExecutive.hh"
 * G4UIExecutive* ui = new G4UIExecutive(argc, argv);
 * ui->SessionStart();
 * delete ui;
 * 
 * G4UIExecutive有几种选择会话类型的方法。在以下规则中选择了一个会话。请注意，会话类型由不区分大小写的字符（“ qt”，“ xm”，“ win32”，“ gag”，“ tcsh”，“ csh”）标识。
 * ①检查G4UIExecutive构造函数的参数。您可以指定一个会话，例如new G4UIExecutive(argc, argv, "qt");
 * ②检查环境变量 。如果定义了相应的环境变量，请选择一个会话。如果设置了多个变量，则按照QT，XM，WIN32，GAG，TCSH的顺序检查变量。G4UI_USE_XX (XX= QT, XM, WIN32, GAG, TCSH)
 * ③检查~/.g4session。您可以通过该文件中的每个应用程序指定默认会话类型和会话类型。下面显示了的示例 .g4session。
 *  tcsh  # default session
 *  exampleN03 Qt # (application name / session type)
 *  myapp  tcsh
 *  hoge csh
 * ④根据构建会话库猜测最佳会话类型。选择的顺序是Qt，tcsh，Xm。
 * 
 * 在任何情况下，请G4UIExecutive检查是否建立了指定的会话。如果不是，则进行下一步。与csh的终端会话是回退会话。如果没有指定的会话可用，则将其选中。
 * *******************************************************************/