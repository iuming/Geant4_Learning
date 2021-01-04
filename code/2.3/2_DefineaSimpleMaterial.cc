/**********************************************************************
FileName: 2_DefineaSimpleMaterial
Author: 刘铭
Describes: 
Create: Dec 31 2020, 21:06
Last Modify:
Modifications: 0
 *********************************************************************/

/*********************************************************************
   通过指定材料名字、密度、摩尔质量和原子数创建液态氩
 ********************************************************************/
G4double density = 1.390*g/cm3;
G4double a = 29.95*g/mole;

G4Material* lAr = new G4Material(name="liquidArgon", z=18. , a, density);

G4LogicalVolume* myLbox = new G4LogicalVolume(abox, lAr, "Lbox", 0 0, 0);
/*********************************************************
   lAr为指向该材料的指针，将用于制定一个给定逻辑体的材料
 ********************************************************/