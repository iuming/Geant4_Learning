#include "G4RunManager.hh"     //Geant4运行管理类
#include "G4UImanager.hh"      //Geant4UI管理类
#include "G4VisExecutive.hh"   //Geant4可视化类
#include "G4UIExecutive.hh"    //Geant4UI执行类

#include "DetectorConstruction.hh"    //自己定义的探测器结构类
#include "PhysicsList.hh"             //自己定义的物理过程类
#include "PrimaryGeneratorAction.hh"  //自己定义的粒子发射器行为类

int main(int argc, char** argv)
{
    G4RunManager* runManager = new G4RunManager;             //创建一个运行管理对象
    G4UIExecutive* ui = new G4UIExecutive(argc, argv);       //创建一个UI执行对象
    G4VisManager* visManager = new G4VisExecutive;           //创建一个可视化管理对象
    visManager -> Initialize();                              //初始化可视化管理对象
    runManager -> SetUserInitialization(new DetectorConstruction);  //将几何结构初始化至运行管理对象
    runManager -> SetUserInitialization(new PhysicsList);           //将物理过程初始化运行管理对象
    runManager -> SetUserAction(new PrimaryGeneratorAction);        //将初级粒子发射器行为类初始化运行管理对象
    runManager -> Initialize();                                     //初始化运行管理对象
    G4UImanager* UI = G4UImanager::GetUIpointer();                  //可视化操作
    UI -> ApplyCommand("/control/execute init_vis.mac");
    ui -> SessionStart();
    delete ui;
    int numberOfEvents = 3;                                       //设置发射粒子数
    runManager -> BeamOn(numberOfEvents);                         //发射粒子
    delete runManager;                                            //释放内存
    delete visManager;                                            //释放内存
    return 0;
}
