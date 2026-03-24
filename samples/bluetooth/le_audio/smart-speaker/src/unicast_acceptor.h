/* Copyright (C) 2025 Alif Semiconductor - All Rights Reserved.
 * Use, distribution and modification of this code is permitted under the
 * terms stated in the Alif Semiconductor Software License Agreement
 *
 * You should have received a copy of the Alif Semiconductor Software
 * License Agreement with this file. If not, please write to:
 * contact@alifsemi.com, or visit: https://alifsemi.com/license
 */

#ifndef _UNICAST_ACCEPTOR_H
#define _UNICAST_ACCEPTOR_H

/**
 * @brief Configure LE audio unicast acceptor functionality
 *
 * @return 0 on success
 */
int unicast_acceptor_init(void);

/**
 * @brief Start the LE audio unicast advertising
 *
 * @param p_address Pointer to the client device address for directed advertising
 *
 * @return 0 on success
 */
int unicast_acceptor_adv_start(void const * const p_address);

/**
 * @brief Stop the advertising
 *
 * @return 0 on success
 */
int unicast_acceptor_adv_stop(void);

/**
 * @brief Volume up
 *
 * @return 0 on success
 */
int volume_up(void);

/**
 * @brief Volume down
 *
 * @return 0 on success
 */
int volume_down(void);

/**
 * @brief Next track
 *
 * @return 0 on success
 */
int media_control_next_track(void);

/**
 * @brief Previous track
 *
 * @return 0 on success
 */
int media_control_prev_track(void);

/**
 * @brief Play
 *
 * @return 0 on success
 */
int media_control_play(void);

/**
 * @brief Previous track
 *
 * @return 0 on success
 */
int media_control_pause(void);

#endif /* _UNICAST_ACCEPTOR_H */
