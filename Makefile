#!/bin/sh
CC = gcc
SRCDIR = src
OBJDIR = obj
SRCS = main.c matrix.c
OBJS = $(SRCS:.c=.o)
OUTPUTDIR = bin
OUTPUTFILE = $(OUTPUTDIR)/matrix-multiply
VPATH = $(SRCDIR):$(OBJDIR)

.PHONY: all
all : $(OBJDIR) $(OBJS) $(OUTPUTDIR) $(OUTPUTFILE)

$(OUTPUTFILE) : $(OBJS)
	$(CC) -o $@ $(addprefix $(OBJDIR)/,$^)

$(OUTPUTDIR) :
	mkdir -p $(OUTPUTDIR)

%.o : %.c
	$(CC) -c -o $(addprefix $(OBJDIR)/,$@) $<

$(OBJDIR):
	mkdir -p $(OBJDIR)
	
.PHONY : clean
clean :
	rm -f $(addprefix $(OBJDIR)/,$(OBJS)) $(OUTPUTFILE)
	rm -rf $(OBJDIR) $(OUTPUTDIR)

.PHONY : echo
echo :
	echo "$(OBJDIR)/$(OBJS)"
