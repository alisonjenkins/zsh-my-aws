local PLUG_DIR
PLUG_DIR=$(dirname ${(%):-%N})

amr() {
    AWS_DEFAULT_REGION="$1"
    export AWS_DEFAULT_REGION
}

source "$PLUG_DIR/lib/instance-commands"
