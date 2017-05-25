# *************************************************
# *** Makefile	-  Problem06 - CIS004B HashTable  *
# *************************************************

EXECUTABLE := cis004b_assignment06_hashtable
CC :=g++
CXXFLAGS := -O3 -std=c++0x -pg -D_DEBUG -g -c -Wall
SRCDIR := src
BUILDDIR := build
BINDIR = bin
TARGET := $(BINDIR)/$(EXECUTABLE)

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%, $(BUILDDIR)/%, $(SOURCES:.$(SRCEXT)=.o))
INC := -I include


$(BUILDDIR)/%.o : $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CXXFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CXXFLAGS) $(INC) $< -o $@

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@mkdir -p $(BINDIR)
	@echo " $(CC) $^ -o $(TARGET)"; $(CC) $^ -o $(TARGET)
	@echo "\nCASH RULES EVERYTHING AROUND ME CREAMIN' 💵"


clean:
	@echo "Cleaning...";
	$(shell echo rm -rf bin build src/*.o)