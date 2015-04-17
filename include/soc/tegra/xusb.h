/*
 * Copyright (C) 2014 NVIDIA Corporation
 * Copyright (C) 2014 Google, Inc.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 */

#ifndef __SOC_TEGRA_XUSB_H__
#define __SOC_TEGRA_XUSB_H__

struct regmap;

struct tegra_xusb {
	struct regmap *fpci_regs;
};

#endif /* __SOC_TEGRA_XUSB_H__ */
