# Toolchain paths and names:

CXX = g++
CC = gcc


#Output directory name
OUTPUTDIR := Output

#Output filename
OUTPUT := DataStructures

#Source list
SOURCES:= \
main.cpp \

#Include list
INCLUDES := \

#Global defines
DEFINES := \

#Compiler settings
CXX_FLAGS := \
-std=c++11 \
-g \

#Linker settings
LDFLAGS := \

################################################################################################################
OBJFILES = $(addprefix $(OUTPUTDIR)/, $(notdir $(SOURCES:.cpp=.o)))
TARGET = $(OUTPUTDIR)/$(OUTPUT).exe


all: $(OUTPUTDIR) $(TARGET)

$(TARGET): $(OBJFILES)
	$(CXX) $(OBJFILES) $(LDFLAGS) -o $@

$(OUTPUTDIR)/%.o: %.cpp
	$(CXX) $(CXX_FLAGS) -c $(DEFINES) $(INCLUDES) $^ -o $@

clean:
ifneq ($(wildcard $(OUTPUTDIR)/.*),)
	rmdir $(subst /, \\, $(OUTPUTDIR)) /s /q
endif

run:
	$(TARGET)

$(OUTPUTDIR):
	mkdir $@
