/*-----------------------------------------------------------------
FileName: main()函数
Author: 刘铭
Describe: 
Create: Dec 29 2020, 15:43
Last Modify: Dec 29 2020, 
Modifications: 0
------------------------------------------------------------------*/

#include "G4RunManager.hh"
#include "G4UImanager.hh"

#include "ExN01DetectorConstruction.hh"
#include "ExN01PhysicsList.hh"
#include "ExN01PrimaryGeneratorAction.hh"

int main()
{
  //新建一个RunManager对象
  G4RunManager* runManager = new G4RunManager;
  /*G4Manager类是Geant4内核中唯一的运行管理类，必须在main函数中显式创建。G4Manager*/
  
  //设置RunManager初始化类
  runManager->SetUserInitialization(new ExN01DetectorConstruction);
  runManager->SetUserInitialization(new ExN01PhysicsList);

  //设置RunManager行为类？干啥的？？？？
  runManager->SetUserAction(new ExN01PrimaryGeneratorAction);

  //初始化runManager
  runManager->initialize();

  //新建一个UImanager对象，起来像是在UI界面发射粒子
  G4UImanager* UI = G4UImanager::GetUIpointer();
  UI->ApplyCommand("/run/verbose 1");
  UI->ApplyCommand("/event/verbose 1");
  UI->ApplyCommand("/tracking/verbose 1");
  
  //
  int numberOfEvent = 3;
  runManager->BeamOn(numberOfEvent);

  //释放RunManager
  delete runManager;

  return 0;
}
