# Geant4_Learning
Record some code and learning process of learning genat4!

学习文档：                 
[Geant4.5.2用户手册](https://github.com/iuming/Geant4_Learning/blob/main/books/Geant4.5.2%E7%94%A8%E6%88%B7%E6%89%8B%E5%86%8C.pdf)                             
[Geant4.10.7Book For Application DevelopersLogo](https://github.com/iuming/Geant4_Learning/blob/main/books/BookForApplicationDevelopers.pdf)

## 2.1如何编写main()函数
### 2.1.1 一个main()函数的例子
[G4RunManager](https://github.com/iuming/Geant4_Learning/blob/main/code/2.1/1_G4RunManagerG4UImanager.cc)                     
[G4UImanager](https://github.com/iuming/Geant4_Learning/blob/main/code/2.1/1_G4RunManagerG4UImanager.cc) 	        
[G4UIterminal](https://github.com/iuming/Geant4_Learning/blob/main/code/2.1/2_G4UIterminal.cc)            
[G4coutG4cerr](https://github.com/iuming/Geant4_Learning/blob/main/code/2.1/3_G4coutG4cerr.cc)         

## 2.2如何定义一个探测器的几何形状
### 2.2.1 [基本概念](https://github.com/iuming/Geant4_Learning/blob/main/code/2.2/1_BasicConcepts.cc)           
### 2.2.2 [创建一个简单的几何体](https://github.com/iuming/Geant4_Learning/blob/main/code/2.2/2_CreateaSimpleVolume.cc)                                  
### 2.2.3[选择一个实体](https://github.com/iuming/Geant4_Learning/blob/main/code/2.2/3_ChooseaSoild.cc)                
### 2.2.4[创建一个逻辑集合体](https://github.com/iuming/Geant4_Learning/blob/main/code/2.2/4_CreateaLogicalVolume.cc)                       
### 2.2.5[放置一个几何体](https://github.com/iuming/Geant4_Learning/blob/main/code/2.2/5_PlaceaVolume.cc)                 
### 2.2.6[创建一个物理几何体](https://github.com/iuming/Geant4_Learning/blob/main/code/2.2/6_CreateaPhysicalVolume.cc)                 
### 2.2.7[坐标系和旋转](https://github.com/iuming/Geant4_Learning/blob/main/code/2.2/7_CoordinateSystemsAndRotations.cc)                    

## 2.3 定义探测器材料
### 2.3.1[通常情况](https://github.com/iuming/Geant4_Learning/blob/main/code/2.3/1_SpecifyDetectorMaterials.cc)                
### 2.3.2[定义简单的材料](https://github.com/iuming/Geant4_Learning/blob/main/code/2.3/2_DefineaSimpleMaterial.cc)               
### 2.3.3[定义分子材料](https://github.com/iuming/Geant4_Learning/blob/main/code/2.3/3_DefineaMolecule.cc)                     
### 2.3.4[通过质量百分比定义混合物](https://github.com/iuming/Geant4_Learning/blob/main/code/2.3/4_DefineaMixtureByFractionalMass.cc)                   
### 2.3.5[通过Geant4数据库定义材料](https://github.com/iuming/Geant4_Learning/blob/main/code/2.3/5_DefineMaterialFromGeant4MaterialDatabase.cc)                   
### 2.3.6[通过已经定义的材料定义新材料](https://github.com/iuming/Geant4_Learning/blob/main/code/2.3/6_DefineaMaterialFromBaseMaterial.cc)                           
### 2.3.7[打印材料信息](https://github.com/iuming/Geant4_Learning/blob/main/code/2.3/7_PrintMaterialInformation.cc)                       
### 2.3.8[连接Geant4材料数据库](https://github.com/iuming/Geant4_Learning/blob/main/code/2.3/8_AccessGeant4MaterialDatabase.cc)                                  

## 2.4如何指定粒子
### 2.4.1[粒子定义](https://github.com/iuming/Geant4_Learning/blob/main/code/2.4/1_SpecifyParticles.cc)                                
### 2.4.2[截断范围](https://github.com/iuming/Geant4_Learning/blob/main/code/2.4/2_RangeCuts.cc)                   

## 2.5如何指定物理过程
### 2.5.1[物理过程](https://github.com/iuming/Geant4_Learning/blob/main/code/2.5/1_PhysicalProcesses.cc)                      
### 2.5.2[物理过程管理](https://github.com/iuming/Geant4_Learning/blob/main/code/2.5/2_ManagerProcesses.cc)                           
### 2.5.3[指定物理过程](https://github.com/iuming/Geant4_Learning/blob/main/code/2.5/3_SpecifyPhysicalProcesses.cc)                              

## 2.6产生一个初级事件
### 2.6.1[产生初级事件](https://github.com/iuming/Geant4_Learning/blob/main/code/2.6/1_GeneratingPrimaryEvents.cc)                        
### 2.6.2[G4VPrimaryGenerator类](https://github.com/iuming/Geant4_Learning/blob/main/code/2.6/2_G4VPrimaryGenerator.cc)                          