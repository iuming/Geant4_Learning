/********************************************************************************************
 * FileName: 4_ExampleMacroFile
 * Author: 刘铭
 * Describes: 
 * Create: Jan 10 2021, 13:12
 * Last Modify:
 * Modifications: 0
 * *****************************************************************************************/

//示例宏文件
// # Macro test2.g4mac
// /control/verbose 0
// /tracking/verbose 0
// /event/verbose 0
// /gps/verbose 2
// /gps/particle gamma
// /gps/pos/type Plane
// /gps/pos/shape Square
// /gps/pos/centre 1 2 1 cm
// /gps/pos/halfx 2 cm
// /gps/pos/halfy 2 cm
// /gps/ang/type cos
// /gps/ene/type Lin
// /gps/ene/min 2 MeV
// /gps/ene/max 10 MeV
// /gps/ene/gradient 1
// /gps/ene/intercept 1
// /run/beamOn 10000
/*************************************************************
 * 上面的宏定义了一个平面源，方形方形，长4厘米 x 4厘米，以（1,2,1）厘米为中心。默认情况下，此平面的法线是z轴。角度分布应遵循余弦定律。能谱是线性的，梯度和截距等于1，并且从2 MeV扩展到10 MeV。将生成10,000个初级粒子。
 * 
 * Geant4的标准输出应显示，原始粒子从1、0、1和3、4、1（以厘米为单位）开始，并且具有2至10 MeV的能量，其中我们绘制了实际的由上述宏文件生成的一次粒子的能量、位置和角度分布。
 * **********************************************************/