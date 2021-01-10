/************************************************************************************************
 * FileName: 3_MacroCommands
 * Author: 刘铭
 * Describes: 
 * Create: Jan 10 2021, 12:50
 * Last Modify: 
 * Modifications: 0
 * *********************************************************************************************/

/**********************************************************************************
 * G4GeneralParticleSource可以通过在/gps命令目录树中键入命令或将/gps命令包括在g4macro文件中进行配置。
 * *******************************************************************************/

/***********************************************************************************
 * G4ParticleGun等效命令
 * 
 * 命令             参数         说明
 * /gps/List                    List available incident particles
 * /gps/particle    name        Defines the particle type [default geantino], using GEANT4 naming convention.
 * /gps/energy      E unit      Sets the energy [default 1 MeV] for mono-energetic sources. The units can be eV, keV, MeV, GeV, TeV or PeV. (NB: it is recommended to use /gps/ene/mono instead.)
 * /gps/position    X Y Z unit  Sets the centre co-ordinates (X,Y,Z) of the source [default (0,0,0) cm].The units can be micron, mm, cm, m or km. (NB: it is recommended to use /gps/pos/centre instead.)
 * /gps/ion         Z A Q E     After /gps/particle ion, sets the properties (atomic number Z, atomic mass A, ionic charge Q, excitation energy E in keV) of the ion.
 * /gps/ionLvl      Z A Q lvl   After /gps/particle ion, sets the properties (atomic number Z, atomic mass A, ionic charge Q, Number of metastable state excitation level (0-9) of the ion.
 * /gps/time        t0 unit     Sets the primary particle (event) time [default 0 ns]. The units can be ps, ns, us, ms, or s.
 * /gps/polarization Px Py Pz   Sets the polarization vector of the source, which does not need to be a unit vector.
 * /gps/number      N           Sets the number of particles [default 1] to simulate on each event.
 * /gps/verbose     level       Control the amount of information printed out by the GPS code. Larger values produce more detailed output.
 * ********************************************************************************/

/***********************************************************************************
 * 多源命令
 * 
 * 命令             参数            说明
 * /gps/source/add  intensity       添加具有指定强度的新粒子源
 * /gps/source/list                 List the particle sources defined.
 * /gps/source/clear                Remove all defined particle sources.
 * /gps/source/show                 Display the current particle source
 * /gps/source/set  index           Select the specified particle source as the current one.
 * /gps/source/delete index         Remove the specified particle source.
 * /gps/source/ multiplevertex flag  Specify true for simultaneous generation of multiple vertices, one from each specified source. False [default] generates a single vertex, choosing one source randomly.
 * /gps/source/ intensity intensity Reset the current source to the specified intensity
 * /gps/source/ flatsampling flag   Set to True to allow biased sampling among the sources. Setting to True will ignore source intensities. The default is False.
 * ********************************************************************************/

/***********************************************************************************
 * 源位置和结构
 * 命令             参数            说明
 * /gps/pos/type    dist            Sets the source positional distribution type: Point [default], Plane, Beam, Surface, Volume.
 * /gps/pos/shape   shape           Sets the source shape type, after /gps/pos/type has been used. For a Plane this can be Circle, Annulus, Ellipse, Square, Rectangle. For both Surface or Volume sources this can be Sphere, Ellipsoid, Cylinder, Para (parallelepiped).
 * /gps/pos/centre  X Y Z unit      Sets the centre co-ordinates (X,Y,Z) of the source [default (0,0,0) cm]. The units can only be micron, mm, cm, m or km.
 * /gps/pos/rot1    R1x R1y R1z     Defines the first (x’ direction) vector R1 [default (1,0,0)], which does not need to be a unit vector, and is used together with /gps/pos/ rot2 to create the rotation matrix of the shape defined with /gps/shape.
 * ********************************************************************************/

/**********************************************************************************
 * 命令太多了，具体查看https://geant4-userdoc.web.cern.ch/UsersGuides/ForApplicationDeveloper/html/GettingStarted/generalParticleSource.html#introduction
 * *******************************************************************************/