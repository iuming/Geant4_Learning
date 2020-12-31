/*************************************************************************
 FileName: 6_CreateaPhysicalVolume
 Author: 刘铭
 Describe: 通过逻辑体来创建几何体
 Create: Dec 30 2020, 19:32
 Last Modify: 
 Modifications: 0
*************************************************************************/

/*************************************************************************
   通过逻辑体来创建物理体，物理体是一个已经放置了的逻辑体实例，这个实例必须被放置在另外一个逻辑母几何体中。
*************************************************************************/

int main()
{
  G4double trackerPos_x = -1.0*meter;
  G4double trackerPos_y = 0.0*meter;
  G4double trackerPos_z = 0.0*meter;

  G4VPhysicalVolume* tracker_phys
    = new G4PVPlacement(0,// 不旋转
			G4ThreeVector(trackerPos_x,trackerPos_y,trackerPos_z), // 子体在母体中的坐标
			tracker_log, // 子逻辑体指针
			"tracker", // 物理体名
			experimentalHall_log, // 母逻辑体指针
			false, // 无布尔操作
			0); // 物理体的拷贝序号
  /*******************************************************
     将逻辑体tracker_log放在母体experimentalHall_log的坐标4原点(难道不是-1.0,0.0,0.0 点吗？)，不旋转，生成的物理体名称叫"tracker"，拷贝序号为0。
   ******************************************************/

  /******************************************************
     一个物理体必须放置在另一个母体之中，除了World，它是被创建的最大的几何体，包含其他所有几何体，它必须使用母体指针通过G4PVPlacement来创建，它不能是旋转的，必须放置于全局坐标原点。
   *****************************************************/
  G4VPhysicalVolume* experimentalHall_phys
    = new G4PVPlacement(0, //不旋转
			G4ThreeVector(0.,0.,0.), //子体在母体中的坐标
			experimentalHall_log, //子逻辑体指针
			"expHall", //物理体名
			0, //母逻辑体指针
			false, //无布尔操作
			0); //物理体的拷贝序号

} 

