/*************************************************************************************
 * FileName: 1_SpecifyParticles
 * Author: 刘铭
 * Describes: 
 * Create: Jan 4 2021, 15:47
 * Last Modify: 
 * Modifications: 0 
 * **********************************************************************************/

/****************************************************************************
 * G4VUserPhysicsList是用户必须要定义的基类之一，在这个类中，所有将用于模拟的粒子和物理过程必须被定义。
 * [注意]截断范围参数也在这个类中被定义。
 * 
 * 用户必须创建一个由G4VUserPhysicsList派生的类并定义一下虚函数：
 *  ConstructParticle();    //粒子构造
 *  ConstructProcess();     //物理过程构造并向相关粒子注册这些过程
 *  SetCuts();              //为所有粒子设定一个截断值
 * *************************************************************************/

/***************************************************************************
 * Geant4为用户提供了 各种类型的粒子：
 *  普通粒子，如电子、质子、伽马射线
 *  短寿命共振粒子，如矢量介子和delta重子
 *  夸克、底夸克、胶子
 * 
 * 每个粒子都由各自的类来描述，这些类都是由 G4ParticleDefinition 派生的。这些粒子主要分为 6 类：
    轻子
    介子
    重子
    玻色子
    短寿命粒子
    离子
    
    上述每一类粒子都被定义在 geant4/source/particles 下的相应子目录中。同样，对于每一类粒子都有一个相应的库。
 * ************************************************************************/

/*****************************************************************************
 * G4ParticleDefinition 类
 * G4ParticleDefinition 中有用于区分每个粒子的属性，如名字、质量、电荷、自旋等等。这些属性中，大部分是“只读”的，用户要对这些属性进行更改，就必须重建库。
 * **************************************************************************/

/*****************************************************************************
 * 如何存取一个粒子
 * 每个粒子类代表一个独立的粒子，并且每个类都有一个唯一的静态对象。
 * 例如，G4Electron 代表电子，它的唯一对象是G4Electron::theElectron。指向这个对象的指针可以通过静态方法G4Electron::ElectronDefinition()获取。
 * 缺省情况下，Geant4 提供了超过100 种粒子用于各种物理过程。在通常的应用程序中，用户不需要定义他自己的粒子。
 * 由于粒子是singleton 粒子类的静态对象，这些对象在main() 函数执行之前自动被实例化。
 * 然而，你必须显式的声明那些将被你的应用程序使用的粒子类，否则，编译程序不能识别哪些类是你需要的，结果将是没有粒子将被实例化。
 * **************************************************************************/

/*****************************************************************************
 * 粒子字典
 * G4ParticleTable 类是一个粒子字典。它提供了各种实用方法，如：
 *      FindParticle(G4String name): 通过 名字 查找粒子
 *      FindParticle(G4int PDGencoding): 通过 PDG编码 查找粒子
 * 
 * G4ParticleTable 同样定义为一个singleton 对象， G4ParticleTable::GetParticleTable()方法提供这个对象的指针。
 * **************************************************************************/
//注意: 粒子在构造期间被自动注册。用户不用控制粒子注册。

/********************************************************************************
 * 构造粒子
 * ConstructParticle() 是一个纯虚函数，所有在模拟中需要的粒子的静态成员函数应在这个方法中被调用。这保证了那些粒子的对象将被建立。
 * [注意]用户必须定义初级粒子和其它所有可能出现的次级粒子。
 * *****************************************************************************/

void ExN01PhysicsList::ConstructParticle() {
    G4Proton::ProtonDefinition();
    G4Geantino::GeantinoDefinition();
}
/*******************************************
 * 一个质子和一个Geantino，Geantino是一个虚粒子，它不与介质发生作用。
 * ****************************************/

/*********************************************************************************
 * 由于有大量预定义的粒子，用这个方法列出所有的粒子非常麻烦。Geant4 有6 个粒子大类，对应有6 个实用类，它们可用于简化粒子构造的过程：
 *      G4BosonConstructor      //玻色子
 *      G4LeptonConstructor     //轻子
 *      G4MesonConstructor      //重子
 *      G4BarionConstructor     //介子
 *      G4IonConstructor        //离子
 *      G4ShortlivedConstructor //短寿命粒子
 * ******************************************************************************/

void ExN05PhysicsList::ConstructLeptons() {
    // Construct all leptons
    G4LeptonConstructor pConstructor;
    pConstructor.ConstructParticle();
}