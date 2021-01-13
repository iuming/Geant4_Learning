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
/// \file B1ActionInitialization.hh
/// \brief Definition of the B1ActionInitialization class

// 刘铭学习B1示例记录
// 时间：2021、1、13 19：08

#ifndef B1ActionInitialization_h
#define B1ActionInitialization_h 1  // 后面加个1是什么意思？

#include "G4VUserActionInitialization.hh" // 导入Geant4为用户写的行为初始化类

/// Action initialization class.

class B1ActionInitialization : public G4VUserActionInitialization // B1的行为初始化类继承G4用户行为初始化类
{
  public: // 公共变量
    B1ActionInitialization(); // 构造函数
    virtual ~B1ActionInitialization();  // 析构函数(虚函数)

    virtual void BuildForMaster() const;  // 虚函数 const修饰符
    virtual void Build() const; // 虚函数 const修饰符
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

    
