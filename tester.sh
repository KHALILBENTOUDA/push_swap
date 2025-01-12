#!/bin/bash
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
RED='\033[0;31m'
NC='\033[0m'

generate_unique_random_numbers() {
    local count=$1
    local min_number=-2147483647
    local max_number=2147483647
    local unique_numbers=()
    local random_number

    while [ ${#unique_numbers[@]} -lt $count ]; do
        random_number=$(( RANDOM % (max_number - min_number + 1) + min_number ))
        if [[ ! "${unique_numbers[*]}" =~ "$random_number" ]]; then
            unique_numbers+=("$random_number")
        fi
    done

    echo "${unique_numbers[@]}"
}

run_test() {
    local count=$1
    local ARG=$(generate_unique_random_numbers $count | tr ' ' ' ')

    local PUSH_SWAP_OUTPUT=$(./push_swap $ARG)

    local RESULT=$(./checker_Mac $ARG <<< "$PUSH_SWAP_OUTPUT")
    local ACTIONS=$(echo "$PUSH_SWAP_OUTPUT" | wc -l)

    if [ "$RESULT" == "OK" ]; then
        if ([ $count -eq 100 ] && [ $ACTIONS -le 700 ]) || ([ $count -eq 500 ] && [ $ACTIONS -le 5500 ]) ||  ([ $count -eq 5 ] && [ $ACTIONS -le 12 ]) || ([ $count -eq 4 ] && [ $ACTIONS -le 12 ]) || ([ $count -eq 3 ] && [ $ACTIONS -le 3 ]) ; then
            echo -e "${GREEN}$RESULT ${YELLOW}$ACTIONS${NC}"
        else
            echo -e "${RED}KO${RED}$ACTIONS${NC}"
            return 1
        fi
    else
        echo -e "${RED}KO${NC}"
        return 1
    fi
    echo -e "${BLUE}------------------------------${NC}"
    return 0
}

if [ $# -ne 2 ]; then
    echo -e "${RED}Usage: $0 <number_of_random_numbers> <number_of_tests>${NC}"
    exit 1
fi

NUMBER_OF_NUMBERS=$1
NUMBER_OF_TESTS=$2
ALL_TESTS_PASS=true

for (( i=1; i<=NUMBER_OF_TESTS; i++ )); do
    echo -e "${BLUE}Test $i for $NUMBER_OF_NUMBERS numbers:${NC}"
    run_test $NUMBER_OF_NUMBERS || ALL_TESTS_PASS=false
done

if $ALL_TESTS_PASS; then
    echo -e "${GREEN}All tests are correct!${NC}"
else
    echo -e "${RED}Some tests failed.${NC}"
fi
