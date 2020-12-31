/***************************************************************
FileName: 7_PrintMaterialInformation
Author: 刘铭
Descirbes: 打印输出材料的信息
Create: Dec 31 2020, 22:06
Last Modify: 
Modifications: 0
 **************************************************************/

int main(){
  G4cout << H2O; //打印给定材料
  G4cout << *(G4Material::GetMaterialTable()); //打印材料列表？
}
