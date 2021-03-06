/*
 * drivers/misc/tegra-profiler/armv7_events.h
 *
 * Copyright (c) 2014, NVIDIA CORPORATION.  All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 */

#ifndef __ARMV7_EVENTS_H
#define __ARMV7_EVENTS_H

/*
 * PMNC Register
 */

 /* 0/1: disables/enables all counters, including CCNT */
#define QUADD_ARMV7_PMNC_E		(1 << 0)
/* 1: Resets all performance counters to zero. */
#define QUADD_ARMV7_PMNC_P		(1 << 1)
/* 1: Resets cycle counter, CCNT, to zero. */
#define QUADD_ARMV7_PMNC_C		(1 << 2)
/* 0: counts every processor clock cycle, reset value. 1:
   counts every 64th processor clock cycle. */
#define QUADD_ARMV7_PMNC_D		(1 << 3)
/* 0/1: Export to ETM disabled/enabled */
#define QUADD_ARMV7_PMNC_X		(1 << 4)
/* 0/1: count is disabled/enabled in regions where
   non-invasive debug is prohibited */
#define QUADD_ARMV7_PMNC_DP		(1 << 5)
/* Mask for writable bits */
#define	QUADD_ARMV7_PMNC_MASK		0x3f

/* Cycle counter */
#define QUADD_ARMV7_CCNT_BIT		31
#define QUADD_ARMV7_CCNT		(1 << QUADD_ARMV7_CCNT_BIT)

/*
 * CNTENS: counters enable reg
 */
#define QUADD_ARMV7_CNTENS_P(i)		(1 << i)
#define QUADD_ARMV7_CNTENS_C		(1 << QUADD_ARMV7_CCNT)

/*
 * CNTENC: counters disable reg
 */
#define QUADD_ARMV7_CNTENC_P(i)	(1 << i)
#define QUADD_ARMV7_CNTENC_C	(1 << QUADD_ARMV7_CCNT)

/*
 * Performance Counter Selection Register mask
 */
#define QUADD_ARMV7_SELECT_MASK	0x1f

/*
 * EVTSEL Register mask
 */
#define QUADD_ARMV7_EVTSEL_MASK	0xff

#define QUADD_ARMV7_COUNTERS_MASK_CORTEX_A5		0x03
#define QUADD_ARMV7_COUNTERS_MASK_CORTEX_A8		0x0f
#define QUADD_ARMV7_COUNTERS_MASK_CORTEX_A9		0x3f
#define QUADD_ARMV7_COUNTERS_MASK_CORTEX_A15		0x3f

enum quadd_armv7_common_events {
	QUADD_ARMV7_HW_EVENT_PMNC_SW_INCR		= 0x00,
	QUADD_ARMV7_HW_EVENT_IFETCH_MISS		= 0x01,
	QUADD_ARMV7_HW_EVENT_ITLB_MISS			= 0x02,
	QUADD_ARMV7_HW_EVENT_DCACHE_REFILL		= 0x03,
	QUADD_ARMV7_HW_EVENT_DCACHE_ACCESS		= 0x04,
	QUADD_ARMV7_HW_EVENT_DTLB_REFILL		= 0x05,
	QUADD_ARMV7_HW_EVENT_DREAD			= 0x06,
	QUADD_ARMV7_HW_EVENT_DWRITE			= 0x07,
	QUADD_ARMV7_HW_EVENT_INSTR_EXECUTED		= 0x08,
	QUADD_ARMV7_HW_EVENT_EXC_TAKEN			= 0x09,
	QUADD_ARMV7_HW_EVENT_EXC_EXECUTED		= 0x0A,
	QUADD_ARMV7_HW_EVENT_CID_WRITE			= 0x0B,
	QUADD_ARMV7_HW_EVENT_PC_WRITE			= 0x0C,
	QUADD_ARMV7_HW_EVENT_PC_IMM_BRANCH		= 0x0D,
	QUADD_ARMV7_HW_EVENT_PC_PROC_RETURN		= 0x0E,
	QUADD_ARMV7_HW_EVENT_UNALIGNED_ACCESS		= 0x0F,

