/************************************************************
FileName: 3_ChooseaSoild
Author: 刘铭
Describe: 定义Box的一些代码
Create: Dec 30 2020, 14:40
Last Modify: 
Modifications: 0
 ***********************************************************/

/************************************************************
  创建一个简单的Box，只需要定义它的名字和尺寸。
 ***********************************************************/

//ExN01DetectorConstruction.cc
#include “G4DetectorConstruction.hh”

//...

int main()
{
  //...
  
  //定义长宽高参数
  G4double expHall_x = 3.0*m;
  G4double expHall_y = 1.0*m;
  G4double expHall_z = 1.0*m;

  //新建一个Box
  G4Box* experimentalHall_box = new G4Box(*expHall_box, expHall_x, expHall_y, expHall_z);
  /********************************************
     创建一个Name为“expHall_box”的Box，Box沿X轴方向从-3.0到3m，沿Y轴方向从-1.0到1m，沿Z轴方向从-1.0到1m。
  *********************************************/

  //定义圆柱体参数
  G4double innerRadiusOfTheTube = 0.*cm;
  G4double outerRadiusOfTheTube = 60.*cm;
  G4double hightOfTheTube = 50.*cm;
  G4double startAngleOfTheTube = 0.*deg;
  G4double spanningAngleOfTheTube = 360.*deg;

  //创建一个圆柱体
  G4Tubs* tracker_tube = new G4Tubs("tracker_tube", innerRadiusOfTheTube, outerRadiusOfTheTube, hightOfTheTube, startAngleOfTheTube, spanningAngleOfTheTube);
  /***********************************************
     创建一个Name为“tracker_tube”的圆柱体，半径为60cm，高为50cm。
   **********************************************/

}
