/**************************************************************************
 FileName: 2_G4UIterminal
 Author: 刘铭
 Describe: G4UImanager类和发送UI用户接口命令
 Create: Dec 29 2020, 22:29
 Last Modify: Dec 29 2020,
 Modifcations: 0
 *************************************************************************/

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4UIterminal.hh"

#include "N02VisManager.hh"
#include "N02DetectorConstruction.hh" 
#include "N02PhysicsList.hh"
#include "N02PrimaryGeneratorAction.hh" 
#include "N02RunAction.hh"
#include "N02EventAction.hh"
#include "N02SteppingAction.hh"

#include "g4templates.hh"

int main(int argc,char** argv)
{
    // 新建G4RunManager类对象runManager
    G4RunManager * runManager = new G4RunManager;
    
    // 设置必须的初始化类
    N02DetectorConstruction* detector = new N02DetectorConstruction;
    runManager->SetUserInitialization(detector);
    runManager->SetUserInitialization(new N02PhysicsList);

    // 可视化 manager
    G4VisManager* visManager = new N02VisManager; visManager->initialize();
    
    // 设置用户行为类
    runManager->SetUserAction(new N02PrimaryGeneratorAction(detector));
    runManager->SetUserAction(new N02RunAction);
    runManager->SetUserAction(new N02EventAction);
    runManager->SetUserAction(new N02SteppingAction);
    
    // 获取指向 UI manager 的指针
    G4UImanager* UI = G4UImanager::GetUIpointer();
 
    if(argc==1)
    // 定义交互式(G)UI 终端
    {
        G4UIsession* session = new G4UIterminal;
        UI->ApplyCommand("/control/execute prerun.g4mac");
        session->sessionStart();
        delete session;
    }
    else
    // 批处理模式
    {
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UI->ApplyCommand(command+fileName);
    }
    
    // 任务结束
    delete visManager;
    delete runManager;
    return 0;
}
