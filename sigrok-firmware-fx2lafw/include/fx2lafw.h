/*
 * This file is part of the sigrok-firmware-fx2lafw project.
 *
 * Copyright (C) 2012 Joel Holdsworth <joel@airwebreathe.org.uk>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

#ifndef FX2LAFW_INCLUDE_FX2LAFW_H
#define FX2LAFW_INCLUDE_FX2LAFW_H

#include <autovector.h>

#define SYNCDELAY() SYNCDELAY4

/*
 * Major and minor fx2lafw firmware version numbers.
 * These can be queried by the host via CMD_GET_FW_VERSION.
 *
 * The minor version number must be increased every time there are
 * backwards-compatible changes (which do not change the API).
 *
 * The major version number must be increased every time there are API
 * changes or functional changes which require adaptations in the host
 * (libsigrok) drivers, i.e. changes where old libsigrok versions would no
 * longer (properly) work with the new fx2lafw firmware.
 */
#define FX2LAFW_VERSION_MAJOR	1
#define FX2LAFW_VERSION_MINOR	1

#endif
