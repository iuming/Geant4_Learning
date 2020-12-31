/******************************************************************
FileName: 1_SpecifyDetectorMaterials
Author: 刘铭
Describes: 
Create:
Last Modify:
Modifications: 0
 *****************************************************************/

/*****************************************************************
   在自然界，通常材料（化合物、混合物）是由元素组成的，元素又是由同位素组成的。因此，在Geant4中有三个主要的类，每一个类都有一个表作为一个静态数据成员，用于跟踪这些类各自的实例。
   G4Element描述原子属性：
      原子序数
      核子数
      原子质量
      壳层能量
      其他量（原子截面等）
   G4Material描述物质的宏观属性：
      密度
      状态
      温度
      压强
      其他量（辐射长度、平均自由程、单位长度能损等）
   G4Material对工具包中的其他部分是可见的，用于粒子跟踪、几何体和物理过程。它包含可能是其组成成分的元素和同位素的所有信息。同时，它隐藏这些实现细节。
 ****************************************************************/
