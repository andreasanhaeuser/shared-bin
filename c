#!/bin/sh
# Compile and run code written in C
#
# Exit status
# ===========
# - if successfully compiled that of the compiled program
# - else that of the compiler



# ========== SETUP =========================== #
tempfile='tmp.exe'
compile_options=' -Wall -W -O'

# compile_options=' -Wall -W -Wstrict-prototypes -O'

# colors
COMPILERCOLOR='\033[0;33m'        
ERRORCOLOR='\033[1;31m'        
INFOCOLOR='\033[1;37m'        
NOCOLOR='\033[0m'
# ============================================ #


# compile
echo "$INFOCOLOR> COMPILE with gcc...$COMPILERCOLOR"
gcc $compile_options $1 -o $tempfile
compile_state=$?

# compile error
if [ ! $compile_state -eq 0 ]
then
    echo "$ERRORCOLOR> ERROR WHILE COMPILING '$1' --> '$tempfile'.$NOCOLOR"
    return $compile_state
fi

# run binary
echo "$INFOCOLOR> SUCCESSFULLY compiled '$1' --> '$tempfile'.$NOCOLOR"
echo "$INFOCOLOR> RUN binary...$NOCOLOR\n"
./$tempfile
run_state=$?

# runtime error
if [ ! $run_state -eq 0 ]
then
    echo "$ERRORCOLOR> RUNTIME ERROR.$NOCOLOR"
else
    echo    "$INFOCOLOR\n> run was SUCCESSFUL.$NOCOLOR"
fi

echo "  source file:  $1\n  binary file:  $tempfile"

return $run_state
