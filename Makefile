# ***********************************************
# *** Makefile	-  Problem06 - Sequence Template  *
# ***********************************************

X := cis004_double_ended_queue
CC :=g++
CXXFLAGS := -O3 -std=c++0x -pg -D_DEBUG -g -c -Wall
SRCDIR := src
BUILDDIR := build
BINDIR = bin
TARGET := $(BINDIR)/$(X)

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