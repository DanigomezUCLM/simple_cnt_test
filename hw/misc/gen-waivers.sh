#!/bin/bash

ROOT_DIR=$(git rev-parse --show-toplevel)
WAIVER_FILE=$ROOT_DIR/hw/misc/verilator-waivers.vlt

# Get Verilator version

# Check if a file was provided as an argument
if [ -z "$1" ]; then
  echo "Usage: $0 <yaml_file>"
  exit 1
fi

# Assign the first argument to a variable
yaml_file="$1"

# Check if the provided file exists
if [ ! -f "$yaml_file" ]; then
  echo "Error: File $yaml_file not found!"
  exit 1
fi

# Extract the version from the YAML file
VERILATOR_VERSION=$(grep -oP '(?<=version: )\d+' "$yaml_file")

# Check if a version was found
if [ -z "$VERILATOR_VERSION" ]; then
  echo "Error: Version not found in $yaml_file"
  exit 1
fi

# Output the extracted version
echo "Verilator version: $VERILATOR_VERSION"
exit 0

# Replace unsupported options for Verilator < 5.000
cp $WAIVER_FILE.v5 $WAIVER_FILE
if [ "$VERILATOR_VERSION" -lt 5 ]; then
    sed -i 's/UNUSED[A-Z_]*/UNUSED/g' $WAIVER_FILE
fi

# Generate new .core file
echo """
CAPI=2:

name: polito:isa-lab:cnt-waiver:0.1.0
description: Waivers

filesets:
  waivers:
    files:
    - verilator-waivers.vlt
    file_type: vlt

targets:
  default:
    filesets:
    - waivers
""" > waivers.core

exit 0
