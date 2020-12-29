/*********************************************************************
 FileName: 1_BasicConcepts
 Author: 刘铭
 Describe: 探测器集合体的基本概念
 Create: Dec 29 2020, 23:04
 Last Modify: 
 Modifications: 0
*********************************************************************/

/*********************************************************************
 在Geant4中，探测器几何体是由大量几何体组成的。其中，几何体的整体叫世界(World)。它包含其他所有的几何体。其它的几何体，都被创建并放置在世界(World)中。
 每个几何体都通过描述它的形状和物理特性来创建，然后放置到另一个几何体中。
 当一个几何体被放置到另一个中时，前者为子几何体，后者为母几何体。用相对于母体坐标系的坐标指定子体放置的位置。
 为了描述几何体的形状，我们使用实体的概念。一个实体是指一个有固定形状和尺寸的几何物体。一个边长 10cm的立方体和一个半径30cm、高75cm的圆柱体都是具体的实体。
 为了描述几何体的全部属性，我们使用逻辑几何体的概念。逻辑几何体包括实体的所有几何特性和另外的物理特性：几何体的材料、是否包含探测器的敏感单元、磁场等等。
 我们必须描述如何放置几何体。为此，需要建立一个物理几何体，用于放置逻辑体的拷贝。
*********************************************************************/