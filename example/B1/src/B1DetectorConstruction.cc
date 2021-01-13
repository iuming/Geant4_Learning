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
/// \file B1DetectorConstruction.cc
/// \brief Implementation of the B1DetectorConstruction class

// 刘铭学习B1记录
// 时间： 2021、1、13 16：37

#include "B1DetectorConstruction.hh"  

#include "G4RunManager.hh"    // Geant4运行管理类头文件
#include "G4NistManager.hh"   // Geant4标准材料库头文件
#include "G4Box.hh"           // Geant4盒子头文件
#include "G4Cons.hh"          // Geant4圆锥体头文件
#include "G4Orb.hh"           // Geant4球形头文件的一个案例
#include "G4Sphere.hh"        // Geant4球形头文件
#include "G4Trd.hh"           // Geant4梯形头文件
#include "G4LogicalVolume.hh" // Geant4逻辑体头文件
#include "G4PVPlacement.hh"   // Geant4表示物理相对位置的头文件
#include "G4SystemOfUnits.hh" // Geant4单位头文件

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1DetectorConstruction::B1DetectorConstruction()  // 构造函数定义
: G4VUserDetectorConstruction(),                  // 继承Geant4为用户定义的探测器结构类的构造函数
  fScoringVolume(0)
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B1DetectorConstruction::~B1DetectorConstruction() // 析构函数定义
{ } // 为空

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* B1DetectorConstruction::Construct()  // 定义探测器结构函数
{  
  // Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();  // Geant4材料库对象
  
  // Envelope parameters
  // 定义容器
  G4double env_sizeXY = 20*cm, env_sizeZ = 30*cm;   // 定义长宽的长度为20厘米，高的长度为30厘米
  G4Material* env_mat = nist->FindOrBuildMaterial("G4_WATER");  // 定义材料类型为水
   
  // Option to switch on/off checking of volumes overlaps
  // 定义重叠检查布尔量
  G4bool checkOverlaps = true;  

  //     
  // World
  // 先定义World物理，World是Geant4首先且必须定义的形状，表示整体范围
  G4double world_sizeXY = 1.2*env_sizeXY; // world的长宽的长度，设置为1.2倍容器长度
  G4double world_sizeZ  = 1.2*env_sizeZ;  // world的高的长度，设置为1.2倍容器长度
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");  // world的材料设置为空气
  
  G4Box* solidWorld =    // 定义实体为长方体
    new G4Box("World",                       //its name 长方体名称 
       0.5*world_sizeXY, 0.5*world_sizeXY, 0.5*world_sizeZ);     //its size 实体大小(长、宽、高)
      
  G4LogicalVolume* logicWorld =       // 定义长方体实体的逻辑体                    
    new G4LogicalVolume(solidWorld,          //its solid  实体变量
                        world_mat,           //its material 逻辑体材料
                        "World");            //its name 长方体名称
                                   
  G4VPhysicalVolume* physWorld =      // 定义长方体逻辑体的物理体
    new G4PVPlacement(0,                     //no rotation  不进行旋转
                      G4ThreeVector(),       //at (0,0,0)   物理体位置
                      logicWorld,            //its logical volume   逻辑体变量
                      "World",               //its name     长方体名称
                      0,                     //its mother  volume   它的母体，由于这个是world，因此没有母体
                      false,                 //no boolean operation 不进行布尔运算，物理之间的逻辑运算，类似OpenSCAD
                      0,                     //copy number  不进行复制
                      checkOverlaps);        //overlaps checking    重叠判断
                     
  //     
  // Envelope
  // 定义实验范围
  G4Box* solidEnv =     // 用长方体定义Envelope
    new G4Box("Envelope",                    //its name 名称
        0.5*env_sizeXY, 0.5*env_sizeXY, 0.5*env_sizeZ); //its size  尺寸
      
  G4LogicalVolume* logicEnv =     // 定义Envelope逻辑体                       
    new G4LogicalVolume(solidEnv,            //its solid  实体变量
                        env_mat,             //its material 材料
                        "Envelope");         //its name 名称
  // 省略了物理体变量名称             
  new G4PVPlacement(0,                       //no rotation  // 不进行旋转
                    G4ThreeVector(),         //at (0,0,0)   // 在母体的位置为(0，0，0)
                    logicEnv,                //its logical volume   // 逻辑体变量
                    "Envelope",              //its name     // 名称
                    logicWorld,              //its mother  volume   // 母体逻辑体变量
                    false,                   //no boolean operation // 不进行物体逻辑运算
                    0,                       //copy number  // 不进行复制
                    checkOverlaps);          //overlaps checking    // 重叠判断
 
  //     
  // Shape 1
  // 定义第一个实体
  G4Material* shape1_mat = nist->FindOrBuildMaterial("G4_A-150_TISSUE");  // 设置Geant4材料化合物---A-150塑料
  G4ThreeVector pos1 = G4ThreeVector(0, 2*cm, -7*cm);   // 定义在母体的位置
        
  // Conical section shape       圆锥尺寸
  G4double shape1_rmina =  0.*cm, shape1_rmaxa = 2.*cm; // 顶端尺寸
  G4double shape1_rminb =  0.*cm, shape1_rmaxb = 4.*cm; // 底端尺寸
  G4double shape1_hz = 3.*cm;                           // 高
  G4double shape1_phimin = 0.*deg, shape1_phimax = 360.*deg;  // 一圈
  G4Cons* solidShape1 =    // 定义Shape1实体
    new G4Cons("Shape1",   // 名称
    shape1_rmina, shape1_rmaxa, shape1_rminb, shape1_rmaxb, shape1_hz,  // 尺寸
    shape1_phimin, shape1_phimax);
                      
  G4LogicalVolume* logicShape1 =             // 定义Shape1逻辑体                 
    new G4LogicalVolume(solidShape1,         //its solid  实体变量
                        shape1_mat,          //its material 材料
                        "Shape1");           //its name 名称
               
  new G4PVPlacement(0,                       //no rotation  不进行旋转  
                    pos1,                    //at position  位置
                    logicShape1,             //its logical volume 逻辑体变量
                    "Shape1",                //its name     名称
                    logicEnv,                //its mother  volume 母体逻辑体
                    false,                   //no boolean operation 不进行逻辑运算
                    0,                       //copy number  不进行复制
                    checkOverlaps);          //overlaps checking  重叠判断

  //     
  // Shape 2 
  // 
  G4Material* shape2_mat = nist->FindOrBuildMaterial("G4_BONE_COMPACT_ICRU");   // 设置Shape2材料
  G4ThreeVector pos2 = G4ThreeVector(0, -1*cm, 7*cm); // 设置Shape2在母体中的位置

  // Trapezoid shape       梯形
  G4double shape2_dxa = 12*cm, shape2_dxb = 12*cm; 
  G4double shape2_dya = 10*cm, shape2_dyb = 16*cm;
  G4double shape2_dz  = 6*cm;      
  G4Trd* solidShape2 =    
    new G4Trd("Shape2",                      //its name
              0.5*shape2_dxa, 0.5*shape2_dxb, 
              0.5*shape2_dya, 0.5*shape2_dyb, 0.5*shape2_dz); //its size
                
  G4LogicalVolume* logicShape2 =                         
    new G4LogicalVolume(solidShape2,         //its solid
                        shape2_mat,          //its material
                        "Shape2");           //its name
               
  new G4PVPlacement(0,                       //no rotation
                    pos2,                    //at position
                    logicShape2,             //its logical volume
                    "Shape2",                //its name
                    logicEnv,                //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking
                
  // Set Shape2 as scoring volume
  // 将Shape2逻辑体变量设置为得分变量？得分变量是啥？
  fScoringVolume = logicShape2;

  //
  //always return the physical World
  // 返回World的物理体
  return physWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
