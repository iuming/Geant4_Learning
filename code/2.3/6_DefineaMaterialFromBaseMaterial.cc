/*************************************************************
FileName: 6_DefineMaterialFromBaseMaterial
Author: 刘铭
Describes: 从现有“基础”材料定义材料
Create: Dec 31 2020, 21:56
Last Modify:
Modifications: 0
 ************************************************************/

int main(){
  G4double density;
 
  density = 1.05*mg/cm3;
  G4Material* water1 = new G4Material("Water_1.05", density, "G4_WATER");

  density = 1.03mg/cm3;
  G4NistManager* man = G4NistManager::Instance();
  G4Material* water2 =man->BuildMaterialWithNewDensity("Water_1.03", "G4_WATER", density);
  /********************************************************
     通过现有“基础”材料构建新材料，可以使派生材料的所有校正数据以及基功率的截止功率和横截面的预先计算表达到峰值。
   *******************************************************/
}
