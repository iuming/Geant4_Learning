/************************************************************************************************
 * FileName: 1_GeneralParticleSource
 * Author: 刘铭
 * Describes: 
 * Create: Jan 9 2021, 19:13
 * Last Modify:
 * Modifications: 0
 * *********************************************************************************************/

/***************************************************************************
 * G4GeneralParticleSource（GPS）是GEANT4工具包蒙特卡洛的一部分，用作高能粒子传输。具体而言，它允许指定主要源粒子的光谱、空间和角度分布。这里介绍了GPS类的结构。配置涵盖了针对用户应用程序的GPS配置，并且“ 宏命令”描述了宏命令界面。示例宏文件提供了一个示例输入文件来指导初次使用的用户。
 * 
 * 在GEANT4应用中，G4GeneralParticleSource的功能和 G4ParticleGun一样。在现有应用程序中，您可以通过全局替换G4ParticleGun为来简单地更改PrimaryGeneratorAction G4GeneralParticleSource。GPS可以通过命令行或基于宏的输入进行配置。还可以使用更详细描述的GPS方法和类别对发行进行硬编码。
 * 
 * 从版本10.01开始，引入了拆分类机制以减少多线程模式下的内存使用。G4GeneralParticleSourceData是线程安全的单它提供了访问的源信息 G4GeneralParticleSource类。G4GeneralParticleSourceData 类可以具有的多个实例化G4SingleParticleSource 类，每个独立的位置、角度和能量分布以及入射粒子类型。对用户而言，此更改更加方便。
 * 
 * ************************************************************************/

