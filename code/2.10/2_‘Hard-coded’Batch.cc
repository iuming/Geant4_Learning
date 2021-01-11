/*****************************************************************
 * FileName: 2_'Hard-coded'Batch
 * Author: 刘铭
 * Describes: 
 * Create: Jan 11 2021, 13:17
 * Last Modify: 
 * Modifications: 0
 * **************************************************************/

/*************************************************
 * 下面是基本示例B1的修改后的主程序，表示将以批处理模式运行的应用程序。
 * **********************************************/

//以批处理模式运行的应用程序例程的示例main()
int main()
{
  // Construct the default run manager
  auto runManager = G4RunManagerFactory::CreateRunManager();

  // Set mandatory initialization classes
  runManager->SetUserInitialization(new B1DetectorConstruction);
  runManager->SetUserInitialization(new QGSP_BIC_EMY);
  runManager->SetUserInitialization(new B1ActionInitialization);

  // Initialize G4 kernel
  runManager->Initialize();

  // start a run
  int numberOfEvent = 1000;
  runManager->BeamOn(numberOfEvent);

  // job termination
  delete runManager;
  return 0;
}

//甚至运行中的事件数都是“冻结”的。要更改此数字，您至少必须重新编译main()。