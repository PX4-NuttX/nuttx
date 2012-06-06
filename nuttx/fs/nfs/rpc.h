/****************************************************************************
 * fs/nfs/rpc.h
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Copyright (C) 2012 Jose Pablo Rojas Vargas. All rights reserved.
 *   Author: Jose Pablo Rojas Vargas <jrojas@nx-engineering.com>
 *
 * Leveraged from OpenBSD:
 *
 *   copyright (c) 2003
 *   the regents of the university of michigan
 *   all rights reserved
 *
 * permission is granted to use, copy, create derivative works and redistribute
 * this software and such derivative works for any purpose, so long as the name
 * of the university of michigan is not used in any advertising or publicity
 * pertaining to the use or distribution of this software without specific,
 * written prior authorization.  if the above copyright notice or any other
 * identification of the university of michigan is included in any copy of any
 * portion of this software, then the disclaimer below must also be included.
 *
 * this software is provided as is, without representation from the university
 * of michigan as to its fitness for any purpose, and without warranty by the
 * university of michigan of any kind, either express or implied, including
 * without limitation the implied warranties of merchantability and fitness for
 * a particular purpose. the regents of the university of michigan shall not be
 * liable for any damages, including special, indirect, incidental, or
 * consequential damages, with respect to any claim arising out of or in
 * connection with the use of the software, even if it has been or is hereafter
 * advised of the possibility of such damages.
 *
 *   Copyright (c) 1989, 1993
 *   The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Rick Macklem at The University of Guelph.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by the University of
 *      California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 ****************************************************************************/

#ifndef __FS_NFS_RPC_H
#define __FS_NFS_RPC_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <sys/types.h>
#include "nfs_proto.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Version # */

#define RPC_VER2         2

/* Authentication */

#define RPCAUTH_NULL     0
#define RPCAUTH_UNIX     1
#define RPCAUTH_SHORT    2
#define RPCAUTH_KERB4    4
#define RPCAUTH_MAXSIZ   400
#define RPCVERF_MAXSIZ   12
                                /* For Kerb, can actually be 400 */
#define RPCAUTH_UNIXGIDS 16

/* Constants associated with authentication flavours. */

#define RPCAKN_FULLNAME  0
#define RPCAKN_NICKNAME  1

/* Rpc Constants */

#define RPC_CALL         0
#define RPC_REPLY        1
#define RPC_MSGACCEPTED  0
#define RPC_MSGDENIED    1
#define RPC_PROGUNAVAIL  1
#define RPC_PROGMISMATCH 2
#define RPC_PROCUNAVAIL  3
#define RPC_GARBAGE      4

#define RPC_MISMATCH     0
#define RPC_AUTHERR      1

/* Authentication failures */

#define AUTH_BADCRED     1
#define AUTH_REJECTCRED  2
#define AUTH_BADVERF     3
#define AUTH_REJECTVERF  4
#define AUTH_TOOWEAK     5

/* Sizes of rpc header parts */

#define RPC_SIZ          24
#define RPC_REPLYSIZ     28

/* RPC Prog definitions */

#define RPCPROG_MNT      100005
#define RPCMNT_VER1      1
#define RPCMNT_VER3      3
#define RPCMNT_MOUNT     1
#define RPCMNT_DUMP      2
#define RPCMNT_UMOUNT    3
#define RPCMNT_UMNTALL   4
#define RPCMNT_EXPORT    5
#define RPCMNT_NAMELEN   255
#define RPCMNT_PATHLEN   1024
#define RPCPROG_NFS      100003

/* for rpcclnt's rc_flags */

#define RPCCLNT_SOFT     0x001 /* soft mount (hard is details) */
#define RPCCLNT_INT      0x002 /* allow interrupts on hard mounts */
#define RPCCLNT_NOCONN   0x004 /* dont connect the socket (udp) */
#define RPCCLNT_DUMBTIMR 0x010

/* XXX should be replaced with real locks */

#define RPCCLNT_SNDLOCK  0x100
#define RPCCLNT_WANTSND  0x200
#define RPCCLNT_RCVLOCK  0x400
#define RPCCLNT_WANTRCV  0x800

/* RPC definitions for the portmapper. */

#define PMAPPORT         111
#define PMAPPROG         100000
#define PMAPVERS         2
#define PMAPPROC_NULL    0
#define PMAPPROC_SET     1
#define PMAPPROC_UNSET   2
#define PMAPPROC_GETPORT 3
#define PMAPPROC_DUMP    4
#define PMAPPROC_CALLIT  5

#define RPCCLNT_DEBUG    1

#define RPC_TICKINTVL    5

/* from nfs/nfsproto.h */

#define RPC_MAXDATA      32768
#define RPC_MAXPKTHDR    404
#define RPC_MAXPACKET    (RPC_MAXPKTHDR + RPC_MAXDATA)

