#ifndef __iop_dmc_out_defs_h
#define __iop_dmc_out_defs_h

/*
 * This file is autogenerated from
 *   file:           ../../inst/io_proc/rtl/iop_dmc_out.r
 *     id:           iop_dmc_out.r,v 1.30 2005/02/16 09:14:11 niklaspa Exp
 *     last modfied: Mon Apr 11 16:08:45 2005
 *
 *   by /n/asic/design/tools/rdesc/src/rdes2c --outfile iop_dmc_out_defs.h ../../inst/io_proc/rtl/iop_dmc_out.r
 *      id: $Id: iop_dmc_out_defs.h,v 1.1.2.1 2011/07/04 16:21:28 lino Exp $
 * Any changes here will be lost.
 *
 * -*- buffer-read-only: t -*-
 */
/* Main access macros */
#ifndef REG_RD
#define REG_RD( scope, inst, reg ) \
  REG_READ( reg_##scope##_##reg, \
            (inst) + REG_RD_ADDR_##scope##_##reg )
#endif

#ifndef REG_WR
#define REG_WR( scope, inst, reg, val ) \
  REG_WRITE( reg_##scope##_##reg, \
             (inst) + REG_WR_ADDR_##scope##_##reg, (val) )
#endif

#ifndef REG_RD_VECT
#define REG_RD_VECT( scope, inst, reg, index ) \
  REG_READ( reg_##scope##_##reg, \
            (inst) + REG_RD_ADDR_##scope##_##reg + \
	    (index) * STRIDE_##scope##_##reg )
#endif

#ifndef REG_WR_VECT
#define REG_WR_VECT( scope, inst, reg, index, val ) \
  REG_WRITE( reg_##scope##_##reg, \
             (inst) + REG_WR_ADDR_##scope##_##reg + \
	     (index) * STRIDE_##scope##_##reg, (val) )
#endif

#ifndef REG_RD_INT
#define REG_RD_INT( scope, inst, reg ) \
  REG_READ( int, (inst) + REG_RD_ADDR_##scope##_##reg )
#endif

#ifndef REG_WR_INT
#define REG_WR_INT( scope, inst, reg, val ) \
  REG_WRITE( int, (inst) + REG_WR_ADDR_##scope##_##reg, (val) )
#endif

#ifndef REG_RD_INT_VECT
#define REG_RD_INT_VECT( scope, inst, reg, index ) \
  REG_READ( int, (inst) + REG_RD_ADDR_##scope##_##reg + \
	    (index) * STRIDE_##scope##_##reg )
#endif

#ifndef REG_WR_INT_VECT
#define REG_WR_INT_VECT( scope, inst, reg, index, val ) \
  REG_WRITE( int, (inst) + REG_WR_ADDR_##scope##_##reg + \
	     (index) * STRIDE_##scope##_##reg, (val) )
#endif

#ifndef REG_TYPE_CONV
#define REG_TYPE_CONV( type, orgtype, val ) \
  ( { union { orgtype o; type n; } r; r.o = val; r.n; } )
#endif

#ifndef reg_page_size
#define reg_page_size 8192
#endif

#ifndef REG_ADDR
#define REG_ADDR( scope, inst, reg ) \
  ( (inst) + REG_RD_ADDR_##scope##_##reg )
#endif

#ifndef REG_ADDR_VECT
#define REG_ADDR_VECT( scope, inst, reg, index ) \
  ( (inst) + REG_RD_ADDR_##scope##_##reg + \
    (index) * STRIDE_##scope##_##reg )
#endif

/* C-code for register scope iop_dmc_out */

/* Register rw_cfg, scope iop_dmc_out, type rw */
typedef struct {
  unsigned int trf_lim         : 16;
  unsigned int last_at_trf_lim : 1;
  unsigned int dth_intr        : 3;
  unsigned int dummy1          : 12;
} reg_iop_dmc_out_rw_cfg;
#define REG_RD_ADDR_iop_dmc_out_rw_cfg 0
#define REG_WR_ADDR_iop_dmc_out_rw_cfg 0

/* Register rw_ctrl, scope iop_dmc_out, type rw */
typedef struct {
  unsigned int dif_en  : 1;
  unsigned int dif_dis : 1;
  unsigned int dummy1  : 30;
} reg_iop_dmc_out_rw_ctrl;
#define REG_RD_ADDR_iop_dmc_out_rw_ctrl 4
#define REG_WR_ADDR_iop_dmc_out_rw_ctrl 4

/* Register r_stat, scope iop_dmc_out, type r */
typedef struct {
  unsigned int dif_en : 1;
  unsigned int dummy1 : 31;
} reg_iop_dmc_out_r_stat;
#define REG_RD_ADDR_iop_dmc_out_r_stat 8

/* Register rw_stream_cmd, scope iop_dmc_out, type rw */
typedef struct {
  unsigned int cmd : 10;
  unsigned int dummy1 : 6;
  unsigned int n   : 8;
  unsigned int dummy2 : 8;
} reg_iop_dmc_out_rw_stream_cmd;
#define REG_RD_ADDR_iop_dmc_out_rw_stream_cmd 12
#define REG_WR_ADDR_iop_dmc_out_rw_stream_cmd 12

/* Register rs_stream_data, scope iop_dmc_out, type rs */
typedef unsigned int reg_iop_dmc_out_rs_stream_data;
#define REG_RD_ADDR_iop_dmc_out_rs_stream_data 16

/* Register r_stream_data, scope iop_dmc_out, type r */
typedef unsigned int reg_iop_dmc_out_r_stream_data;
#define REG_RD_ADDR_iop_dmc_out_r_stream_data 20

/* Register r_stream_stat, scope iop_dmc_out, type r */
typedef struct {
  unsigned int dth            : 7;
  unsigned int dummy1         : 9;
  unsigned int dv             : 1;
  unsigned int all_avail      : 1;
  unsigned int last           : 1;
  unsigned int size           : 3;
  unsigned int data_md_valid  : 1;
  unsigned int ctxt_md_valid  : 1;
  unsigned int group_md_valid : 1;
  unsigned int stream_busy    : 1;
  unsigned int cmd_rdy        : 1;
  unsigned int cmd_rq         : 1;
  unsigned int dummy2         : 4;
} reg_iop_dmc_out_r_stream_stat;
#define REG_RD_ADDR_iop_dmc_out_r_stream_stat 24

/* Register r_data_descr, scope iop_dmc_out, type r */
typedef struct {
  unsigned int ctrl : 8;
  unsigned int stat : 8;
  unsigned int md   : 16;
} reg_iop_dmc_out_r_data_descr;
#define REG_RD_ADDR_iop_dmc_out_r_data_descr 28

/* Register r_ctxt_descr, scope iop_dmc_out, type r */
typedef struct {
  unsigned int ctrl : 8;
  unsigned int stat : 8;
  unsigned int md0  : 16;
} reg_iop_dmc_out_r_ctxt_descr;
#define REG_RD_ADDR_iop_dmc_out_r_ctxt_descr 32

/* Register r_ctxt_descr_md1, scope iop_dmc_out, type r */
typedef unsigned int reg_iop_dmc_out_r_ctxt_descr_md1;
#define REG_RD_ADDR_iop_dmc_out_r_ctxt_descr_md1 36

/* Register r_ctxt_descr_md2, scope iop_dmc_out, type r */
typedef unsigned int reg_iop_dmc_out_r_ctxt_descr_md2;
#define REG_RD_ADDR_iop_dmc_out_r_ctxt_descr_md2 40

/* Register r_group_descr, scope iop_dmc_out, type r */
typedef struct {
  unsigned int ctrl : 8;
  unsigned int stat : 8;
  unsigned int md   : 16;
} reg_iop_dmc_out_r_group_descr;
#define REG_RD_ADDR_iop_dmc_out_r_group_descr 52

/* Register rw_data_descr, scope iop_dmc_out, type rw */
typedef struct {
  unsigned int dummy1 : 16;
  unsigned int md : 16;
} reg_iop_dmc_out_rw_data_descr;
#define REG_RD_ADDR_iop_dmc_out_rw_data_descr 56
#define REG_WR_ADDR_iop_dmc_out_rw_data_descr 56

/* Register rw_ctxt_descr, scope iop_dmc_out, type rw */
typedef struct {
  unsigned int dummy1 : 16;
  unsigned int md0 : 16;
} reg_iop_dmc_out_rw_ctxt_descr;
#define REG_RD_ADDR_iop_dmc_out_rw_ctxt_descr 60
#define REG_WR_ADDR_iop_dmc_out_rw_ctxt_descr 60

/* Register rw_ctxt_descr_md1, scope iop_dmc_out, type rw */
typedef unsigned int reg_iop_dmc_out_rw_ctxt_descr_md1;
#define REG_RD_ADDR_iop_dmc_out_rw_ctxt_descr_md1 64
#define REG_WR_ADDR_iop_dmc_out_rw_ctxt_descr_md1 64

/* Register rw_ctxt_descr_md2, scope iop_dmc_out, type rw */
typedef unsigned int reg_iop_dmc_out_rw_ctxt_descr_md2;
#define REG_RD_ADDR_iop_dmc_out_rw_ctxt_descr_md2 68
#define REG_WR_ADDR_iop_dmc_out_rw_ctxt_descr_md2 68

/* Register rw_group_descr, scope iop_dmc_out, type rw */
typedef struct {
  unsigned int dummy1 : 16;
  unsigned int md : 16;
} reg_iop_dmc_out_rw_group_descr;
#define REG_RD_ADDR_iop_dmc_out_rw_group_descr 80
#define REG_WR_ADDR_iop_dmc_out_rw_group_descr 80

/* Register rw_intr_mask, scope iop_dmc_out, type rw */
typedef struct {
  unsigned int data_md   : 1;
  unsigned int ctxt_md   : 1;
  unsigned int group_md  : 1;
  unsigned int cmd_rdy   : 1;
  unsigned int dth       : 1;
  unsigned int dv        : 1;
  unsigned int last_data : 1;
  unsigned int trf_lim   : 1;
  unsigned int cmd_rq    : 1;
  unsigned int dummy1    : 23;
} reg_iop_dmc_out_rw_intr_mask;
#define REG_RD_ADDR_iop_dmc_out_rw_intr_mask 84
#define REG_WR_ADDR_iop_dmc_out_rw_intr_mask 84

/* Register rw_ack_intr, scope iop_dmc_out, type rw */
typedef struct {
  unsigned int data_md   : 1;
  unsigned int ctxt_md   : 1;
  unsigned int group_md  : 1;
  unsigned int cmd_rdy   : 1;
  unsigned int dth       : 1;
  unsigned int dv        : 1;
  unsigned int last_data : 1;
  unsigned int trf_lim   : 1;
  unsigned int cmd_rq    : 1;
  unsigned int dummy1    : 23;
} reg_iop_dmc_out_rw_ack_intr;
#define REG_RD_ADDR_iop_dmc_out_rw_ack_intr 88
#define REG_WR_ADDR_iop_dmc_out_rw_ack_intr 88

/* Register r_intr, scope iop_dmc_out, type r */
typedef struct {
  unsigned int data_md   : 1;
  unsigned int ctxt_md   : 1;
  unsigned int group_md  : 1;
  unsigned int cmd_rdy   : 1;
  unsigned int dth       : 1;
  unsigned int dv        : 1;
  unsigned int last_data : 1;
  unsigned int trf_lim   : 1;
  unsigned int cmd_rq    : 1;
  unsigned int dummy1    : 23;
} reg_iop_dmc_out_r_intr;
#define REG_RD_ADDR_iop_dmc_out_r_intr 92

/* Register r_masked_intr, scope iop_dmc_out, type r */
typedef struct {
  unsigned int data_md   : 1;
  unsigned int ctxt_md   : 1;
  unsigned int group_md  : 1;
  unsigned int cmd_rdy   : 1;
  unsigned int dth       : 1;
  unsigned int dv        : 1;
  unsigned int last_data : 1;
  unsigned int trf_lim   : 1;
  unsigned int cmd_rq    : 1;
  unsigned int dummy1    : 23;
} reg_iop_dmc_out_r_masked_intr;
#define REG_RD_ADDR_iop_dmc_out_r_masked_intr 96


/* Constants */
enum {
  regk_iop_dmc_out_ack_pkt                 = 0x00000100,
  regk_iop_dmc_out_array                   = 0x00000008,
  regk_iop_dmc_out_burst                   = 0x00000020,
  regk_iop_dmc_out_copy_next               = 0x00000010,
  regk_iop_dmc_out_copy_up                 = 0x00000020,
  regk_iop_dmc_out_dis_c                   = 0x00000010,
  regk_iop_dmc_out_dis_g                   = 0x00000020,
  regk_iop_dmc_out_lim1                    = 0x00000000,
  regk_iop_dmc_out_lim16                   = 0x00000004,
  regk_iop_dmc_out_lim2                    = 0x00000001,
  regk_iop_dmc_out_lim32                   = 0x00000005,
  regk_iop_dmc_out_lim4                    = 0x00000002,
  regk_iop_dmc_out_lim64                   = 0x00000006,
  regk_iop_dmc_out_lim8                    = 0x00000003,
  regk_iop_dmc_out_load_c                  = 0x00000200,
  regk_iop_dmc_out_load_c_n                = 0x00000280,
  regk_iop_dmc_out_load_c_next             = 0x00000240,
  regk_iop_dmc_out_load_d                  = 0x00000140,
  regk_iop_dmc_out_load_g                  = 0x00000300,
  regk_iop_dmc_out_load_g_down             = 0x000003c0,
  regk_iop_dmc_out_load_g_next             = 0x00000340,
  regk_iop_dmc_out_load_g_up               = 0x00000380,
  regk_iop_dmc_out_next_en                 = 0x00000010,
  regk_iop_dmc_out_next_pkt                = 0x00000010,
  regk_iop_dmc_out_no                      = 0x00000000,
  regk_iop_dmc_out_restore                 = 0x00000020,
  regk_iop_dmc_out_rw_cfg_default          = 0x00000000,
  regk_iop_dmc_out_rw_ctxt_descr_default   = 0x00000000,
  regk_iop_dmc_out_rw_ctxt_descr_md1_default = 0x00000000,
  regk_iop_dmc_out_rw_ctxt_descr_md2_default = 0x00000000,
  regk_iop_dmc_out_rw_data_descr_default   = 0x00000000,
  regk_iop_dmc_out_rw_group_descr_default  = 0x00000000,
  regk_iop_dmc_out_rw_intr_mask_default    = 0x00000000,
  regk_iop_dmc_out_save_down               = 0x00000020,
  regk_iop_dmc_out_save_up                 = 0x00000020,
  regk_iop_dmc_out_set_reg                 = 0x00000050,
  regk_iop_dmc_out_set_w_size1             = 0x00000190,
  regk_iop_dmc_out_set_w_size2             = 0x000001a0,
  regk_iop_dmc_out_set_w_size4             = 0x000001c0,
  regk_iop_dmc_out_store_c                 = 0x00000002,
  regk_iop_dmc_out_store_descr             = 0x00000000,
  regk_iop_dmc_out_store_g                 = 0x00000004,
  regk_iop_dmc_out_store_md                = 0x00000001,
  regk_iop_dmc_out_update_down             = 0x00000020,
  regk_iop_dmc_out_yes                     = 0x00000001
};
#endif /* __iop_dmc_out_defs_h */
