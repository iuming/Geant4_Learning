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
/// \file B1DetectorConstruction.hh
/// \brief Definition of the B1DetectorConstruction class

// 刘铭学习B1示例记录!
// 时间：2021、1、13 16：46

#ifndef B1DetectorConstruction_h  
#define B1DetectorConstruction_h 1  // 后面加个1代表什么意思？有什么用？

#include "G4VUserDetectorConstruction.hh" // 继承Geant4为用户定义好的探测器结构类
#include "globals.hh"   //全局类？？？

class G4VPhysicalVolume;  // Geant4物理体类
class G4LogicalVolume;    // Geant4逻辑体类

/// Detector construction class to define materials and geometry.

class B1DetectorConstruction : public G4VUserDetectorConstruction // 定义的B1探测器结构类继承Geant4探测器结构类
{
  public:   // 公共函数(除派生类外，外部函数也可以直接访问)
    B1DetectorConstruction(); // 构造函数
    virtual ~B1DetectorConstruction();  // 析构函数（虚函数）

    virtual G4VPhysicalVolume* Construct(); // 物理体结构函数，用户必须自行定义
    
    G4LogicalVolume* GetScoringVolume() const { return fScoringVolume; }  // 逻辑体

  protected:  // 保护函数(内部函数、派生类都能访问，外部类、外部函数不能访问)
    G4LogicalVolume*  fScoringVolume; 
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

