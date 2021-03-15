#include "G4RunManager.hh"              // Geant4为用户定义的运行管理类文件
#include "G4UImanager.hh"               // Geant4为用户定义的UI管理类文件

#include "DetectorConstruction.hh"      // 探测器结构类文件
#include "PhysicsList.hh"               // 物理过程类文件
#include "PrimaryGeneratorAction.hh"    // 初级粒子发射行为类文件

int main()
{
    G4RunManager * runManager = new G4RunManager;                   // 创建运行管理对象runManager
    runManager -> SetUserInitialization(new DetectorConstruction);  // 对运行管理对象进行模型初始化
    runManager -> SetUserInitialization(new PhysicsList);           // 对运行管理对象进行物理过程初始化
    runManager -> SetUserAction(new PrimaryGeneratorAction);        // 对运行对立对象进行初级粒子初始化
    runManager -> Initialize();                                     // 初始化
    G4UImanager* UI = G4UImanager::GetUIpointer();                  // 创建UI管理对象UI
    UI -> ApplyCommand("/run/verbose 1");                           // run输出level为1
    UI -> ApplyCommand("/event/verbose 1");                         // event输出level为1
    UI -> ApplyCommand("/tracking/verbose 1");                      // tracking输出level为1
    int numberOfEvents = 3;                                         // 设置3个event
    runManager -> BeamOn(numberOfEvents);                           // 发射3个粒子
    delete runManager;                                              // 释放运行管理对象内存
    return 0;                                                       
}