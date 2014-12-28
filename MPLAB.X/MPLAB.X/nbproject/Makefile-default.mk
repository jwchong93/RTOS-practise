#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../../src/PIC18/Clock.c ../../src/PIC18/Interrupt.c ../../src/PIC18/LEDSM.c ../../src/PIC18/Led2.c ../../src/PIC18/LoopBack.c ../../src/PIC18/PreemptiveOS.c ../../src/PIC18/PriorityLinkedList.c ../../src/PIC18/SevenSeg.c ../../src/PIC18/TCB.c ../../src/PIC18/UartLoopBack.c ../../src/PIC18/blinky.c ../../src/PIC18/main.c ../../src/PIC18/mutex.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/681521030/Clock.o ${OBJECTDIR}/_ext/681521030/Interrupt.o ${OBJECTDIR}/_ext/681521030/LEDSM.o ${OBJECTDIR}/_ext/681521030/Led2.o ${OBJECTDIR}/_ext/681521030/LoopBack.o ${OBJECTDIR}/_ext/681521030/PreemptiveOS.o ${OBJECTDIR}/_ext/681521030/PriorityLinkedList.o ${OBJECTDIR}/_ext/681521030/SevenSeg.o ${OBJECTDIR}/_ext/681521030/TCB.o ${OBJECTDIR}/_ext/681521030/UartLoopBack.o ${OBJECTDIR}/_ext/681521030/blinky.o ${OBJECTDIR}/_ext/681521030/main.o ${OBJECTDIR}/_ext/681521030/mutex.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/681521030/Clock.o.d ${OBJECTDIR}/_ext/681521030/Interrupt.o.d ${OBJECTDIR}/_ext/681521030/LEDSM.o.d ${OBJECTDIR}/_ext/681521030/Led2.o.d ${OBJECTDIR}/_ext/681521030/LoopBack.o.d ${OBJECTDIR}/_ext/681521030/PreemptiveOS.o.d ${OBJECTDIR}/_ext/681521030/PriorityLinkedList.o.d ${OBJECTDIR}/_ext/681521030/SevenSeg.o.d ${OBJECTDIR}/_ext/681521030/TCB.o.d ${OBJECTDIR}/_ext/681521030/UartLoopBack.o.d ${OBJECTDIR}/_ext/681521030/blinky.o.d ${OBJECTDIR}/_ext/681521030/main.o.d ${OBJECTDIR}/_ext/681521030/mutex.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/681521030/Clock.o ${OBJECTDIR}/_ext/681521030/Interrupt.o ${OBJECTDIR}/_ext/681521030/LEDSM.o ${OBJECTDIR}/_ext/681521030/Led2.o ${OBJECTDIR}/_ext/681521030/LoopBack.o ${OBJECTDIR}/_ext/681521030/PreemptiveOS.o ${OBJECTDIR}/_ext/681521030/PriorityLinkedList.o ${OBJECTDIR}/_ext/681521030/SevenSeg.o ${OBJECTDIR}/_ext/681521030/TCB.o ${OBJECTDIR}/_ext/681521030/UartLoopBack.o ${OBJECTDIR}/_ext/681521030/blinky.o ${OBJECTDIR}/_ext/681521030/main.o ${OBJECTDIR}/_ext/681521030/mutex.o

