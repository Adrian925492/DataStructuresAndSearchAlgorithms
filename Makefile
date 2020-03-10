CXX = g++
CC = gcc

OUTPUTDIR := Output

OUTPUT := DataStructures

SOURCES:= \
main.cpp \


INCLUDES := \

DEFINES := \


CXX_FLAGS := \
-std=c++11 \
-g \

LDFLAGS := \

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

$(OUTPUTDIR):
	mkdir $@
