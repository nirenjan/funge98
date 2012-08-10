#############################################################################
# Makefile
#
# Makefile for BrainFunge memory manager
#
# Copyright (C) 2012 Nirenjan Krishnan
#############################################################################
# This file is part of BrainFunge.
#
# BrainFunge is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# BrainFunge is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public Licese for more details.
#
# You should have received a copy of the GNU General Public License
# along with BrainFunge. If not, see <http://www.gnu.org/licenses/>.
#############################################################################

CC=gcc
CFLAGS=-Wall -Werror

all: funge_stack.o funge_extn.o

funge_stack.o: funge_stack.c funge_stack.h funge_const.h funge_fwd.h
	$(CC) $(CFLAGS) -c funge_stack.c

funge_extn.o: funge_extn.c funge_extn.h funge_thread.h funge_const.h funge_fwd.h
	$(CC) $(CFLAGS) -c funge_extn.c

clean:
	rm -rfv *.o

