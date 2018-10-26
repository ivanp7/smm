LIB_NAME = libsmm
TOOL_NAME = smmt

IDIR = .
ODIR = .

AR       = ar
AR_FLAGS = rcs
CC     = gcc
CFLAGS = -I$(IDIR) -Wall
LIBS   = 

GGO    = gengetopt
CMDLINEARGS_FILE_PREFIX = smmt_cmdline

_DEPS = $(CMDLINEARGS_FILE_PREFIX).ggo.h libsmm.h smmt.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = $(CMDLINEARGS_FILE_PREFIX).ggo.o libsmm.o smmt.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

.PHONY: all
all: $(LIB_NAME).a $(TOOL_NAME)

$(LIB_NAME).a: $(LIB_NAME).o
	$(AR) $(AR_FLAGS) $@ $^

$(TOOL_NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(CMDLINEARGS_FILE_PREFIX).ggo.c: $(CMDLINEARGS_FILE_PREFIX).ggo
	$(GGO) --include-getopt --input=$< --file-name=$(CMDLINEARGS_FILE_PREFIX).ggo

.PHONY: clean clean-all
clean:
	rm -f $(ODIR)/*.o $(CMDLINEARGS_FILE_PREFIX).ggo.*

clean-all: clean
	rm -f $(LIB_NAME).a $(TOOL_NAME)

