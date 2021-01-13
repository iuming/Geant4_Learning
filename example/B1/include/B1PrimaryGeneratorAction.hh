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
/// \file B1PrimaryGeneratorAction.hh
/// \brief Definition of the B1PrimaryGeneratorAction class

// 刘铭学习B1实例记录
// 时间：2021、1、13 19:45

#ifndef B1PrimaryGeneratorAction_h
#define B1PrimaryGeneratorAction_h 1  

#include "G4VUserPrimaryGeneratorAction.hh"   // 导入G4初级粒子发生器行为类
#include "G4ParticleGun.hh"                   // Geant4粒子发生抢
#include "globals.hh"                         // 全局变量(物理常量、单位量纲)

class G4ParticleGun;                          // Geant4 粒子枪类
class G4Event;                                // Geant4 Event类
class G4Box;                                  // Geant4 盒子类

/// The primary generator action class with particle gun.
///
/// The default kinematic is a 6 MeV gamma, randomly distribued 
/// in front of the phantom across 80% of the (X,Y) phantom size.

class B1PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction   // 继承G4初级粒子发生器行为类
{   // 派生函数
  public:
    B1PrimaryGeneratorAction();    // 构造函数
    virtual ~B1PrimaryGeneratorAction();  // 析构函数

    // method from the base class
    virtual void GeneratePrimaries(G4Event*);   // 产生初级粒子函数         
  
    // method to access particle gun
    const G4ParticleGun* GetParticleGun() const { return fParticleGun; }  // 获取粒子枪函数
  
  private:
    G4ParticleGun*  fParticleGun; // pointer a to G4 gun class  设置G4粒子枪对象
    G4Box* fEnvelopeBox;  // 设置Envelope对象
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
