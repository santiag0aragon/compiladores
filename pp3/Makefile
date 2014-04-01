## 
## Simple makefile for decaf programming projects
##


.PHONY: clean strip

# Set the default target. When you make with no arguments,
# this will be the target built.
COMPILER = dcc
PRODUCTS = $(COMPILER) 
default: $(PRODUCTS)

# Set up the list of source and object files
SRCS = ast.cc ast_decl.cc ast_expr.cc ast_stmt.cc ast_type.cc errors.cc utility.cc main.cc \
	

# OBJS can deal with either .cc or .c files listed in SRCS
OBJS = y.tab.o lex.yy.o $(patsubst %.cc, %.o, $(filter %.cc,$(SRCS))) $(patsubst %.c, %.o, $(filter %.c, $(SRCS)))

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

lex.yy.c: scanner.l  parser.y y.tab.h 
	$(LEX) $(LEXFLAGS) scanner.l

y.tab.o: y.tab.c
	$(CC) $(CFLAGS) -c -o y.tab.o y.tab.c

y.tab.h y.tab.c: parser.y
	$(YACC) $(YACCFLAGS) parser.y
.cc.o: $*.cc
	$(CC) $(CFLAGS) -c -o $@ $*.cc

# rules to build compiler (dcc)

$(COMPILER) :  $(OBJS)
	$(LD) -o $@ $(OBJS) $(LIBS)

$(COMPILER).purify : $(OBJS)
	purify -log-file=purify.log -cache-dir=/tmp/$(USER) -leaks-at-exit=no $(LD) -o $@ $(OBJS) $(LIBS)


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

# DO NOT DELETE

