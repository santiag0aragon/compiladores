## 
## Simple makefile for decaf programming projects
##


.PHONY: clean strip

# Set the default target. When you make with no arguments,
# this will be the target built.
COMPILER = dcc
PREPROCESSOR = dpp
PRODUCTS = $(COMPILER) $(PREPROCESSOR)
default: $(PRODUCTS)

# Set up the list of source and object files
SRCS = errors.cc utility.cc main.cc \
	

# OBJS can deal with either .cc or .c files listed in SRCS
OBJS = lex.yy.o $(patsubst %.cc, %.o, $(filter %.cc,$(SRCS))) $(patsubst %.c, %.o, $(filter %.c, $(SRCS)))

JUNK =  *.o lex.yy.c dpp.yy.c y.tab.c y.tab.h *.core core $(COMPILER).purify purify.log 

# Define the tools we are going to use
CC= g++
LD = g++
LEX = flex
YACC = bison

# Set up the necessary flags for the tools

# We want debugging and most warnings, but lex/yacc generate some
# static symbols we don't use, so turn off unused warnings to avoid clutter
# Also STL has some signed/unsigned comparisons we want to suppress
CFLAGS = -g -Wall -Wno-unused -Wno-sign-compare

# The -d flag tells lex to set up for debugging. Can turn on/off by
# setting value of global yy_flex_debug inside the scanner itself
LEXFLAGS = -d

# The -d flag tells yacc to generate header with token types
# The -v flag writes out a verbose description of the states and conflicts
# The -t flag turns on debugging capability
# The -y flag means imitate yacc's output file naming conventions
YACCFLAGS = -dvty

# Link with standard c library, math library, and lex library
LIBS = -lc -lm -ll

# Rules for various parts of the target

.yy.o: $*.yy.c
	$(CC) $(CFLAGS) -c -o $@ $*.cc

lex.yy.c: scanner.l 
	$(LEX) $(LEXFLAGS) scanner.l

.cc.o: $*.cc
	$(CC) $(CFLAGS) -c -o $@ $*.cc

# rules to build compiler (dcc)

$(COMPILER) : $(PREPROCESSOR) $(OBJS)
	$(LD) -o $@ $(OBJS) $(LIBS)

$(COMPILER).purify : $(OBJS)
	purify -log-file=purify.log -cache-dir=/tmp/$(USER) -leaks-at-exit=no $(LD) -o $@ $(OBJS) $(LIBS)

# rules to build preprocessor (dpp) j
PREP_OBJS = dpp.yy.o dppmain.o utility.o errors.o

$(PREPROCESSOR) : $(PREP_OBJS)
	$(LD) -o $@ $(PREP_OBJS) $(LIBS)

dpp.yy.c : dpp.l
	$(LEX) -odpp.yy.c dpp.l

# This target is to build small for testing (no debugging info), removes
# all intermediate products, too
strip : $(PRODUCTS)
	strip $(PRODUCTS)
	rm -rf $(JUNK)


# make depend will set up the header file dependencies for the 
# assignment.  You should make depend whenever you add a new header
# file to the project or move the project between machines
#
depend:
	makedepend -- $(CFLAGS) -- $(SRCS)

clean:
	rm -f $(JUNK) y.output $(PRODUCTS)

test:
	dcc < ./samples/badbool.frag >& ./samples/tested/badbool.test &
	dcc < ./samples/baddouble.frag >& ./samples/tested/baddouble.test &
	dcc < ./samples/badident.frag >& ./samples/tested/badident.test &
	dcc < ./samples/badint.frag >& ./samples/tested/badint.test &
	dcc < ./samples/badop.frag >& ./samples/tested/badop.test &
	dcc < ./samples/badpre.frag >& ./samples/tested/badpre.test &
	dcc < ./samples/badreserve.frag >& ./samples/tested/badreserve.test &
	dcc < ./samples/badstring.frag >& ./samples/tested/badstring.test &
	dcc < ./samples/comment.frag >& ./samples/tested/comment.test &
	dcc < ./samples/define.frag >& ./samples/tested/define.test &
	dcc < ./samples/ident.frag >& ./samples/tested/ident.test &
	dcc < ./samples/number.frag >& ./samples/tested/number.test &
	dcc < ./samples/program2.decaf >& ./samples/tested/program2.test &
	dcc < ./samples/program3.decaf >& ./samples/tested/program3.test &
	dcc < ./samples/reserve_op.frag >& ./samples/tested/reserve_op.test &
	dcc < ./samples/string.frag >& ./samples/tested/string.test &


	diff  ./samples/badbool.out  ./samples/tested/badbool.test > ./samples/tested/diff/badbool.test.diff &
	diff  ./samples/baddouble.out  ./samples/tested/baddouble.test > ./samples/tested/diff/baddouble.test.diff &
	diff  ./samples/badident.out  ./samples/tested/badident.test > ./samples/tested/diff/badident.test.diff &
	diff  ./samples/badint.out  ./samples/tested/badint.test > ./samples/tested/diff/badint.test.diff &
	diff  ./samples/badop.out  ./samples/tested/badop.test > ./samples/tested/diff/badop.test.diff &
	diff  ./samples/badpre.out  ./samples/tested/badpre.test > ./samples/tested/diff/badpre.test.diff &
	diff  ./samples/badreserve.out  ./samples/tested/badreserve.test > ./samples/tested/diff/badreserve.test.diff &
	diff  ./samples/badstring.out  ./samples/tested/badstring.test > ./samples/tested/diff/badstring.test.diff &
	diff  ./samples/comment.out  ./samples/tested/comment.test > ./samples/tested/diff/comment.test.diff &
	diff  ./samples/define.out  ./samples/tested/define.test > ./samples/tested/diff/define.test.diff &
	diff  ./samples/ident.out  ./samples/tested/ident.test > ./samples/tested/diff/ident.test.diff &
	diff  ./samples/number.out  ./samples/tested/number.test > ./samples/tested/diff/number.test.diff &
	diff  ./samples/program2.out  ./samples/tested/program2.test > ./samples/tested/diff/program2.test.diff &
	diff  ./samples/program3.out  ./samples/tested/program3.test > ./samples/tested/diff/program3.test.diff &
	diff  ./samples/reserve_op.out  ./samples/tested/reserve_op.test > ./samples/tested/diff/reserve_op.test.diff &
	diff  ./samples/string.out  ./samples/tested/string.test > ./samples/tested/diff/string.test.diff &