	QUADD_ARMV7_HW_EVENT_PC_BRANCH_MIS_PRED		= 0x10,
	QUADD_ARMV7_HW_EVENT_CLOCK_CYCLES		= 0x11,
	QUADD_ARMV7_HW_EVENT_PC_BRANCH_PRED		= 0x12,
	QUADD_ARMV7_HW_EVENT_MEM_ACCESS			= 0x13,
	QUADD_ARMV7_HW_EVENT_L1_ICACHE_ACCESS		= 0x14,
	QUADD_ARMV7_HW_EVENT_L1_DCACHE_WB		= 0x15,
	QUADD_ARMV7_HW_EVENT_L2_DCACHE_ACCESS		= 0x16,
	QUADD_ARMV7_HW_EVENT_L2_DCACHE_REFILL		= 0x17,
	QUADD_ARMV7_HW_EVENT_L2_DCACHE_WB		= 0x18,
	QUADD_ARMV7_HW_EVENT_BUS_ACCESS			= 0x19,
	QUADD_ARMV7_HW_EVENT_MEMORY_ERROR		= 0x1A,
	QUADD_ARMV7_HW_EVENT_INSTR_SPEC			= 0x1B,
	QUADD_ARMV7_HW_EVENT_TTBR_WRITE			= 0x1C,
	QUADD_ARMV7_HW_EVENT_BUS_CYCLES			= 0x1D,
};

enum quadd_armv7_a8_specific_events {
	QUADD_ARMV7_A8_HW_EVENT_WRITE_BUFFER_FULL			= 0x40,
	QUADD_ARMV7_A8_HW_EVENT_L2_STORE_MERGED				= 0x41,
	QUADD_ARMV7_A8_HW_EVENT_L2_STORE_BUFF				= 0x42,
	QUADD_ARMV7_A8_HW_EVENT_L2_ACCESS				= 0x43,
	QUADD_ARMV7_A8_HW_EVENT_L2_CACH_MISS				= 0x44,
	QUADD_ARMV7_A8_HW_EVENT_AXI_READ_CYCLES				= 0x45,
	QUADD_ARMV7_A8_HW_EVENT_AXI_WRITE_CYCLES			= 0x46,
	QUADD_ARMV7_A8_HW_EVENT_MEMORY_REPLAY				= 0x47,
	QUADD_ARMV7_A8_HW_EVENT_UNALIGNED_ACCESS_REPLAY			= 0x48,
	QUADD_ARMV7_A8_HW_EVENT_L1_DATA_MISS				= 0x49,
	QUADD_ARMV7_A8_HW_EVENT_L1_INST_MISS				= 0x4A,
	QUADD_ARMV7_A8_HW_EVENT_L1_DATA_COLORING			= 0x4B,
	QUADD_ARMV7_A8_HW_EVENT_L1_NEON_DATA				= 0x4C,
	QUADD_ARMV7_A8_HW_EVENT_L1_NEON_CACH_DATA			= 0x4D,
	QUADD_ARMV7_A8_HW_EVENT_L2_NEON					= 0x4E,
	QUADD_ARMV7_A8_HW_EVENT_L2_NEON_HIT				= 0x4F,
	QUADD_ARMV7_A8_HW_EVENT_L1_INST					= 0x50,
	QUADD_ARMV7_A8_HW_EVENT_PC_RETURN_MIS_PRED			= 0x51,
	QUADD_ARMV7_A8_HW_EVENT_PC_BRANCH_FAILED			= 0x52,
	QUADD_ARMV7_A8_HW_EVENT_PC_BRANCH_TAKEN				= 0x53,
	QUADD_ARMV7_A8_HW_EVENT_PC_BRANCH_EXECUTED			= 0x54,
	QUADD_ARMV7_A8_HW_EVENT_OP_EXECUTED				= 0x55,
	QUADD_ARMV7_A8_HW_EVENT_CYCLES_INST_STALL			= 0x56,
	QUADD_ARMV7_A8_HW_EVENT_CYCLES_INST				= 0x57,
	QUADD_ARMV7_A8_HW_EVENT_CYCLES_NEON_DATA_STALL			= 0x58,
	QUADD_ARMV7_A8_HW_EVENT_CYCLES_NEON_INST_STALL			= 0x59,
	QUADD_ARMV7_A8_HW_EVENT_NEON_CYCLES				= 0x5A,

