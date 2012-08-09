/****************************************************************************
 * version.h
 *
 * Version header file for Funge98
 *
 * Copyright (C) 2012 Nirenjan Krishnan
 ****************************************************************************
 * This file is part of Funge98.
 *
 * Funge98 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Funge98 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public Licese for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Funge98. If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/
#ifndef _VERSION_H
#define _VERSION_H

/*
 * When updating the version number in this file, make sure to update all
 * the #define's so that they all match up.
 */
/* Binary name */
#define BIN_NAME            "Funge98"

/* Version number */
#define VERSION_TAG         "v1.0a"

/*
 * Sysinfo version number - used by 'y' command
 * Format - Major * 1000 + Minor * 100 + ord(Rev) - 0x60
 * Eg. v1.0a -> Major = 1; Minor = 0; Rev = a -> 1001
 */
#define SYSINFO_VERSION             1001

/* Handprint - used by 'y' command */
// TODO
#define SYSINFO_HANDPRINT           0xfc29e981

#endif /* !defined _VERSION_H */