#define RPCX_UNSIGNED    4

#define RPC_SUCCESS      0

/* Flag values for r_flags */

#define TASK_TIMING      0x01            /* timing request (in mntp) */
#define TASK_SENT        0x02            /* request has been sent */
#define TASK_SOFTTERM    0x04            /* soft mnt, too many retries */


#define TASK_INTR        0x08            /* intr mnt, signal pending */
#define TASK_SOCKERR     0x10            /* Fatal error on socket */


#define TASK_TPRINTFMSG  0x20            /* Did a tprintf msg. */

#define TASK_MUSTRESEND  0x40            /* Must resend request */
#define TASK_GETONEREP   0x80            /* Probe for one reply only */


#define RPC_HZ           (CLOCKS_PER_SEC / rpcclnt_ticks) /* Ticks/sec */
#define RPC_TIMEO        (1 * RPC_HZ)    /* Default timeout = 1 second */

#define RPC_MAXREXMIT    100             /* Stop counting after this many */


#define RPCIGNORE_SOERROR(s, e) \
                        ((e) != EINTR && (e) != ERESTART && (e) != EWOULDBLOCK)

#define RPCINT_SIGMASK  (sigmask(SIGINT)|sigmask(SIGTERM)|sigmask(SIGKILL)| \
                         sigmask(SIGHUP)|sigmask(SIGQUIT))

#define RPCMADV(m, s)   (m)->m_data += (s)

#define RPCAUTH_ROOTCREDS NULL

#define RPCCLNTINT_SIGMASK(set)             \
  (SIGISMEMBER(set, SIGINT) || SIGISMEMBER(set, SIGTERM) || \
         SIGISMEMBER(set, SIGHUP) || SIGISMEMBER(set, SIGKILL) || \
         SIGISMEMBER(set, SIGQUIT))

/****************************************************************************
 * Public Types
 ****************************************************************************/

struct xidr
{
  uint32_t xid;
};

/* global rpcstats */

struct rpcstats
{
  int rpcretries;
  int rpcrequests;
  int rpctimeouts;
  int rpcunexpected;
  int rpcinvalid;
};

/* PMAP headers */
struct call_args_pmap
{
  uint32_t prog;
  uint32_t vers;
  uint32_t proc;
  uint32_t port;
};

struct call_result_pmap
{
  uint32_t port;
};

/* MOUNTD headers */

struct call_args_mount
{
  uint32_t len;
  char rpath[90];
};

struct call_result_mount
{
  uint32_t status;
  nfsfh_t fhandle;
};

/* Generic RPC call headers */

enum auth_flavor
{
  AUTH_NONE  = 0,
  AUTH_SYS   = 1,
  AUTH_SHORT = 2
  /* and more to be defined */
};

struct rpc_auth_info
{
  enum auth_flavor authtype;  /* auth type */
  uint32_t authlen;           /* auth length */
};

struct auth_unix
{
  int32_t stamp;
  unsigned char hostname;     /* null */
  int32_t uid;
  int32_t gid;
  int32_t gidlist;            /* null */
};

struct rpc_call_header
{
  uint32_t rp_xid;            /* request transaction id */
  int32_t  rp_direction;      /* call direction (0) */
  uint32_t rp_rpcvers;        /* rpc version (2) */
  uint32_t rp_prog;           /* program */
  uint32_t rp_vers;           /* version */
  uint32_t rp_proc;           /* procedure */
  struct rpc_auth_info rpc_auth;
#ifdef CONFIG_NFS_UNIX_AUTH
  struct auth_unix rpc_unix;
#endif
  struct rpc_auth_info rpc_verf;
};

struct rpc_call_pmap
{
  struct rpc_call_header ch;
  struct call_args_pmap pmap;
};

struct rpc_call_mount
{
  struct rpc_call_header ch;
  struct call_args_mount mount;
};

struct rpc_call_create
{
  struct rpc_call_header ch;
  struct CREATE3args create;
};

struct rpc_call_read
{
  struct rpc_call_header ch;
  struct READ3args read;
};

struct rpc_call_write
{
  struct rpc_call_header ch;
  struct WRITE3args write;
};

struct rpc_call_remove
{
  struct rpc_call_header ch;
  struct REMOVE3args remove;
};

struct rpc_call_rename
{
  struct rpc_call_header ch;
  struct RENAME3args rename;
};

struct rpc_call_mkdir
{
  struct rpc_call_header ch;
  struct MKDIR3args mkdir;
};

struct rpc_call_rmdir
{
  struct rpc_call_header ch;
  struct RMDIR3args rmdir;
};

struct rpc_call_readdir
{
  struct rpc_call_header ch;
  struct READDIR3args readdir;
};

struct rpc_call_fs
{
  struct rpc_call_header ch;
  struct FS3args fs;
};

