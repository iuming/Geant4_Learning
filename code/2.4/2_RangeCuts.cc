/***********************************************************************************
 * FileName: 2_RangeCuts
 * Author: 刘铭
 * Describes: 设置截断范围
 * Create: Jan 6 2020, 14:35
 * Last Modify:
 * Modifications: 0
 * ********************************************************************************/

/*********************************************************************
 * 为了避免红外发散，一些电磁过程要求设定一个低阈。在阈值以下，将不产生任何次级粒子。因此，gamma、电子和正电子要求用户设定阈值。阈值应定义为距离，或者截断范围，它将自动转换为对应于不同介质的截断能量。这个阈值应在用户初始化部分用G4VUserPhysicsList 的SetCuts() 函数定义。
 * ******************************************************************/

/**********************************************************************
 * 截断设置
 * 产物的阈值应在SetCuts() 中定义，它是 G4VUserPhysicsList 类的纯虚函数。粒子、材料、物理过程的构造应在引用SetCuts()之前。在通常的应用程序中， G4RunManager 关心这个顺序。
 * “唯一截断范围值”的思想是Geant4 的一个重要特性，它用一个一致的方法处理截断值。对于多数应用来说，用户只要确定一个截断范围值，这个值将以同样的方式用于gamma、电子、正电子。
 * 在这种情况下，可以使用 SetCutsWithDefault() 方法，它由基类G4VuserPhysicsList 提供，它有一个defaultCutValue 成员作为缺省截断范围值。SetCutsWithDefault()使用这个值。
 * 可以对gamma，电子和正电子设定不同的截断范围值，并且对不同的几何区域设置不同的截断范围值。在这种情况下，必须非常小心，因为Geant4 进程(特别是能量损失)是遵循“唯一截断范围值”的模式设计的。
 * *******************************************************************/

// 使用缺省截断值设置截断值
void ExN04PhysicsList::SetCuts() {
// the G4VUserPhysicsList::SetCutsWithDefault() method sets
// the default cut value for all particle types
    SetCutsWithDefault();
}

/******************************************************
 * defaultCutValue 在缺省情况下设置为1.0 mm。
 * 当然，可以在PhysicsList 类中设置新的缺省值。
 * ***************************************************/

//设置缺省截断值
ExN04PhysicsList::ExN04PhysicsList(): G4VUserPhysicsList(){
    defaultCutValue = 1.0*mm;
}

/*********************************************************************************
 * 也可以使用在G4VUserPhysicsList 中的SetDefaultCutValue() 方法， 和 "/run/setCut" 命令来交互的改变缺省截断值。
 * 
 * [注意]不要在一个事件循环内改变截断值，但截断值可以在两次run之间改变。
 * ******************************************************************************/

//SetCuts() 方法的一个实现方法
void ExN03PhysicsList::SetCuts(){
    // set cut values for gamma at first and for e- second and next for e+,
    // because some processes for e+/e- need cut values for gamma
    SetCutValue(cutForGamma, "gamma");
    SetCutValue(cutForElectron, "e-");
    SetCutValue(cutForElectron, "e+");
}