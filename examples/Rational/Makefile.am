# Copyright(c)'1994-2009 by The Givaro group
# This file is part of Givaro.
# Givaro is governed by the CeCILL-B license under French law
# and abiding by the rules of distribution of free software.
# see the COPYRIGHT file for more details.
examples: $(EXTRA_PROGRAMS)
AM_CPPFLAGS=-I$(top_builddir)

#OPTFLAGS = -O7 -funroll-all-loops -felide-constructors -fstrict-aliasing
#OPTFLAGS+= -frerun-loop-opt -fexpensive-optimizations
#OPTFLAGS+= -fomit-frame-pointer
#OPTFLAGS+= -fprefetch-loop-arrays -floop-optimize
#OPTFLAGS+= -malign-double
#OPTFLAGS+= -falign-loops -falign-jumps -falign-functions -falign-labels
#OPTFLAGS+= -fschedule-insns2
#OPTFLAGS+= -fforce-addr -fforce-mem -fstrength-reduce
#OPTFLAGS+= -ffast-math

# for icc ...
#OPTFLAGS = -fast -Ob2  -ipo_obj -unroll
#OPTFLAGS+= -parallel -par_report1
# icc for itanium2
#OPTFLAGS+= -tpp2 -mcpu=itanium2


AM_CXXFLAGS = @DEFAULT_CFLAGS@
AM_CPPFLAGS += $(OPTFLAGS) $(GMP_CFLAGS)
AM_CPPFLAGS += -I$(top_builddir)/src/kernel/system  -I$(top_builddir)/src/kernel/ring -I$(top_builddir)/src/kernel/memory -I$(top_builddir)/src/kernel/integer -I$(top_builddir)/src/kernel -I$(top_builddir)/src/kernel/bstruct -I$(top_builddir)/src/kernel/rational -I$(top_builddir)/src/library/tools -I$(top_builddir)/src/library/poly1 -I$(top_builddir)/src/kernel

LDADD = $(top_builddir)/src/libgivaro.la $(GMP_LIBS) $(LDFLAGS)
AM_LDFLAGS=-static


EXTRA_PROGRAMS=iratrecon polydouble

CLEANFILES=$(EXTRA_PROGRAMS)

iratrecon_SOURCES  = iratrecon.C
polydouble_SOURCES = polydouble.C

# for compilation of new examples
GIVARO_BIN=@bindir@
new_examp_comp = $(CXX) $(OPTFLAGS) $(AM_CPPFLAGS) $(AM_CXXFLAGS) $< -o $@ `$(GIVARO_BIN)/givaro-config --cflags` $(LDADD)  `$(GIVARO_BIN)/givaro-config --libs`

%:%.C
	$(new_examp_comp)

%:%.cpp
	$(new_examp_comp)
