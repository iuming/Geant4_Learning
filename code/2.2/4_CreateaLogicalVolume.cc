/**************************************************************
FileName: CreateaLogicalVolume
Author: 刘铭
Describe: 创建带有实体和材料等逻辑几何体
Create: Dec 30 2020, 15:04
Last Modify:
Modifications: 0 
 *************************************************************/

int main()
{
  //创建逻辑几何体
  G4LogicalVolume* experimentalHall_log = new G4LogicalVolume(experimentalHall_box,Ar,"expHall_log");
  /********************************************************
     用已经创建过的Box(experimentHall_box)创建逻辑几何体，填充氩气(Ar)。
   *******************************************************/

  //创建圆柱逻辑体
  G4LogicalVolume* tracker_log = new G4LogicalVolume(tracker_tube,Al,"tracker_log");
  /***********************************************************
     用已经创建过的Box(tracker_tube)，创建逻辑几何体，填充铝(Al)。
   **********************************************************/
}
