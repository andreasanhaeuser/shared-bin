#!/bin/bash
# Convert a sequence of png-pictures to an mp4-video.
# 
# Call:
# png_to_mp4.sh '<input_file(s)>'
#
# It is important that you use the ' characters to avoid premature globbing!
#
# Author
# ------
# Andreas Anhaeuser <andreas.anhaeuser@greenpeace.org>
# 
# The solution is mainly copied from here:
# https://trac.ffmpeg.org/wiki/Slideshow

# setup ----------------------------------------------
filenames_in=$1         # read from command line
filename_out='out.mp4'  #
framerate_in='2/1'      # pictures per second
framerate_out='24'      # frames per second
vcodec='libx264'
pix_fmt='yuv420p'
#  ---------------------------------------------------

ffmpeg \
    -r $framerate_in -pattern_type glob -i "${filenames_in}" \
    -vcodec $vcodec \
    -pix_fmt $pix_fmt \
    -r $framerate_out \
    $filename_out \
    || exit

echo $fno
