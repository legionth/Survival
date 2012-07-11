#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/GameObject.o \
	${OBJECTDIR}/World.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/Ressource.o \
	${OBJECTDIR}/Building.o \
	${OBJECTDIR}/Button.o \
	${OBJECTDIR}/Player.o \
	${OBJECTDIR}/TileMap.o \
	${OBJECTDIR}/BuildingMenu.o \
	${OBJECTDIR}/LivingObject.o \
	${OBJECTDIR}/Game.o \
	${OBJECTDIR}/Menu.o \
	${OBJECTDIR}/ItemMenu.o \
	${OBJECTDIR}/BuildingButton.o \
	${OBJECTDIR}/Enemy.o \
	${OBJECTDIR}/Tile.o \
	${OBJECTDIR}/ItemButton.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../../libs/LaurentGomila-SFML-3c0de3e/lib -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/legionth-survival-normal

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/legionth-survival-normal: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/legionth-survival-normal ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/GameObject.o: GameObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../libs/LaurentGomila-SFML-3c0de3e/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/GameObject.o GameObject.cpp

${OBJECTDIR}/World.o: World.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../libs/LaurentGomila-SFML-3c0de3e/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/World.o World.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../libs/LaurentGomila-SFML-3c0de3e/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/Ressource.o: Ressource.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../libs/LaurentGomila-SFML-3c0de3e/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Ressource.o Ressource.cpp

${OBJECTDIR}/Building.o: Building.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../libs/LaurentGomila-SFML-3c0de3e/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Building.o Building.cpp

${OBJECTDIR}/Button.o: Button.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../libs/LaurentGomila-SFML-3c0de3e/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Button.o Button.cpp

${OBJECTDIR}/Player.o: Player.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../libs/LaurentGomila-SFML-3c0de3e/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Player.o Player.cpp

${OBJECTDIR}/TileMap.o: TileMap.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../libs/LaurentGomila-SFML-3c0de3e/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/TileMap.o TileMap.cpp

${OBJECTDIR}/BuildingMenu.o: BuildingMenu.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../libs/LaurentGomila-SFML-3c0de3e/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/BuildingMenu.o BuildingMenu.cpp

${OBJECTDIR}/LivingObject.o: LivingObject.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../libs/LaurentGomila-SFML-3c0de3e/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/LivingObject.o LivingObject.cpp

${OBJECTDIR}/Game.o: Game.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../libs/LaurentGomila-SFML-3c0de3e/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Game.o Game.cpp

${OBJECTDIR}/Menu.o: Menu.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../libs/LaurentGomila-SFML-3c0de3e/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Menu.o Menu.cpp

${OBJECTDIR}/ItemMenu.o: ItemMenu.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../libs/LaurentGomila-SFML-3c0de3e/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/ItemMenu.o ItemMenu.cpp

${OBJECTDIR}/BuildingButton.o: BuildingButton.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../libs/LaurentGomila-SFML-3c0de3e/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/BuildingButton.o BuildingButton.cpp

${OBJECTDIR}/Enemy.o: Enemy.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../libs/LaurentGomila-SFML-3c0de3e/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Enemy.o Enemy.cpp

${OBJECTDIR}/Tile.o: Tile.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../libs/LaurentGomila-SFML-3c0de3e/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/Tile.o Tile.cpp

${OBJECTDIR}/ItemButton.o: ItemButton.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../libs/LaurentGomila-SFML-3c0de3e/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/ItemButton.o ItemButton.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/legionth-survival-normal

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
