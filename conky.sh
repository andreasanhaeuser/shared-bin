#!/bin/bash
source ~/.profile

conky_path=~/shared/bin/conky

conky -c ${conky_path}/conky_network &
conky -c ${conky_path}/conky_cpu &
conky -c ${conky_path}/conky_sys &