# Source Files
SOURCEFILES=../../src/PIC18/Clock.c ../../src/PIC18/Interrupt.c ../../src/PIC18/LEDSM.c ../../src/PIC18/Led2.c ../../src/PIC18/LoopBack.c ../../src/PIC18/PreemptiveOS.c ../../src/PIC18/PriorityLinkedList.c ../../src/PIC18/SevenSeg.c ../../src/PIC18/TCB.c ../../src/PIC18/UartLoopBack.c ../../src/PIC18/blinky.c ../../src/PIC18/main.c ../../src/PIC18/mutex.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4520
MP_PROCESSOR_OPTION_LD=18f4520
MP_LINKER_DEBUG_OPTION=  -u_DEBUGSTACK
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/681521030/Clock.o: ../../src/PIC18/Clock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/681521030 
	@${RM} ${OBJECTDIR}/_ext/681521030/Clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/681521030/Clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/681521030/Clock.o   ../../src/PIC18/Clock.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/681521030/Clock.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/681521030/Clock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/681521030/Interrupt.o: ../../src/PIC18/Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/681521030 
	@${RM} ${OBJECTDIR}/_ext/681521030/Interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/681521030/Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/681521030/Interrupt.o   ../../src/PIC18/Interrupt.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/681521030/Interrupt.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/681521030/Interrupt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/681521030/LEDSM.o: ../../src/PIC18/LEDSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/681521030 
	@${RM} ${OBJECTDIR}/_ext/681521030/LEDSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/681521030/LEDSM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/681521030/LEDSM.o   ../../src/PIC18/LEDSM.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/681521030/LEDSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/681521030/LEDSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/681521030/Led2.o: ../../src/PIC18/Led2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/681521030 
	@${RM} ${OBJECTDIR}/_ext/681521030/Led2.o.d 
	@${RM} ${OBJECTDIR}/_ext/681521030/Led2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/681521030/Led2.o   ../../src/PIC18/Led2.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/681521030/Led2.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/681521030/Led2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/681521030/LoopBack.o: ../../src/PIC18/LoopBack.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/681521030 
	@${RM} ${OBJECTDIR}/_ext/681521030/LoopBack.o.d 
	@${RM} ${OBJECTDIR}/_ext/681521030/LoopBack.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/681521030/LoopBack.o   ../../src/PIC18/LoopBack.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/681521030/LoopBack.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/681521030/LoopBack.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/681521030/PreemptiveOS.o: ../../src/PIC18/PreemptiveOS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/681521030 
	@${RM} ${OBJECTDIR}/_ext/681521030/PreemptiveOS.o.d 
	@${RM} ${OBJECTDIR}/_ext/681521030/PreemptiveOS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/681521030/PreemptiveOS.o   ../../src/PIC18/PreemptiveOS.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/681521030/PreemptiveOS.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/681521030/PreemptiveOS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/681521030/PriorityLinkedList.o: ../../src/PIC18/PriorityLinkedList.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/681521030 
	@${RM} ${OBJECTDIR}/_ext/681521030/PriorityLinkedList.o.d 
	@${RM} ${OBJECTDIR}/_ext/681521030/PriorityLinkedList.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/681521030/PriorityLinkedList.o   ../../src/PIC18/PriorityLinkedList.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/681521030/PriorityLinkedList.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/681521030/PriorityLinkedList.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/681521030/SevenSeg.o: ../../src/PIC18/SevenSeg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/681521030 
	@${RM} ${OBJECTDIR}/_ext/681521030/SevenSeg.o.d 
	@${RM} ${OBJECTDIR}/_ext/681521030/SevenSeg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/681521030/SevenSeg.o   ../../src/PIC18/SevenSeg.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/681521030/SevenSeg.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/681521030/SevenSeg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/681521030/TCB.o: ../../src/PIC18/TCB.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/681521030 
	@${RM} ${OBJECTDIR}/_ext/681521030/TCB.o.d 
	@${RM} ${OBJECTDIR}/_ext/681521030/TCB.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/681521030/TCB.o   ../../src/PIC18/TCB.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/681521030/TCB.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/681521030/TCB.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/681521030/UartLoopBack.o: ../../src/PIC18/UartLoopBack.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/681521030 
	@${RM} ${OBJECTDIR}/_ext/681521030/UartLoopBack.o.d 
	@${RM} ${OBJECTDIR}/_ext/681521030/UartLoopBack.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/681521030/UartLoopBack.o   ../../src/PIC18/UartLoopBack.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/681521030/UartLoopBack.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/681521030/UartLoopBack.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/681521030/blinky.o: ../../src/PIC18/blinky.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/681521030 
	@${RM} ${OBJECTDIR}/_ext/681521030/blinky.o.d 
	@${RM} ${OBJECTDIR}/_ext/681521030/blinky.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/681521030/blinky.o   ../../src/PIC18/blinky.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/681521030/blinky.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/681521030/blinky.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/681521030/main.o: ../../src/PIC18/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/681521030 
	@${RM} ${OBJECTDIR}/_ext/681521030/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/681521030/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/681521030/main.o   ../../src/PIC18/main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/681521030/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/681521030/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/681521030/mutex.o: ../../src/PIC18/mutex.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/681521030 
	@${RM} ${OBJECTDIR}/_ext/681521030/mutex.o.d 
	@${RM} ${OBJECTDIR}/_ext/681521030/mutex.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG  -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/681521030/mutex.o   ../../src/PIC18/mutex.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/681521030/mutex.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/681521030/mutex.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/_ext/681521030/Clock.o: ../../src/PIC18/Clock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/681521030 
	@${RM} ${OBJECTDIR}/_ext/681521030/Clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/681521030/Clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/681521030/Clock.o   ../../src/PIC18/Clock.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/681521030/Clock.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/681521030/Clock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/681521030/Interrupt.o: ../../src/PIC18/Interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/681521030 
	@${RM} ${OBJECTDIR}/_ext/681521030/Interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/681521030/Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/681521030/Interrupt.o   ../../src/PIC18/Interrupt.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/681521030/Interrupt.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/681521030/Interrupt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/681521030/LEDSM.o: ../../src/PIC18/LEDSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/681521030 
	@${RM} ${OBJECTDIR}/_ext/681521030/LEDSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/681521030/LEDSM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/681521030/LEDSM.o   ../../src/PIC18/LEDSM.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/681521030/LEDSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/681521030/LEDSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/681521030/Led2.o: ../../src/PIC18/Led2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/681521030 
	@${RM} ${OBJECTDIR}/_ext/681521030/Led2.o.d 
	@${RM} ${OBJECTDIR}/_ext/681521030/Led2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/681521030/Led2.o   ../../src/PIC18/Led2.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/681521030/Led2.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/681521030/Led2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/681521030/LoopBack.o: ../../src/PIC18/LoopBack.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/681521030 
	@${RM} ${OBJECTDIR}/_ext/681521030/LoopBack.o.d 
	@${RM} ${OBJECTDIR}/_ext/681521030/LoopBack.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/681521030/LoopBack.o   ../../src/PIC18/LoopBack.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/681521030/LoopBack.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/681521030/LoopBack.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/681521030/PreemptiveOS.o: ../../src/PIC18/PreemptiveOS.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/681521030 
	@${RM} ${OBJECTDIR}/_ext/681521030/PreemptiveOS.o.d 
	@${RM} ${OBJECTDIR}/_ext/681521030/PreemptiveOS.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/681521030/PreemptiveOS.o   ../../src/PIC18/PreemptiveOS.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/681521030/PreemptiveOS.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/681521030/PreemptiveOS.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/681521030/PriorityLinkedList.o: ../../src/PIC18/PriorityLinkedList.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/681521030 
	@${RM} ${OBJECTDIR}/_ext/681521030/PriorityLinkedList.o.d 
	@${RM} ${OBJECTDIR}/_ext/681521030/PriorityLinkedList.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/681521030/PriorityLinkedList.o   ../../src/PIC18/PriorityLinkedList.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/681521030/PriorityLinkedList.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/681521030/PriorityLinkedList.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/681521030/SevenSeg.o: ../../src/PIC18/SevenSeg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/681521030 
	@${RM} ${OBJECTDIR}/_ext/681521030/SevenSeg.o.d 
	@${RM} ${OBJECTDIR}/_ext/681521030/SevenSeg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/681521030/SevenSeg.o   ../../src/PIC18/SevenSeg.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/681521030/SevenSeg.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/681521030/SevenSeg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/681521030/TCB.o: ../../src/PIC18/TCB.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/681521030 
	@${RM} ${OBJECTDIR}/_ext/681521030/TCB.o.d 
	@${RM} ${OBJECTDIR}/_ext/681521030/TCB.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/681521030/TCB.o   ../../src/PIC18/TCB.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/681521030/TCB.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/681521030/TCB.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/681521030/UartLoopBack.o: ../../src/PIC18/UartLoopBack.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/681521030 
	@${RM} ${OBJECTDIR}/_ext/681521030/UartLoopBack.o.d 
	@${RM} ${OBJECTDIR}/_ext/681521030/UartLoopBack.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/681521030/UartLoopBack.o   ../../src/PIC18/UartLoopBack.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/681521030/UartLoopBack.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/681521030/UartLoopBack.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/681521030/blinky.o: ../../src/PIC18/blinky.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/681521030 
	@${RM} ${OBJECTDIR}/_ext/681521030/blinky.o.d 
	@${RM} ${OBJECTDIR}/_ext/681521030/blinky.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/681521030/blinky.o   ../../src/PIC18/blinky.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/681521030/blinky.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/681521030/blinky.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/681521030/main.o: ../../src/PIC18/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/681521030 
	@${RM} ${OBJECTDIR}/_ext/681521030/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/681521030/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/681521030/main.o   ../../src/PIC18/main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/681521030/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/681521030/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/681521030/mutex.o: ../../src/PIC18/mutex.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/681521030 
	@${RM} ${OBJECTDIR}/_ext/681521030/mutex.o.d 
	@${RM} ${OBJECTDIR}/_ext/681521030/mutex.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/681521030/mutex.o   ../../src/PIC18/mutex.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/681521030/mutex.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/681521030/mutex.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../../src/PIC18/LKR/18f4520_g.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "..\..\src\PIC18\LKR\18f4520_g.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../../src/PIC18/LKR/18f4520_g.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "..\..\src\PIC18\LKR\18f4520_g.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