ast.o: ast.h /usr/include/stdlib.h /usr/include/Availability.h
ast.o: /usr/include/AvailabilityInternal.h /usr/include/_types.h
ast.o: /usr/include/sys/_types.h /usr/include/sys/cdefs.h
ast.o: /usr/include/sys/_symbol_aliasing.h
ast.o: /usr/include/sys/_posix_availability.h /usr/include/machine/_types.h
ast.o: /usr/include/i386/_types.h /usr/include/sys/wait.h
ast.o: /usr/include/sys/_types/_pid_t.h /usr/include/sys/_types/_id_t.h
ast.o: /usr/include/sys/signal.h /usr/include/sys/appleapiopts.h
ast.o: /usr/include/machine/signal.h /usr/include/i386/signal.h
ast.o: /usr/include/machine/_mcontext.h /usr/include/i386/_mcontext.h
ast.o: /usr/include/mach/i386/_structs.h
ast.o: /usr/include/sys/_types/_sigaltstack.h
ast.o: /usr/include/sys/_types/_ucontext.h
ast.o: /usr/include/sys/_types/_pthread_attr_t.h
ast.o: /usr/include/sys/_types/_sigset_t.h /usr/include/sys/_types/_size_t.h
ast.o: /usr/include/sys/_types/_uid_t.h /usr/include/sys/resource.h
ast.o: /usr/include/stdint.h /usr/include/sys/_types/_int8_t.h
ast.o: /usr/include/sys/_types/_int16_t.h /usr/include/sys/_types/_int32_t.h
ast.o: /usr/include/sys/_types/_int64_t.h /usr/include/_types/_uint8_t.h
ast.o: /usr/include/_types/_uint16_t.h /usr/include/_types/_uint32_t.h
ast.o: /usr/include/_types/_uint64_t.h /usr/include/sys/_types/_intptr_t.h
ast.o: /usr/include/sys/_types/_uintptr_t.h /usr/include/_types/_intmax_t.h
ast.o: /usr/include/_types/_uintmax_t.h /usr/include/sys/_types/_timeval.h
ast.o: /usr/include/machine/endian.h /usr/include/i386/endian.h
ast.o: /usr/include/sys/_endian.h /usr/include/libkern/_OSByteOrder.h
ast.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
ast.o: /usr/include/sys/_types/_ct_rune_t.h /usr/include/sys/_types/_rune_t.h
ast.o: /usr/include/sys/_types/_wchar_t.h /usr/include/sys/_types/_null.h
ast.o: /usr/include/machine/types.h /usr/include/i386/types.h
ast.o: /usr/include/sys/_types/___offsetof.h /usr/include/sys/_types/_dev_t.h
ast.o: /usr/include/sys/_types/_mode_t.h location.h errors.h hashtable.h
ast.o: /usr/include/string.h /usr/include/sys/_types/_rsize_t.h
ast.o: /usr/include/sys/_types/_errno_t.h /usr/include/sys/_types/_ssize_t.h
ast.o: /usr/include/strings.h /usr/include/secure/_string.h
ast.o: /usr/include/secure/_common.h hashtable.cc list.h utility.h
ast.o: /usr/include/stdio.h /usr/include/sys/_types/_va_list.h
ast.o: /usr/include/sys/_types/_off_t.h /usr/include/secure/_stdio.h
ast.o: ast_type.h ast_decl.h ast_stmt.h
ast_decl.o: ast_decl.h ast.h /usr/include/stdlib.h
ast_decl.o: /usr/include/Availability.h /usr/include/AvailabilityInternal.h
ast_decl.o: /usr/include/_types.h /usr/include/sys/_types.h
ast_decl.o: /usr/include/sys/cdefs.h /usr/include/sys/_symbol_aliasing.h
ast_decl.o: /usr/include/sys/_posix_availability.h
ast_decl.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
ast_decl.o: /usr/include/sys/wait.h /usr/include/sys/_types/_pid_t.h
ast_decl.o: /usr/include/sys/_types/_id_t.h /usr/include/sys/signal.h
ast_decl.o: /usr/include/sys/appleapiopts.h /usr/include/machine/signal.h
ast_decl.o: /usr/include/i386/signal.h /usr/include/machine/_mcontext.h
ast_decl.o: /usr/include/i386/_mcontext.h /usr/include/mach/i386/_structs.h
ast_decl.o: /usr/include/sys/_types/_sigaltstack.h
ast_decl.o: /usr/include/sys/_types/_ucontext.h
ast_decl.o: /usr/include/sys/_types/_pthread_attr_t.h
ast_decl.o: /usr/include/sys/_types/_sigset_t.h
ast_decl.o: /usr/include/sys/_types/_size_t.h
ast_decl.o: /usr/include/sys/_types/_uid_t.h /usr/include/sys/resource.h
ast_decl.o: /usr/include/stdint.h /usr/include/sys/_types/_int8_t.h
ast_decl.o: /usr/include/sys/_types/_int16_t.h
ast_decl.o: /usr/include/sys/_types/_int32_t.h
ast_decl.o: /usr/include/sys/_types/_int64_t.h /usr/include/_types/_uint8_t.h
ast_decl.o: /usr/include/_types/_uint16_t.h /usr/include/_types/_uint32_t.h
ast_decl.o: /usr/include/_types/_uint64_t.h
ast_decl.o: /usr/include/sys/_types/_intptr_t.h
ast_decl.o: /usr/include/sys/_types/_uintptr_t.h
ast_decl.o: /usr/include/_types/_intmax_t.h /usr/include/_types/_uintmax_t.h
ast_decl.o: /usr/include/sys/_types/_timeval.h /usr/include/machine/endian.h
ast_decl.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
ast_decl.o: /usr/include/libkern/_OSByteOrder.h
ast_decl.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
ast_decl.o: /usr/include/sys/_types/_ct_rune_t.h
ast_decl.o: /usr/include/sys/_types/_rune_t.h
ast_decl.o: /usr/include/sys/_types/_wchar_t.h
ast_decl.o: /usr/include/sys/_types/_null.h /usr/include/machine/types.h
ast_decl.o: /usr/include/i386/types.h /usr/include/sys/_types/___offsetof.h
ast_decl.o: /usr/include/sys/_types/_dev_t.h
ast_decl.o: /usr/include/sys/_types/_mode_t.h location.h errors.h hashtable.h
ast_decl.o: /usr/include/string.h /usr/include/sys/_types/_rsize_t.h
ast_decl.o: /usr/include/sys/_types/_errno_t.h
ast_decl.o: /usr/include/sys/_types/_ssize_t.h /usr/include/strings.h
ast_decl.o: /usr/include/secure/_string.h /usr/include/secure/_common.h
ast_decl.o: hashtable.cc list.h utility.h /usr/include/stdio.h
ast_decl.o: /usr/include/sys/_types/_va_list.h
ast_decl.o: /usr/include/sys/_types/_off_t.h /usr/include/secure/_stdio.h
ast_decl.o: ast_type.h ast_stmt.h
ast_expr.o: ast_expr.h ast.h /usr/include/stdlib.h
ast_expr.o: /usr/include/Availability.h /usr/include/AvailabilityInternal.h
ast_expr.o: /usr/include/_types.h /usr/include/sys/_types.h
ast_expr.o: /usr/include/sys/cdefs.h /usr/include/sys/_symbol_aliasing.h
ast_expr.o: /usr/include/sys/_posix_availability.h
ast_expr.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
ast_expr.o: /usr/include/sys/wait.h /usr/include/sys/_types/_pid_t.h
ast_expr.o: /usr/include/sys/_types/_id_t.h /usr/include/sys/signal.h
ast_expr.o: /usr/include/sys/appleapiopts.h /usr/include/machine/signal.h
ast_expr.o: /usr/include/i386/signal.h /usr/include/machine/_mcontext.h
ast_expr.o: /usr/include/i386/_mcontext.h /usr/include/mach/i386/_structs.h
ast_expr.o: /usr/include/sys/_types/_sigaltstack.h
ast_expr.o: /usr/include/sys/_types/_ucontext.h
ast_expr.o: /usr/include/sys/_types/_pthread_attr_t.h
ast_expr.o: /usr/include/sys/_types/_sigset_t.h
ast_expr.o: /usr/include/sys/_types/_size_t.h
ast_expr.o: /usr/include/sys/_types/_uid_t.h /usr/include/sys/resource.h
ast_expr.o: /usr/include/stdint.h /usr/include/sys/_types/_int8_t.h
ast_expr.o: /usr/include/sys/_types/_int16_t.h
ast_expr.o: /usr/include/sys/_types/_int32_t.h
ast_expr.o: /usr/include/sys/_types/_int64_t.h /usr/include/_types/_uint8_t.h
ast_expr.o: /usr/include/_types/_uint16_t.h /usr/include/_types/_uint32_t.h
ast_expr.o: /usr/include/_types/_uint64_t.h
ast_expr.o: /usr/include/sys/_types/_intptr_t.h
ast_expr.o: /usr/include/sys/_types/_uintptr_t.h
ast_expr.o: /usr/include/_types/_intmax_t.h /usr/include/_types/_uintmax_t.h
ast_expr.o: /usr/include/sys/_types/_timeval.h /usr/include/machine/endian.h
ast_expr.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
ast_expr.o: /usr/include/libkern/_OSByteOrder.h
ast_expr.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
ast_expr.o: /usr/include/sys/_types/_ct_rune_t.h
ast_expr.o: /usr/include/sys/_types/_rune_t.h
ast_expr.o: /usr/include/sys/_types/_wchar_t.h
ast_expr.o: /usr/include/sys/_types/_null.h /usr/include/machine/types.h
ast_expr.o: /usr/include/i386/types.h /usr/include/sys/_types/___offsetof.h
ast_expr.o: /usr/include/sys/_types/_dev_t.h
ast_expr.o: /usr/include/sys/_types/_mode_t.h location.h errors.h hashtable.h
ast_expr.o: /usr/include/string.h /usr/include/sys/_types/_rsize_t.h
ast_expr.o: /usr/include/sys/_types/_errno_t.h
ast_expr.o: /usr/include/sys/_types/_ssize_t.h /usr/include/strings.h
ast_expr.o: /usr/include/secure/_string.h /usr/include/secure/_common.h
ast_expr.o: hashtable.cc list.h utility.h /usr/include/stdio.h
ast_expr.o: /usr/include/sys/_types/_va_list.h
ast_expr.o: /usr/include/sys/_types/_off_t.h /usr/include/secure/_stdio.h
ast_expr.o: ast_stmt.h ast_type.h ast_decl.h
ast_stmt.o: ast_stmt.h list.h utility.h /usr/include/stdlib.h
ast_stmt.o: /usr/include/Availability.h /usr/include/AvailabilityInternal.h
ast_stmt.o: /usr/include/_types.h /usr/include/sys/_types.h
ast_stmt.o: /usr/include/sys/cdefs.h /usr/include/sys/_symbol_aliasing.h
ast_stmt.o: /usr/include/sys/_posix_availability.h
ast_stmt.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
ast_stmt.o: /usr/include/sys/wait.h /usr/include/sys/_types/_pid_t.h
ast_stmt.o: /usr/include/sys/_types/_id_t.h /usr/include/sys/signal.h
ast_stmt.o: /usr/include/sys/appleapiopts.h /usr/include/machine/signal.h
ast_stmt.o: /usr/include/i386/signal.h /usr/include/machine/_mcontext.h
ast_stmt.o: /usr/include/i386/_mcontext.h /usr/include/mach/i386/_structs.h
ast_stmt.o: /usr/include/sys/_types/_sigaltstack.h
ast_stmt.o: /usr/include/sys/_types/_ucontext.h
ast_stmt.o: /usr/include/sys/_types/_pthread_attr_t.h
ast_stmt.o: /usr/include/sys/_types/_sigset_t.h
ast_stmt.o: /usr/include/sys/_types/_size_t.h
ast_stmt.o: /usr/include/sys/_types/_uid_t.h /usr/include/sys/resource.h
ast_stmt.o: /usr/include/stdint.h /usr/include/sys/_types/_int8_t.h
ast_stmt.o: /usr/include/sys/_types/_int16_t.h
ast_stmt.o: /usr/include/sys/_types/_int32_t.h
ast_stmt.o: /usr/include/sys/_types/_int64_t.h /usr/include/_types/_uint8_t.h
ast_stmt.o: /usr/include/_types/_uint16_t.h /usr/include/_types/_uint32_t.h
ast_stmt.o: /usr/include/_types/_uint64_t.h
ast_stmt.o: /usr/include/sys/_types/_intptr_t.h
ast_stmt.o: /usr/include/sys/_types/_uintptr_t.h
ast_stmt.o: /usr/include/_types/_intmax_t.h /usr/include/_types/_uintmax_t.h
ast_stmt.o: /usr/include/sys/_types/_timeval.h /usr/include/machine/endian.h
ast_stmt.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
ast_stmt.o: /usr/include/libkern/_OSByteOrder.h
ast_stmt.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
ast_stmt.o: /usr/include/sys/_types/_ct_rune_t.h
ast_stmt.o: /usr/include/sys/_types/_rune_t.h
ast_stmt.o: /usr/include/sys/_types/_wchar_t.h
ast_stmt.o: /usr/include/sys/_types/_null.h /usr/include/machine/types.h
ast_stmt.o: /usr/include/i386/types.h /usr/include/sys/_types/___offsetof.h
ast_stmt.o: /usr/include/sys/_types/_dev_t.h
ast_stmt.o: /usr/include/sys/_types/_mode_t.h /usr/include/stdio.h
ast_stmt.o: /usr/include/sys/_types/_va_list.h
ast_stmt.o: /usr/include/sys/_types/_off_t.h
ast_stmt.o: /usr/include/sys/_types/_ssize_t.h /usr/include/secure/_stdio.h
ast_stmt.o: /usr/include/secure/_common.h ast.h location.h errors.h
ast_stmt.o: hashtable.h /usr/include/string.h
ast_stmt.o: /usr/include/sys/_types/_rsize_t.h
ast_stmt.o: /usr/include/sys/_types/_errno_t.h /usr/include/strings.h
ast_stmt.o: /usr/include/secure/_string.h hashtable.cc ast_type.h ast_decl.h
ast_stmt.o: ast_expr.h
ast_type.o: ast_type.h ast.h /usr/include/stdlib.h
ast_type.o: /usr/include/Availability.h /usr/include/AvailabilityInternal.h
ast_type.o: /usr/include/_types.h /usr/include/sys/_types.h
ast_type.o: /usr/include/sys/cdefs.h /usr/include/sys/_symbol_aliasing.h
ast_type.o: /usr/include/sys/_posix_availability.h
ast_type.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
ast_type.o: /usr/include/sys/wait.h /usr/include/sys/_types/_pid_t.h
ast_type.o: /usr/include/sys/_types/_id_t.h /usr/include/sys/signal.h
ast_type.o: /usr/include/sys/appleapiopts.h /usr/include/machine/signal.h
ast_type.o: /usr/include/i386/signal.h /usr/include/machine/_mcontext.h
ast_type.o: /usr/include/i386/_mcontext.h /usr/include/mach/i386/_structs.h
ast_type.o: /usr/include/sys/_types/_sigaltstack.h
ast_type.o: /usr/include/sys/_types/_ucontext.h
ast_type.o: /usr/include/sys/_types/_pthread_attr_t.h
ast_type.o: /usr/include/sys/_types/_sigset_t.h
ast_type.o: /usr/include/sys/_types/_size_t.h
ast_type.o: /usr/include/sys/_types/_uid_t.h /usr/include/sys/resource.h
ast_type.o: /usr/include/stdint.h /usr/include/sys/_types/_int8_t.h
ast_type.o: /usr/include/sys/_types/_int16_t.h
ast_type.o: /usr/include/sys/_types/_int32_t.h
ast_type.o: /usr/include/sys/_types/_int64_t.h /usr/include/_types/_uint8_t.h
ast_type.o: /usr/include/_types/_uint16_t.h /usr/include/_types/_uint32_t.h
ast_type.o: /usr/include/_types/_uint64_t.h
ast_type.o: /usr/include/sys/_types/_intptr_t.h
ast_type.o: /usr/include/sys/_types/_uintptr_t.h
ast_type.o: /usr/include/_types/_intmax_t.h /usr/include/_types/_uintmax_t.h
ast_type.o: /usr/include/sys/_types/_timeval.h /usr/include/machine/endian.h
ast_type.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
ast_type.o: /usr/include/libkern/_OSByteOrder.h
ast_type.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
ast_type.o: /usr/include/sys/_types/_ct_rune_t.h
ast_type.o: /usr/include/sys/_types/_rune_t.h
ast_type.o: /usr/include/sys/_types/_wchar_t.h
ast_type.o: /usr/include/sys/_types/_null.h /usr/include/machine/types.h
ast_type.o: /usr/include/i386/types.h /usr/include/sys/_types/___offsetof.h
ast_type.o: /usr/include/sys/_types/_dev_t.h
ast_type.o: /usr/include/sys/_types/_mode_t.h location.h errors.h hashtable.h
ast_type.o: /usr/include/string.h /usr/include/sys/_types/_rsize_t.h
ast_type.o: /usr/include/sys/_types/_errno_t.h
ast_type.o: /usr/include/sys/_types/_ssize_t.h /usr/include/strings.h
ast_type.o: /usr/include/secure/_string.h /usr/include/secure/_common.h
ast_type.o: hashtable.cc list.h utility.h /usr/include/stdio.h
ast_type.o: /usr/include/sys/_types/_va_list.h
ast_type.o: /usr/include/sys/_types/_off_t.h /usr/include/secure/_stdio.h
ast_type.o: ast_decl.h ast_stmt.h
errors.o: errors.h location.h /usr/include/stdio.h /usr/include/sys/cdefs.h
errors.o: /usr/include/sys/_symbol_aliasing.h
errors.o: /usr/include/sys/_posix_availability.h /usr/include/Availability.h
errors.o: /usr/include/AvailabilityInternal.h /usr/include/_types.h
errors.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
errors.o: /usr/include/i386/_types.h /usr/include/sys/_types/_va_list.h
errors.o: /usr/include/sys/_types/_size_t.h /usr/include/sys/_types/_null.h
errors.o: /usr/include/sys/_types/_off_t.h /usr/include/sys/_types/_ssize_t.h
errors.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h
errors.o: scanner.h ast_type.h ast.h /usr/include/stdlib.h
errors.o: /usr/include/sys/wait.h /usr/include/sys/_types/_pid_t.h
errors.o: /usr/include/sys/_types/_id_t.h /usr/include/sys/signal.h
errors.o: /usr/include/sys/appleapiopts.h /usr/include/machine/signal.h
errors.o: /usr/include/i386/signal.h /usr/include/machine/_mcontext.h
errors.o: /usr/include/i386/_mcontext.h /usr/include/mach/i386/_structs.h
errors.o: /usr/include/sys/_types/_sigaltstack.h
errors.o: /usr/include/sys/_types/_ucontext.h
errors.o: /usr/include/sys/_types/_pthread_attr_t.h
errors.o: /usr/include/sys/_types/_sigset_t.h
errors.o: /usr/include/sys/_types/_uid_t.h /usr/include/sys/resource.h
errors.o: /usr/include/stdint.h /usr/include/sys/_types/_int8_t.h
errors.o: /usr/include/sys/_types/_int16_t.h
errors.o: /usr/include/sys/_types/_int32_t.h
errors.o: /usr/include/sys/_types/_int64_t.h /usr/include/_types/_uint8_t.h
errors.o: /usr/include/_types/_uint16_t.h /usr/include/_types/_uint32_t.h
errors.o: /usr/include/_types/_uint64_t.h /usr/include/sys/_types/_intptr_t.h
errors.o: /usr/include/sys/_types/_uintptr_t.h
errors.o: /usr/include/_types/_intmax_t.h /usr/include/_types/_uintmax_t.h
errors.o: /usr/include/sys/_types/_timeval.h /usr/include/machine/endian.h
errors.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
errors.o: /usr/include/libkern/_OSByteOrder.h
errors.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
errors.o: /usr/include/sys/_types/_ct_rune_t.h
errors.o: /usr/include/sys/_types/_rune_t.h
errors.o: /usr/include/sys/_types/_wchar_t.h /usr/include/machine/types.h
errors.o: /usr/include/i386/types.h /usr/include/sys/_types/___offsetof.h
errors.o: /usr/include/sys/_types/_dev_t.h /usr/include/sys/_types/_mode_t.h
errors.o: hashtable.h /usr/include/string.h
errors.o: /usr/include/sys/_types/_rsize_t.h
errors.o: /usr/include/sys/_types/_errno_t.h /usr/include/strings.h
errors.o: /usr/include/secure/_string.h hashtable.cc list.h utility.h
errors.o: ast_expr.h ast_stmt.h ast_decl.h
utility.o: utility.h /usr/include/stdlib.h /usr/include/Availability.h
utility.o: /usr/include/AvailabilityInternal.h /usr/include/_types.h
utility.o: /usr/include/sys/_types.h /usr/include/sys/cdefs.h
utility.o: /usr/include/sys/_symbol_aliasing.h
utility.o: /usr/include/sys/_posix_availability.h
utility.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
utility.o: /usr/include/sys/wait.h /usr/include/sys/_types/_pid_t.h
utility.o: /usr/include/sys/_types/_id_t.h /usr/include/sys/signal.h
utility.o: /usr/include/sys/appleapiopts.h /usr/include/machine/signal.h
utility.o: /usr/include/i386/signal.h /usr/include/machine/_mcontext.h
utility.o: /usr/include/i386/_mcontext.h /usr/include/mach/i386/_structs.h
utility.o: /usr/include/sys/_types/_sigaltstack.h
utility.o: /usr/include/sys/_types/_ucontext.h
utility.o: /usr/include/sys/_types/_pthread_attr_t.h
utility.o: /usr/include/sys/_types/_sigset_t.h
utility.o: /usr/include/sys/_types/_size_t.h /usr/include/sys/_types/_uid_t.h
utility.o: /usr/include/sys/resource.h /usr/include/stdint.h
utility.o: /usr/include/sys/_types/_int8_t.h
utility.o: /usr/include/sys/_types/_int16_t.h
utility.o: /usr/include/sys/_types/_int32_t.h
utility.o: /usr/include/sys/_types/_int64_t.h /usr/include/_types/_uint8_t.h
utility.o: /usr/include/_types/_uint16_t.h /usr/include/_types/_uint32_t.h
utility.o: /usr/include/_types/_uint64_t.h
utility.o: /usr/include/sys/_types/_intptr_t.h
utility.o: /usr/include/sys/_types/_uintptr_t.h
utility.o: /usr/include/_types/_intmax_t.h /usr/include/_types/_uintmax_t.h
utility.o: /usr/include/sys/_types/_timeval.h /usr/include/machine/endian.h
utility.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
utility.o: /usr/include/libkern/_OSByteOrder.h
utility.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
utility.o: /usr/include/sys/_types/_ct_rune_t.h
utility.o: /usr/include/sys/_types/_rune_t.h
utility.o: /usr/include/sys/_types/_wchar_t.h /usr/include/sys/_types/_null.h
utility.o: /usr/include/machine/types.h /usr/include/i386/types.h
utility.o: /usr/include/sys/_types/___offsetof.h
utility.o: /usr/include/sys/_types/_dev_t.h /usr/include/sys/_types/_mode_t.h
utility.o: /usr/include/stdio.h /usr/include/sys/_types/_va_list.h
utility.o: /usr/include/sys/_types/_off_t.h
utility.o: /usr/include/sys/_types/_ssize_t.h /usr/include/secure/_stdio.h
utility.o: /usr/include/secure/_common.h list.h /usr/include/string.h
utility.o: /usr/include/sys/_types/_rsize_t.h
utility.o: /usr/include/sys/_types/_errno_t.h /usr/include/strings.h
utility.o: /usr/include/secure/_string.h
main.o: /usr/include/string.h /usr/include/_types.h /usr/include/sys/_types.h
main.o: /usr/include/sys/cdefs.h /usr/include/sys/_symbol_aliasing.h
main.o: /usr/include/sys/_posix_availability.h /usr/include/machine/_types.h
main.o: /usr/include/i386/_types.h /usr/include/Availability.h
main.o: /usr/include/AvailabilityInternal.h /usr/include/sys/_types/_size_t.h
main.o: /usr/include/sys/_types/_null.h /usr/include/sys/_types/_rsize_t.h
main.o: /usr/include/sys/_types/_errno_t.h /usr/include/sys/_types/_ssize_t.h
main.o: /usr/include/strings.h /usr/include/secure/_string.h
main.o: /usr/include/secure/_common.h /usr/include/stdio.h
main.o: /usr/include/sys/_types/_va_list.h /usr/include/sys/_types/_off_t.h
main.o: /usr/include/secure/_stdio.h utility.h /usr/include/stdlib.h
main.o: /usr/include/sys/wait.h /usr/include/sys/_types/_pid_t.h
main.o: /usr/include/sys/_types/_id_t.h /usr/include/sys/signal.h
main.o: /usr/include/sys/appleapiopts.h /usr/include/machine/signal.h
main.o: /usr/include/i386/signal.h /usr/include/machine/_mcontext.h
main.o: /usr/include/i386/_mcontext.h /usr/include/mach/i386/_structs.h
main.o: /usr/include/sys/_types/_sigaltstack.h
main.o: /usr/include/sys/_types/_ucontext.h
main.o: /usr/include/sys/_types/_pthread_attr_t.h
main.o: /usr/include/sys/_types/_sigset_t.h /usr/include/sys/_types/_uid_t.h
main.o: /usr/include/sys/resource.h /usr/include/stdint.h
main.o: /usr/include/sys/_types/_int8_t.h /usr/include/sys/_types/_int16_t.h
main.o: /usr/include/sys/_types/_int32_t.h /usr/include/sys/_types/_int64_t.h
main.o: /usr/include/_types/_uint8_t.h /usr/include/_types/_uint16_t.h
main.o: /usr/include/_types/_uint32_t.h /usr/include/_types/_uint64_t.h
main.o: /usr/include/sys/_types/_intptr_t.h
main.o: /usr/include/sys/_types/_uintptr_t.h /usr/include/_types/_intmax_t.h
main.o: /usr/include/_types/_uintmax_t.h /usr/include/sys/_types/_timeval.h
main.o: /usr/include/machine/endian.h /usr/include/i386/endian.h
main.o: /usr/include/sys/_endian.h /usr/include/libkern/_OSByteOrder.h
main.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
main.o: /usr/include/sys/_types/_ct_rune_t.h
main.o: /usr/include/sys/_types/_rune_t.h /usr/include/sys/_types/_wchar_t.h
main.o: /usr/include/machine/types.h /usr/include/i386/types.h
main.o: /usr/include/sys/_types/___offsetof.h
main.o: /usr/include/sys/_types/_dev_t.h /usr/include/sys/_types/_mode_t.h
main.o: errors.h location.h parser.h scanner.h list.h ast.h hashtable.h
main.o: hashtable.cc ast_type.h ast_decl.h ast_stmt.h ast_expr.h y.tab.h
