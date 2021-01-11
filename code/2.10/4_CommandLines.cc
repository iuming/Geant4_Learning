/***************************************************************************
 * FileName: 4_CommandLines
 * Author: 刘铭
 * Describes: 
 * Create: Jan 11 2021, 13:37
 * Last Modify: 
 * Modifications: 0
 * ************************************************************************/

//下面是一个应用程序的主程序示例，该程序将交互运行，等待从键盘输入的命令行。
//一个应用程序例程的示例，该main()例程将交互运行，等待来自键盘的命令
int main(int argc,char** argv)
{
  // Construct the default run manager
  G4RunManager* runManager = new G4RunManager;

  // Set mandatory initialization classes
  runManager->SetUserInitialization(new B1DetectorConstruction);
  runManager->SetUserInitialization(new QGSP_BIC_EMY);
  runManager->SetUserInitialization(new B1ActionInitialization);

  // Initialize G4 kernel
  runManager->Initialize();

  // Define UI terminal for interactive mode
  G4UIsession * session = new G4UIterminal;
  session->SessionStart();
  delete session;

  // job termination
  delete runManager;
  return 0;
}

/********************************
 * 此示例将使用以下命令执行:
 *  > exampleB1
 * G4内核将提示：
 *  Idle>
 * 运行5个事件：
 *  Idle> /run/beamOn 5
 * 启用跟踪/详细信息，然后再运行一个事件：
 *  Idle> /tracking/verbose 1
 *  Idle> /run/beamOn 1
 * 更改一次粒子类型运行更多事件：
 *  Idle> /gun/particle mu+
 *  Idle> /gun/energy 10 GeV
 *  Idle> /run/beamOn 1
 *  Idle> /gun/particle proton
 *  Idle> /gun/energy 100 MeV
 *  Idle> /run/beamOn 3
 *  Idle> exit
 * 
 * 此模式对于在调试模式下运行一些事件并使其可视化非常有用。在下一个一般示例中，将显示如何包括可视化。
 * *****************************/