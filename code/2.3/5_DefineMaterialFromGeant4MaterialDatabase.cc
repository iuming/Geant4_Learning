/***************************************************************
FileName: 5_DefineMaterialFromGeant4MaterialDatabase
Author: 刘铭
Describes: 从Geant材料数据库中定义材料
Create: Dec 31 2020, 21:48
Last Modify:
Modifications: 0 
 **************************************************************/

int main(){
  //...
  G4NistManager* man = G4NistManager::Instance();
  
  G4Material* H2O = man->FindOrBuildMaterial("G4_WATER");
  G4Material* Air = man->FindOrBuildMaterial("G4_AIR");
  /***********************************************
     通过Geant4材料数据库访问空气和水。
   **********************************************/
}

