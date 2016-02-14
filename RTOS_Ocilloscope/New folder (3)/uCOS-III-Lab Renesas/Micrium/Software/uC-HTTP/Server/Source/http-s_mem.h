/*
*********************************************************************************************************
*                                               uC/HTTP
*                                      Hypertext Transfer Protocol
*
*                         (c) Copyright 2004-2015; Micrium, Inc.; Weston, FL
*
*                  All rights reserved.  Protected by international copyright laws.
*
*                  uC/HTTP is provided in source form to registered licensees ONLY.  It is
*                  illegal to distribute this source code to any third party unless you receive
*                  written permission by an authorized Micrium representative.  Knowledge of
*                  the source code may NOT be used to develop a similar product.
*
*                  Please help us continue to provide the Embedded community with the finest
*                  software available.  Your honesty is greatly appreciated.
*
*                  You can find our product's user manual, API reference, release notes and
*                  more information at: https://doc.micrium.com
*
*                  You can contact us at: http://www.micrium.com
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                     HTTP SERVER MEMORY LIBRARY
*
* Filename      : http-s_mem.h
* Version       : V3.00.01
* Programmer(s) : AA
*                 MM
*********************************************************************************************************
* Note(s)       : (1) See http-s.h file header
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*********************************************************************************************************
*                                               MODULE
*
* Note(s) : (1) This main network protocol suite header file is protected from multiple pre-processor
*               inclusion through use of the HTTP memory module present pre-processor macro definition.
*********************************************************************************************************
*********************************************************************************************************
*/

#ifndef  HTTPs_MEM_PRESENT                                          /* See Note #1.                                         */
#define  HTTPs_MEM_PRESENT

/*
*********************************************************************************************************
*********************************************************************************************************
*                                         HTTPs INCLUDE FILES
*********************************************************************************************************
*********************************************************************************************************
*/

#include  "http-s.h"

/*
*********************************************************************************************************
*********************************************************************************************************
*                                               EXTERNS
*********************************************************************************************************
*********************************************************************************************************
*/

#ifdef   HTTPs_MEM_MODULE
#define  HTTPs_MEM_EXT
#else
#define  HTTPs_MEM_EXT  extern
#endif


/*
*********************************************************************************************************
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*********************************************************************************************************
*/

                                                                /* Instance functionalities.            */
void                 HTTPsMem_InstanceInit                (MEM_SEG             *p_mem_seg,
                                                           HTTPs_ERR           *p_err);

HTTPs_OS_TASK_OBJ   *HTTPsMem_InstanceTaskInit            (HTTPs_ERR           *p_err);

HTTPs_INSTANCE      *HTTPsMem_InstanceGet                 (HTTPs_ERR           *p_err);

void                 HTTPsMem_InstanceRelease             (HTTPs_INSTANCE      *p_instance);

                                                                /* Conn functionalities.                */
void                 HTTPsMem_ConnPoolInit                (HTTPs_INSTANCE      *p_instance,
                                                           HTTPs_ERR           *p_err);

HTTPs_CONN          *HTTPsMem_ConnGet                     (HTTPs_INSTANCE      *p_instance,
                                                           NET_SOCK_ID          sock_id,
                                                           NET_SOCK_ADDR        client_addr);

void                 HTTPsMem_ConnRelease                 (HTTPs_INSTANCE      *p_instance,
                                                           HTTPs_CONN          *p_conn);

void                 HTTPsMem_ConnClr                     (HTTPs_INSTANCE      *p_instance,
                                                           HTTPs_CONN          *p_conn);

#if (HTTPs_CFG_TOKEN_PARSE_EN == DEF_ENABLED)
CPU_BOOLEAN          HTTPsMem_TokenGet                    (HTTPs_INSTANCE      *p_instance,
                                                           HTTPs_CONN          *p_conn,
                                                           HTTPs_ERR           *p_err);

void                 HTTPsMem_TokenRelease                (HTTPs_INSTANCE      *p_instance,
                                                           HTTPs_CONN          *p_conn);
#endif

#if (HTTPs_CFG_QUERY_STR_EN == DEF_ENABLED)
HTTPs_KEY_VAL       *HTTPsMem_QueryStrKeyValBlkGet        (HTTPs_INSTANCE      *p_instance,
                                                           HTTPs_CONN          *p_conn,
                                                           HTTPs_ERR           *p_err);

void                 HTTPsMem_QueryStrKeyValBlkReleaseAll (HTTPs_INSTANCE      *p_instance,
                                                           HTTPs_CONN          *p_conn);
#endif

#if (HTTPs_CFG_FORM_EN == DEF_ENABLED)
HTTPs_KEY_VAL       *HTTPsMem_FormKeyValBlkGet            (HTTPs_INSTANCE      *p_instance,
                                                           HTTPs_CONN          *p_conn,
                                                           HTTPs_ERR           *p_err);

void                 HTTPsMem_FormKeyValBlkReleaseAll     (HTTPs_INSTANCE      *p_instance,
                                                           HTTPs_CONN          *p_conn);
#endif

#if (HTTPs_CFG_HDR_RX_EN == DEF_ENABLED)
HTTPs_HDR_BLK       *HTTPsMem_ReqHdrGet                   (HTTPs_INSTANCE      *p_instance,
                                                           HTTPs_CONN          *p_conn,
                                                           HTTP_HDR_FIELD       hdr_fied,
                                                           HTTPs_HDR_VAL_TYPE   val_type,
                                                           HTTPs_ERR           *p_err);

void                 HTTPsMem_ReqHdrRelease               (HTTPs_INSTANCE      *p_instance,
                                                           HTTPs_CONN          *p_conn);
#endif

#if (HTTPs_CFG_HDR_TX_EN == DEF_ENABLED)
HTTPs_HDR_BLK       *HTTPsMem_RespHdrGet                  (HTTPs_INSTANCE      *p_instance,
                                                           HTTPs_CONN          *p_conn,
                                                           HTTP_HDR_FIELD       hdr_fied,
                                                           HTTPs_HDR_VAL_TYPE   val_type,
                                                           HTTPs_ERR           *p_err);

void                 HTTPsMem_RespHdrRelease              (HTTPs_INSTANCE      *p_instance,
                                                           HTTPs_CONN          *p_conn);
#endif


/*
*********************************************************************************************************
*********************************************************************************************************
*                                             MODULE END
*********************************************************************************************************
*********************************************************************************************************
*/

#endif                                                          /* End of HTTPs mem module include.                     */

