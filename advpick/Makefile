SHELL=/bin/sh
LIB=$(TECADDONDEVDIR)/lib/$(PLATFORM)/$(OBJSUBDIR)/lib$(LIBBASENAME).$(LIBEXT)
STATLIB=$(ADDONLIBDIR)/lib$(LIBBASENAME).a
OBJDIR=obj/$(PLATFORM)/$(OBJSUBDIR)
EXTLIBDIR=$(EXTBASEDIR)/$(PLATFORM)
IOUTILLIB=$(EXTLIBDIR)/libioutil.a
GUILIB=$(EXTLIBDIR)/libgui.a
 
shlib: $(LIB)
statlib: $(STATLIB)
#
# list of obj files....
#
OBJS=$(OBJDIR)/advpick.o $(OBJDIR)/guidefs.o $(OBJDIR)/guicb.o
 
#
# The next two dependencies probably can remain unchanged...
#
 
$(LIB) : $(OBJS)
	cd $(OBJDIR); $(LD) $(LDFLAGS) *.o $(GUILIB) -o $(LIB)
 
$(STATLIB) : $(OBJS)
	cd $(OBJDIR); $(AR) q lib$(LIBBASENAME).a *.o $(GUILIB); mv lib$(LIBBASENAME).a  $(STATLIB)
 
#
# Duplicate the next line for additional source files...
#
 
$(OBJDIR)/advpick.o : advpick.c GUIDEFS.h ADDONVER.h
	cd $(OBJDIR); $(CCOMP) $(CFLAGS) ../../../advpick.c 
$(OBJDIR)/guidefs.o : guidefs.c guibld.c GUIDEFS.h
	cd $(OBJDIR); $(CCOMP) $(CFLAGS) ../../../guidefs.c 
$(OBJDIR)/guicb.o : guicb.c guibld.c GUIDEFS.h
	cd $(OBJDIR); $(CCOMP) $(CFLAGS) ../../../guicb.c 
 
 
clean:
	rm obj/*/*/*.o > /dev/null 2>&1
