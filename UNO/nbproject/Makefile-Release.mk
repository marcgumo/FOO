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
CND_PLATFORM=GNU-Linux
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
	${OBJECTDIR}/h/azar.o \
	${OBJECTDIR}/h/cartas.o \
	${OBJECTDIR}/h/colores.o \
	${OBJECTDIR}/h/jugadores.o \
	${OBJECTDIR}/h/partida.o \
	${OBJECTDIR}/h/preguntas.o \
	${OBJECTDIR}/h/uno.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/uno

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/uno: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/uno ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/h/azar.o: h/azar.c
	${MKDIR} -p ${OBJECTDIR}/h
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/h/azar.o h/azar.c

${OBJECTDIR}/h/cartas.o: h/cartas.c
	${MKDIR} -p ${OBJECTDIR}/h
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/h/cartas.o h/cartas.c

${OBJECTDIR}/h/colores.o: h/colores.c
	${MKDIR} -p ${OBJECTDIR}/h
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/h/colores.o h/colores.c

${OBJECTDIR}/h/jugadores.o: h/jugadores.c
	${MKDIR} -p ${OBJECTDIR}/h
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/h/jugadores.o h/jugadores.c

${OBJECTDIR}/h/partida.o: h/partida.c
	${MKDIR} -p ${OBJECTDIR}/h
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/h/partida.o h/partida.c

${OBJECTDIR}/h/preguntas.o: h/preguntas.c
	${MKDIR} -p ${OBJECTDIR}/h
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/h/preguntas.o h/preguntas.c

${OBJECTDIR}/h/uno.o: h/uno.c
	${MKDIR} -p ${OBJECTDIR}/h
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/h/uno.o h/uno.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
