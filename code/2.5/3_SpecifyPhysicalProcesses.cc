/*********************************************************************************************
 * FileName: 3_SpecifyPhysicalProcesses.cc
 * Author: 刘铭
 * Describes: 指定物理过程
 * Create: Jan 6 2020, 15：08
 * Last Modify: 
 * Modifications: 0
 * ******************************************************************************************/

/**********************************************************************
 * G4VUserPhysicsList 是"必要的用户类"的一个基类，在这个类中，所有模拟中需要的物理过程和粒子必须被注册。
 * 用户必须构造一个从G4VUserPhysicsList 类派生的类，并且实现它的纯虚函数ConstructProcess()。
 * *******************************************************************/

//如果在模拟过程中只有使用了G4Geantino 粒子，那么只要注册输运过程就可以了。ConstructProcess() 方法将被实现：
void ExN01PhysicsList::ConstructProcess(){
    // Define transportation process
    AddTransportation();
}

/***********************************************
 * 在此，AddTransportation() 方法在G4VUserPhysicsList 类中提供，用于向所有粒子类注册G4Transportation 类。
 * G4Transportation 类 (或相关类) 描述粒子在时空中的运动。它是实现粒子跟踪所必需的类。
 * 
 * 物理过程应该在ConstructProcess() 方法中创建并向G4ProcessManager 类的每个粒子实例注册。
 * ********************************************/

//光子注册电磁作用过程的示例：
void MyPhysicsList::ConstructProcess(){
    // Define transportation process
    AddTransportation();
    // electromagnetic processes
    ConstructEM();
}
void MyPhysicsList::ConstructEM(){
    // Get the process manager for gamma
    G4ParticleDefinition* particle = G4Gamma::GammaDefinition();
    G4ProcessManager* pmanager = particle->GetProcessManager();
    // Construct processes for gamma
    G4PhotoElectricEffect * thePhotoElectricEffect = new G4PhotoElectricEffect();
    G4ComptonScattering * theComptonScattering = new G4ComptonScattering();
    G4GammaConversion* theGammaConversion = new G4GammaConversion();
    // Register processes to gamma's process manager
    pmanager->AddDiscreteProcess(thePhotoElectricEffect);
    pmanager->AddDiscreteProcess(theComptonScattering);
    pmanager->AddDiscreteProcess(theGammaConversion);
}

/***********************************************************
 * 在G4VUserPhysicsList::AddTransportation() 方法中注册物理过程的例子。
 * 在G4ProcessManager 中注册其他物理过程和粒子是一个复杂的过程，因为对于某些物理过程来说，物理过程之间的关系是非常重要的。
 * ********************************************************/