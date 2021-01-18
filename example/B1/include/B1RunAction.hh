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
/// \file B1RunAction.hh
/// \brief Definition of the B1RunAction class

// 刘铭学习B1记录！
// 时间：2021、1、14 19：43

#ifndef B1RunAction_h
#define B1RunAction_h 1

#include "G4UserRunAction.hh" // Geant4为用户写的运行行为类
#include "G4Accumulable.hh"   // Geant4能量沉积类
#include "globals.hh"         // 全局变量

class G4Run;  

/// Run action class
///
/// In EndOfRunAction(), it calculates the dose in the selected volume 
/// from the energy deposit accumulated via stepping and event actions.
/// The computed dose is then printed on the screen.

class B1RunAction : public G4UserRunAction    // 继承Geant4为用户编写的运行行为类
{ // 派生函数
  public:
    B1RunAction();  // 构造函数
    virtual ~B1RunAction(); // 析构函数

    // virtual G4Run* GenerateRun();
    virtual void BeginOfRunAction(const G4Run*);  // 运行开始行为记录
    virtual void   EndOfRunAction(const G4Run*);  // 运行结束行为记录

    void AddEdep (G4double edep);   // 添加能量沉积量

  private:
    G4Accumulable<G4double> fEdep;  // 多线程记录能量沉积量
    G4Accumulable<G4double> fEdep2; // 为啥要定义两个？
};

#endif

