/****************************************************************
 * FileName: 3_BatchModewithMacroFile
 * Author: 刘铭
 * Describes: 
 * Create: Jan 11 2021, 13:25
 * Last Modify:
 * Modifications: 0
 * *************************************************************/

/***********************************
 * 下面是基本示例B1的修改后的主程序，代表了将以批处理模式运行但读取命令文件的应用程序。
 * ********************************/

//一个应用程序例程的示例，该main()例程将以批处理模式运行，但会读取命令文件
int main(int argc,char** argv)
{
  // Construct the default run manager
  auto runManager = G4RunManagerFactory::CreateRunManager();

  // Set mandatory initialization classes
  runManager->SetUserInitialization(new B1DetectorConstruction);
  runManager->SetUserInitialization(new QGSP_BIC_EMY);
  runManager->SetUserInitialization(new B1ActionInitialization);

  // Initialize G4 kernel
  runManager->Initialize();

  //read a macro file of commands
  G4UImanager* UI = G4UImanager::GetUIpointer();
  G4String command = "/control/execute ";
  G4String fileName = argv[1];
  UI->ApplyCommand(command+fileName);

  // job termination
  delete runManager;
  return 0;
}

/**********************************
 * 此示例将使用以下命令执行：
 *  > exampleB1  run1.mac
 * *******************************/

//run1.mac文件如下：
#
# Macro file for myProgram
#
# set verbose level for this run
#
/run/verbose      2
/event/verbose    0
/tracking/verbose 1
#
# Set the initial kinematic and run 100 events
# electron 1 GeV to the direction (1.,0.,0.)
#
/gun/particle e-
/gun/energy 1 GeV
/run/beamOn 100

/******************************************
 * 许多G4类类别都有一个详细标记，用于控制“详细程度”的级别。
 *      /run/verbose 用于 RunManager
 *      /event/verbose 用于 EventManager
 *      /tracking/verbose 用于 TrackingManager
 * ***************************************/