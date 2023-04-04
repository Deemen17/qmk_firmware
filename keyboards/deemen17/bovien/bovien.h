#pragma once

#include "quantum.h"

#define XXX KC_NO

#define LAYOUT( \
	k0A, k0B, k0C, 		k0D, 	 k0E, k0F, k0G, k0H, k0I, k0J, k0K, k0L, k0M, k0N, k0O, k0P, k0Q, \
	k1A, k1B, k1C, 				 k1E, k1F, k1G, k1H, k1I, k1J, k1K, k1L, k1M, k1N, k1O, k1P, k1Q, \
	k2A, k2B, k2C, 		k2D,	 k2E,	   k2G, k2H, k2I, k2J, k2K, k2L, k2M, k2N, k2O, k2P, k2Q, \
	k3A, k3B, 	   k3C, k3D, k3E,	  k3F, k3G, k3H, 	  k3J, k3K, k3L, 	  k3N, k3O, k3P, k3Q \
) { \
	{k0A, k0B, k0C, k0D, k0E, k0F, k0G, k0H, k0I, k0J, k0K, k0L, k0M, k0N, k0O, k0P, k0Q}, \
	{k1A, k1B, k1C, XXX, k1E, k1F, k1G, k1H, k1I, k1J, k1K, k1L, k1M, k1N, k1O, k1P, k1Q}, \
	{k2A, k2B, k2C, k2D, k2E, XXX, k2G, k2H, k2I, k2J, k2K, k2L, k2M, k2N, k2O, k2P, k2Q}, \
	{k3A, k3B, k3C, k3D, k3E, k3F, k3G, k3H, XXX, k3J, k3K, k3L, XXX, k3N, k3O, k3P, k3Q} \
}