	QUADD_ARMV7_A8_HW_EVENT_PMU0_EVENTS				= 0x70,
	QUADD_ARMV7_A8_HW_EVENT_PMU1_EVENTS				= 0x71,
	QUADD_ARMV7_A8_HW_EVENT_PMU_EVENTS				= 0x72,
};

enum quadd_armv7_a9_specific_events {
	QUADD_ARMV7_A9_HW_EVENT_JAVA_HW_BYTECODE_EXEC			= 0x40,
	QUADD_ARMV7_A9_HW_EVENT_JAVA_SW_BYTECODE_EXEC			= 0x41,
	QUADD_ARMV7_A9_HW_EVENT_JAZELLE_BRANCH_EXEC			= 0x42,

	QUADD_ARMV7_A9_HW_EVENT_COHERENT_LINE_MISS			= 0x50,
	QUADD_ARMV7_A9_HW_EVENT_COHERENT_LINE_HIT			= 0x51,

	QUADD_ARMV7_A9_HW_EVENT_ICACHE_DEP_STALL_CYCLES			= 0x60,
	QUADD_ARMV7_A9_HW_EVENT_DCACHE_DEP_STALL_CYCLES			= 0x61,
	QUADD_ARMV7_A9_HW_EVENT_TLB_MISS_DEP_STALL_CYCLES		= 0x62,
	QUADD_ARMV7_A9_HW_EVENT_STREX_EXECUTED_PASSED			= 0x63,
	QUADD_ARMV7_A9_HW_EVENT_STREX_EXECUTED_FAILED			= 0x64,
	QUADD_ARMV7_A9_HW_EVENT_DATA_EVICTION				= 0x65,
	QUADD_ARMV7_A9_HW_EVENT_ISSUE_STAGE_NO_INST			= 0x66,
	QUADD_ARMV7_A9_HW_EVENT_ISSUE_STAGE_EMPTY			= 0x67,
	QUADD_ARMV7_A9_HW_EVENT_INST_OUT_OF_RENAME_STAGE		= 0x68,

	QUADD_ARMV7_A9_HW_EVENT_PREDICTABLE_FUNCT_RETURNS		= 0x6E,

	QUADD_ARMV7_A9_HW_EVENT_MAIN_UNIT_EXECUTED_INST			= 0x70,
	QUADD_ARMV7_A9_HW_EVENT_SECOND_UNIT_EXECUTED_INST		= 0x71,
	QUADD_ARMV7_A9_HW_EVENT_LD_ST_UNIT_EXECUTED_INST		= 0x72,
	QUADD_ARMV7_A9_HW_EVENT_FP_EXECUTED_INST			= 0x73,
	QUADD_ARMV7_A9_HW_EVENT_NEON_EXECUTED_INST			= 0x74,

	QUADD_ARMV7_A9_HW_EVENT_PLD_FULL_DEP_STALL_CYCLES		= 0x80,
	QUADD_ARMV7_A9_HW_EVENT_DATA_WR_DEP_STALL_CYCLES		= 0x81,
	QUADD_ARMV7_A9_HW_EVENT_ITLB_MISS_DEP_STALL_CYCLES		= 0x82,
	QUADD_ARMV7_A9_HW_EVENT_DTLB_MISS_DEP_STALL_CYCLES		= 0x83,
	QUADD_ARMV7_A9_HW_EVENT_MICRO_ITLB_MISS_DEP_STALL_CYCLES	= 0x84,
	QUADD_ARMV7_A9_HW_EVENT_MICRO_DTLB_MISS_DEP_STALL_CYCLES	= 0x85,
	QUADD_ARMV7_A9_HW_EVENT_DMB_DEP_STALL_CYCLES			= 0x86,

