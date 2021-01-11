/****************************************************************************
 * FileName: 5_GeneralCase
 * Author: 刘铭
 * Describes: 
 * Create: Jan 11 2021, 13:44
 * Last Modify: 
 * Modifications: 0
 * *************************************************************************/

/***************************
 * Geant4 源代码分发的examples/basic子目录中的所有基本示例均具有以下结构。该应用程序可以批处理或交互模式运行。main()
 * ************************/

//目录中的典型main()例程
int main(int argc,char** argv)
{
  // Detect interactive mode (if no arguments) and define UI session
  G4UIExecutive* ui = 0;
  if ( argc == 1 ) {
    ui = new G4UIExecutive(argc, argv);
  }

  // Optionally: choose a different Random engine...
  // G4Random::setTheEngine(new CLHEP::MTwistEngine);

  // Construct the default run manager
  G4RunManager* runManager = new G4RunManager;

  // Set mandatory initialization classes
  //
  // Detector construction
  runManager->SetUserInitialization(new B1DetectorConstruction());

  // Physics list
  G4VModularPhysicsList* physicsList = new QBBC;
  physicsList->SetVerboseLevel(1);
  runManager->SetUserInitialization(physicsList);

  // User action initialization
  runManager->SetUserInitialization(new B1ActionInitialization());

  // Initialize visualization
  G4VisManager* visManager = new G4VisExecutive;
  // G4VisExecutive can take a verbosity argument - see /vis/verbose guidance.
  // G4VisManager* visManager = new G4VisExecutive("Quiet");
  visManager->Initialize();

  // Get the pointer to the User Interface manager
  G4UImanager* UImanager = G4UImanager::GetUIpointer();

  // Process macro or start UI session
  if ( ! ui ) {
    // batch mode
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UImanager->ApplyCommand(command+fileName);
  } else {
    // interactive mode
    UImanager->ApplyCommand("/control/execute init_vis.mac");
    ui->SessionStart();
    delete ui;
  }

  // Job termination
  // Free the store: user actions, physics_list and detector_description are
  // owned and deleted by the run manager, so they should not be deleted
  // in the main() program !

  delete visManager;
  delete runManager;
}


//init.mac宏:
# Macro file for the initialization phase of example B1
# when running in interactive mode without visualization
#
# Set some default verbose
/control/verbose 2
/control/saveHistory
/run/verbose 2


//该init_vis.mac 宏刚刚添加了一行，其中包含对vis.mac的调用：
# Macro file for the initialization phase of example B1
# when running in interactive mode with visualization
#
# Set some default verbose
#
/control/verbose 2
/control/saveHistory
/run/verbose 2
#
# Visualization setting
/control/execute vis.mac

// 该vis.mac 宏定义绘制积累对于一个给定运行的所有事件数量和轨迹的最低设置：
# Macro file for the visualization setting in the initialization phase
# of the B1 example when running in interactive mode
#
#
# Use this open statement to create an OpenGL view:
/vis/open OGL 600x600-0+0
#
# Draw geometry:
/vis/drawVolume
#
# Specify view angle:
/vis/viewer/set/viewpointThetaPhi 90. 180.
#
# Draw smooth trajectories at end of event, showing trajectory points
# as markers 2 pixels wide:
/vis/scene/add/trajectories smooth
#
# To superimpose all of the events from a given run:
/vis/scene/endOfEventAction accumulate
#
# Re-establish auto refreshing and verbosity:
/vis/viewer/set/autoRefresh true
/vis/verbose warnings
#
# For file-based drivers, use this to create an empty detector view:
#/vis/viewer/flush

/****************************
 * 此外，此示例还演示了您可以从另一个宏或交互方式读取和执行宏：
 *  Idle> /control/execute  mySubMacro.mac
 * *************************/