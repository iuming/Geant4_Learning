#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"   // Geant4为用户提供的探测器结构类
#include "globals.hh"                       // 包含Geant4中的全局变量等，除Actioninitializtion外均应包含

class G4PhysicalVolume;                     // Geant4物理体类
class G4LogicalVolume;                      // Geant4逻辑体类

// 定义探测器结构类，继承G4探测器结构类
class DetectorConstruction : public G4VUserDetectorConstruction 
{
private:
    void DefineMaterials();                 // 定义材料，仅在类中可进行调用
public:
    DetectorConstruction();                 // 定义探测器材料
    virtual ~DetectorConstruction();        // 释放内存（可为空）
    virtual G4VPhysicalVolume* Construct(); // 定义探测器结构
}; 

#endif