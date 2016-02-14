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
*                                           HTTP SERVER TASK MODULE
*
* Filename      : http-s_task.h
* Version       : V3.00.01
* Programmer(s) : AA
*                 MM
*********************************************************************************************************
* Note(s)       : (1) See http-s.h file header.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*********************************************************************************************************
*                                               MODULE
*
* Note(s) : (1) This main network protocol suite header file is protected from multiple pre-processor
*               inclusion through use of the HTTPs module present pre-processor macro definition.
*********************************************************************************************************
*********************************************************************************************************
*/

#ifndef  HTTPs_TASK_MODULE_PRESENT                          /* See Note #1.                                         */
#define  HTTPs_TASK_MODULE_PRESENT


/*
*********************************************************************************************************
*********************************************************************************************************
*                                         INCLUDE FILES
*********************************************************************************************************
*********************************************************************************************************
*/

#include  <KAL/kal.h>
#include  <cpu.h>
#include  <cpu_core.h>

#include  "http-s.h"


/*
*********************************************************************************************************
*********************************************************************************************************
*                                          FUNCTION PROTOTYPES
*********************************************************************************************************
*********************************************************************************************************
*/

KAL_LOCK_HANDLE      HTTPsTask_LockCreate                   (HTTPs_ERR                 *p_err);

void                 HTTPsTask_LockAcquire                  (KAL_LOCK_HANDLE            os_lock_obj,
                                                             HTTPs_ERR                 *p_err);

void                 HTTPsTask_LockRelease                  (KAL_LOCK_HANDLE            os_lock_obj);

void                 HTTPsTask_InstanceObjInit              (HTTPs_INSTANCE            *p_instance,
                                                             HTTPs_ERR                 *p_err);

void                 HTTPsTask_InstanceTaskCreate           (HTTPs_INSTANCE            *p_instance,
                                                             HTTPs_ERR                 *p_err);

void                 HTTPsTask_InstanceTaskDel              (HTTPs_INSTANCE            *p_instance);

void                 HTTPsTask_InstanceStopReqSignal        (HTTPs_INSTANCE            *p_instance,
                                                             HTTPs_ERR                 *p_err);

CPU_BOOLEAN          HTTPsTask_InstanceStopReqPending       (HTTPs_INSTANCE            *p_instance);

void                 HTTPsTask_InstanceStopCompletedSignal  (HTTPs_INSTANCE            *p_instance);

void                 HTTPsTask_InstanceStopCompletedPending (HTTPs_INSTANCE            *p_instance,
                                                             HTTPs_ERR                 *p_err);

void                 HTTPsTask_TimeDly_ms                   (CPU_INT32U                 time_dly_ms);


/*
*********************************************************************************************************
*********************************************************************************************************
*                                             MODULE END
*********************************************************************************************************
*********************************************************************************************************
*/

#endif  /* HTTPs_TASK_MODULE_PRESENT  */
