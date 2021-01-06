/***************************************************************************
 * FileName: 1_GeneratingPrimaryEvents
 * Author: 刘铭
 * Describes: 
 * Create: Jan 6 2021, 16:18
 * Last Modify:
 * Modifications: 0
 * ************************************************************************/

/****************************************************
 * G4VuserPrimaryGeneratorAction 是一个用户必需的类，用户需要从它派生自己的类。在用户派生的类中，必须指定如何产生一个初级事件。实际上，初级粒子的产生是由G4VPrimaryGenerator 类完成的，这将在下一小节中讨论。
 * 用户的G4VUserPrimaryGeneratorAction 构造类，只是描述了初级粒子的产生方式。
 * *************************************************/

#ifndef ExN01PrimaryGeneratorAction_h
#define ExN01PrimaryGeneratorAction_h 1
#include "G4VUserPrimaryGeneratorAction.hh"

class G4ParticleGun;
class G4Event;
class ExN01PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction{
    public:
        ExN01PrimaryGeneratorAction();
        ~ExN01PrimaryGeneratorAction();
    public:
        void generatePrimaries(G4Event* anEvent);
    private:
        G4ParticleGun* particleGun;
};
#endif

#include "ExN01PrimaryGeneratorAction.hh"
#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ThreeVector.hh"
#include "G4Geantino.hh"
#include "globals.hh"

ExN01PrimaryGeneratorAction::ExN01PrimaryGeneratorAction(){
    G4int n_particle = 1;
    particleGun = new G4ParticleGun(n_particle);
    particleGun->SetParticleDefinition(G4Geantino::GeantinoDefinition());
    particleGun->SetParticleEnergy(1.0*GeV);
    particleGun->SetParticlePosition(G4ThreeVector(-2.0*m,0.0*m,0.0*m));
}

ExN01PrimaryGeneratorAction::~ExN01PrimaryGeneratorAction(){
    delete particleGun;
}
void ExN01PrimaryGeneratorAction::generatePrimaries(G4Event* anEvent){
    G4int i = anEvent->get_eventID() % 3;
    switch(i){
        case 0:
            particleGun->SetParticleMomentumDirection(G4ThreeVector(1.0,0.0,0.0));
            break;
        case 1:
            particleGun->SetParticleMomentumDirection(G4ThreeVector(1.0,0.1,0.0));
            break;
        case 2:
            particleGun->SetParticleMomentumDirection(G4ThreeVector(1.0,0.0,0.1));
            break;
    }
    particleGun->generatePrimaryVertex(anEvent);
}

/************************************************************************************
 * 粒子发生器的选择
 * 在用户的 G4VUserPrimaryGeneratorAction 类的构造函数中，用户应该初始化初级粒子发生器。如果必要的化，用户需要为这些粒子发生器设置一些初始值。
 * G4ParticleGun 是用来作为实际的粒子发生器的。G4ParticleGun 中的方法，将在下节中讨论。
 * [注意]那些在用户的G4VUserPrimaryGeneratorAction 构造函数中构造的初级粒子发生器的对象，必须在相应的析构函数中删除。
 * *********************************************************************************/

/************************************************************************************
 * 事件的产生
 * G4VUserPrimaryGeneratorAction 类，有一个纯虚方法generatePrimaries()。这个方法在每一个事件的开始被调用。在这个方法中，用户必须调用具体G4VPrimaryGenerator 类的generatePrimaryVertex() 方法。
 * 用户可以调用一个或多个粒子发生器，也可以多次调用同一个粒子发生器。混合使用几个发生器可以产生一个非常复杂的初级事件。
 * *********************************************************************************/