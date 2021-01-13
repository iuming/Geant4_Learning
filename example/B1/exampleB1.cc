//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
/// \file exampleB1.cc
/// \brief Main program of the B1 example

// 刘铭学习B1记录！
// 时间： 2021、1、13     15：21


#include "B1DetectorConstruction.hh"    // 定义探测器形状头文件
#include "B1ActionInitialization.hh"    // 初始化行为类（用作记录数据）头文件

#include "G4RunManagerFactory.hh"       // Geant4运行管理类头文件

#include "G4UImanager.hh"               // Geant4可视化头文件
#include "QBBC.hh"                      // Geant4物理过程头文件

#include "G4VisExecutive.hh"            // Geant4可视化头文件
#include "G4UIExecutive.hh"             // Geant4可视化头文件

#include "Randomize.hh"                 // 产生随机数头文件

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

int main(int argc,char** argv)  //程序开始
{
  // Detect interactive mode (if no arguments) and define UI session
  // 如果执行文件后面没有脚本文件，则开启可视化界面
  G4UIExecutive* ui = 0;    
  if ( argc == 1 ) {
    ui = new G4UIExecutive(argc, argv);
  }

  // Optionally: choose a different Random engine...
  // G4Random::setTheEngine(new CLHEP::MTwistEngine);
  
  // Construct the default run manager
  // 产生一个运行管理对象runManager，采用默认类型
  auto* runManager =
    G4RunManagerFactory::CreateRunManager(G4RunManagerType::Default);

  // Set mandatory initialization classes
  //
  // Detector construction
  // 用定义的运行管理对象
  runManager->SetUserInitialization(new B1DetectorConstruction());

  // Physics list
  // 创建物理过程对象physicsList
  G4VModularPhysicsList* physicsList = new QBBC;
  physicsList->SetVerboseLevel(1);  // 设置物理过程的详细级别为1级
  runManager->SetUserInitialization(physicsList); // 初始化运行管理对象runManager的物理过程
    
  // User action initialization
  runManager->SetUserInitialization(new B1ActionInitialization());  // 初始化B1示例中行为类
  
  // Initialize visualization
  // 初始化可视化管理对象visManager
  G4VisManager* visManager = new G4VisExecutive;
  // G4VisExecutive can take a verbosity argument - see /vis/verbose guidance.
  // G4VisManager* visManager = new G4VisExecutive("Quiet");
  visManager->Initialize();   // 初始化可视化管理对象

  // Get the pointer to the User Interface manager
  G4UImanager* UImanager = G4UImanager::GetUIpointer();   // 获取指向可视化界面管理器的指针

  // Process macro or start UI session
  // 如果运行程序时输入了运行脚本文件，则运行为批处理模式；否则，则运行可视化界面
  if ( ! ui ) { 
    // batch mode
    G4String command = "/control/execute "; // 用户界面命令
    G4String fileName = argv[1];  // 记录脚本文件名称
    UImanager->ApplyCommand(command+fileName);  //执行用户界面命令
  }
  else { 
    // interactive mode 
    UImanager->ApplyCommand("/control/execute init_vis.mac");
    ui->SessionStart(); // 开始可视化界面
    delete ui;  // 释放执行对象ui内存
  }

  // Job termination
  // Free the store: user actions, physics_list and detector_description are
  // owned and deleted by the run manager, so they should not be deleted 
  // in the main() program !
  
  delete visManager;  // 释放可视化管理器内存
  delete runManager;  // 释放运行管理对象内存
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.....
