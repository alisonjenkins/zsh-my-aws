local PLUG_DIR="$(dirname \"${(%):-%N}\")"

amr() {
    AWS_DEFAULT_REGION="$1"
    export AWS_DEFAULT_REGION
}

source "$PLUG_DIR/instance-commands"