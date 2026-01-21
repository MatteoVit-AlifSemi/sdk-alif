/** @file
 * @brief Bluetooth Audio shell module
 *
 * Provide some Bluetooth Audio shell commands that can be useful to applications.
 *
 * Copyright (c) 2017 Intel Corporation
 * Copyright (c) 2018 Nordic Semiconductor ASA
 * Copyright (c) Alif Semiconductor
 *
 * Alif Semiconductor version uses the Zephyr's bt shell module as a base
 * but adapts it to the Ceva-Waves' BLE stack.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/sys/util.h>
#include <zephyr/sys/printk.h>
#include <zephyr/shell/shell.h>
#include <zephyr/shell/shell_uart.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <zephyr/logging/log.h>
#include "unicast_sink.h"

//LOG_MODULE_REGISTER(bt_audio_shell, CONFIG_BT_AUDIO_SHELL_LOG_LEVEL);

static int cmd_vol_up(const struct shell *sh, size_t argc, char *argv[])
{
	int err;

	volume_increase(); 
		
    shell_fprintf(sh, SHELL_NORMAL, "Volume up\n");
	return 0;
}

static int cmd_vol_down(const struct shell *sh, size_t argc, char *argv[])
{
	int err;

	volume_decrease(); 
	
    shell_fprintf(sh, SHELL_NORMAL, "Volume down\n");	
	return 0;
}

static int cmd_track_next(const struct shell *sh, size_t argc, char *argv[])
{
	int err;

	next_track();
		
    shell_fprintf(sh, SHELL_NORMAL, "Next track\n");
	return 0;
}

static int cmd_track_prev(const struct shell *sh, size_t argc, char *argv[])
{
	int err;

	prev_track();
	
	shell_fprintf(sh, SHELL_NORMAL, "Prev track\n");
	return 0;
}

static int cmd_start(const struct shell *sh, size_t argc, char *argv[])
{
	int err;

	// TODO
	
	shell_fprintf(sh, SHELL_NORMAL, "Start\n");
	return 0;
}

static int cmd_stop(const struct shell *sh, size_t argc, char *argv[])
{
	int err;

	// TODO
	
    shell_fprintf(sh, SHELL_NORMAL, "Stop\n");
	return 0;
}

static int cmd_default_handler(const struct shell *sh, size_t argc, char **argv)
{
	if (argc == 1) {
		shell_help(sh);
		return SHELL_CMD_HELP_PRINTED;
	}

    shell_fprintf(sh, SHELL_ERROR, "%s unknown parameter: %s", argv[0], argv[1]);
	
	return -EINVAL;
}

#define HELP_NONE "[none]"

SHELL_STATIC_SUBCMD_SET_CREATE(
	bt_audio_cmds, 
	SHELL_CMD_ARG(vol-up, NULL, HELP_NONE, cmd_vol_up, 0, 0),
	SHELL_CMD_ARG(vol-down, NULL, HELP_NONE, cmd_vol_down, 0, 0),
	SHELL_CMD_ARG(track-next, NULL, HELP_NONE, cmd_track_next, 0, 0),
	SHELL_CMD_ARG(track-prev, NULL, HELP_NONE, cmd_track_prev, 0, 0),
	SHELL_CMD_ARG(start, NULL, HELP_NONE, cmd_start, 0, 0),
	SHELL_CMD_ARG(stop, NULL, HELP_NONE, cmd_stop, 0, 0),
	SHELL_SUBCMD_SET_END);

SHELL_CMD_REGISTER(bt_audio, &bt_audio_cmds, "Bluetooth audio shell commands", cmd_default_handler);
