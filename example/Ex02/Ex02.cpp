#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "DetectorConstruction.hh"
#include "PhysicsList.hh"
#include "PrimaryGeneratorAction.hh"

int main(int argc, char** argv){
    G4RunManager* runManager = new G4RunManager;
    G4UIExecutive* ui = new G4UIExecutive(argc, argv);
    G4VisManager* visManager = new G4VisExecutive;
    visManager -> Initialize();
    runManager -> SetUserInitialization(new DetectorConstruction);
    runManager -> SetUserInitialization(new PhysicsList);
    runManager -> SetUserAction(new PrimaryGeneratorAction);
    runManager -> Initialize();
    G4UImanager* UI = G4UImanager::GetUIpointer();
    UI -> ApplyCommand("/control/execute init_vis.mac");
    ui -> SessionStart();
    delete ui;
    int numberOfEvents = 3;
    runManager -> BeamOn(numberOfEvents);
    delete runManager;
    delete visManager;
    return 0;
}