#include "G4RunManager.hh"
#include "G4UImanager.hh"

#include "DetectorConstruction.hh"
#include "PhysicalList.hh"
#include "PrimaryGeneratorAction.hh"

int main(){
    G4RunManager * runManager = new G4RunManager;
    runManager->SetUserInitialization(new DetectorConstruction);
}