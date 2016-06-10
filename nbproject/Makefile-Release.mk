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
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/CAbstractMenuScreen.o \
	${OBJECTDIR}/CBishop.o \
	${OBJECTDIR}/CBoard.o \
	${OBJECTDIR}/CColorMenu.o \
	${OBJECTDIR}/CCommand.o \
	${OBJECTDIR}/CController.o \
	${OBJECTDIR}/CDifficultyMenu.o \
	${OBJECTDIR}/CFilePersistence.o \
	${OBJECTDIR}/CGameSession.o \
	${OBJECTDIR}/CHostJoinMenu.o \
	${OBJECTDIR}/CIntelligence.o \
	${OBJECTDIR}/CKing.o \
	${OBJECTDIR}/CKnight.o \
	${OBJECTDIR}/CLoadGameMenu.o \
	${OBJECTDIR}/CLocalPlayer.o \
	${OBJECTDIR}/CMainMenu.o \
	${OBJECTDIR}/CNetworking.o \
	${OBJECTDIR}/COpponentMenu.o \
	${OBJECTDIR}/CPawn.o \
	${OBJECTDIR}/CPersistence.o \
	${OBJECTDIR}/CPiece.o \
	${OBJECTDIR}/CPlayer.o \
	${OBJECTDIR}/CQueen.o \
	${OBJECTDIR}/CRemotePlayer.o \
	${OBJECTDIR}/CServer.o \
	${OBJECTDIR}/CSlot.o \
	${OBJECTDIR}/CTower.o \
	${OBJECTDIR}/MoveList.o \
	${OBJECTDIR}/MyMove.o \
	${OBJECTDIR}/main.o


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/chess

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/chess: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/chess ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/CAbstractMenuScreen.o: CAbstractMenuScreen.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CAbstractMenuScreen.o CAbstractMenuScreen.cpp

${OBJECTDIR}/CBishop.o: CBishop.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CBishop.o CBishop.cpp

${OBJECTDIR}/CBoard.o: CBoard.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CBoard.o CBoard.cpp

${OBJECTDIR}/CColorMenu.o: CColorMenu.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CColorMenu.o CColorMenu.cpp

${OBJECTDIR}/CCommand.o: CCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CCommand.o CCommand.cpp

${OBJECTDIR}/CController.o: CController.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CController.o CController.cpp

${OBJECTDIR}/CDifficultyMenu.o: CDifficultyMenu.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CDifficultyMenu.o CDifficultyMenu.cpp

${OBJECTDIR}/CFilePersistence.o: CFilePersistence.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CFilePersistence.o CFilePersistence.cpp

${OBJECTDIR}/CGameSession.o: CGameSession.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CGameSession.o CGameSession.cpp

${OBJECTDIR}/CHostJoinMenu.o: CHostJoinMenu.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CHostJoinMenu.o CHostJoinMenu.cpp

${OBJECTDIR}/CIntelligence.o: CIntelligence.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CIntelligence.o CIntelligence.cpp

${OBJECTDIR}/CKing.o: CKing.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CKing.o CKing.cpp

${OBJECTDIR}/CKnight.o: CKnight.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CKnight.o CKnight.cpp

${OBJECTDIR}/CLoadGameMenu.o: CLoadGameMenu.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CLoadGameMenu.o CLoadGameMenu.cpp

${OBJECTDIR}/CLocalPlayer.o: CLocalPlayer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CLocalPlayer.o CLocalPlayer.cpp

${OBJECTDIR}/CMainMenu.o: CMainMenu.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CMainMenu.o CMainMenu.cpp

${OBJECTDIR}/CNetworking.o: CNetworking.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CNetworking.o CNetworking.cpp

${OBJECTDIR}/COpponentMenu.o: COpponentMenu.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/COpponentMenu.o COpponentMenu.cpp

${OBJECTDIR}/CPawn.o: CPawn.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CPawn.o CPawn.cpp

${OBJECTDIR}/CPersistence.o: CPersistence.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CPersistence.o CPersistence.cpp

${OBJECTDIR}/CPiece.o: CPiece.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CPiece.o CPiece.cpp

${OBJECTDIR}/CPlayer.o: CPlayer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CPlayer.o CPlayer.cpp

${OBJECTDIR}/CQueen.o: CQueen.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CQueen.o CQueen.cpp

${OBJECTDIR}/CRemotePlayer.o: CRemotePlayer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CRemotePlayer.o CRemotePlayer.cpp

${OBJECTDIR}/CServer.o: CServer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CServer.o CServer.cpp

${OBJECTDIR}/CSlot.o: CSlot.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CSlot.o CSlot.cpp

${OBJECTDIR}/CTower.o: CTower.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CTower.o CTower.cpp

${OBJECTDIR}/MoveList.o: MoveList.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MoveList.o MoveList.cpp

${OBJECTDIR}/MyMove.o: MyMove.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MyMove.o MyMove.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/chess

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
