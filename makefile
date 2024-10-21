# Copyright 2024 Politecnico di Torino.
# Solderpad Hardware License, Version 2.1, see LICENSE.md for details.
# SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
#
# File: makefile
# Author: Luigi Giuffrida
# Date: 03/10/2024
# Description: Top-level makefile for cnt

# ----- CONFIGURATION ----- #

# Global configuration
ROOT_DIR			:= $(realpath .)
BUILD_DIR 			:= build

# FUSESOC and Python values (default)
ifndef CONDA_DEFAULT_ENV
$(info USING VENV)
FUSESOC = ./.venv/bin/fusesoc
PYTHON  = ./.venv/bin/python
else
$(info USING MINICONDA $(CONDA_DEFAULT_ENV))
FUSESOC := $(shell which fusesoc)
PYTHON  := $(shell which python)
endif

# ----- TARGETS ----- #

## @section Simulation

## @subsection Verilator RTL simulation

## Build simulation model (do not launch simulation)
.PHONY: verilator-build
verilator-build:
	$(FUSESOC) run --no-export --target sim --tool verilator --build $(FUSESOC_FLAGS) polito:isa_lab:cnt \
		$(FUSESOC_ARGS)

## Build and run simulation
.PHONY: verilator-sim
verilator-sim: verilator-build
	$(FUSESOC) run --no-export --target sim --tool verilator --run $(FUSESOC_FLAGS) polito:isa_lab:cnt \
		$(FUSESOC_ARGS)

## Run simulation
.PHONY: verilator-run
verilator-run:
	$(FUSESOC) run --no-export --target sim --tool verilator --run $(FUSESOC_FLAGS) polito:isa_lab:cnt \
		$(FUSESOC_ARGS)


