/*
 * arch/arm/plat-meson/include/mach/plat-cpuidle.h
 *
 * MESON cpuidle driver
 *
 * Copyright (C) 2012 Amlogic
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 */

#include <linux/cpuidle.h>
#include <asm/proc-fns.h>


int meson_enter_idle_simple(struct cpuidle_device *dev,
			struct cpuidle_driver *drv,
			int index)
{
	local_fiq_disable();
//	printk("enter wfi.\n");
	cpu_do_idle();
//	printk("exit wfi.\n");

	local_fiq_enable();

	return index;
}

/*
 * Power off cpu
 */
int meson_enter_idle_cpu_off(struct cpuidle_device *dev,
			struct cpuidle_driver *drv,
			int index)
{
	return index;
}
