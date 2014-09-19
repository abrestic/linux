/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 2000, 07 MIPS Technologies, Inc.
 */
#ifndef _LINUX_IRQCHIP_MIPS_GIC_H
#define _LINUX_IRQCHIP_MIPS_GIC_H

#include <linux/clocksource.h>

#define GIC_MAX_INTRS			256

/* Local GIC interrupts. */
#define GIC_LOCAL_INT_WD	0 /* GIC watchdog */
#define GIC_LOCAL_INT_COMPARE	1 /* GIC count and compare timer */
#define GIC_LOCAL_INT_TIMER	2 /* CPU timer interrupt */
#define GIC_LOCAL_INT_PERFCTR	3 /* CPU performance counter */
#define GIC_LOCAL_INT_SWINT0	4 /* CPU software interrupt 0 */
#define GIC_LOCAL_INT_SWINT1	5 /* CPU software interrupt 1 */
#define GIC_LOCAL_INT_FDC	6 /* CPU fast debug channel */
#define GIC_NUM_LOCAL_INTRS	7

/* Convert between local/shared IRQ number and GIC HW IRQ number. */
#define GIC_LOCAL_HWIRQ_BASE	0
#define GIC_LOCAL_TO_HWIRQ(x)	(GIC_LOCAL_HWIRQ_BASE + (x))
#define GIC_HWIRQ_TO_LOCAL(x)	((x) - GIC_LOCAL_HWIRQ_BASE)
#define GIC_SHARED_HWIRQ_BASE	GIC_NUM_LOCAL_INTRS
#define GIC_SHARED_TO_HWIRQ(x)	(GIC_SHARED_HWIRQ_BASE + (x))
#define GIC_HWIRQ_TO_SHARED(x)	((x) - GIC_SHARED_HWIRQ_BASE)

extern unsigned int gic_present;

extern void gic_init(unsigned long gic_base_addr,
	unsigned long gic_addrspace_size, unsigned int cpu_vec,
	unsigned int irqbase);
extern void gic_clocksource_init(unsigned int);
extern cycle_t gic_read_count(void);
extern unsigned int gic_get_count_width(void);
extern cycle_t gic_read_compare(void);
extern void gic_write_compare(cycle_t cnt);
extern void gic_write_cpu_compare(cycle_t cnt, int cpu);
extern void gic_send_ipi(unsigned int intr);
extern unsigned int plat_ipi_call_int_xlate(unsigned int);
extern unsigned int plat_ipi_resched_int_xlate(unsigned int);
extern unsigned int gic_get_timer_pending(void);
extern int gic_get_c0_compare_int(void);
extern int gic_get_c0_perfcount_int(void);
#endif /* _LINUX_IRQCHIP_MIPS_GIC_H */
