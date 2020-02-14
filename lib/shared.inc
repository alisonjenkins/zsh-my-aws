# shared.inc
#
# Source in the internal functions

local PLUG_DIR=$(dirname ${(%):-%N})
source "$PLUG_DIR/parameter.inc"

__zma_error() {
  echo "ERROR: $@" > /dev/stderr
  ZMA_STATUS=1
  # TODO: Return zero. Returning non-zero should only happen when there is a
  # failure to return an error.
  return 1
}

__zma_usage() {
  echo "USAGE: ${funcstack[1]} $@" > /dev/stderr
}

# vim: ft=zsh