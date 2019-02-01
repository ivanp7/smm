#!/bin/bash

function error ()
{
    >&2 echo $2
    exit $1
}

function check_args_count ()
{
    case $# in
        2)
            if [[ $1 -ne $2 ]]
            then
                error 1 "Error: incorrect number of arguments."
            fi
            ;;

        3)
            if [[ $1 -lt $2 ]] || [[ $1 -gt $3 ]]
            then
                error 1 "Error: incorrect number of arguments."
            fi
            ;;
    esac
}

function cd_to_argument ()
{
    if [[ ! -z $1 ]]
    then
        if [[ ! -d $1 ]]
        then
            error 1 "Error: invalid path."
        fi

        cd $1
    fi
}

function check_subpath ()
{
    if [[ "$(readlink -m $1)" != "$(readlink -e $SMM_ROOT_DIRECTORY/$2)"* ]]
    then
        error 1 "Error: the specified path '$1' is not a subpath of '\$SMM_ROOT_DIRECTORY/$2'."
    fi
}

###############################################################################

if [[ -z $SMM_ROOT_DIRECTORY ]]
then
    >&2 echo "Error: SMM_ROOT_DIRECTORY not set."
    exit 1
fi

SMMT_DIRECTORY=$(realpath $(dirname $0))
SMMT=$SMMT_DIRECTORY/smmt.sh

if [[ -f "$SMMT_DIRECTORY/commands/$1" ]]
then
    . "$SMMT_DIRECTORY/commands/$1" "$@"
else
    error 1 "Error: unknown command. Use 'smmt.sh help' for list of available commands."
fi

