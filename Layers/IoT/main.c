/*---------------------------------------------------------------------------
 * Copyright (c) 2021-2022 Arm Limited (or its affiliates).
 * All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *---------------------------------------------------------------------------*/

#include "RTE_Components.h"
#include  CMSIS_device_header
#include "cmsis_vio.h"
#ifdef    CMSIS_shield_header
#include  CMSIS_shield_header
#endif

#include "clock_config.h"
#include "board.h"
#include "pin_mux.h"
#include "peripherals.h"
#include "fsl_iomuxc.h"
#include "main.h"

// Callbacks for LPUART1 Driver
uint32_t LPUART1_GetFreq   (void) { return BOARD_BOOTCLOCKRUN_UART_CLK_ROOT; }
void     LPUART1_InitPins  (void) { /* Done in BOARD_InitDEBUG_UART function */ }
void     LPUART1_DeinitPins(void) { /* Not implemented */ }

// Callbacks for LPUART3 Driver
uint32_t LPUART3_GetFreq   (void) { return BOARD_BOOTCLOCKRUN_UART_CLK_ROOT; }
void     LPUART3_InitPins  (void) { /* Done in BOARD_InitARDUINO_UART function */ }
void     LPUART3_DeinitPins(void) { /* Not implemented */ }

int main (void) {

  /* System initialization */
  BOARD_ConfigMPU();
  BOARD_InitBootPeripherals();
  BOARD_InitBootPins();
  BOARD_InitBootClocks();
  BOARD_InitDebugConsole();

  NVIC_SetPriority(ENET_IRQn,    8U);
  NVIC_SetPriority(USDHC1_IRQn,  8U);
  NVIC_SetPriority(LPUART3_IRQn, 8U);

  /* Update System Core Clock info */
  SystemCoreClockUpdate();

  /* Reset Ethernet PHY (Required 100 us delay for PHY power on reset) */
  GPIO_PinWrite(GPIO1,  9U, 0U);
  SDK_DelayAtLeastUs(500U, CLOCK_GetFreq(kCLOCK_CpuClk));
  GPIO_PinWrite(GPIO1,  9U, 1U);

  vioInit();                            // Initialize Virtual I/O

#ifdef CMSIS_shield_header
  shield_setup();
#endif

  return (app_main());
}
