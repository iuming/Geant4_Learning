#ifndef PrimaryGeneratorAction_h 
#define PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"

class G4ParticleGun;
class G4Event;

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
private:
    G4ParticleGun* particleGun;

public:
    PrimaryGeneratorAction(/* args */);
    virtual ~PrimaryGeneratorAction();

public:
    virtual void GeneratePrimaries(G4Event*);
    const G4ParticleGun* GetParticleGun() const {return particleGun;}
};

#endif