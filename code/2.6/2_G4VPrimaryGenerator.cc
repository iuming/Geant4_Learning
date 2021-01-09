/**************************************************************************************
 * FileName: 2_G4VPrimaryGenerator
 * Author: 刘铭
 * Describes:
 * Create: Jan 9 2021, 14:00
 * Last Modify:
 * Modifications: 0
 * ***********************************************************************************/

/******************************************************
 * Geant4提供了三个G4VPrimaryGenerator具体的类。其中G4ParticleGun，G4GeneralParticleSource将在这里讨论。第三个是G4HEPEvtInterface，将在事件生成器接口中讨论。
 * ***************************************************/

/**************************************************************************
 * G4ParticleGun
 * G4ParticleGun是Geant4提供的粒子产生器。此类生成具有给定动量和位置的一次粒子。它不提供任何形式的随机化。构造函数 G4ParticleGun采用一个整数，该整数会导致生成一个或多个完全相同的运动学基元。用户需求相当频繁，以产生具有随机能量，动量和位置的原边。这种随机化可以通过调用所提供的各种设置方法来实现G4ParticleGun。这些方法的调用，应在执行generatePrimaries()您的具体的方法G4VUserPrimaryGeneratorAction类调用之前 generatePrimaryVertex()的G4ParticleGun。Geant4提供了具有各种分布的各种随机数生成方法。
 * ***********************************************************************/

/*************************************************************************
 * G4ParticleGun的公共函数
 * G4ParticleGun提供了以下方法，并且可以从generatePrimaries()的具体G4VUserPrimaryGeneratorAction类中的方法中调用所有这些方法 ：
 *      void SetParticleDefinition(G4ParticleDefinition*)
 *      void SetParticleMomentum(G4ParticleMomentum)
 *      void SetParticleMomentumDirection(G4ThreeVector)
 *      void SetParticleEnergy(G4double)
 *      void SetParticleTime(G4double)
 *      void SetParticlePosition(G4ThreeVector)
 *      void SetParticlePolarization(G4ThreeVector)
 *      void SetNumberOfParticles(G4int)
 ************************************************************************/

/************************************************************************
 * G4GeneralParticleSource
 * 对于许多应用而言G4ParticleGun是合适的粒子发生器。但是，如果你想生成更复杂的方式初级粒子，可以利用G4GeneralParticleSource的 GEANT4一般粒子源模块（GPS）。
 * *********************************************************************/