#!/usr/bin/env bash
# Copyright (c) 2018-2020 The Dash Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.
# use testnet settings,  if you need mainnet,  use ~/.dreamledger/dreamledgerd.pid file instead
export LC_ALL=C

dreamledger_pid=$(<~/.dreamledger/testnet3/dreamledgerd.pid)
sudo gdb -batch -ex "source debug.gdb" dreamledgerd ${dreamledger_pid}
