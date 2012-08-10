#############################################################################
# Makefile
#
# Makefile for Funge98 memory manager
#
# Copyright (C) 2012 Nirenjan Krishnan
#############################################################################
# This file is part of Funge98.
#
# Funge98 is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Funge98 is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public Licese for more details.
#
# You should have received a copy of the GNU General Public License
# along with Funge98. If not, see <http://www.gnu.org/licenses/>.
#############################################################################

CC=gcc

funge_stack.o: funge_stack.c funge_stack.h funge_const.h
	$(CC) -c funge_stack.c

all: funge_stack.o

clean:
	rm -f *.o

