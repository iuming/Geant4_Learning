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
  /*********************************************
    G4Manager类是Geant4内核中唯一的运行管理类，必须在main函数中显式创建。
    G4Manager被创建的同时其他grant4管理类同时被创建，在释放G4Manager对象时自动释放！
  **********************************************/
  
  //设置RunManager初始化类
  runManager->SetUserInitialization(new ExN01DetectorConstruction);
  runManager->SetUserInitialization(new ExN01PhysicsList);
  /*********************************************
    在创建runManager之后，必须设置初始化运行控制进程的消息，这些消息包括：
        探测器将如何构建（DetectorConstruction）
        被模拟的所有粒子和所有物理过程(PhysicsList)
        在一个event中初级粒子将如何产生
        其他模拟必须的消息
    ExN01DetectorConstruction类是从G4UserDetectorConstruction类派生的，用来描述整个探测器的结构，需要定义：
         探测器的几何形状
         探测器使用的材料
         探测器的敏感区域
         敏感区域的读出方式
     ExN01PhysicsList是由G4UserPhysicsList派生的，需要定义：
         在模拟中将被使用的粒子
         粒子的截断范围
         所有将被模拟的物理过程
  **********************************************/

  //设置RunManager行为类
  runManager->SetUserAction(new ExN01PrimaryGeneratorAction);
  /***********************************************
    新建一个粒子发生器的实例并传递指向它的指针给运行管理进程。
    ExN01PrimaryGeneratorAction是用户行为（Action）类，是由G4UserPrimaryGeneratorAction派生，在该类中，用户必须描述初级粒子事件的初始状态，这个类有一个公有虚方法generatrPrimaries()，它将在每个事件的开始时刻被调用。
    【注意】Geant4不提供任何缺省行为用于产生一个初级事件！
  ************************************************/
  
  //初始化runManager
  runManager->initialize();
  /************************************************
     
   ************************************************/
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
