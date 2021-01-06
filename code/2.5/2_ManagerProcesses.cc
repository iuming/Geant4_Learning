/***************************************************************************
 * FileName: 2_ManagerProcesses
 * Author: 刘铭
 * Describes: 管理物理过程的一些函数
 * Create: Jan 6 2021, 15:01
 * Last Modify: 
 * Modifications: 0
 * ************************************************************************/

/***************************************************************
 * G4ProcessManager 类包含了与粒子相关的一个物理过程列表。它包含了与物理过程顺序相关的信息。同时，在列表中的每一个物理过程都有一个相应的DoIt 方法可用。一个G4ProcessManager 对象与一个粒子相对应，并且与G4ParticleDefiniton 类相关联。
 * 
 * 为了使物理过程有效，它们应该向该粒子的G4ProcessManager 对象注册。物理过程的顺序信息是用AddProcess() 和SetProcessOrdering() 方法添加的。AddAtRestProcess()、AddContinuousProcess() 和 AddDiscreteProcess() 方法可以用来注册简单的物理过程。
 * 
 * G4ProcessManager 可以在一个run 过程中，使用ActivateProcess() 和 InActivateProcess()方法来打开或关闭一些物理过程。这些方法只能在物理过程注册之后使用，所以它们不能在用户预初始化部分使用。
 * 
 * G4VUserPhysicsList 类创建G4ProcessManager 对象，并将这些对象与在ConstructParticle()方法中定义的所有粒子相关联。
 * ************************************************************/