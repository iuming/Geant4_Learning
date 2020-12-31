/***********************************************************
FileName: 4_DefineaMixtureByFractionalMass
Author: 刘铭
Describes: 描述混合物的物理体定义方法
Create: Dec 31 2020, 21:33
Last Modify:
Modifications: 0
 **********************************************************/
int main(){
  //...
  G4double z, a, fractionmass, density;
  G4String name, symbol;
  G4int ncomponents;

  a = 14.01*g/mole;
  G4Element* elN  = new G4Element(name="Nitrogen",symbol="N" , z= 7., a);

  a = 16.00*g/mole;
  G4Element* elO  = new G4Element(name="Oxygen"  ,symbol="O" , z= 8., a);

  density = 1.290*mg/cm3;
  G4Material* Air = new G4Material(name="Air  ",density,ncomponents=2);
  Air->AddElement(elN, fractionmass=70*perCent);
  Air->AddElement(elO, fractionmass=30*perCent);
  /*******************************************
     通过给出每种成分的分数质量，来定义混合物。
   ******************************************/
}
