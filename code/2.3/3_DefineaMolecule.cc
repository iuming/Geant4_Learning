/*******************************************************
FileName: 3_DefineaMolecule
Author: 刘铭
Describes: 描述定义水分子材料
Create: Dec 31 2020, 21:22
Last Modify:
Modificaions: 0
 ******************************************************/

G4double z, a, density;
G4String name, symbol;
G4int ncomponents, natoms;

a = 1.01*g/mole;
G4Element* elH = new G4Element(name="Hydrogen", symbol="H", z=1. ,a);

a = 16.00*g/mole;
G4Element* elO = new G4Element(name="Oxygen", symbol="O", z=8. ,a);

density = 1.000*g/cm3;
G4Material* H2O = new G4Material(name="Water", density, ncomponents=2);
H2O->AddElement(elH, natoms=2);
H2O->AddElement(elO, natoms=1);

/**********************************************************************
通过定义组成水分子成分的原子以及水分子中各原子的数目，创建水分子材料。
 *********************************************************************/
