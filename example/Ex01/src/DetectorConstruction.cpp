#include "DetectorConstruction.hh"  

#include "G4NistManager.hh"            // Geant4材料库
#include "G4Box.hh"                    // Geant4方形物体
#include "G4LogicalVolume.hh"          // Geant4逻辑体
#include "G4PVPlacement.hh"            // Geant4相对位置
#include "G4RotationMatrix.hh"         // Geant4旋转角度
#include "G4Transform3D.hh"            // Geant4相对变换
#include "G4PhysicalConstants.hh"      // Geant4物理体
#include "G4SystemOfUnits.hh"          // Geant4单位制

// 构造函数
DetectorConstruction::DetectorConstruction():G4VUserDetectorConstruction(){
   DefineMaterials();
}

// 析构函数
DetectorConstruction::~DetectorConstruction(){

}

// 定义物质材料
void DetectorConstruction::DefineMaterials(){
   G4NistManager* man = G4NistManager::Instance();                // 创建材料对象
   G4bool isotopes = false;                                       // 设置同位素布尔量
   G4Element* H = man -> FindOrBuildElement("H", isotopes);       // 从Geant4材料库找寻H
   G4Element* O = man -> FindOrBuildElement("O", isotopes);       // 从Geant4材料库找寻O
   G4Material* H2O = new G4Material("Water", 1.000 * g/cm3, 2);   // 创建H2O材料
   H2O -> AddElement(H, 2);                                       // 定义H2O
   H2O -> AddElement(O, 1);                                       // 定义H2O
   G4Element* N = man -> FindOrBuildElement("N", isotopes);       // 从Geant4材料库找寻N
   G4double density = 1.290 * mg/cm3;                             // 定义密度
   G4Material* Air = new G4Material("Air", density, 2);           // 创建Air材料
   Air -> AddElement(N, 70 * perCent);                            // 定义Air
   Air -> AddElement(O, 30 * perCent);                            // 定义Air
}           

// 最重要的函数，设置探测器几何体、逻辑体、物理体
G4VPhysicalVolume* DetectorConstruction::Construct(){
   G4NistManager* man = G4NistManager::Instance();
   G4Material* default_mat = man -> FindOrBuildMaterial("Air");
   G4Material* box_mat = man -> FindOrBuildMaterial("Water");
   G4double worldSize = 1 * m;
   G4Box* soildWorld = new G4Box("World", worldSize, worldSize, worldSize);
   G4LogicalVolume* logicWorld = new G4LogicalVolume(soildWorld, default_mat, "World");
   G4VPhysicalVolume* physWorld = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "World", 0, false, 0);
   G4double Box_x = 0.5 * m;
   G4double Box_y = 0.5 * m;
   G4double Box_z = 0.5 * m;
   G4Box* testBox = new G4Box("testBox", Box_x, Box_y, Box_z);
   G4LogicalVolume* testBox_log = new G4LogicalVolume(testBox, box_mat, "testBox");
   G4VPhysicalVolume* testBox_phy = new G4PVPlacement(0, G4ThreeVector(), testBox_log, "testBox", logicWorld, false, 0);
   return physWorld;
}