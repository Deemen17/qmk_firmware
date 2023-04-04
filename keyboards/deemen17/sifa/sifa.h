/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#include "quantum.h"

#define XXX KC_NO

#define LAYOUT( \
	k0A, k0B, k0C, k0D, k0E, k0F, k0G, k0H, k0I, k0J, k0K, k0L, k0M, k0N, k2M, k0O, \
	k1A, k1B, k1C, k1D, k1E, k1F, k1G, k1H, k1I, k1J, k1K, k1L, k1M, k1N, 	   k1O, \
	k2A, k2B, k2C, k2D, k2E, k2F, k2G, k2H, k2I, k2J, k2K, k2L, 	 k2N, 	   k2O, \
	k3A, k3B, k3C, k3D, k3E, k3F, k3G, k3H, k3I, k3J, k3K, 		k3M, k3N,      k3O, \
	k4A, k4B, k4C, 				  k4G, 			 k4J, k4K, 		k4M, k4N,      k4O \
) { \
	{k0A, k0B, k0C, k0D, k0E, k0F, k0G, k0H, k0I, k0J, k0K, k0L, k0M, k0N, k0O}, \
	{k1A, k1B, k1C, k1D, k1E, k1F, k1G, k1H, k1I, k1J, k1K, k1L, k1M, k1N, k1O}, \
	{k2A, k2B, k2C, k2D, k2E, k2F, k2G, k2H, k2I, k2J, k2K, k2L, k2M, k2N, k2O}, \
	{k3A, k3B, k3C, k3D, k3E, k3F, k3G, k3H, k3I, k3J, k3K, XXX, k3M, k3N, k3O}, \
	{k4A, k4B, k4C, XXX, XXX, XXX, k4G, XXX, XXX, k4J, k4K, XXX, k4M, k4N, k4O} \
}