/* Generic RPC reply headers */

struct rpc_reply_header
{
  uint32_t rp_xid;            /* request transaction id */
  uint32_t rp_direction;       /* call direction (1) */
  uint32_t type;
  struct rpc_auth_info rpc_verfi;
  uint32_t status;
};

struct rpc_reply_pmap
{
  struct rpc_reply_header rh;
  struct call_result_pmap pmap;
};

struct rpc_reply_mount
{
  struct rpc_reply_header rh;
  struct call_result_mount mount;
};

struct rpc_reply_create
{
  struct rpc_reply_header rh;
  struct CREATE3resok create;
};

struct rpc_reply_write
{
  struct rpc_reply_header rh;
  struct WRITE3resok write;
};

struct rpc_reply_read
{
  struct rpc_reply_header rh;
  struct READ3resok read;
};

struct rpc_reply_remove
{
  struct rpc_reply_header rh;
  struct REMOVE3resok remove;
};

struct rpc_reply_rename
{
  struct rpc_reply_header rh;
  struct RENAME3resok rename;
};

struct rpc_reply_mkdir
{
  struct rpc_reply_header rh;
  struct MKDIR3resok mkdir;
};

struct rpc_reply_rmdir
{
  struct rpc_reply_header rh;
  struct RMDIR3resok rmdir;
};

struct rpc_reply_readdir
{
  struct rpc_reply_header rh;
  struct READDIR3resok readdir;
};

struct rpc_reply_fsinfo
{
  struct rpc_reply_header rh;
  struct nfsv3_fsinfo fsinfo;
};

struct rpc_reply_fsstat
{
  struct rpc_reply_header rh;
  struct nfs_statfs fsstat;
};

struct rpc_reply_getattr
{
  struct rpc_reply_header rh;
  uint32_t status;
  struct nfs_fattr attr;
};

/* RPC Client connection context. One allocated on every NFS mount.
 * Holds RPC specific information for mount.
 */

struct rpc_program
{
  uint32_t prog_id;
  uint32_t prog_version;
  char    *prog_name;
};

struct rpctask
{
  dq_entry_t      r_chain;
  struct rpcclnt *r_rpcclnt;
  uint32_t        r_xid;
  int             r_flags;    /* flags on request, see below */
  int             r_retry;    /* max retransmission count */
  int             r_rexmit;   /* current retrans count */
  int             r_timer;    /* tick counter on reply */
  int             r_procnum;  /* NFS procedure number */
  int             r_rtt;      /* RTT for rpc */
};

struct  rpcclnt
{
  int     rc_flag;            /* For RPCCLNT_* flags  */

  int     rc_wsize;           /* Max size of the request data */
  int     rc_rsize;           /* Max size of the response data */
  nfsfh_t rc_fh;              /* File handle of root dir */
  char    *rc_path;           /* server's path of the directory being mount */

  struct  sockaddr *rc_name;
  struct  socket *rc_so;      /* Rpc socket */

  uint8_t rc_sotype;          /* Type of socket */
  int     rc_soproto;         /* and protocol */
  uint8_t rc_soflags;         /* pr_flags for socket protocol */

  int     rc_timeo;           /* Init timer for NFSMNT_DUMBTIMR */
  int     rc_retry;           /* Max retries */
  int     rc_srtt[4];         /* Timers for rpcs */
  int     rc_sdrtt[4];
  int     rc_sent;            /* Request send count */
  int     rc_cwnd;            /* Request send window */
  int     rc_timeouts;        /* Request timeouts */

//int     rc_deadthresh;      /* Threshold of timeouts-->dead server*/

  /* authentication: */
  /* currently can be RPCAUTH_NULL, RPCAUTH_KERBV4, RPCAUTH_UNIX */
  /* should be kept in XDR form */

// int     rc_authtype;      /* Authenticator type */
#ifdef CONFIG_NFS_UNIX_AUTH
  /* RPCAUTH_UNIX*/

  struct rpc_auth_info rc_oldauth; /* authentication */
#endif
//void                *rc_auth;

  struct rpc_program  *rc_prog;

//char *rc_servername;

  int rc_proctlen;            /* if == 0 then rc_proct == NULL */
  int *rc_proct;
};

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

void rpcclnt_init(void);
int  rpcclnt_connect(struct rpcclnt *);
int  rpcclnt_reconnect(struct rpctask *);
void rpcclnt_disconnect(struct rpcclnt *);
int  rpcclnt_umount(struct rpcclnt *);
void rpcclnt_safedisconnect(struct rpcclnt *);
int  rpcclnt_request(struct rpcclnt *, int, int, int, void *, FAR const void *);
#undef COMP
#ifdef COMP
int  rpcclnt_cancelreqs(struct rpcclnt *);
#endif

#endif /* _RPCCLNT_H_ */
