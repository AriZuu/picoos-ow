/*
 * Copyright (c) 2013, Ari Suutari <ari@stonepile.fi>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. The name of the author may not be used to endorse or promote
 *     products derived from this software without specific prior written
 *     permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 * INDIRECT,  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file    owcfg.h
 * @brief   picoos-ow library configuration file
 * @author  Ari Suutari <ari@stonepile.fi>
 */

/**
 * @ingroup config
 * @{
 */

/**
 * Configure GPIO operation to be used when library
 * wants to read bus state.
 */
#define OWCFG_READ_IN()   ( (P2IN & BIT6) ? 1 : 0 )

/**
 * Configure GPIO operation to be used when library
 * wants to drive bus low.
 */
#define OWCFG_OUT_LOW()  ( P2OUT &= ~BIT6 )

/**
 * Configure GPIO operation to be used when library
 * wants to drive bus high to deliver strong pull-up.
 */
#define OWCFG_OUT_HIGH() ( P2OUT |= BIT6 )

/**
 * Configure GPIO operation to be used when library
 * wants to change bus pin into input (floating).
 */
#define OWCFG_DIR_IN()   ( P2DIR &= ~(BIT6) )

/**
 * Configure GPIO operation to be used when library
 * wants to change bus pin into output (for driving
 * it high or low).
 */
#define OWCFG_DIR_OUT()  ( P2DIR |= BIT6 )

/**
 * Configure GPIO operation to be used when library
 * wants to turn power on for 1-Wire bus pull-up resistor.
 * This is optional. If not configured, it is assumed
 * that pull-up is always powered.
 */
#define OWCFG_POWER_ON()   P2DIR |= BIT7;  P2OUT |= BIT7

/**
 * Configure GPIO operation to be used when library
 * wants to turn power off for 1-Wire bus pull-up resistor.
 * This is optional. If not configured, it is assumed
 * that pull-up is always powered.
 *
 * This can be used to save power in battery-powered systems.
 */
#define OWCFG_POWER_OFF()  P2OUT &= ~BIT7

/** @} */
