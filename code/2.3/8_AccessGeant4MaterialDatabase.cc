/****************************************************************
FileName: 8_AccessGeant4MaterialDatabase
Author: 刘铭
Descirbes: 连接查看Geant4材料数据库
Create: Dec 31 2020, 22:11
Last Modify: 
Modifications: 0
 ***************************************************************/

/material/nist/printElement  Fe      \\ 通过元素名称打印元素
/material/nist/printElementZ 13      \\ 通过原子序数打印元素
/material/nist/listMaterials type    \\ print materials type = [simple | compound | hep | all]
/material/g4/printElement    elmName \\ print instantiated element by name
/material/g4/printMaterial   matName \\ print instantiated material by name
