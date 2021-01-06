/*********************************************************************************************
 * FileName: 1_SpecifyPhysicalProcesses.cc
 * Author: 刘铭
 * Describes: 描述物理过程
 * Create: Jan 6 2020, 14:54
 * Last Modify: 
 * Modifications: 0
 * ******************************************************************************************/

/***********************************************************
 * 物理过程描述粒子如何与物质相互作用。Geant4 提供了7 个大类的这些过程。
 *      电磁相互作用
 *      强相互作用
 *      输运
 *      衰变
 *      可见光
 *      photolepton_hadron
 *      参数化相互作用
 * ********************************************************/

/************************************************************
 * 所有这些物理过程的基类都是G4VProcess 。他的虚函数
 *      AtRestDoIt
 *      AlongStepDoIt
 *      PostStepDoIt
 *  和对应的方法
 *      AtRestGetPhysicalInteractionLength
 *      AlongStepGetPhysicalInteractionLength
 *      PostStepGetPhysicalInteractionLength
 *  在它们的派生类中描述了这些物理过程的行为。
 * *********************************************************/

/**************************************************************
 * 下面是用于单一物理过程的特殊化基类：
 *      G4VAtRestProcess        //只有  AtRestDoIt 的物理过程
 *      G4VContinuousProcess    //只有  AlongStepDoIt 的物理过程
 *      G4VDiscreteProcess      //只有  PostStepDoIt 的物理过程
 *  其余的4 个虚类，如 G4VContinuousDiscreteProcess 用于复杂的物理过程
 * ***********************************************************/