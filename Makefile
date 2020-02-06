#########################################################
################		Makefile		 ################
#########################################################
###########				 MACROS				  ###########
#########################################################
# $(1) : Compiler
# $(2) : Object file to generate
# $(3) : Source file
# $(4) : Additional dependencies
# $(5) : Compiler flags
define COMPILE
$(2) : $(3) $(4)
	$(1) -c -o $(2) $(3) $(5)
endef

# $(1) : Source file
define C2O
$(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(patsubst $(SRC)%,$(OBJ)%,$(1))))
endef

# $(1) : Source file
define C2H
$(patsubst %.c,%.h,$(patsubst %.cpp,%.hpp,$(1)))
endef

# $(1) : The message to print
define PRINT
$(info [$(APP)] $(1))
endef
#########################################################
###########				 CONFIG				  ###########
#########################################################
APP			:= Vincula
CFLAGS		:= -Wall -pedantic
CCFLAGS 	:= $(CCFLAGS) -std=c++17 -ffast-math
CC			:= g++ 
C 			:= gcc
MKDIR		:= mkdir -p
SRC 		:= src
OBJ 		:= obj
LIBDIR		:= lib



#LOWLEVEL_LIB = ./lib/libfmod.so
#STUDIO_LIB = ./lib/libfmodstudio.so
#LIBSFMOD 	:= -Wl,-rpath=\$$ORIGIN/$(dir ./$(LIBDIR)/fmod/lib/libfmod.so),-rpath=\$$ORIGIN/$(dir ./$(LIBDIR)/fmod/lib/libfmodstudio.so) ./$(LIBDIR)/fmod/lib/libfmod.so ./$(LIBDIR)/fmod/lib/libfmodstudio.so
#LIBSFMOD 	:= -Wl,-rpath=./$(LIBDIR)/fmod/lib/libfmod.so,-rpath=./$(LIBDIR)/fmod/lib/libfmodstudio.so ./$(LIBDIR)/fmod/lib/libfmod.so ./$(LIBDIR)/fmod/lib/libfmodstudio.so

#LIBS   := $(LIBDIR)/irrlicht/libIrrlicht.a -L./$(LIBDIR)/irrlicht -lIrrlicht -L/usr/X11R6/lib -lGL -lXxf86vm -lXext -lX11 -lXcursor 
#INCDIR		:= -I$(SRC) -I$(LIBDIR) -I$(LIBDIR)/irrlicht/include -I$(LIBDIR)/fmod/inc


ifdef CACHE
	CC := ccache $(CC)
endif

ifdef RELEASE
	CCFLAGS += -O3
else
	CCFLAGS += -g
endif






ALLCPPS		:= $(shell find src/ -type f -iname *.cpp)
ALLCS 		:= $(shell find src/ -type f -iname *.c)
ALLOBJ		:= $(foreach F,$(ALLCPPS) $(ALLCS),$(call C2O,$(F)))
SUBIDRS		:= $(shell find $(SRC) -type d)
OBJSUBDIRS	:= $(patsubst $(SRC)%,$(OBJ)%,$(SUBIDRS))


$(APP): $(OBJSUBDIRS) $(ALLOBJ)
	$(call PRINT,Compiling executable file)
	$(CC) -o $(APP) $(ALLOBJ) $(LIBS) $(LIBSFMOD)

#Generate rules for all objects
$(foreach F, $(ALLCPPS),$(eval $(call COMPILE,$(CC),$(call C2O,$(F)),$(F),$(call C2H,$(F)),$(CCFLAGS) $(INCDIR))))
$(foreach F, $(ALLCS),$(eval $(call COMPILE,$(C),$(call C2O,$(F)),$(F),$(call C2H,$(F)),$(CFLAGS) $(INCDIR))))

$(OBJSUBDIRS): 
	$(MKDIR) $(OBJSUBDIRS)

.PHONY: info clean cleanall all

info:
	$(info $(SUBIDRS))
	$(info $(OBJSUBDIRS))
	$(info $(ALLCPPS))
	$(info $(ALLCS))
	$(info $(ALLOBJ))
	
clean:
	@if [ -d $(OBJ) ]; then \
	rm -r "./$(OBJ)" \
	; fi
	$(call PRINT,Removing .o files)

cleanall: clean
	@if [ -f $(APP) ]; then \
	rm "./$(APP)" \
	; fi
	$(call PRINT,Removing executable file)

all: cleanall
	make

