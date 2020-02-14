# parameter.inc
#
# Used by zsh-my-aws functions to work with stdin and arguments.

__zma_read_inputs() {
  echo $(__zma_read_stdin) $@ |
    sed -E 's/\ +$//'         |
    sed -E 's/^\ +//'
}

__zma_read_stdin() {
  [[ -t 0 ]] ||
    cat                  |
      awk '{ print $1 }' |
      tr '\n' ' '        |
      sed 's/\ $//'
}

__zma_read_resources() {
  __zma_arg_types $@ |
    grep '^r'        |
    cut -d: -f2-
}

__zma_read_switches() {
  result="$(
    __zma_arg_types "$@"    |
      grep '^s:'            |
      cut -d: -f2-          |
      sort
  )"
  __zma_expand_switches "${result}"
}

# Prepend arguments with their type
# r:resource
# s:switch
#
# Resources cannot be included after switches
#
__zma_arg_types() {
  local switched
  switched=false

  for arg in $@; do
    if [[ "$arg" =~ ^-- ]]; then
      $switched && echo
      switched=true
      echo -n "s:$arg"
      continue
    fi

    if $switched; then
      echo -n " $arg"
      continue
    fi

    echo "r:$arg"
  done
  echo
}

__zma_expand_switches() {
  # this function is for expanding or rewriting switches.
  result=$(
    echo "$@"                              |
      sed -E 's/^--json/--output json/'   |
      sed -E 's/^--table/--output table/' |
      sed -E 's/^--text/--output text/'   |
      sed -E 's/^-f/--filters/'           |
      sed -E 's/^-q/--query/'
  )
  [[ -z "${result}" ]] || echo "${result}"
}

# vim: ft=zsh
