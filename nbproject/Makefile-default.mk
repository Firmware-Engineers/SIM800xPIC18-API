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
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/SIM800x.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/SIM800x.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=Src/ApplicationExample.c Src/main.c C:/EmbeddedDevOps/M8M_APIs/PIC18.X/Src/FUSE_CONFIG.c C:/EmbeddedDevOps/M8M_APIs/PIC18.X/Src/ISR.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/Src/ApplicationExample.p1 ${OBJECTDIR}/Src/main.p1 ${OBJECTDIR}/_ext/1712581837/FUSE_CONFIG.p1 ${OBJECTDIR}/_ext/1712581837/ISR.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/Src/ApplicationExample.p1.d ${OBJECTDIR}/Src/main.p1.d ${OBJECTDIR}/_ext/1712581837/FUSE_CONFIG.p1.d ${OBJECTDIR}/_ext/1712581837/ISR.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/Src/ApplicationExample.p1 ${OBJECTDIR}/Src/main.p1 ${OBJECTDIR}/_ext/1712581837/FUSE_CONFIG.p1 ${OBJECTDIR}/_ext/1712581837/ISR.p1

# Source Files
SOURCEFILES=Src/ApplicationExample.c Src/main.c C:/EmbeddedDevOps/M8M_APIs/PIC18.X/Src/FUSE_CONFIG.c C:/EmbeddedDevOps/M8M_APIs/PIC18.X/Src/ISR.c



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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/SIM800x.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F452
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/Src/ApplicationExample.p1: Src/ApplicationExample.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Src" 
	@${RM} ${OBJECTDIR}/Src/ApplicationExample.p1.d 
	@${RM} ${OBJECTDIR}/Src/ApplicationExample.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -O1 -fasmfile -maddrqual=ignore -DFOSC_MHZ=16 -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Src/ApplicationExample.p1 Src/ApplicationExample.c 
	@-${MV} ${OBJECTDIR}/Src/ApplicationExample.d ${OBJECTDIR}/Src/ApplicationExample.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Src/ApplicationExample.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Src/main.p1: Src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Src" 
	@${RM} ${OBJECTDIR}/Src/main.p1.d 
	@${RM} ${OBJECTDIR}/Src/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -O1 -fasmfile -maddrqual=ignore -DFOSC_MHZ=16 -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Src/main.p1 Src/main.c 
	@-${MV} ${OBJECTDIR}/Src/main.d ${OBJECTDIR}/Src/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Src/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1712581837/FUSE_CONFIG.p1: C\:/EmbeddedDevOps/M8M_APIs/PIC18.X/Src/FUSE_CONFIG.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1712581837" 
	@${RM} ${OBJECTDIR}/_ext/1712581837/FUSE_CONFIG.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1712581837/FUSE_CONFIG.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -O1 -fasmfile -maddrqual=ignore -DFOSC_MHZ=16 -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1712581837/FUSE_CONFIG.p1 C:/EmbeddedDevOps/M8M_APIs/PIC18.X/Src/FUSE_CONFIG.c 
	@-${MV} ${OBJECTDIR}/_ext/1712581837/FUSE_CONFIG.d ${OBJECTDIR}/_ext/1712581837/FUSE_CONFIG.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1712581837/FUSE_CONFIG.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1712581837/ISR.p1: C\:/EmbeddedDevOps/M8M_APIs/PIC18.X/Src/ISR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1712581837" 
	@${RM} ${OBJECTDIR}/_ext/1712581837/ISR.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1712581837/ISR.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1    -fno-short-double -fno-short-float -memi=wordwrite -O1 -fasmfile -maddrqual=ignore -DFOSC_MHZ=16 -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1712581837/ISR.p1 C:/EmbeddedDevOps/M8M_APIs/PIC18.X/Src/ISR.c 
	@-${MV} ${OBJECTDIR}/_ext/1712581837/ISR.d ${OBJECTDIR}/_ext/1712581837/ISR.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1712581837/ISR.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/Src/ApplicationExample.p1: Src/ApplicationExample.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Src" 
	@${RM} ${OBJECTDIR}/Src/ApplicationExample.p1.d 
	@${RM} ${OBJECTDIR}/Src/ApplicationExample.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -O1 -fasmfile -maddrqual=ignore -DFOSC_MHZ=16 -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Src/ApplicationExample.p1 Src/ApplicationExample.c 
	@-${MV} ${OBJECTDIR}/Src/ApplicationExample.d ${OBJECTDIR}/Src/ApplicationExample.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Src/ApplicationExample.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Src/main.p1: Src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Src" 
	@${RM} ${OBJECTDIR}/Src/main.p1.d 
	@${RM} ${OBJECTDIR}/Src/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -O1 -fasmfile -maddrqual=ignore -DFOSC_MHZ=16 -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Src/main.p1 Src/main.c 
	@-${MV} ${OBJECTDIR}/Src/main.d ${OBJECTDIR}/Src/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Src/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1712581837/FUSE_CONFIG.p1: C\:/EmbeddedDevOps/M8M_APIs/PIC18.X/Src/FUSE_CONFIG.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1712581837" 
	@${RM} ${OBJECTDIR}/_ext/1712581837/FUSE_CONFIG.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1712581837/FUSE_CONFIG.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -O1 -fasmfile -maddrqual=ignore -DFOSC_MHZ=16 -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1712581837/FUSE_CONFIG.p1 C:/EmbeddedDevOps/M8M_APIs/PIC18.X/Src/FUSE_CONFIG.c 
	@-${MV} ${OBJECTDIR}/_ext/1712581837/FUSE_CONFIG.d ${OBJECTDIR}/_ext/1712581837/FUSE_CONFIG.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1712581837/FUSE_CONFIG.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1712581837/ISR.p1: C\:/EmbeddedDevOps/M8M_APIs/PIC18.X/Src/ISR.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1712581837" 
	@${RM} ${OBJECTDIR}/_ext/1712581837/ISR.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1712581837/ISR.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c    -fno-short-double -fno-short-float -memi=wordwrite -O1 -fasmfile -maddrqual=ignore -DFOSC_MHZ=16 -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/_ext/1712581837/ISR.p1 C:/EmbeddedDevOps/M8M_APIs/PIC18.X/Src/ISR.c 
	@-${MV} ${OBJECTDIR}/_ext/1712581837/ISR.d ${OBJECTDIR}/_ext/1712581837/ISR.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1712581837/ISR.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/SIM800x.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  Libs/LightJSONParser.X.a C:/EmbeddedDevOps/M8M_APIs/PIC18.X/Lib/SUART-16-9600-B0-B3.a C:/EmbeddedDevOps/M8M_APIs/PIC18.X/Lib/SystemTime.X.a Libs/SIM800x.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/SIM800x.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1    -fno-short-double -fno-short-float -memi=wordwrite -O1 -fasmfile -maddrqual=ignore -DFOSC_MHZ=16 -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     -mrom=default,-7dc0-7fff -mram=default,-5f4-5ff,-f9c-f9c,-fd4-fd4,-fdb-fdf,-fe3-fe7,-feb-fef,-ffd-fff  $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/SIM800x.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    Libs\LightJSONParser.X.a C:\EmbeddedDevOps\M8M_APIs\PIC18.X\Lib\SUART-16-9600-B0-B3.a C:\EmbeddedDevOps\M8M_APIs\PIC18.X\Lib\SystemTime.X.a Libs\SIM800x.a 
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/SIM800x.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/SIM800x.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  Libs/LightJSONParser.X.a C:/EmbeddedDevOps/M8M_APIs/PIC18.X/Lib/SUART-16-9600-B0-B3.a C:/EmbeddedDevOps/M8M_APIs/PIC18.X/Lib/SystemTime.X.a Libs/SIM800x.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/SIM800x.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1    -fno-short-double -fno-short-float -memi=wordwrite -O1 -fasmfile -maddrqual=ignore -DFOSC_MHZ=16 -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx032 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c90 -gdwarf-3 -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/SIM800x.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    Libs\LightJSONParser.X.a C:\EmbeddedDevOps\M8M_APIs\PIC18.X\Lib\SUART-16-9600-B0-B3.a C:\EmbeddedDevOps\M8M_APIs\PIC18.X\Lib\SystemTime.X.a Libs\SIM800x.a 
	
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
