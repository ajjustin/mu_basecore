/** @file
*  Main file supporting the SEC Phase on ARM PLatforms
*
*  Copyright (c) 2011, ARM Limited. All rights reserved.
*
*  This program and the accompanying materials
*  are licensed and made available under the terms and conditions of the BSD License
*  which accompanies this distribution.  The full text of the license may be found at
*  http://opensource.org/licenses/bsd-license.php
*
*  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
*  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
*
**/

#ifndef __SEC_H__
#define __SEC_H__

#include <Base.h>
#include <Library/BaseLib.h>
#include <Library/DebugLib.h>

#include <Chipset/ArmV7.h>

#define IS_ALIGNED(Address, Align) (((UINTN)Address & (Align-1)) == 0)

VOID
ArmSetupGicNonSecure (
  IN  INTN          GicDistributorBase,
  IN  INTN          GicInterruptInterfaceBase
);

// Vector Table for Sec Phase
VOID
SecVectorTable (
  VOID
  );

VOID
NonSecureWaitForFirmware (
  VOID
  );

VOID
enter_monitor_mode (
  IN VOID* Stack
  );

VOID
return_from_exception (
  IN UINTN NonSecureBase
  );

VOID
copy_cpsr_into_spsr (
  VOID
  );

VOID
SecCommonExceptionEntry (
  IN UINT32 Entry,
  IN UINT32 LR
  );

#endif