	QUADD_ARMV7_A9_HW_EVENT_INTGR_CLK_ENABLED_CYCLES		= 0x8A,
	QUADD_ARMV7_A9_HW_EVENT_DATA_ENGINE_CLK_EN_CYCLES		= 0x8B,

	QUADD_ARMV7_A9_HW_EVENT_ISB_INST				= 0x90,
	QUADD_ARMV7_A9_HW_EVENT_DSB_INST				= 0x91,
	QUADD_ARMV7_A9_HW_EVENT_DMB_INST				= 0x92,
	QUADD_ARMV7_A9_HW_EVENT_EXT_INTERRUPTS				= 0x93,

	QUADD_ARMV7_A9_HW_EVENT_PLE_CACHE_LINE_RQST_COMPLETED		= 0xA0,
	QUADD_ARMV7_A9_HW_EVENT_PLE_CACHE_LINE_RQST_SKIPPED		= 0xA1,
	QUADD_ARMV7_A9_HW_EVENT_PLE_FIFO_FLUSH				= 0xA2,
	QUADD_ARMV7_A9_HW_EVENT_PLE_RQST_COMPLETED			= 0xA3,
	QUADD_ARMV7_A9_HW_EVENT_PLE_FIFO_OVERFLOW			= 0xA4,
	QUADD_ARMV7_A9_HW_EVENT_PLE_RQST_PROG				= 0xA5
};

enum quadd_armv7_a5_specific_events {
	QUADD_ARMV7_A5_HW_EVENT_IRQ_TAKEN				= 0x86,
	QUADD_ARMV7_A5_HW_EVENT_FIQ_TAKEN				= 0x87,

	QUADD_ARMV7_A5_HW_EVENT_EXT_MEM_RQST				= 0xc0,
	QUADD_ARMV7_A5_HW_EVENT_NC_EXT_MEM_RQST				= 0xc1,
	QUADD_ARMV7_A5_HW_EVENT_PREFETCH_LINEFILL			= 0xc2,
	QUADD_ARMV7_A5_HW_EVENT_PREFETCH_LINEFILL_DROP			= 0xc3,
	QUADD_ARMV7_A5_HW_EVENT_ENTER_READ_ALLOC			= 0xc4,
	QUADD_ARMV7_A5_HW_EVENT_READ_ALLOC				= 0xc5,

	QUADD_ARMV7_A5_HW_EVENT_STALL_SB_FULL				= 0xc9,
};

enum quadd_armv7_a15_specific_events {
	QUADD_ARMV7_A15_HW_EVENT_L1_DCACHE_READ_ACCESS	= 0x40,
	QUADD_ARMV7_A15_HW_EVENT_L1_DCACHE_WRITE_ACCESS	= 0x41,
	QUADD_ARMV7_A15_HW_EVENT_L1_DCACHE_READ_REFILL	= 0x42,
	QUADD_ARMV7_A15_HW_EVENT_L1_DCACHE_WRITE_REFILL	= 0x43,

	QUADD_ARMV7_A15_HW_EVENT_L1_DTLB_READ_REFILL	= 0x4C,
	QUADD_ARMV7_A15_HW_EVENT_L1_DTLB_WRITE_REFILL	= 0x4D,

	QUADD_ARMV7_A15_HW_EVENT_L2_DCACHE_READ_ACCESS	= 0x50,
	QUADD_ARMV7_A15_HW_EVENT_L2_DCACHE_WRITE_ACCESS	= 0x51,
	QUADD_ARMV7_A15_HW_EVENT_L2_DCACHE_READ_REFILL	= 0x52,
	QUADD_ARMV7_A15_HW_EVENT_L2_DCACHE_WRITE_REFILL	= 0x53,

	QUADD_ARMV7_A15_HW_EVENT_SPEC_PC_WRITE		= 0x76,
};

#define QUADD_ARMV7_UNSUPPORTED_EVENT	0xff00
#define QUADD_ARMV7_CPU_CYCLE_EVENT	0xffff

#endif	/* __ARMV7_EVENTS_H */
