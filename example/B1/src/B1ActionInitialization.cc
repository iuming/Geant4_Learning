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
/// \file B1ActionInitialization.cc
/// \brief Implementation of the B1ActionInitialization class

// 刘铭学习B1示例记录
// 时间：2021、1、13 19：15

#include "B1ActionInitialization.hh"    

#include "B1PrimaryGeneratorAction.hh"  // 初级粒子发生器行为类
#include "B1RunAction.hh"               // 运行管理类
#include "B1EventAction.hh"             // Event行为类
#include "B1SteppingAction.hh"          // Stepping行为类

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1ActionInitialization::B1ActionInitialization()  // B1行为初始化构造函数继承G4用户行为初始化构造函数
 : G4VUserActionInitialization()
{}  // 无派生

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1ActionInitialization::~B1ActionInitialization() // B1行为初始化析构函数为空
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B1ActionInitialization::BuildForMaster() const // 定义BuildForMaster函数 
{
  B1RunAction* runAction = new B1RunAction;   // 新建运行行为对象runAction
  SetUserAction(runAction);   // 设置用户行为为运行行为对象runAction
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B1ActionInitialization::Build() const  // 定义Build函数
{
  SetUserAction(new B1PrimaryGeneratorAction);  // 设置B1初级粒子发生器行为为用户行为

  B1RunAction* runAction = new B1RunAction;   // 新建运行行为对象runAction
  SetUserAction(runAction);     // 设置runAction为用户行为
  
  B1EventAction* eventAction = new B1EventAction(runAction);  // 新建Event行为对象eventAction
  SetUserAction(eventAction);   // 设置eventAction为用户行为
  
  SetUserAction(new B1SteppingAction(eventAction));   // 设置新建的Stepping行为类为用户行为
}  

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
