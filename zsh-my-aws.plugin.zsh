local PLUG_DIR=$(dirname ${(%):-%N})

amr() {
    if [ -z "$1" ]; then
        if [ -z "$AWS_DEFAULT_REGION" ]; then
            echo "AWS_DEFAULT_REGION is not set."
        fi
        echo "$AWS_DEFAULT_REGION"
    else
        AWS_DEFAULT_REGION="$1"
        export AWS_DEFAULT_REGION
    fi
}

source "$PLUG_DIR/lib/instance-commands"
