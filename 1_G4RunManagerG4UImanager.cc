/*-----------------------------------------------------------------
FileName: 1_G4RunManagerG4UImanager.cc
Author: 刘铭
Describe: main()函数的编写，对G4RunManager和G4UImanager初步认识！
Create: Dec 29 2020, 15:43
Last Modify: Dec 29 2020, 20:55
Modifications: 1
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
     建立探测器结构，创建物理过程，计算截面并且建立run.
   ************************************************/

  //新建一个UImanager对象，起来像是在UI界面发射粒子
  G4UImanager* UI = G4UImanager::GetUIpointer();
  UI->ApplyCommand("/run/verbose 1");
  UI->ApplyCommand("/event/verbose 1");
  UI->ApplyCommand("/tracking/verbose 1");
  /*************************************************
     G4UImanager是用户接口管理类。在上面的代码中，ApplyCommand()被调用了3次，用来发命令给应用程序，让应用程序打印出run、事件和粒子跟踪的信息。
     可以使用大量可用的用户接口命令对模拟过程进行控制。
  *************************************************/

  //启动一个run
  int numberOfEvent = 3;
  runManager->BeamOn(numberOfEvent);
  /**************************************************
     运行三个顺序处理的事件。beamOn()可以在main()函数中调用任意多次，一旦开始一次run，探测器结构和物理过程都不可以更改。
  **************************************************/

  //释放RunManager
  delete runManager;

  return 0;
}



/*****************************************************
   用户初始化(Initialization)和行为(Action)类
 必须定义的类
	有三个类必须定义，两个是初始化类，另一个是行为类。它们必须由Geant4提供的抽象基类G4VUserDetectorConstruction,G4VUserPhysicsList和G4VUserPrimaryGeneratorAction派生。Geant4不提供这些类的缺省方法，G4RunManager在调用initialize()和BeamOn()方法的时候，检查这些类是否存在。
 可选行为(Action)类
	Geant4提供了5个用户hook类：
	G4UserRunAction
	G4UserEventAction
	G4UserStackingAction
	G4UserTrackingAction
	G4UserSteppingAction
   这些类中，有几个虚函数允许用户在模拟程序的各个层次添加其它代码。
*****************************************************/
